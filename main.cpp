/*
=====================================================================================================
Name:			Jefferson Crelia		JeffersonCrelia@my.unt.edu
Instructor:		David Keathly
Date:			February 28, 2017
Description:		Program used for book-keeping in a library
=====================================================================================================
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include "functions.h"
#include "patron.h"
#include "patrons.h"
#include "borrow.h"
#include "borrows.h"
#include "book.h"
#include "books.h"


using namespace std;

int main(int argc, const char * argv[])
{
	patrons pats;
	books inventory;
	borrows transactions;

	int choice = -1;
	int id = 0;
	float fines;

	prtinfo();//print course and personal info
	pats.load();
	inventory.load();
	transactions.load();

	while (choice != 0)// creating menu
	{
		cout << "What do you want to do?\n";
		cout << " 0  - quit\n 1  - Add patron\n 2  - Edit patron\n 3  - Remove patron\n 4  - Print list of patrons\n 5  - Print list of a patrons fines\n 6  - Add new book\n 7  - Edit book\n 8  - Remove book\n 9  - Print list of a patrons books\n 10 - Check out a book\n 11 - Check in a book\n 12 - Pay fines\n 13 - Print overdues\n 14 - Print adress mailing labels\n\n";
		cout << "Enter your selection: ";
		cin  >> choice;

		switch (choice)
		{

		case 1: pats.addpat(); break; //add patron
		case 2: {
				cout << "Patron ID: ";
				cin >> id;
				pats.editpat(id);
				break;
			 }//edit patron

		case 3:  {
				cout << "Patron ID: ";
				cin >> id;
				pats.delpat(id);
				break;
			}//remove patron

		case 4: pats.prtlist() ; break; //print patrons
		case 5: transactions.prtfines(); break; //print patron fines
		case 6: inventory.addbook(); break; //add book
		case 7: {
				cout << "Book ID: ";
				cin >> id;
				inventory.editbook(id);
				break;
			 }//edit book

		case 8:  {
                                cout << "Book ID: ";
                                cin >> id;
                                inventory.delbook(id);
                                break;
                        }//remove book

		case 9:  {
				cout << "Patron ID: ";
				cin >> id;
				transactions.prtlist(id);
				break;
			  }//print list of patrons books
		case 10: transactions.addborrow(); break; //check out book
		case 11: {
				cout << "Borrow ID: ";
				cin >> id;
				transactions.delborrow(id, fines);
				break;
			 }//record returned book
		case 12: transactions.payfines(); break; //pay fines
		case 13: transactions.prtoverdues(); break; //print overdues
		case 14: pats.prtlabels();; break; //print mailing labels
		}
	}
	pats.save();//safe to disk
	inventory.save();
	transactions.save();

	//clear nodes
	pats.cleanup();
	inventory.cleanup();
	transactions.cleanup();


	return 0;
}
