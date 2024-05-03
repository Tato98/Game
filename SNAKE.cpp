#include <iostream>
#include <conio.h>
#include <windows.h>

#define  WIDTH 20
#define HEIGHT 20

using namespace std;

bool GameOver, print;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;

void Intro()
{
    system("color B");
    cout<<"\n\nษอออออออออออออออออออออออออออออออออออ   SNAKE   อออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                   \n";
    cout<<"                           Prodotto da: Corrado Raiola                             \n";
    cout<<"                                                                                  \n";
    cout<<"                                 Versione: 1.0                                  \n";
    cout<<"                                                                                   \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    system("pause");
    system("cls");
    cout<<"\n\nษอออออออออออออออออออออออออออออออออออ   SNAKE   อออออออออออออออออออออออออออออออออออป\n";
    cout<<"                                                                                   \n";
    cout<<"                               Regolamento di Gioco:                             \n";
    cout<<"                                                                                  \n";
    cout<<"       Il gioco e' molto semplice. Muovi snake nel campo usando le freccie        \n";
    cout<<"         direzionali e recupera tutti i ฉ per aumentare il tuo punteggio.       \n";
    cout<<"             Stai attento a non sbattere contro le pareti del campo                   \n";
    cout<<"                 da gioco! Se lo farai il gioco terminera'.                         \n";
    cout<<"                                                                                    \n";
    cout<<"           Il tuo obiettivo e' cercare di raccogliere piu' ฉ possibili.                \n";
    cout<<"      Il punteggio sara' stimato in base al numero di ฉ raccolti, e ogni volta        \n";
    cout<<"        che ne raccoglierai uno snake aumentera' la propria lunghezza.                \n";
    cout<<"             Se dovessi morderti la coda il gioco avra' termine!                          \n";
    cout<<"                               Sei pronto a giocare?                                    \n";
    cout<<"                                                                                  \n";
    cout<<"                                BUON DIVERTIMENTO!!!                             \n";
    cout<<"                                                                                   \n";
    cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
    system("pause");
	system("cls");  
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void Setup()
{
	ShowConsoleCursor(false);
    GameOver = false;
    print = false;
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
}

void Draw()
{
	system("color B");
    system("cls");
    for(int i = 0; i < WIDTH+2; i++)
        cout << "ฐ";
    cout << endl;

    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            if(j == 0)
                cout << "ฐ";
            if(i == y && j == x)
                cout << "O"; // print Snake
            else if(i == fruitY && j == fruitX)
                cout << "ฉ"; // print Fruit
            else
            {
                print = false;
                for(int k = 0; k < nTail; k++)
                {
                    if(tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o"; // print Tail
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (j == WIDTH - 1)
                cout << "ฐ";
        }
        cout << endl;
    }
 
    for(int i = 0; i < WIDTH+2; i++)
        cout << "ฐ";
        
    cout << endl;
    cout << "Score:" << score;
}

void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 75:
            dir = LEFT;
            break;
        case 77:
            dir = RIGHT;
            break;
        case 72:
            dir = UP;
            break;
        case 80:
            dir = DOWN;
            break;
        case 'x':
            GameOver = true;
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    //if(x > WIDTH || x < 0 || y > HEIGHT || y < 0)
    //  GameOver = true;
    if(x >= WIDTH) x = 0; else if(x < 0) x = WIDTH - 1;
    if(y >= HEIGHT) y = 0; else if(y < 0) y = HEIGHT - 1;
 
    for(int i = 0; i < nTail; i++)
		if(tailX[i] == x && tailY[i] == y)
            GameOver = true;
 
    if(x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}

void Outro()
{
     system("cls");
     system("color B");
     cout<<"\n\nษอออออออออออออออออออออออออออออออออออ   SNAKE   อออออออออออออออออออออออออออออออออป\n";
     cout<<"                                                                                       \n";
     cout<<"                                Punteggio finale: "<<score<<"                          \n";
     cout<<"                                                                                   \n";
     cout<<"                             Grazie per aver giocato!!                            \n";
     cout<<"                                                                                   \n";
     cout<<"                                    A presto!!                                   \n";
     cout<<"                                                                                   \n";
     cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n";
     system("pause");
}

int main()
{
	Setup();
	Intro();
    while (!GameOver)
    {
        Draw();
        Input();
        Logic();
        // Sleep(10);
    }
    Outro();
    return 0;
}
