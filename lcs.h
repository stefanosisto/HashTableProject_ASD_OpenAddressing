#ifndef LCS_H
#define LCS_H
#include "tabellahash.h"
#include <map>
#include <algorithm>
class LCS 
{

	private:
		map<string,int> valori;
		vector<pair <int,string> > vett;
		int elem;
	public:
		LCS();
		int valoreLCS(string a,string b);
		bool calcoloLCS(string par,TabellaHash tab);
		void stampaLCS(int n);
		int elementi();
		void setE(int n);
		~LCS();
};

#endif
