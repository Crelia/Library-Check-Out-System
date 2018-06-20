#ifndef book_h
#define book_h

#include <string>
using namespace std;

//header for book
class book {
	private:
		int	b_id;
		double	cost;
		string  name;
		book * 	next;

	public:
		book();
		book	(int, double, string);
		int	getid();
		double	getcost();
		book *	getnext();
		string  getname();
		void	setid(int);
		void	setcost(double);
		void	setnext(book *);
		void    setname(string nm);
		string	title;
		string	publisher;
		int	status;
		void	print();
};

#endif /* book_h */
