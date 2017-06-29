#include "filetesto.h"

FileTesto::FileTesto()
{}

FileTesto::~FileTesto()
{}

void FileTesto::salva(vector<PAROLE> par,string s)
{
	s=s+".txt";
fstream file(s.c_str(),ios::out);
for(unsigned int i=0;i<par.size();i++)
		{ 
			if(par.at(i).getP() != "")
					{
						file<<par.at(i).getP()<<endl;
						file<<par.at(i).getD()<<endl;
					}
		}
				file.close();
}

void FileTesto::carica(TabellaHash &tab,string s)
{
string chiave,des;
PAROLE p;
s=s+".txt";
fstream file;
file.open(s.c_str(),ios::in);
if(!file) cout<<"NON HO TROVATO IL FILE!"<<endl;
		while ( file.is_open() == false )
				{ cout<<"Prova a reinserire il nome, oppure digita esci se non intendi piu' caricarlo!"<<endl;
					fflush(stdin); getline(cin,s); s=p.set(s); s=s+".txt"; file.open(s.c_str(),ios::in);
					if(s == "Esci.txt") return;
				}


while( getline(file,chiave) )
{
	getline(file,des);
	p.UP_P(chiave); p.UP_D(des);
	tab.inserisci(p);  
	
	
}
file.close(); cout<<"Dizionario caricato correttamente!"<<endl;
}
