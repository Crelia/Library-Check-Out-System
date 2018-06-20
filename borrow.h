#ifndef borrow_h
#define borrow_h

//header for borow
class borrow {
	private:
		int 		borrow_id;
		int 		bookloc;
		int 		patloc;
		time_t		date;
		borrow* 	next;
		float		fines;
	public:
		borrow();
		borrow(int, int, int, time_t, float);
		int getid();
    		int getpatid();
    		int getbookid();
    		borrow* getnext();
		time_t getdate();
		float getfines();
    		void setid(int);
    		void setpatid(int);
    		void setbookid(int);
    		void setnext(borrow*);
		void setdate(time_t);
		void setfines(float);
    		void print();
};

#endif /* borrow_h */
