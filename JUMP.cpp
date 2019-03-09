#include<iostream>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define L 50
#define N 6
#define N2 6
#define DA 25
#define A 21
using namespace std;

bool GameOver,flag;
char jump;
int x,y,score,distanza,bin,timejump;
int xW[N],yW[N];
int xW2[N2],yW2[N2];

void Setup()
{
	x=5;
	y=1;
	xW[0]=L-1;
	yW[0]=1;
	score=0;
	srand(time(NULL));
	distanza=DA+rand()%A;
	bin=rand()%2;
	timejump=0;
	GameOver=false;
	flag=false;
}

void Intro()
{
	system("color A");
    cout<<"\n\nษออออออออออออออออออออออออออออออออออออ   JUMP   อออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                   \n";
    cout<<"                           Prodotto da: Corrado Raiola                             \n";
    cout<<"                                                                                   \n";
    cout<<"                                 Versione: 1.0                                     \n";
    cout<<"                                                                                   \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    system("pause");
    system("cls");
    cout<<"\n\nษออออออออออออออออออออออออออออออออออออ   JUMP   อออออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                    \n";
    cout<<"                               Regolamento di Gioco:                                \n";
    cout<<"                                                                                    \n";
    cout<<"          Salta il maggior numero di pareti utilizzando la frccia <sopra>           \n";
    cout<<"                         e ottieni il miglior punteggio!!                           \n";
    cout<<"           Se dovessi scontrarti con una di esse il gioco avra' termine.            \n";
    cout<<"                                                                                    \n";
    cout<<"                                Buon divertimento!!                                 \n";
    cout<<"                                                                                    \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    system("pause");
	system("cls");  
}

void Draw()
{
	system("cls");
	cout<<"Score: "<<score;
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	cout<<"\n\n\n\n\n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<L;j++)
		{
			if(i==y && j==x) cout<<"Ü";
			for(int k=0;k<N;k++)
			{
				if(i==yW[k] && j==xW[k])
				{
					cout<<"ฑ";
					xW[k]--;
				}
			}
			if(i!=2) cout<<" ";
			else cout<<"ฐ";
		}
		cout<<endl;
	}
}

void Logic()
{
	
	if (timejump==5)
	{
		y=1;
		timejump=0;
		flag=false;
	}
	if(kbhit())
	{
		jump=getch();
		if(jump==72)
		{
			y--;
			flag=true;
		}
	}
	if(y<0) y=0;
	if(flag) timejump++;
	for(int i=1;i<N;i++)
	{
		if(x==xW[i] && y==yW[i]) GameOver=true;
	}
	score++;
}

void Wall()
{
	if(xW[0]==distanza)
	{
		distanza=DA+rand()%A;
		for(int i=N;i>0;i--)
		{
			xW[i]=xW[i-1];
			yW[i]=yW[i-1];
		}
		xW[0]=L-1;
	}
}

void Outro()
{
	system("cls");
    system("color A");
    cout<<"\n\nษออออออออออออออออออออออออออออออออออออ   JUMP   อออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                  \n";
    cout<<"                                Punteggio finale: "<<score<<"                     \n";
    cout<<"                                                                                  \n";
    cout<<"                             Grazie per aver giocato!!                            \n";
    cout<<"                                                                                  \n";
    cout<<"                                    A presto!!                                    \n";
    cout<<"                                                                                  \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    system("pause");
}

int main()
{
	Intro();
	Setup();
	while(!GameOver)
	{
		Draw();
		Logic();
		Wall();
		Sleep(20);
	}
	Outro();
	return 0;
}
