#include <iostream>
#include "tabellahash.h"
#include "parole.h"
#include "lcs.h"
#include "filetesto.h"
using namespace std;
int main() {

cout<<"-----------------------------------------"<<endl;
cout<<" Traccia B    Sisto Stefano mat.0124/899 "<<endl;
cout<<"-----------------------------------------"<<endl;
cout<<"Hash Table con indirizzamento aperto."<<endl<<endl;;
cout<<"In caso di fallimento nella ricerca, utilizza l'algoritmo LCS per dare una lista delle parole piu' prossime."<<endl;
cout<<"-----------------------------------------"<<endl;
string nome_dizionario;
TabellaHash table;
PAROLE parola;
LCS lcs;
string par,descr;
FileTesto dizionario;
char scelta;
cout<<"Vuoi caricare il tuo dizionario (di tipo .txt !) ? premi Y per caricare"<<endl;
fflush(stdin); cin>>scelta;
if(scelta == 'y' || scelta == 'Y') { cout<<"Inserisci il nome del file senza l'estensione: "; fflush(stdin); getline(cin,nome_dizionario);
									 nome_dizionario=parola.set(nome_dizionario);
									 dizionario.carica(table,nome_dizionario);
									 }

cout<<"Hai ora la possibilita' di inserire o cercare un nuovo termine"<<endl;
cout<<"-----------------------------------------"<<endl;
cout<<"Premi la lettera tra parentesi per scegliere."<<endl;
cout<<"(i) - inserisci un nuovo termine"<<endl;
cout<<"(c) - cerca un termine"<<endl;
cout<<"(r) - rimuovi un termine"<<endl;
cout<<"(s) - stampa l'hash table"<<endl;
cout<<"(e) - esci e salva il dizionario"<<endl;
cout<<"-----------------------------------------"<<endl;
fflush(stdin);
cin>>scelta;
while(scelta != 'e')
	{   system("cls");
		switch(scelta)
			{   
				case 'i':
						cout<<"Inserisci il termine: "; fflush(stdin); getline(cin,par); fflush(stdin);
						cout<<"Inserisci la descrizione: "; getline(cin,descr);
						parola.UP_P(par); parola.UP_D(descr);
						if(table.inserisci(parola) == true) cout<<"Termine inserito!"<<endl;
						
						break;
				case 'c':
						cout<<"Quale termine vuoi cercare?"<<endl; fflush(stdin); getline(cin,par); par=parola.set(par);
						if(table.cerca(par) == false) {cout<<"Non ho trovato il termine. Provo con l'algoritmo LCS "<<endl;
														if (lcs.calcoloLCS(par,table) == false)
														cout<<"Mi dispiace, ma non ho riscontri con l'algoritmo LCS"<<endl;
														}													
						break;
				case 's':
						table.stampatable();
						break;
				case 'r':
						cout<<"Quale termine vuoi rimuovere?"<<endl; fflush(stdin); getline(cin,par); par=parola.set(par);
						if(table.rimuovi(par) == false) { cout<<"Non ho trovato il termine da rimuovere!"<<endl;}
						break;
			}
			cout<<"-----------------------------------------"<<endl;
			cout<<"(i) - inserisci un nuovo termine"<<endl;
			cout<<"(c) - cerca un termine"<<endl;
			cout<<"(r) - rimuovi un termine"<<endl;
			cout<<"(s) - stampa l'hash table"<<endl;
			cout<<"(e) - esci e salva il dizionario"<<endl;
			cout<<"-----------------------------------------"<<endl;
			fflush(stdin);
			cin>>scelta;
			
	} 
	cout<<"Vuoi salvare il tuo dizionario? premi Y per salvare"<<endl;
		fflush(stdin); cin>>scelta;
		if(scelta == 'y' || scelta == 'Y') { cout<<"ATTENZIONE! Salvando il tuo nuovo dizionario con un nome uguale al vecchio sovrascriverai il tuo vecchio dizionario."<<endl;
											 cout<<"Vuoi continuare? Y per procedere"<<endl;
											fflush(stdin); cin>>scelta;
											if(scelta == 'y' || scelta == 'Y') { 
													cout<<"Inserisci il nome con cui vuoi salvare il dizionario"<<endl; 
													fflush(stdin); getline(cin,nome_dizionario); nome_dizionario=parola.set(nome_dizionario);
													dizionario.salva(table.testa(),nome_dizionario); cout<<"Ho salvato il tuo dizionario"<<endl;}
											else cout<<"Hai scelto di non salvare il dizionario"<<endl;	}
	cout<<"Arrivederci!"<<endl;
	cout<<"Scritto da Stefano Sisto per l'esame di Algoritmi e Strutture Dati"<<endl;
	return 0;
}
