#include <iostream>
#include <string>
#include <time.h>
#include "borrow.h"
#include <time.h>
using namespace std;

//borrow methods
borrow::borrow() {
	borrow_id = bookloc = patloc = 0;
	next = NULL;
	date = time(NULL);
	fines = 0.00;
}

borrow::borrow(int id, int id2, int id3, time_t  dt, float fi) {borrow_id = id; patloc = id2; bookloc = id3; date = dt; fines = fi;}

int borrow::getid() {return borrow_id;}

int borrow::getpatid() { return patloc;}

int borrow::getbookid() {return bookloc;}

time_t borrow::getdate() {return date;}

borrow* borrow::getnext() {return next;}

float borrow::getfines() {return fines;}

void borrow::setid(int id) { borrow_id = id;}

void borrow::setpatid(int id) {patloc = id;}

void borrow::setbookid(int id) {bookloc = id;}

void borrow::setnext(borrow* np) {next = np;}

void borrow::setdate(time_t dt) {date = dt;}

void borrow::setfines(float fi) {fines = fi;}

void borrow::print() {
    cout << "Borrow id: " <<borrow_id << "Patron: " << patloc << "Book: " <<bookloc <<endl;
}
