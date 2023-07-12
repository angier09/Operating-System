#include<iostream>
#include<unistd.h>

using namespace std;
char map[32][28];

int score = 0;
int lives = 20;
void displaypacman(int& i, int& j)
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            map[i][j] = '.';
        }
    }
    for (int i = 6; i < 26; i++)
    {
        map[i][4] = '|';
    }
    for (int i = 6; i < 26; i++)
    {
        map[i][24] = '|';
    }
    for (int j = 4; j < 25; j++)
    {
        map[3][j] = '_';
    }
    for (int j = 4; j < 25; j++)
    {
        map[28][j] = '_';
    }
    for (int i = 10; i < 16; i++)
    {
        map[i][8] = '|';
    }
    for (int j = 8; j < 18; j++)
    {
        map[16][j] = '_';
    }
    for (int j = 8; j < 18; j++)
    {
        map[20][j] = '_';
    }
    for (int i = 20; i < 26; i++)
    {
        map[i][18] = '|';
    }
    map[1][2] = 'P';
    map[7][9] = ',';
    map[12][15] = ',';
    map[19][23] = ',';
    map[8][18] = ',';
    cout << " ________________________________________________________" << endl;
    for (int i = 0; i < 32; i++)
    {
        // print the first character as part of the opener.
        cout << " " << "|" << map[i][0];
        for (int j = 1; j < 28; j++)
        {
            // only add spaces for subsequent characters.
            cout << " " << map[i][j];
        }
        cout << "|" << endl;
    }
    cout << " ________________________________________________________" << endl;
    cout << "SCORE = " << score << endl;

}
void updisplaypacman(int& i, int& j)
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            map[i][j] = '.';
        }
    }
    for (int i = 6; i < 26; i++)
    {
        map[i][4] = '|';
    }
    for (int i = 6; i < 26; i++)
    {
        map[i][24] = '|';
    }
    for (int j = 4; j < 25; j++)
    {
        map[3][j] = '_';
    }
    for (int j = 4; j < 25; j++)
    {
        map[28][j] = '_';
    }
    for (int i = 10; i < 16; i++)
    {
        map[i][8] = '|';
    }
    for (int j = 8; j < 18; j++)
    {
        map[16][j] = '_';
    }
    for (int j = 8; j < 18; j++)
    {
        map[20][j] = '_';
    }
    for (int i = 20; i < 26; i++)
    {
        map[i][18] = '|';
    }

    map[7][9] = ',';
    map[12][15] = ',';
    map[19][20] = ',';
    map[8][18] = ',';
    map[i][j] = 'P';
    cout << " ________________________________________________________" << endl;
    for (int i = 0; i < 32; i++)
    {
        // print the first character as part of the opener.
        cout << " " << "|" << map[i][0];
        for (int j = 1; j < 28; j++)
        {
            // only add spaces for subsequent characters.
            cout << " " << map[i][j];   
        }
        cout << "|" << endl;
    }
    cout << " ________________________________________________________" << endl;
    cout << "SCORE = " << score << "                 LIVES = " << lives << endl;
    cout << " ________________________________________________________" << endl;
}
void movepacman(int& i, int& j, char& b)
{
    while (b != 'e')
    {
        lives = lives - 1;
        updisplaypacman(i, j);
        if (score >= 90)
        {
            cout << "\n         ----WINNER--- \n            SCORE = "<<score << endl;
            exit(0);
        }
        if (lives == 0 )
        {
            if (score < 90)
            {
                cout << "\n         ----YOU LOST!!--- \n            SCORE = " << score << endl;
            }
            exit(0);
        }
         cin >> b;
        
        if (b == 87 || b == 119) //W->top
        {
            if (map[i - 1][j] != '_' && map[i - 1][j] != '|')
            {
                if (map[i - 1][j] == ' ' || map[i - 2][j] == '.')
                {
                  if (map[i - 2][j] == ',')
                  {
                     score = score + 10;
                  }
                    score = score + 5;

                    map[i - 2][j] = 'P';
                    map[i][j] = ' ';
                    i--;
                }
            }
        }
        if (b == 83 || b==115) //S->down 
        {
            if (map[i + 1][j] != '_' && map[i + 1][j] != '|')
            {
                if (map[i + 1][j] == ' ' || map[i + 2][j] == '.')
                {
                    if (map[i + 2][j] == ',')
                    {
                        score = score + 10;
                    }
                    score = score + 5;

                    map[i + 2][j] = 'P';
                    map[i][j] = ' ';
                    i++;
                }
            }
        }
        if (b == 65 || b == 97) //A->left
        {
            if (map[i][j - 1] != '_' && map[i][j - 1] != '|')
            {
                if (map[i][j - 1] == ' ' || map[i][j - 2] == '.')
                {
                    if (map[i][j-1] == ',')
                    {
                        score = score + 10;
                    }
                    score = score + 5;
                    map[i][j - 2] = 'P';
                    map[i][j] = ' ';
                    j--;
                }
            }
        }
        if (b == 68 || b == 100) //D->right
        {
            if (map[i][j + 1] != '_' && map[i][j + 1] != '|')
            {
                if (map[i][j + 1] == ' ' || map[i][j + 2] == '.')
                {
                    if (map[i][j+1] == ',')
                    {
                        score = score + 10;
                    }
                    score = score + 5;
                    map[i][j + 2] = 'P';
                    map[i][j] = ' ';
                    j++;
                }
            }
        }
    }
}
//GAME PACMAN
void pacman()
{
    int i = 5;
    int j = 5;
    char b;
    int a;
    cout << "PRESS 1 TO PLAY GAME" << endl;
    cout << "CONTROLS FOR MOVEMENT" << endl;
    cout << "A -> Left" << endl;
    cout << "D -> Right" << endl;
    cout << "W -> Up" << endl;
    cout << "S -> Down" << endl;


    cout << "PRESS 2 TO READ INSTRUCTIONS" << endl;
    cin >> a;
    if (a == 1)
    {
        cout << "PACMAN GAME" << endl;

        cout << "PLEASE WAIT WHILE GAME IS LOADING.....";
        for (int i = 0; i < 35; i++)
        {
            cout << '|';
        }
        cout << endl;

        movepacman(i, j, b);
    }
    else if (a == 2)
    {
        cout << "Guide Pacman around the maze and eat all the little white dots to get score = 5." << endl;
        cout << "If you eat a Power Pill, you can get score = 10! Occasionally, a fruit appears which gives you a bonus score when eaten.";
    }
}

int main()
{

    pacman();

    std::cin.get();
    std::cin.get();
    return 0;
}