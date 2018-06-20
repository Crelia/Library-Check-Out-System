#include <iostream>
#include <ctime>
//#include <string>
#include "patron.h"
using namespace std;

//patron methods
patron::patron() {
	patid = phone = 0;
	name=address= "";
	next = NULL;
}

patron::patron(int id, string nm, string ad, int num, float fi) {patid = id; nm = name; ad = address; num = phone; fi = fines;}

int patron::getid() {return patid;}

string patron::getname() {return name;}

string patron::getaddress() {return address;}

patron* patron::getnext() {return next;}

int patron::getphone() {return phone;}

float patron::getfines() {return fines;}

void patron::setid(int id) {patid = id;}

void patron::setname(string nm) {name = nm;}

void patron::setaddress(string ad) {address = ad;}

void patron::setnext(patron* np) {next = np;}

void patron::setphone(int num) {phone = num;}

void patron::setfines(float fi) {
	fines = fi;
}

void patron::print() {
    cout << "Patron: " << patid << endl;
    cout << "Name: " << getname() << endl;
    cout << "Number: " << getphone() << endl;

    cout << endl << endl;
}

void patron::prtlabels() {
//    cout << fixed;
//    cout.precision(2);
    cout << endl << endl;
    cout << getname() << endl;
    cout << getaddress() << endl;
//  cout << getphone() << endl;
    cout << endl << endl;
}
