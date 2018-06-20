#ifndef patron_h
#define patron_h

#include <string>
using namespace std;

//header for patron
class patron {
	private:
		int			patid;
		string			name;
		string			address;
		patron *		next;
		int			phone;
		float			fines;
	public:
		patron();
		patron(int, string, string, int, float);
		int			getid();
		string			getname();
		string			getaddress();
		patron *		getnext();
		int			getphone();
		float			getfines();
		void			setid(int id);
		void			setname(string nm);
		void			setaddress(string ad);
		void			setnext(patron*);
		void			setphone(int num);
		void			setfines(float fi);
		double			balance;
		int			numofbooks;
		int			status;
		void			print();
		void			prtlabels();
};
 #endif /* patron_h */
