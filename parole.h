#ifndef PAROLE_H
#define PAROLE_H
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class PAROLE
{
	private:
		string parola;
		string descrizione;
		
		
	public:
		PAROLE();
		string getP();
		string getD();
		void UP_P(string s);
		void UP_D(string s);
		string set(string s);
		~PAROLE();
};

#endif
