#include<iostream>
#include<cstring>
#define H 15
#define L 29
using namespace std;

bool GameOver=false;
int b=0,n=0,coord2,x[9],y[9],win=0;
char coord1,giocatore1[10],giocatore2[10],M[H][L],vincitore[10];

//INTRO CHE CHIEDE IL NOME DEI GIOCATORI
void intro()
{
	system("color B");
    cout<<"\n\nษอออออออออออออออออออออออออออออออออออ   TRIS   อออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                   \n";
    cout<<"                           Prodotto da: Corrado Raiola                             \n";
    cout<<"                                                                                  \n";
    cout<<"                                 Versione: 1.0                                  \n";
    cout<<"                                                                                   \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    system("pause");
    system("cls");
	cout<<"Inserire il nome dei giocatori:\n\n";
	cout<<"Giocatore 1: ";
	cin>>giocatore1;
	cout<<"\nGiocatore 2: ";
	cin>>giocatore2;
	system("pause");
}

//DISEGNA LA STRUTTURA DEL GIOCO
void draw()
{
	system("color B");
	system("cls");
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<L;j++)
		{
			if(i==0 && j>0) {cout<<"อ"; M[i][j]='อ';}
			else if(i==1 && j==8) {cout<<"1"; M[i][j]='1';}
			else if(i==1 && j==12) {cout<<"บ"; M[i][j]='บ';}
			else if(i==1 && j==16) {cout<<"2"; M[i][j]='2';}
			else if(i==1 && j==20) {cout<<"บ"; M[i][j]='บ';}
			else if(i==1 && j==24) {cout<<"3"; M[i][j]='3';}
			else if(i==2 && (j>4 && j<28)) {cout<<"อ"; M[i][j]='อ';}
			else if(i==2 && j==4) {cout<<"ษ"; M[i][j]='ษ';}
			else if(j==0 && i>0) {cout<<"บ"; M[i][j]='บ';}
			else if(j==2 && i==4) {cout<<"A"; M[i][j]='A';}
			else if(j==1 && i==6) {cout<<"อ"; M[i][j]='อ';}
			else if(j==2 && i==6) {cout<<"อ"; M[i][j]='อ';}
			else if(j==3 && i==6) {cout<<"อ"; M[i][j]='อ';}
			else if(j==2 && i==8) {cout<<"B"; M[i][j]='B';}
			else if(j==1 && i==10) {cout<<"อ"; M[i][j]='อ';}
			else if(j==2 && i==10) {cout<<"อ"; M[i][j]='อ';}
			else if(j==3 && i==10) {cout<<"อ"; M[i][j]='อ';}
			else if(j==2 && i==12) {cout<<"C"; M[i][j]='C';}
			else if(j==4 && (i>2 && i<14)) {cout<<"บ"; M[i][j]='บ';}
			else if(i==14 && (j>4 && j<28)) {cout<<"อ"; M[i][j]='อ';}
			else if(i==14 && j==4) {cout<<"ศ"; M[i][j]='ศ';}
			else if(j==28 && (i>2 && i<14)) {cout<<"บ"; M[i][j]='บ';}
			else if(j==28 && i==2) {cout<<"ป"; M[i][j]='ป';}
			else if(i==6 && j>4) {cout<<"ฐ"; M[i][j]='ฐ';}
			else if(i==10 && j>4) {cout<<"ฐ"; M[i][j]='ฐ';}
			else if(j==12 && i>2) {cout<<"ฐ"; M[i][j]='ฐ';}
			else if(j==20 && i>2) {cout<<"ฐ"; M[i][j]='ฐ';}
			else if(i==14 && j==28) {cout<<"ผ"; M[i][j]='ผ';}
			else if(i==0 && j==0) {cout<<"ษ"; M[i][j]='ษ';}
			else if(i==x[0] && j==y[0]) {cout<<"þ"; M[i][j]='þ';}
			else if(i==x[1] && j==y[1]) {cout<<"O"; M[i][j]='O';}
			else if(i==x[2] && j==y[2]) {cout<<"þ"; M[i][j]='þ';}
			else if(i==x[3] && j==y[3]) {cout<<"O"; M[i][j]='O';}
			else if(i==x[4] && j==y[4]) {cout<<"þ"; M[i][j]='þ';}
			else if(i==x[5] && j==y[5]) {cout<<"O"; M[i][j]='O';}
			else if(i==x[6] && j==y[6]) {cout<<"þ"; M[i][j]='þ';}
			else if(i==x[7] && j==y[7]) {cout<<"O"; M[i][j]='O';}
			else if(i==x[8] && j==y[8]) {cout<<"þ"; M[i][j]='þ';}
			else {cout<<" "; M[i][j]=' ';}
		}
		cout<<endl;
	}
}

void logic()
{
	//VINCITA GIOCATORE 1
	if(M[4][8]=='þ' && M[4][16]=='þ' && M[4][24]=='þ') {win=1; GameOver=true;}
	else if(M[8][8]=='þ' && M[8][16]=='þ' && M[8][24]=='þ') {win=1; GameOver=true;}
	else if(M[12][8]=='þ' && M[12][16]=='þ' && M[12][24]=='þ') {win=1; GameOver=true;}
	else if(M[4][8]=='þ' && M[8][8]=='þ' && M[12][8]=='þ') {win=1; GameOver=true;}
	else if(M[4][16]=='þ' && M[8][16]=='þ' && M[12][16]=='þ') {win=1; GameOver=true;}
	else if(M[4][24]=='þ' && M[8][24]=='þ' && M[12][24]=='þ') {win=1; GameOver=true;}
	else if(M[4][8]=='þ' && M[8][16]=='þ' && M[12][24]=='þ') {win=1; GameOver=true;}
	else if(M[4][24]=='þ' && M[8][16]=='þ' && M[12][8]=='þ') {win=1; GameOver=true;}

	//VINCITA GIOCATORE 2
	if(M[4][8]=='O' && M[4][16]=='O' && M[4][24]=='O') {win=2; GameOver=true;}
	else if(M[8][8]=='O' && M[8][16]=='O' && M[8][24]=='O') {win=2; GameOver=true;}
	else if(M[12][8]=='O' && M[12][16]=='O' && M[12][24]=='O') {win=2; GameOver=true;}
	else if(M[4][8]=='O' && M[8][8]=='O' && M[12][8]=='O') {win=2; GameOver=true;}
	else if(M[4][16]=='O' && M[8][16]=='O' && M[12][16]=='O') {win=2; GameOver=true;}
	else if(M[4][24]=='O' && M[8][24]=='O' && M[12][24]=='O') {win=2; GameOver=true;}
	else if(M[4][8]=='O' && M[8][16]=='O' && M[12][24]=='O') {win=2; GameOver=true;}
	else if(M[4][24]=='O' && M[8][16]=='O' && M[12][8]=='O') {win=2; GameOver=true;}
	
	//PAREGGIO
	if(win==0 && x[8]!=0 && y[8]!=0) {win=3; GameOver=true;}
	
	if(!GameOver){
		do{
			if(coord1>'c' || coord2>3) cout<<"Coordinate ERRATE! Inserire quelle CORRETTE!\n\n";
			if(n%2==0)
			{
				cout<<"þOþOþO Turno di "<<giocatore1<<" OþOþOþ"<<endl;
				cout<<"Inserisci le coordinate: ";
				cin>> coord1 >> coord2;
			}
			else if(n%2!=0)
			{
				cout<<"þOþOþO Turno di "<<giocatore2<<" OþOþOþ"<<endl;
				cout<<"Inserisci le coordinate: ";
				cin>> coord1 >> coord2;
			}
		}while(coord1>'c' || coord2>3);
	
		if(coord1=='a' && coord2==1) {x[b]=4; y[b]=8;}
		else if(coord1=='a' && coord2==2) {x[b]=4; y[b]=16;}
		else if(coord1=='a' && coord2==3) {x[b]=4; y[b]=24;}
		else if(coord1=='b' && coord2==1) {x[b]=8; y[b]=8;}
		else if(coord1=='b' && coord2==2) {x[b]=8; y[b]=16;}
		else if(coord1=='b' && coord2==3) {x[b]=8; y[b]=24;}
		else if(coord1=='c' && coord2==1) {x[b]=12; y[b]=8;}
		else if(coord1=='c' && coord2==2) {x[b]=12; y[b]=16;}
		else if(coord1=='c' && coord2==3) {x[b]=12; y[b]=24;}
	}
}

// OUTRO PER LA VINCITA
void outroV()
{
    system("cls");
    system("color B");
    cout<<"\n\nษอออออออออออออออออออออออออออออออออออ   TRIS   อออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                    \n";
    cout<<"                                Il vincitore e': "<<vincitore<<"                    \n";
    cout<<"                                                                                    \n";
    cout<<"                             Grazie per aver giocato!!                              \n";
    cout<<"                                                                                    \n";
    cout<<"                                    A presto!!                                      \n";
    cout<<"                                                                                    \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    system("pause");
}

// OUTRO PER IL PAREGGIO
void outroP()
{
    system("cls");
    system("color B");
    cout<<"\n\nษอออออออออออออออออออออออออออออออออออ   TRIS   อออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                    \n";
    cout<<"                        Il gioco e' terminato con un pareggio!                      \n";
    cout<<"                                                                                    \n";
    cout<<"                             Grazie per aver giocato!!                              \n";
    cout<<"                                                                                    \n";
    cout<<"                                    A presto!!                                      \n";
    cout<<"                                                                                    \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    system("pause");
}

int main()
{
	intro();
	while(!GameOver)
	{
		draw();
		logic();
		n++; b++;
	}
	if(win==1) {
		for(int i=0; i<strlen(giocatore1); i++) vincitore[i]=giocatore1[i];
		outroV();
		}
	else if(win==2) {
		for(int i=0; i<strlen(giocatore2); i++) vincitore[i]=giocatore2[i];
		outroV();
		}
	else if(win==3) outroP();
	return 0;
}
