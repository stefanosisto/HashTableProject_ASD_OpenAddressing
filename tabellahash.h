#ifndef TABELLAHASH_H
#define TABELLAHASH_H
#include <vector>
#include <string>
#include "parole.h"
using namespace std;

class TabellaHash 
{
	private:
		vector<PAROLE> hashtable;
		int size;
		int termini;
	public:
		TabellaHash();
		~TabellaHash();
		int hash1(char *v,int m);
		int hash2(char *v,int m);
		int hashingdoppio(string par,int);
		bool inserisci(PAROLE par);
		bool cerca(string par);
		bool rimuovi(string par);
		void stampatable();
		int grandezza();
		void sizepiu();
		vector<PAROLE> testa();
};

#endif
