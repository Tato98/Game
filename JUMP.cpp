#include<iostream>
#include<time.h>
#include<conio.h>
#include<windows.h>

#define  LENGTH  50 // field length
#define N_WALLS  7  // number of walls
#define       A  25 // first parameter of the random number range
#define       B  21 // second parameter of the random number range

using namespace std;

bool GameOver, flag;
int xW[N_WALLS], y, score, dist, timejump;
int const x = 5, yW = 1; // these variables are const because they represent respectively the x coord of the main character and the y coord of all the walls that do not change

void Setup()
{
	y = 1;
	xW[0] = LENGTH-1;
	score = 0;
	srand(time(NULL));
	// In general the instruction "rand() % N" returns a random (integer positive) number in the range [0, N-1]
	dist = A + rand() % B; // the instruction "A + rand() % B" returns a random integer number in the range [A, A+B-1]
	timejump = 0;
	GameOver = false;
	flag = false;
}

void Intro()
{
	system("color A");
    cout<<"\n\nษออออออออออออออออออออออออออออออออออออ   JUMP   อออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                   \n";
    cout<<"                           Prodotto da: Corrado Raiola                             \n";
    cout<<"                                                                                   \n";
    cout<<"                                 Versione: 1.1                                     \n";
    cout<<"                                                                                   \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    system("pause");
    system("cls");
    cout<<"\n\nษออออออออออออออออออออออออออออออออออออ   JUMP   อออออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                    \n";
    cout<<"                               Regolamento di Gioco:                                \n";
    cout<<"                                                                                    \n";
    cout<<"          Salta il maggior numero di pareti utilizzando la barra spaziatrice        \n";
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
	cout << "Score: " << score;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<LENGTH; j++)
		{
			if(i==y && j==x) cout << "Ü"; // print the main character
			for(int k=0; k<N_WALLS; k++)
			{
				if(i==yW && j==xW[k])
				{
					cout << "ฑ"; // print the wall
					xW[k]--;
				}
			}
			if(i<2) cout << " "; // print the sky
			else cout << "ฐ";  // print the ground
		}
		cout << endl;
	}
}

void Logic()
{
	if(timejump == 5) // after 5 cycle the main character comes back to the ground
	{
		y = 1; // set the y coord to 1 which means that the character comes back to the ground after the jump
		timejump = 0;
		flag = false;
	}
	if(kbhit())
	{
		if(getch() == 32) // 32 corresponds to the spacebar key
		{
			y = 0; // set the y coord to 0 which means that the character is jumping
			flag = true; // after the jump the flag is high so that "timejump" can be incremented
		}
	}
	if(flag) timejump++;
	for(int i=0; i<N_WALLS; i++) // This for cycle implement the logic of Game Over after touching a wall
	{
		if(x==xW[i] && y==yW) GameOver = true;
	}
	score++;
}

void Wall()
{
	if(xW[0] == dist) // every time the first wall x coord is equal to "dist" the entries of "xW[N_WALLS]" shift rightward
	{
		dist = A + rand() % B; // the value of dist is updated so that the distance between two walls is always random
		for(int i=N_WALLS-1; i>0; i--) // shifts the entries of "xW[N_WALLS]"
		{
			xW[i] = xW[i-1];
		}
		xW[0] = LENGTH-1; // the first element is set to "LENGTH-1" so that a new wall can be generated
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
		//Sleep(20);
	}
	Outro();
	return 0;
}
