#include "lcs.h"

LCS::LCS() {}
LCS::~LCS() {}
int LCS::valoreLCS(string a,string b)
{
	vector < vector<int> > mat;
	int lung_a=a.length();
	int lung_b=b.length();
	int lcs=0;
	mat.resize(lung_a+1, vector<int> (lung_b+1) );
	
	for(int i=0;i<=lung_a;i++)   mat[i][0]=0;
	for(int i=0;i<=lung_b;i++)   mat[0][i]=0; 
	
	for(int i=1;i<=lung_a;i++)
	{
		for(int j=1;j<=lung_b;j++)
			{
				if(a[i-1]==b[j-1])  mat[i][j]=mat[i-1][j-1]+1;
				else
									mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
			}
	}
	lcs=mat[lung_a][lung_b];    
	return lcs;
}


int LCS::elementi()
{ return elem;}

void LCS::setE(int n)
{ elem=n;}

bool LCS::calcoloLCS(string par,TabellaHash tab)
{ 
valori.clear();
int contatore=0;
int val=0;
int n=0;
vector<PAROLE> punt;
int size=tab.grandezza();
punt=tab.testa();
	for(int i=0;i<size;i++)
		{
			if(punt.at(i).getP() != "")
				{	val=valoreLCS(par,punt.at(i).getP());
					if(val>1) {valori[punt.at(i).getP()]=val;
								contatore++;}
				}
		}
	
	
			 if(contatore==0) return false;
		else 
			{cout<<"L'algoritmo LCS ha prodotto "<<contatore<<" risultati."<<endl; }
			 cout<<"Quanti vuoi visualizzarne?"<<endl;
			 fflush(stdin); cin>>n;
			 if(n<=contatore) { setE(n);  stampaLCS( elementi() ); return true;}
			 else
			 	{do{ cout<<"Vuoi visualizzare un numero di elementi maggiore di quelli trovati!"<<endl;
			 		cout<<"Inserisci nuovamente il valore!"<<endl;
			 		cin>>n;}while(n>contatore);}
			 		 setE(n);  stampaLCS( elementi() );
				return true;
    
}

void LCS::stampaLCS(int n)
{	
	cout<<endl;
	vett.clear();
	map<string,int>::iterator it;
	for ( it = valori.begin(); it != valori.end(); it++ )
  		{
		  vett.push_back(pair<int,string>(it->second, it->first));
		}
			
			
			sort(vett.rbegin(),vett.rend());
		
				for( int i=0;i<n;i++)
				{
					cout<<"La parola: "<<vett.at(i).second<<" ha un valore di LCS: "<<vett.at(i).first<<endl;
				}
					
}
