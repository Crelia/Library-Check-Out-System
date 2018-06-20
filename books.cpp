#include <iostream>
#include <fstream>
#include "books.h"
#include "book.h"

using namespace std;

//books methods

int books::getcount() {return bookcnt;}

book* books::gettail() {return tail;}

book* books::gethead() {return head;}

void books::inccount() {bookcnt++;}

void books::deccount() {bookcnt--;}

void books::settail(book*tp) {tail = tp;}

void books::sethead(book* hp) {head = hp;}

void books::addbook()
{
    int id; float co;
    string nm;
    book *temp;

    cout << "Enter new book ID: " << endl;
    cin >> id;
    cin.ignore();

    cout << "Enter cost: " << endl;
    cin  >> co;

    cout << "Enter title: " << endl;
    cin.ignore();
    getline(cin, nm);

    temp = new book(id,co, nm);

    temp->setnext(NULL);

    if (bookcnt == 0)
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

void books::editbook(int id)
{
    int co;
    string nm;
    book *temp, *temp2;

    if (bookcnt == 0 ) return;

    if (head == tail && head->getid() == id)
    {
        cout << "Enter the same or new cost: " << endl;
        cin >> co;

	cout << "Enter the same or new title: " << endl;
	cin.ignore();
	getline(cin, nm);

	temp->setcost(co);
	temp->setname(nm);

        return;
    }

    while (temp != tail)
    {
        if (temp->getid() == id)
        {
                cout << "Enter the same or new cost: " << endl;
                cin >> co;

		cout << "Enter the same or new title: " << endl;
		cin.ignore();
		getline(cin, nm);

		temp->setcost(co);
		temp->setname(nm);

                return;
        }

        else
        {
                temp2 = temp;
                temp = temp->getnext();
        }
    }
}


void books::delbook(int id)
{

    book *temp, *temp2;

    if (head == tail && head->getid() == id)
    {
        head = tail = NULL;
        deccount();
        return;
    }


    temp2 = head;
    temp = head->getnext();
    while (temp != tail)
    {
        if (temp->getid() == id)
        {
            temp2->setnext(temp->getnext());
            delete temp;
            deccount();
            return;
        }
        else
        {
            temp2 = temp;
            temp = temp->getnext();
        }
    }

}

book* books::findbook(int id)
{
    book *temp;
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

void books::cleanup()
{
    book *temp;
    temp = head;
    while (temp != NULL)
    {
        book *temp2;
        temp2 = temp->getnext();
        delete temp;
        temp = temp2;
    }

}

void books::prtlist()
{
    book *temp;
    temp = head;
    while (temp != NULL)
    {
        book *temp2;
        temp2 = temp->getnext();
        cout<< "Book id: " << temp->getid() <<" Cost: "<< temp->getcost() << endl;
        temp = temp2;
    }
}

void books::load() {
	//patron *temp = new patron();
	ifstream in;
	int b_id, co;
	string name;
	in.open("books"); //opens a file for patrons
	if(in.fail())
	{
		cout << "Could not open loading file! Bringing you to menu." << endl; //error message
		return;
		//exit(EXIT_FAILURE); //exits the prgram if the file cannot open
	}

	while(!in.eof())// while not the end of the file
	{
		book *temp = new book();

		in >> b_id;

		in >> co;

		in.ignore();
		getline(in, name);

		temp->setid(b_id);

		temp->setcost(co);

		temp->setname(name);

		if(bookcnt == 0)
		{
			head = tail = temp;
		}
		else
		{
			tail->setnext(temp);
			tail = temp;
		}
		bookcnt++;
	}
	in.close();
	return;
}
void books::save(){
	book *temp;

	ofstream out;

	out.open("books"); //open save file

	if(out.fail())
	{
		cout << "Could not open book file! Exiting now." << endl; //error message
		return;
		//exit(EXIT_FAILURE);
	}

	temp = gethead();

	while(temp != NULL)
	{
		out << temp->getid() << endl;

		out << temp->getcost() << endl;

		out << temp->getname() << endl;

		temp = temp->getnext();
	}
	out.close();
	return;
}
