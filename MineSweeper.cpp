#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void CreateBoard(int);
void countaround(int);
void ShowTabLoser(int);
void ShowTab(int);
bool Discover(int, int, int);
void Box_0(int, int, int);
void Update(int);
bool Verify_Earn(int);

int matrix[15][15];
char board[15][15];
char showBoard[15][15];

using namespace std;

int main() 
{

    int size = 0;
    srand(time(NULL));

    cout << "     ------------- MINE SWEEPER -------------" << endl;
    cout << endl;
    cout << "INSTRUCTIONS:" << endl;
    cout << "1. Enter the size of the board, it must be a value between 6 and 15." << endl;
    cout << "Note: The more squares the board has, the harder it is to win!" << endl;
    cout << endl;

    cout << "Enter the size of the board: ";
    cin >> size;
    cout << endl;

    while (size < 6 || size > 15)
    {
        cout << "ERROR! Enter a number between 6 and 15." << endl;
        cout << "Enter the size of the board: ";
        cin >> size;
    }

    CreateBoard(size);
    countaround(size);
    ShowTab(size);
    cout << endl;
    cout << "LET'S START PLAYING!!!" << endl;
    cout << "Enter the coordinate of the matrix you want to select:" << endl;
    int row = 0;
    int column = 0;
    cout << "Enter the row: ";
    cin >> row;
    row = row - 1;
    cout << "Enter the column: ";
    cin >> column;
    column = column - 1;
    cout << endl;

    while (row<0 || row>size - 1 || column<0 || column>size - 1) {
        cout << endl;
        cout << "Error! Coordinates excede board size" << endl;
        cout << "Enter the row: ";
        cin >> row;
        row = row - 1;
        cout << "Enter the column: ";
        cin >> column;
        column = column - 1;
        cout << endl;
    }
    bool dFlag = true;
    bool Gain = false;
    dFlag = Discover(size, row, column);
    while (dFlag == true) {
        cout << endl;
        cout << "Enter the row: ";
        cin >> row;
        row = row - 1;
        cout << "Enter the column: ";
        cin >> column;
        cout << endl;
        column = column - 1;
        dFlag = Discover(size, row, column);
        Gain = Verify_Earn(size);
        if (Gain == true) 
        {
            cout << endl;
            cout << "CONGRATULATIONS!!...YOU WON THE GAME!!" << endl;
            dFlag = false;
        }
    }
    return 0;
}


void CreateBoard(int size)
{
    int rows = 0;
    int columns = 0;
    rows = size;
    columns = size;
    double k;
    k = (12 + rand() % (9));
    double percentage;
    percentage = (size * size) * (k / 100);

    int cantMinas;
    cantMinas = percentage;
    cout << endl;
    cout << "Number of mines on the board: " << cantMinas << endl;
    cout << endl;

    int board;
    board = (size * size);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 7;
        }
    }

    for (int i = 0; i < cantMinas; i++)
    {
        int posCol = rand() % (columns);
        int posFil = rand() % (rows);
        if (matrix[posCol][posFil] == 7)
        {
            matrix[posCol][posFil] = 9;
        }
        else {
            i--;
        }
    }
}

void countaround(int size)
{
    int rows = 0;
    int columns = 0;
    int cont = 0;
    rows = size;
    columns = size;

    //--------------------------------------------count the corners-------------------------------------------------
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if ((i == 0 && j == 0) && (matrix[i][j] != 9)) {
                //count if it is in the upper left corner
                if (matrix[i][j + 1] == 9) {
                    cont++;
                }
                if (matrix[i + 1][j + 1] == 9) {
                    cont++;
                }
                if (matrix[i + 1][j] == 9) {
                    cont++;
                }

                matrix[i][j] = cont;
                cont = 0;
            }
            else if ((i == 0 && j == size - 1) && (matrix[i][j] != 9)) {//count if it is in the upper right corner
                if (matrix[i][j - 1] == 9) {
                    cont++;
                }
                if (matrix[i + 1][j - 1] == 9) {
                    cont++;
                }
                if (matrix[i + 1][j] == 9) {
                    cont++;
                }

                matrix[i][j] = cont;
                cont = 0;
            }
            else if ((i == size - 1 && j == 0) && (matrix[i][j] != 9)) { // count if it is in the lower left corner
                if (matrix[i - 1][j] == 9) {
                    cont++;
                }
                if (matrix[i - 1][j + 1] == 9) {
                    cont++;
                }
                if (matrix[i][j + 1] == 9) {
                    cont++;
                }

                matrix[i][j] = cont;
                cont = 0;
            }
            else if ((i == size - 1 && j == size - 1) && (matrix[i][j] != 9)) { // count if it's in the bottom right corner
                if (matrix[i - 1][j] == 9) {
                    cont++;
                }
                if (matrix[i - 1][j - 1] == 9) {
                    cont++;
                }
                if (matrix[i][j - 1] == 9) {
                    cont++;
                }

                matrix[i][j] = cont;
                cont = 0;
            }
            //Count the edges that are not corners

            else if (i == 0 && (matrix[i][j] != 9)) { //count if it's on top edge
                if (matrix[i][j + 1] == 9) {
                    cont++;
                }
                if (matrix[i + 1][j + 1] == 9) {
                    cont++;
                }
                if (matrix[i + 1][j] == 9) {
                    cont++;
                }
                if (matrix[i][j - 1] == 9) {
                    cont++;
                }
                if (matrix[i + 1][j - 1] == 9) {
                    cont++;
                }
                matrix[i][j] = cont;
                cont = 0;
            }
            else if (i == size - 1 && (matrix[i][j] != 9)) { // count if it is on the bottom edge
                if (matrix[i - 1][j] == 9) {
                    cont++;
                }
                if (matrix[i - 1][j + 1] == 9) {
                    cont++;
                }
                if (matrix[i][j + 1] == 9) {
                    cont++;
                }
                if (matrix[i - 1][j - 1] == 9) {
                    cont++;
                }
                if (matrix[i][j - 1] == 9) {
                    cont++;
                }

                matrix[i][j] = cont;
                cont = 0;
            }

            else if (j == 0 && (matrix[i][j] != 9)) { // count if it is on the left bank
                if (matrix[i - 1][j] == 9) {
                    cont++;
                }
                if (matrix[i - 1][j + 1] == 9) {
                    cont++;
                }
                if (matrix[i][j + 1] == 9) {
                    cont++;
                }
                if (matrix[i + 1][j + 1] == 9) {
                    cont++;
                }
                if (matrix[i + 1][j] == 9) {
                    cont++;
                }

                matrix[i][j] = cont;
                cont = 0;
            }

            else if (j == size - 1 && (matrix[i][j] != 9)) { //count if it is on the right bank
                if (matrix[i - 1][j] == 9) {
                    cont++;
                }
                if (matrix[i - 1][j - 1] == 9) {
                    cont++;
                }
                if (matrix[i][j - 1] == 9) {
                    cont++;
                }
                if (matrix[i + 1][j - 1] == 9) {
                    cont++;
                }
                if (matrix[i + 1][j] == 9) {
                    cont++;
                }

                matrix[i][j] = cont;
                cont = 0;
            }
            else {
                // count if they are the squares in the center
                if (matrix[i][j] != 9) {
                    if (matrix[i - 1][j] == 9) {
                        cont++;
                    }
                    if (matrix[i - 1][j - 1] == 9) {
                        cont++;
                    }
                    if (matrix[i][j - 1] == 9) {
                        cont++;
                    }
                    if (matrix[i + 1][j - 1] == 9) {
                        cont++;
                    }
                    if (matrix[i + 1][j] == 9) {
                        cont++;
                    }
                    if (matrix[i - 1][j + 1] == 9) {
                        cont++;
                    }
                    if (matrix[i][j + 1] == 9) {
                        cont++;
                    }
                    if (matrix[i + 1][j + 1] == 9) {
                        cont++;
                    }
                    matrix[i][j] = cont;
                    cont = 0;
                }
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] == 9) 
            {
                matrix[i][j] = '*';
            }
            else 
            {
                matrix[i][j] = char(matrix[i][j] + 48);
            }
        }
    }
}

void ShowTabLoser(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << char(matrix[i][j]) << " ";
        }
        cout << endl;
    }
    return;
}

void ShowTab(int size) {
    int rows = size;
    int columns = size;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            showBoard[i][j] = '#';
            cout << showBoard[i][j] << " ";
        }
        cout << endl;
    }


}

bool Discover(int size, int row, int column)
{
    int rows = size;
    int columns = size;

    while (row<0 || row>size - 1 || column<0 || column>size - 1) {
        cout << "ERROR! coordinate out of board" << endl;
        cout << "Enter Row: ";
        cin >> row;
        row = row - 1;
        cout << "Enter Column: ";
        cin >> column;
        column = column - 1;
        cout << endl;
    }

    if (matrix[row][column] == '0') {
        Box_0(size, row, column);
        Update(size);
        return true;
    }
    else if (matrix[row][column] != '*') {
        showBoard[row][column] = matrix[row][column];
        Update(size);
        return true;
    }
    else if (matrix[row][column] == '*')
    {
        cout << "YOU HAVE SELECTED A MINE...YOU LOST THE GAME!!" << endl;
        cout << endl;
        ShowTabLoser(size);
        return false;
    }
    
    return NULL;

}

void Update(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << showBoard[i][j] << " ";
        }
        cout << endl;
    }
}

void Box_0(int size, int row, int column)
{
    showBoard[row][column] = matrix[row][column];
    //----------------------------------------------------count the corners---------------------------------------------------------------------
    if (row == 0 && column == 0) 
    {// count if it is in the upper left corner
        showBoard[row][column + 1] = matrix[row][column + 1];
        showBoard[row + 1][column + 1] = matrix[row + 1][column + 1];
        showBoard[row + 1][column] = matrix[row + 1][column];

    }

    else if (row == 0 && column == size - 1) { // count if it is in the upper right corner
        showBoard[row][column - 1] = matrix[row][column - 1];
        showBoard[row + 1][column - 1] = matrix[row + 1][column - 1];
        showBoard[row + 1][column] = matrix[row + 1][column];
    }

    else if (row == size - 1 && column == 0) { // count if it is in the lower left corner
        showBoard[row - 1][column] = matrix[row - 1][column];
        showBoard[row - 1][column + 1] = matrix[row - 1][column + 1];
        showBoard[row][column + 1] = matrix[row][column + 1];
    }

    else if (row == size - 1 && column == size - 1) { // count if it's in the bottom right corner
        showBoard[row - 1][column] = matrix[row - 1][column];
        showBoard[row - 1][column - 1] = matrix[row - 1][column - 1];
        showBoard[row][column - 1] = matrix[row][column - 1];
    }

    //----------------------------------------------------//Count the edges that are not corners---------------------------------------------------------------------
    else if (row == 0) { //count if it's on top edge
        showBoard[row][column + 1] = matrix[row][column + 1];
        showBoard[row + 1][column + 1] = matrix[row + 1][column + 1];
        showBoard[row + 1][column] = matrix[row + 1][column];
        showBoard[row][column - 1] = matrix[row][column - 1];
        showBoard[row + 1][column - 1] = matrix[row + 1][column - 1];
    }

    else if (row == size - 1) { // count if it is on the bottom edge
        showBoard[row - 1][column] = matrix[row - 1][column];
        showBoard[row - 1][column + 1] = matrix[row - 1][column + 1];
        showBoard[row][column + 1] = matrix[row][column + 1];
        showBoard[row - 1][column - 1] = matrix[row - 1][column - 1];
        showBoard[row][column - 1] = matrix[row][column - 1];
    }

    else if (column == 0) { // count if it is on the left bank
        showBoard[row - 1][column] = matrix[row - 1][column];
        showBoard[row - 1][column + 1] = matrix[row - 1][column + 1];
        showBoard[row][column + 1] = matrix[row][column + 1];
        showBoard[row + 1][column + 1] = matrix[row + 1][column + 1];
        showBoard[row + 1][column] = matrix[row + 1][column];
    }

    else if (column == size - 1) { // count if it is on the right bank
        showBoard[row - 1][column] = matrix[row - 1][column];
        showBoard[row - 1][column - 1] = matrix[row - 1][column - 1];
        showBoard[row][column - 1] = matrix[row][column - 1];
        showBoard[row + 1][column - 1] = matrix[row + 1][column - 1];
        showBoard[row + 1][column] = matrix[row + 1][column];
    }

    else {/// count if they are the squares in the center
        showBoard[row - 1][column] = matrix[row - 1][column];
        showBoard[row - 1][column - 1] = matrix[row - 1][column - 1];
        showBoard[row][column - 1] = matrix[row][column - 1];
        showBoard[row + 1][column - 1] = matrix[row + 1][column - 1];
        showBoard[row + 1][column] = matrix[row + 1][column];
        showBoard[row - 1][column + 1] = matrix[row - 1][column + 1];
        showBoard[row][column + 1] = matrix[row][column + 1];
        showBoard[row + 1][column + 1] = matrix[row + 1][column + 1];
    }

}
bool Verify_Earn(int size)
{
    int cont = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            if ((showBoard[i][j] == '#') && (matrix[i][j] != '*'))
            {
                cont++;
            }
        }
    }
    if (cont == 0) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}
