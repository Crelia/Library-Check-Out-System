// Jefferson Crelia
// March 3, 2017

#ifndef books_h
#define books_h

#include "book.h"

class books {
	private:
		int bookcnt;
		book* tail;
		book* head;
	public:
		books() { bookcnt = 0; head = tail = NULL;}

    		int getcount();
	   	book* gettail();
    		book* gethead();
    		void inccount();
    		void deccount();
    		void settail(book*);
    		void sethead(book*);
    		void addbook();
		void editbook(int);
    		void delbook(int);
    		book *findbook(int);
    		void cleanup();
    		void prtlist();
		void load();
		void save();
};

#endif /* books_h */
