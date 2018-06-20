// Jefferson Crelia
// March 3, 2017

#ifndef patrons_h
#define patrons_h

#include "patron.h"
//#include <string>
using namespace std;

class patrons {
	private:
		int patcnt;
		patron* tail;
		patron* head;
	public:
		patrons() {patcnt = 0; head = tail = NULL;}
		int getcount();
		patron* gettail();
		patron* gethead();
		void inccount();
		void deccount();
		void settail(patron*);
		void sethead(patron*);
		void addpat();
		void editpat(int);
		void delpat(int);
		patron* findpat(int);
		void cleanup();
		void prtlist();
		void prtlabels();
		void load();
		void save();
};

#endif /* patrons_h */
