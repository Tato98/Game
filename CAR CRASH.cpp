#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
#define R 20
#define C 10
using namespace std;

bool GameOver,Game,flag;
char decisione;
int x,y,score,var,bin1,bin2;
int xN,yN;

void Intro()
{
	system("color B");
    cout<<"\n\nษอออออออออออออออออออออออออออออออออออ CAR CRASH อออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                   \n";
    cout<<"                           Prodotto da: Corrado Raiola                             \n";
    cout<<"                                                                                   \n";
    cout<<"                                 Versione: 1.0                                     \n";
    cout<<"                                                                                   \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    system("pause");
    system("cls");
    cout<<"\n\nษอออออออออออออออออออออออออออออออออออ CAR CRASH อออออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                    \n";
    cout<<"                               Regolamento di Gioco:                                \n";
    cout<<"                                                                                    \n";
    cout<<"       Evita tutte le macchine usando i tasti direzionali freccia sinistra          \n";
    cout<<"                 e freccia destra e ottieni il miglior punteggio!!                  \n";
    cout<<"          Se dovessi scontrarti con una macchina il gioco avra' termine.            \n";
    cout<<"                                                                                    \n";
    cout<<"                                Buon divertimento!!                                 \n";
    cout<<"                                                                                    \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    system("pause");
	system("cls");  
}

void Setup()
{
	GameOver=false;
	Game=false;
	flag=false;
 	x=(C/2)-1,y=R-1;
	yN=0;
	srand((unsigned)time(NULL));
	bin1=rand()%2;
	if(bin1==0) bin1=-2;
	else bin1=1;
	bin2=rand()%2;
	if(bin2==0) bin2=-1;
	else bin2=2;
	var=1+rand()%(C-3);
	if(var==1 || var==4 || var==7)
		xN=var;
	else if(var==3 || var==6)
		xN=var+bin1;
	else xN=var+bin2;
	score=0;
}

void Campo()
{
	system("color B");
	system("cls");
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(j==0) cout<<"บ";
			else if(i==yN && j==xN) cout<<"ฐ";
			else if(i==yN+1 && j==xN+1) cout<<"ฐ";
			else if(i==yN+1 && j==xN) cout<<"ฐ";
			else if(i==yN && j==xN+1) cout<<"ฐ";
			else if(j==3) cout<<"|";
			else if(j==6) cout<<"|";
			else if(i==y && j==x) cout<<"ฑ";
			else if(i==y-1 && j==x+1) cout<<"ฑ";
			else if(i==y && j==x+1) cout<<"ฑ";
			else if(i==y-1 && j==x) cout<<"ฑ";
			else if(j==C-1) cout<<"บ";
			else cout<<" ";
			if(i==0 && j==C-1) cout<<"Score: "<<score;
			if(x==xN && y-1==yN+1) GameOver=true;
		}
		cout<<endl;
	}
}

void Movimento()
{
	char ch;
	if(kbhit())
	{	
		switch(ch=getch())
		{
			case 75: x-=3; break;
			case 77: x+=3; break;
			default: break;
		}
		if(x==-2) x=1;
		if(x==C) x=C-3;
	}	
}

void Nemici()
{
	yN++;
	if(yN==R)
	{
		bin1=rand()%2;
		if(bin1==0) bin1=-2;
		else bin1=1;
		bin2=rand()%2;
		if(bin2==0) bin2=-1;
		else bin2=2;
		var=1+rand()%(C-3);
		if(var==1 || var==4 || var==7)
			xN=var;
		else if(var==3 || var==6)
			xN=var+bin1;
		else xN=var+bin2;
		yN=0;
		score+=10;
	}
}

void Outro()
{
	system("cls");
    system("color B");
    cout<<"\n\nษอออออออออออออออออออออออออออออออออออ CAR CRASH อออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                 \n";
    cout<<"                                Punteggio finale: "<<score<<"                    \n";
    cout<<"                                                                                 \n";
    cout<<"                              Vuoi giocare ancora?(Y/N)                          \n";
    cout<<"                                                                                 \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    decisione=getch();
    while(!flag)
	if(decisione=='n')
    {
		Game=true;
    	system("cls");
    	cout<<"\n\nษอออออออออออออออออออออออออออออออออออ CAR CRASH อออออออออออออออออออออออออออออออออป\n";
    	cout<<"                                                                                 \n";
    	cout<<"                               Grazie per aver giocato!!                         \n";
    	cout<<"                                                                                 \n";
    	cout<<"                                    A presto!!                                   \n";
    	cout<<"                                                                                 \n";
		cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
		system("pause");
		flag=true;
	}
	else if(decisione=='y')
	{
		system("cls");
		flag=true;
	}
	else
	{
		cout<<"Rispondere solo con Y(si) o N(no): ";
		decisione=getch();
		cout<<endl;
	}
	
}

int main()
{
	while(!Game)
	{	
		Setup();
		Intro();
		while(!GameOver)
		{
			Campo();
			Movimento();
			Nemici();
		}
		Outro();
	}
	return 0;
}
