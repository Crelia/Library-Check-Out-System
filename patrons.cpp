#include "patrons.h"
#include "borrows.h"
#include <iostream>
#include <fstream>
//#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

//patrons methods
//patrons::patrons() {head = NULL; tail = NULL; patcnt = 0;}

int patrons::getcount() { return patcnt;}

patron* patrons::gettail() {return tail;}

patron* patrons::gethead() {return head;}

void patrons::inccount() {patcnt++;}

void patrons::deccount() { patcnt--;}

void patrons::settail(patron* tp) {tail = tp;}

void patrons::sethead(patron* hp) {head = hp;}

/*void patrons::addpat() {
    int id; string name; string address; int number;
    patron *temp = new patron();

    cout << "Enter new patron ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter name: ";
    getline(cin, name);
    cin.ignore();

    cout << "Enter address: ";
    getline(cin, address);
    cin.ignore();

    cout << "Enter phone number: ";
    cin >> number;
    cin.ignore();

    temp->setname(name);
    temp->setaddress(address);

    //cout << temp->getid() << temp->getname() << temp->getaddress();

    temp = new patron(id,name,address,number);

    temp->setnext(NULL);

    if (patcnt == 0)
    {
        head = tail = temp;
    }
    else
    {
        tail->setnext(temp);
        tail = temp;
    }

    patcnt +=1;
} For some reason this wouldnt print the strings so I just rewrotre a similar function beloow*/

void patrons::addpat(){
	int id, num;
	string name, address;

	patron *temp = new patron();

	cout << "\n\nWhat is the patron name: " << endl;
	cin.ignore();
	getline(cin, name); //get patron name

	cout << "What is the patron address: " << endl;
	cin.ignore();
	getline(cin, address); //get patron address

	cout << "What is the phone number: " << endl;
	cin >> num; //get patron number

	cout << "What would you like the ID to be: " << endl;
	cin >> id; //get patron id

	temp->setid(id);
	temp->setname(name);
	temp->setaddress(address);
	temp->setphone(num);

	if(patcnt == 0)
	{
		head = tail = temp;
	}
	else
	{
		tail->setnext(temp);
		tail = temp;
	}
	patcnt++;

	cout << endl << endl;
	return;
}


void patrons::editpat(int)
{
    int id, num;
    string name, address;

    patron *temp, *temp2;

    if (patcnt == 0 ) return;

    temp2 = head;
    temp = head->getnext();

    while (temp != tail) //while the head isnt the tail
    {
    	if (temp->getid() == id)
    	{
        	cout << "\n\nEnter the same or new name: ";
		getline(cin, name);
		cin.ignore();//get new name

		cout << "Enter the same or new address: ";
		getline(cin, address);//get new address

		cout << "Enter the same or new phone: ";
		cin >> num;//get new phone

		temp->setname(name);
		temp->setaddress(address);
		temp->setphone(num);

		cout << endl << endl;

		return;
	}

	else
	{
		temp2 = temp;
		temp = temp->getnext();//get the next patron to check
	}
    }
}



void patrons::delpat(int id)
{
    patron *temp, *temp2;

    if (patcnt == 0 ) return; //if no patrons, quit to menu
    if (head == tail && head->getid() == id)
    {
        head = tail = NULL;
        patcnt = 0;
        return;
    }


    temp2 = head;
    temp = head->getnext();
    while (temp != tail)
    {
        if (temp->getid() == id)
        {
            temp2->setnext(temp->getnext());
            delete temp;//delete the patron
            deccount();
            return;
        }
        else
        {
            temp2 = temp;
            temp = temp->getnext();
        }
    }

    cout << endl << endl;
}

patron* patrons::findpat(int id)
{
    patron *temp;
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

void patrons::cleanup()
{
    patron *temp;
    temp = head;
    while (temp != NULL)
    {
        patron *temp2;
        temp2 = temp->getnext();
        delete temp; //get rid or nodes
        temp = temp2;
    }
}

void patrons::prtlist()
{
    patron *temp;
    temp = head;
    while (temp != NULL)
    {
        patron *temp2;
        temp2 = temp->getnext();
	temp->print();//go to patron.print
//      cout<< "Patron id: " << temp->getid() <<" Name: "<< temp->getname() << endl <<endl;
//	temp->print();
        temp = temp2;
    }
}

void patrons::prtlabels()
{
	patron *temp;
	temp = head;
	while (temp != NULL)
	{
		patron *temp2;
		temp2 = temp->getnext();

		temp->prtlabels();//go to patron.prtlabels

		temp = temp2;
	}
}


void patrons::load()
{
	//patron *temp = new patron();

	ifstream in;

	int id, num;
	string name, address;

	in.open("patrons"); //opens a file for patrons

	if(in.fail())
	{
		cout << "Could not open loading file! Exiting to main." << endl; //error message
		return;
		//exit(EXIT_FAILURE); //exits the prgram if the file cannot open
	}

	while(!in.eof())// while not the end of the file
	{
		patron *temp = new patron();

		in >> id;

		in.ignore();
		getline(in, name);

		in.ignore();
		getline(in, address);

		in >> num;

		temp->setid(id);

		temp->setname(name);

		temp->setaddress(address);

		temp->setphone(num);

		if(patcnt == 0)
		{
			head = tail = temp;
		}
		else
		{
			tail->setnext(temp);

			tail = temp;
		}
		patcnt++;
	}

	in.close();

	return;
}


void patrons::save(){
	patron *temp;

	ofstream out;

	out.open("patrons"); //open save file

	if(out.fail())
	{
		cout << "Could not open patron file! Exiting now." << endl; //error message
		exit(EXIT_FAILURE);
	}

	temp = gethead();

	while(temp != NULL)
	{
		out << temp->getid() << endl;

		out << temp->getname() << endl;

		out << temp->getaddress() << endl;

		out << temp->getphone() << endl;

		temp = temp->getnext();
	}

	out.close();

	return;
}
