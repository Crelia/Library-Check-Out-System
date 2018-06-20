#include <iostream>
//#include <string>
#include "book.h"
using namespace std;

//book methods
book::book() {
        b_id = cost = 0;
        name= "";
        next = NULL;
}

book::book (int id, double co, string nm)  {b_id = id; cost = co; nm = name;}

int book::getid()  {return b_id;}

double book::getcost() {return cost;}

book * book::getnext() {return next;}

string book::getname() {return name;}

void book::setid(int id) {b_id = id;}

void book::setcost(double co) {cost = co;}

void book::setnext(book *np) {next = np;}

void book::setname(string nm) {name = nm;}

void book::print() {
    cout << "Book ID: " << getid() << endl;
    cout << "Cost: " << getcost() << endl;
    cout << "Title: :" << getname() << endl << endl;
}
