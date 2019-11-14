#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

    char m [6][7];
    int isFull, winner=0;

#define PrintScreen \
    system ("CLS");\
    cout << "1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";\
    cout <<m[0][0] << " | " << m[0][1] << " | " << m[0][2] << " | " << m[0][3] << " | " << m[0][4] << " | " << m[0][5] << " | " << m[0][6] << " | " << endl;\
    cout <<m[1][0] << " | " << m[1][1] << " | " << m[1][2] << " | " << m[1][3] << " | " << m[1][4] << " | " << m[1][5] << " | " << m[1][6] << " | " << endl;\
    cout <<m[2][0] << " | " << m[2][1] << " | " << m[2][2] << " | " << m[2][3] << " | " << m[2][4] << " | " << m[2][5] << " | " << m[2][6] << " | " << endl;\
    cout <<m[3][0] << " | " << m[3][1] << " | " << m[3][2] << " | " << m[3][3] << " | " << m[3][4] << " | " << m[3][5] << " | " << m[3][6] << " | " << endl;\
    cout <<m[4][0] << " | " << m[4][1] << " | " << m[4][2] << " | " << m[4][3] << " | " << m[4][4] << " | " << m[4][5] << " | " << m[4][6] << " | " << endl;\
    cout <<m[5][0] << " | " << m[5][1] << " | " << m[5][2] << " | " << m[5][3] << " | " << m[5][4] << " | " << m[5][5] << " | " << m[5][6] << " | " << endl;


void Game(int turnb, int playerb)
{
    turnb=turnb-1;
    int i;
    char save;

    //aiming at the top of the stack + checking if the row is full
    for (i=5;i>=-1;i--)
    {
        if (i==-1)
        {
            cout << "Row is full, try again.\n";
            isFull = 1;
            return;
        }
        else if (m[i][turnb]==0)
        {
            break;
        }
    }
    //placing the x or o
        if (playerb==1)
        m[i][turnb]='x';
        if (playerb==2)
        m[i][turnb]='o';

    //Checking if the game ended
            save = m[i][turnb];
            if (save==m[i+1][turnb] && save==m[i+2][turnb] && save==m[i+3][turnb] || //checking under
                save==m[i][turnb+1] && save==m[i][turnb+2] && save==m[i][turnb+3] || //checking right 1xxx
                save==m[i][turnb-1] && save==m[i][turnb-2] && save==m[i][turnb-3] || //checking left xxx1
                save==m[i][turnb-1] && save==m[i][turnb-2] && save==m[i][turnb+1] || //xx1x
                save==m[i][turnb+1] && save==m[i][turnb+2] && save==m[i][turnb-1] )  //x1xx
            {
                winner = playerb;
            }

    //Checking if the game is draw
            if (m[0][0]!=0 && m[0][1]!=0 && m[0][2]!=0 && m[0][3]!=0 && m[0][4]!=0 && m[0][5]!=0 && m[0][6]!=0)
                winner = 3;
}

int main()
{
    int turn, player;
    memset(m,0,sizeof(m));
    PrintScreen;
    cout << "Connect4 Game starts!\n";
    for (player = 1;winner==0;player=!player)
    {
        if (player==0)
            player = 2;
    invalid:
    cout << "Player " << player << ": ";
    cin >> turn;
    if (turn<0 || turn>7)
    {
        cout << "Invalid place, try again.\n";
        goto invalid;
    }
    isFull=0;
    Game(turn, player);
    if (isFull==1)
        goto invalid;
    PrintScreen;
        if (player==2)
            player=0;
    }
    if (winner!=3)
        cout << "Player " << winner << " is the Winner!";
    else
        cout << "The game is draw!";
}
