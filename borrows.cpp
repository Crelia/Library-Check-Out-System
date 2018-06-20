#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>
#include "borrows.h"
#include "borrow.h"

using namespace std;

//borrows methods

int borrows::getcount() {return borcnt;}

borrow* borrows::gettail(){return tail;}

borrow* borrows::gethead() {return head;}

void borrows::inccount() {borcnt++;}

void borrows::deccount() {borcnt--;}

void borrows::settail(borrow*tp) {tail = tp;}


void borrows::sethead(borrow* hp) {head = hp;}


void borrows::addborrow()
{
    int id, id2, id3;
    time_t dt;

    borrow *temp = new borrow();

    cout << "Enter new borrow ID: ";
    cin >> id;
//    cin.ignore();
    temp->setid(id);

    cout << "Enter patron ID: ";
    cin >> id2;
//    cin.ignore();
    temp->setpatid(id2);

    cout << "Enter book ID: ";
    cin >> id3;
//    cin.ignore();
    temp->setbookid(id3);

    dt = time(&dt);

    temp->setdate(dt);

    temp->setnext(NULL);

    if (borcnt == 0)
    {
        head = tail = temp;
    }
    else
    {
        tail->setnext(temp);
        tail = temp;
    }

    inccount();

}

void borrows::delborrow(int id, float fines)
{
    borrow *temp, *temp2;

    time_t now;
    int secs, extra, amt;

    if (head == tail && head->getid() == id)
    {
	if(difftime(time(&now), temp->getdate()) > 1209600)
	{
		secs = difftime(now, temp->getdate());

		extra = temp->getdate() - 1209600;

		amt =  (((extra/60)/60)/24);

		fines = amt * .25;

		temp->setfines(fines);


		cout << "Fines must be paid before you can check the book as in. Patron owes $";
		cout  << temp->getfines() << endl;
		return;
	}
	else
	{
	        head = tail = NULL;
      		deccount();
	}

        return;
    }


    temp2 = head;
    temp = head->getnext();
    while (temp != tail)
    {
        if (temp->getid() == id)
        {
        	if(difftime(time(&now), temp->getdate()) > 1209600)
        	{
                	secs = difftime(now, temp->getdate());

	                extra = temp->getdate() - 1209600;

	                amt =  (((extra/60)/60)/24);

	                fines = amt * .25;

	                temp->setfines(fines);


	                cout << "Fines must be paid before you can check the book as in. Patron owes " << temp->getfines() << endl;
        	        return;
       		}

	     	 else
		{
		    temp2->setnext(temp->getnext());
        	    delete temp;
         	    deccount();
       	    	    return;
        	}
	}
        else
        {
            temp2 = temp;
            temp = temp->getnext();
        }
    }

}

borrow* borrows::findborrow(int id)
{
    borrow *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->getid() == id)
            return temp;
        else
            temp = temp->getnext();
    }
    return NULL;


}

void borrows::cleanup()
{
    borrow *temp;
    temp = head;
    while (temp != NULL)
    {
        borrow *temp2;
        temp2 = temp->getnext();
        delete temp;
        temp = temp2;
    }

}

void borrows::prtlist(int id)
{
    borrow *temp;
    temp = head;
    while (temp != NULL)
    {
        borrow *temp2;
        temp2 = temp->getnext();

	if (temp->getpatid() == id)
	{
        	cout<< "Borrow id: " << temp->getid() <<" Patron: "<< temp->getpatid() << " Book: " << temp->getbookid() << endl;
        	temp = temp2;
	}
    }
    return;
}

void borrows::prtfines()
{
	borrow *temp;
	temp = head;

	while (temp != NULL)
	{
		borrow *temp2;
		temp2 = temp->getnext();

		if (temp->getfines() > 0)
		{
			cout << "Borrow id: " << temp->getid() << " Patron: " << temp->getpatid() << " Book: " << temp->getbookid() << "Fines: $" << temp->getfines() << endl << endl;
			temp = temp2;
		}
	}
	return;
}

void borrows::prtoverdues()
{
	borrow *temp;
	temp = head;

	time_t now;

	while ( temp != NULL)
	{
		borrow *temp2;
		temp2 = temp->getnext();

		if (difftime(time(&now), temp->getdate()) > 1209600)
		{
			cout << "Borrow id: " << temp->getid() << " Patron: " << temp->getpatid() << " Book: " << temp->getbookid() << "Days overdue: " << (((temp->getdate()/60)/60)/24) - 14 << endl << endl;
			temp = temp2;
		}
	}
	return;
}


void borrows::payfines()
{
	int id;

	cout << "What is the patron id: ";
	cin >> id;

	borrow * temp;
	temp = head;

	while( temp != NULL)
	{
		borrow *temp2;
		temp2 = temp->getnext();

		if (temp->getpatid() == id)
		{
			temp2->setnext(temp->getnext());
			delete temp;
			deccount();
			return;
		}
	}
}

void borrows::load()
{
	ifstream in;

	int borrow_id, bookloc, patloc;
	time_t date;
	float fines;

	in.open("borrows"); //opens a file for patrons

	if(in.fail())
	{
		cout << "Could not open loading file! Bringing you to main." << endl; //error message
		return;
		//exit(EXIT_FAILURE); //exits the prgram if the file cannot open
	}

	while(!in.eof())// while not the end of the file
	{
		borrow *temp = new borrow();

		in >> borrow_id;

		in >> bookloc;

		in >> patloc;

		in >> date;

		in >> fines;



		temp->setid(borrow_id);

		temp->setbookid(bookloc);

		temp->setpatid(patloc);

		temp->setdate(date);

		temp->setfines(fines);

		if(borcnt == 0)
		{
			head = tail = temp;
		}
		else
		{
			tail->setnext(temp);
			tail = temp;
		}
		borcnt++;
	}

	in.close();

	return;
}


void borrows::save()
{
	borrow *temp;

	ofstream out;
	out.open("borrows"); //open save file

	if(out.fail())
	{
		cout << "Could not open patron file! Exiting now." << endl; //error message
		return;
		//exit(EXIT_FAILURE);
	}

	temp = gethead();

	while(temp != NULL)
	{
		out << temp->getid() << endl;

		out << temp->getbookid() << endl;

		out << temp->getpatid() << endl;

		out << temp->getdate() << endl;

		out << temp->getfines() << endl;

		temp = temp->getnext();
	}

	out.close();

	return;
}
