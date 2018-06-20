//Jefferson Crelia
// March 30, 2017

#ifndef borrows_h
#define borrows_h

#include "borrow.h"

class borrows {
	private:
    		int borcnt;
    		borrow* tail;
    		borrow* head;
	public:
    		borrows() {borcnt = 0; head = tail = NULL;}

    		int getcount();
    		borrow* gettail();
   		borrow* gethead();
    		void inccount();
    		void deccount();
    		void settail(borrow*);
    		void sethead(borrow*);
    		void addborrow();
    		void delborrow(int, float);
    		borrow *findborrow(int);
    		void cleanup();
    		void prtlist(int);
		void prtfines();
		void prtoverdues();
		void payfines();
		void load();
		void save();
};

#endif /* borrows_h */
