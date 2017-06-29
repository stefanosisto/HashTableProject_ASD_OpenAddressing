#include "parole.h"

PAROLE::PAROLE()
{ parola="";
  descrizione="";
}

PAROLE::~PAROLE()
{}

void PAROLE::UP_P(string s)
{	unsigned int i=0;
	parola=s;
	parola[i]=toupper(parola[i]);
	for (i=1;i<parola.length();i++)
		parola[i]=tolower(parola[i]);
}

void PAROLE::UP_D(string s)
{
    unsigned int i=0;
	descrizione=s;
	descrizione[i]=toupper(descrizione[i]);
	for (i=1;i<descrizione.length();i++)
		descrizione[i]=tolower(descrizione[i]);
	
}

string PAROLE::getP()
{return parola;}

string PAROLE::getD()
{return descrizione;}

string PAROLE::set(string s)
{
	unsigned int i=0;
	s[i]=toupper(s[i]);
	for(i=1;i<s.length();i++)
		s[i]=tolower(s[i]);
		return s;
}


