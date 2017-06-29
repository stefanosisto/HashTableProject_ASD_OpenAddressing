#include "tabellahash.h"

TabellaHash::TabellaHash()
{
	size=10;
	termini=0;
	hashtable.resize(size);
}

TabellaHash::~TabellaHash()
{}

int TabellaHash::hash1(char *v,int m)
{
	int h=0;
	for(; *v!=0;v++)
	h=h+*v;
	h=h%m;
	return h;
}

int TabellaHash::hash2(char *v,int m)
{
	int h=0;
	for(; *v != 0; v++)
	h=h+*v;
	h=(h%(m-2))+1;
	return h;
}

int TabellaHash::hashingdoppio(string par,int i)
{
	int h1=hash1((char*)par.c_str(),size);
	int h2=hash2((char*)par.c_str(),size);
	int hd=(h1+(i*h2))%size;
	return hd;
}

void TabellaHash::stampatable()
{
	
	for(int i=0;i<grandezza();i++)
		{   if(hashtable.at(i).getP() != "")
			cout<<hashtable.at(i).getP()<<endl;
		}
	
}

bool TabellaHash::inserisci(PAROLE par)
{	
	int i=0;
	char scelta;	
	if ( termini*2 >= size ) sizepiu();
	int hd=hashingdoppio(par.getP(),i);
	while(hashtable.at(hd).getP() != "")
			{   
				if(hashtable.at(hd).getP() == par.getP() )	
				{  cout<<"Il termine inserito esiste gia' ed ha questa definizione:"<<endl<<endl;
				   cout<<hashtable.at(hd).getD()<<endl<<endl;	
				   cout<<"Se vuoi aggiornare la descrizione digita Y altrimenti digita N"<<endl;
				   cin>>scelta;
				   if ( scelta == 'Y' || scelta == 'y') { 
				   					hashtable.at(hd).UP_D(par.getD()); cout<<"Descrizione aggiornata!"<<endl;}
									return false;
				}		
				i++;
				hd=hashingdoppio(par.getP(),i);
			}

	termini++;

	hashtable.at(hd)=par;

	return true;
}

bool TabellaHash::cerca(string par)
{
	int i=0;
	int hd=hashingdoppio(par,i);
	
	while(hashtable.at(hd).getP() != "" )
		{   
			if(hashtable.at(hd).getP() == par)
				{
					cout<<"La definizione e': "<<hashtable.at(hd).getD()<<endl;
					return true;
				}
			else{	
				i++;  
				hd=hashingdoppio(par,i);
				}
		}
		
		return false;
}

bool TabellaHash::rimuovi(string par)
{
	int i=0;
	int hd=hashingdoppio(par,i);
	
	while(hashtable.at(hd).getP() != "" )
		{
				if(hashtable.at(hd).getP() == par)
						{	
							 
							
							
									while(hashtable.at(hashingdoppio(par,i+1)).getP() != "" )
										{
												
												hashtable.at(hd).UP_P( hashtable.at(hashingdoppio(par,i+1)).getP() );
												hashtable.at(hd).UP_D( hashtable.at(hashingdoppio(par,i+1)).getD() );
												
												i++;
										}
										hashtable.at(hd).UP_P("");
										hashtable.at(hd).UP_D("");
										cout<<"Ho eliminato il termine!"<<endl;
										return true;
											
						}
						i++; hd=hashingdoppio(par,i);
		} return false;
	
		
}

int TabellaHash::grandezza()
{ return size;}

void TabellaHash::sizepiu()
{		
		vector<PAROLE> supporto;
		supporto.clear();
		supporto.resize(size);
		for(int i=0;i<size;i++)
		supporto.at(i) = hashtable.at(i);
		int vecchiosize=size; 
		size=size*2;
		hashtable.clear();
		hashtable.resize(size);
		for(int i=0;i<vecchiosize;i++)
	    if (supporto.at(i).getP() != "") inserisci(supporto.at(i));

	   
} 


vector<PAROLE> TabellaHash::testa()
{ return hashtable; }
