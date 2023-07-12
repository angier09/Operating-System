#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
//to fill 2D array
void grid(string myArray[][9], int size);
//to print grid
void display(string myArray[][9], int size);

//input rows and cols
void inputFun(string myArray[][9], int size);

//swipe candies
void swapFun(string myArray[][9], int size, int& r, int& c, int& nR, int& nC);

//score combination
void gameScore(string myArray[][9], int size, int& r, int& c);

//moving candies down after crusing 
void displaceCandy(string myArray[][9], int size);

//filling empty spaces after crusing
void fillRandcandy(string myArray[][9], int size);

//5 candies bomb-combination
void bombCombination(string myArray[][9], int size, int& r, int& c);

//L or T candy combination
void wrapCandy(string myArray[][9], int size, int& r, int& c);

//4 candies strip-combination
void stripCandy(string myArray[][9], int size, int& r, int& c);

//clear whole row
void rowStripcandy(string myArray[][9], int size, int& r, int& c);

void columnStripcandy(string myArray[][9], int size, int& r, int& c);

//check combinations of three candies
void threeCombo(string myArray[][9], int size, int& r, int& c);

//Checking Win or lost
void winGame(int& score, int targetScore);

//to add delay
void delay(int a);

//global variables
int r = 0, c = 0, nR = 0, nC = 0;
string temp;
static int moves = 0, score = 0, targetScore = 100;
int main()
{
	moves = 15;
	string myArray[9][9];
	char arr2[5] = { 'R','G','B','Y','O' };

	//to fill array
	grid(myArray, 9);

	//display grid
	display(myArray, 9);

	//initially checking for combinations
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			bombCombination(myArray, 9, i, j);
			stripCandy(myArray, 9, i, j);
			threeCombo(myArray, 9, i, j);

		}
		score = 0;
	}

	display(myArray, 9);


	//input rows & col
	inputFun(myArray, 9);

	cout << endl;
	system("PAUSE");
	return 0;
}

//to fill the 2D array
void grid(string myArray[][9], int size)
{
	char candy = 0;
	srand(time(0));
	char arr2[5] = { 'R','G','B','Y','O' };
	int x = 0;
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			x = (rand() % 5);
			candy = arr2[x];
			myArray[row][col] = { ' ',' ',candy,' ',' ' };
		}

	}
}

//to display 2D array 
void display(string myArray[][9], int size)
{
	cout << "			*******************************" << endl;
	delay(4);
	cout << "				  CANDY CRUSH" << endl;
	delay(4);
	cout << "			*******************************" << endl;
	delay(4);
	cout << " 	  MOVES : " << moves << "		   YOUR SCORE : " << score << "		    Target SCORE : " << targetScore << endl;
	cout << endl;
	cout << "	    _________________________________________________________________________" << endl;
	cout << "	 ___|___0___|___1___|___2___|___3___|___4___|___5___|___6___|___7___|___8___|" << endl;
	cout << "	|_0_| " << myArray[0][0] << "   " << myArray[0][1] << "   " << myArray[0][2] << "   " << myArray[0][3] << "   " << myArray[0][4] << "   " << myArray[0][5] << "   " << myArray[0][6] << "   " << myArray[0][7] << "   " << myArray[0][8] << endl;
	cout << "	|_1_| " << myArray[1][0] << "   " << myArray[1][1] << "   " << myArray[1][2] << "   " << myArray[1][3] << "   " << myArray[1][4] << "   " << myArray[1][5] << "   " << myArray[1][6] << "   " << myArray[1][7] << "   " << myArray[1][8] << endl;
	cout << "	|_2_| " << myArray[2][0] << "   " << myArray[2][1] << "   " << myArray[2][2] << "   " << myArray[2][3] << "   " << myArray[2][4] << "   " << myArray[2][5] << "   " << myArray[2][6] << "   " << myArray[2][7] << "   " << myArray[2][8] << endl;
	cout << "	|_3_| " << myArray[3][0] << "   " << myArray[3][1] << "   " << myArray[3][2] << "   " << myArray[3][3] << "   " << myArray[3][4] << "   " << myArray[3][5] << "   " << myArray[3][6] << "   " << myArray[3][7] << "   " << myArray[3][8] << endl;
	cout << "	|_4_| " << myArray[4][0] << "   " << myArray[4][1] << "   " << myArray[4][2] << "   " << myArray[4][3] << "   " << myArray[4][4] << "   " << myArray[4][5] << "   " << myArray[4][6] << "   " << myArray[4][7] << "   " << myArray[4][8] << endl;
	cout << "	|_5_| " << myArray[5][0] << "   " << myArray[5][1] << "   " << myArray[5][2] << "   " << myArray[5][3] << "   " << myArray[5][4] << "   " << myArray[5][5] << "   " << myArray[5][6] << "   " << myArray[5][7] << "   " << myArray[5][8] << endl;
	cout << "	|_6_| " << myArray[6][0] << "   " << myArray[6][1] << "   " << myArray[6][2] << "   " << myArray[6][3] << "   " << myArray[6][4] << "   " << myArray[6][5] << "   " << myArray[6][6] << "   " << myArray[6][7] << "   " << myArray[6][8] << endl;
	cout << "	|_7_| " << myArray[7][0] << "   " << myArray[7][1] << "   " << myArray[7][2] << "   " << myArray[7][3] << "   " << myArray[7][4] << "   " << myArray[7][5] << "   " << myArray[7][6] << "   " << myArray[7][7] << "   " << myArray[7][8] << endl;
	cout << "	|_8_| " << myArray[8][0] << "   " << myArray[8][1] << "   " << myArray[8][2] << "   " << myArray[8][3] << "   " << myArray[8][4] << "   " << myArray[8][5] << "   " << myArray[8][6] << "   " << myArray[8][7] << "   " << myArray[8][8] << endl;
	cout << endl;

}

//basic input function
void inputFun(string myArray[][9], int size)
{

	bool flag = true;
	string temp;
	int r = 0, c = 0;
	int nR = 0, nC = 0;
	cout << endl;

	while (moves > 0)
	{
		moves = moves - 1;

		cout << "	Enter Current Row = ";
		cin >> r;
		cout << "	Enter Current Column= ";
		cin >> c;
		cout << endl;
		cout << "	Enter New Row= ";
		cin >> nR;
		cout << "	Enter New Column= ";
		cin >> nC;


		while (flag == true)
		{
			if (r > 9 || c > 9 || nR > 9 || nC > 9)
			{
				cout << endl << "Invalid Input!! Enter Again" << endl;
				cout << "	Enter Current Row = ";
				cin >> r;
				cout << "	Enter Current Column= ";
				cin >> c;
				cout << endl;
				cout << "	Enter New Row= ";
				cin >> nR;
				cout << "	Enter New Column= ";
				cin >> nC;
				flag = true;
			}
			else
			{
				flag = false;
			}
		}

		swapFun(myArray, 9, r, c, nR, nC);
		bombCombination(myArray, 9, r, c);
		wrapCandy(myArray, 9, r, c);
		stripCandy(myArray, 9, r, c);
		rowStripcandy(myArray, 9, r, c);
		columnStripcandy(myArray, 9, r, c);
		threeCombo(myArray, 9, r, c);
		display(myArray, 9);
		cout << endl;

	}
	winGame(score, targetScore);
}

//swap two candies
void swapFun(string myArray[][9], int size, int& r, int& c, int& nR, int& nC)
{
	temp = myArray[r][c];
	myArray[r][c] = myArray[nR][nC];
	myArray[nR][nC] = temp;
	cout << endl;
}

//increase score when candy crused  
void gameScore(string myArray[][9], int size, int& r, int& c)
{
	if (myArray[r][c].at(2) == 'R' || myArray[r][c].at(2) == 'Y')
	{
		score = score + 30;
	}
	else if (myArray[r][c].at(2) == 'G')
	{
		score = score + 40;
	}
	else if (myArray[r][c].at(2) == 'B')
	{
		score = score + 50;
	}
	else if (myArray[r][c].at(2) == 'O')
	{
		score = score + 60;
	}
}

//check 5 similar candies
void bombCombination(string myArray[][9], int size, int& r, int& c)
{
	bool bombFlag = false;
	//checking for row combinations

	if (r >= 0 && r <= 4)
	{
		if (myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2) && myArray[r][c].at(2) == myArray[r + 3][c].at(2) && myArray[r][c].at(2) == myArray[r + 4][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = '!';
			myArray[r + 1][c].at(2) = ' ';
			myArray[r + 2][c].at(2) = ' ';
			myArray[r + 3][c].at(2) = ' ';
			myArray[r + 4][c].at(2) = ' ';
			bombFlag = true;
		}
	}

	if (r >= 1 && r <= 5)
	{
		if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2) && myArray[r][c].at(2) == myArray[r + 3][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = '!';
			myArray[r - 1][c].at(2) = ' ';
			myArray[r + 1][c].at(2) = ' ';
			myArray[r + 2][c].at(2) = ' ';
			myArray[r + 3][c].at(2) = ' ';
			bombFlag = true;
		}
	}

	if (r >= 2 && r <= 6)
	{
		if (myArray[r][c].at(2) == myArray[r - 2][c].at(2) && myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = '!';
			myArray[r - 2][c].at(2) = ' ';
			myArray[r - 1][c].at(2) = ' ';
			myArray[r + 1][c].at(2) = ' ';
			myArray[r + 2][c].at(2) = ' ';
			bombFlag = true;
		}
	}

	if (r >= 3 && r <= 7)
	{
		if (myArray[r][c].at(2) == myArray[r - 3][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2) && myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = '!';
			myArray[r - 3][c].at(2) = ' ';
			myArray[r - 2][c].at(2) = ' ';
			myArray[r - 1][c].at(2) = ' ';
			myArray[r + 1][c].at(2) = ' ';
			bombFlag = true;
		}
	}

	if (r >= 4 && r <= 8)
	{
		if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2) && myArray[r][c].at(2) == myArray[r - 3][c].at(2) && myArray[r][c].at(2) == myArray[r - 4][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = '!';
			myArray[r - 1][c].at(2) = ' ';
			myArray[r - 2][c].at(2) = ' ';
			myArray[r - 3][c].at(2) = ' ';
			myArray[r - 4][c].at(2) = ' ';
			bombFlag = true;
		}
	}

	//checking for column combinations
	if (c >= 0 && c <= 4)
	{
		if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2) && myArray[r][c].at(2) == myArray[r][c + 3].at(2) && myArray[r][c].at(2) == myArray[r][c + 4].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = '!';
			myArray[r][c + 1].at(2) = ' ';
			myArray[r][c + 2].at(2) = ' ';
			myArray[r][c + 3].at(2) = ' ';
			myArray[r][c + 4].at(2) = ' ';
			bombFlag = true;
		}
	}

	if (c >= 1 && c <= 5)
	{
		if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2) && myArray[r][c].at(2) == myArray[r][c + 3].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = '!';
			myArray[r][c - 1].at(2) = ' ';
			myArray[r][c + 1].at(2) = ' ';
			myArray[r][c + 2].at(2) = ' ';
			myArray[r][c + 3].at(2) = ' ';
			bombFlag = true;
		}
	}

	if (c >= 2 && c <= 6)
	{
		if (myArray[r][c].at(2) == myArray[r][c - 2].at(2) && myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = '!';
			myArray[r][c - 2].at(2) = ' ';
			myArray[r][c - 1].at(2) = ' ';
			myArray[r][c + 2].at(2) = ' ';
			myArray[r][c + 1].at(2) = ' ';
			bombFlag = true;
		}
	}
	if (c >= 3 && c <= 7)
	{
		if (myArray[r][c].at(2) == myArray[r][c - 3].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2) && myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = '!';
			myArray[r][c - 3].at(2) = ' ';
			myArray[r][c - 2].at(2) = ' ';
			myArray[r][c - 1].at(2) = ' ';
			myArray[r][c + 1].at(2) = ' ';
			bombFlag = true;
		}
	}
	if (c >= 4 && c <= 8)
	{
		if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2) && myArray[r][c].at(2) == myArray[r][c - 3].at(2) && myArray[r][c].at(2) == myArray[r][c - 4].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = '!';
			myArray[r][c - 1].at(2) = ' ';
			myArray[r][c - 2].at(2) = ' ';
			myArray[r][c - 3].at(2) = ' ';
			myArray[r][c - 4].at(2) = ' ';
			bombFlag = true;
		}
	}

	if (bombFlag == true)
	{
		delay(1);
		displaceCandy(myArray, 9);
		delay(1);
		fillRandcandy(myArray, 9);
	}
}

//check similar candies in L & T
void wrapCandy(string myArray[][9], int size, int& r, int& c)
{
	bool wrapFlag = false;
	// L conditions
	// upward left L
	if ((r <= 6 && r >= 0) && (c <= 6 && c >= 0))
	{
		if (myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2))
		{
			if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2))
			{
				gameScore(myArray, 9, r, c);
				myArray[r][c].at(1) = '@';
				myArray[r][c].at(2) = myArray[r][c].at(2);
				myArray[r + 1][c].at(2) = ' ';
				myArray[r + 2][c].at(2) = ' ';
				myArray[r][c + 1].at(2) = ' ';
				myArray[r][c + 2].at(2) = ' ';
				wrapFlag = true;
			}
		}
		if (c >= 2)
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2))
			{
				if (myArray[r][c - 2].at(2) == myArray[r + 1][c].at(2) && myArray[r][c - 2].at(2) == myArray[r + 2][c].at(2))
				{
					gameScore(myArray, 9, r, c);
					myArray[r][c].at(1) = '@';
					myArray[r][c].at(2) = myArray[r][c].at(2);
					myArray[r + 1][c].at(2) = ' ';
					myArray[r + 2][c].at(2) = ' ';
					myArray[r][c - 1].at(2) = ' ';
					myArray[r][c - 2].at(2) = ' ';
					wrapFlag = true;

				}
			}
		}


	}
	//upward right L
	if ((r <= 6 && r >= 0) && (c <= 8 && c >= 2))
	{
		if (myArray[r][c].at(2) == myArray[r][r + 1].at(2) && myArray[r][c].at(2) == myArray[r][r + 2].at(2))
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2))
			{
				gameScore(myArray, 9, r, c);
				myArray[r][c].at(1) = '@';
				myArray[r][c].at(2) = myArray[r][c].at(2);
				myArray[r + 1][c].at(2) = ' ';
				myArray[r + 2][c].at(2) = ' ';
				myArray[r][c - 1].at(2) = ' ';
				myArray[r][c - 2].at(2) = ' ';
				wrapFlag = true;

			}
		}
	}

	//downward left L
	if ((r >= 2 && r <= 8) && (c <= 6 && c >= 0))
	{
		if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2))
		{
			if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r + 2][c].at(2) == myArray[r][c + 2].at(2))
			{
				gameScore(myArray, 9, r, c);
				myArray[r][c].at(1) = '@';
				myArray[r][c].at(2) = myArray[r][c].at(2);
				myArray[r - 1][c].at(2) = ' ';
				myArray[r - 2][c].at(2) = ' ';
				myArray[r][c + 1].at(2) = ' ';
				myArray[r][c + 2].at(2) = ' ';
				wrapFlag = true;


			}
		}
	}
	//downward right L
	if ((r >= 2 && r <= 8) && (c >= 2 && c <= 8))
	{
		if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2))
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2))
			{
				gameScore(myArray, 9, r, c);
				myArray[r][c].at(1) = '@';
				myArray[r][c].at(2) = myArray[r][c].at(2);
				myArray[r - 1][c].at(2) = ' ';
				myArray[r - 2][c].at(2) = ' ';
				myArray[r][c - 1].at(2) = ' ';
				myArray[r][c - 2].at(2) = ' ';
				wrapFlag = true;


			}

		}
	}

	// T condition
	if ((r >= 0 && r <= 6) && (c >= 1 && c <= 7))
	{
		if (myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2))
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2))
			{
				gameScore(myArray, 9, r, c);
				myArray[r][c].at(1) = '@';
				myArray[r][c].at(2) = myArray[r][c].at(2);
				myArray[r + 1][c].at(2) = ' ';
				myArray[r + 2][c].at(2) = ' ';
				myArray[r][c - 1].at(2) = ' ';
				myArray[r][c + 1].at(2) = ' ';
				wrapFlag = true;

			}
		}
	}
	if ((r >= 1 && r <= 7) && (c >= 0 && c <= 6))
	{
		if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2))
		{
			if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2))
			{
				gameScore(myArray, 9, r, c);
				myArray[r][c].at(1) = '@';
				myArray[r][c].at(2) = myArray[r][c].at(2);
				myArray[r - 1][c].at(2) = ' ';
				myArray[r + 1][c].at(2) = ' ';
				myArray[r][c + 1].at(2) = ' ';
				myArray[r][c + 2].at(2) = ' ';
				wrapFlag = true;

			}
		}

	}

	if (wrapFlag == true)
	{
		displaceCandy(myArray, 9);
		delay(2);
		fillRandcandy(myArray, 9);
	}
}

//check 4 similar candies 
void stripCandy(string myArray[][9], int size, int& r, int& c)
{
	//candies displaces when stripFlag is true only
	bool stripFlag = false;

	// checking rows for possible combination
	if (r >= 0 && r <= 5)
	{
		if (myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2) && myArray[r][c].at(2) == myArray[r + 3][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(1) = '$';
			myArray[r][c].at(2) = myArray[r][c].at(2);
			myArray[r + 1][c].at(2) = ' ';
			myArray[r + 2][c].at(2) = ' ';
			myArray[r + 3][c].at(2) = ' ';
			stripFlag = true;
		}
	}
	if (r >= 1 && r <= 6)
	{
		if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(1) = '$';
			myArray[r][c].at(2) = myArray[r][c].at(2);
			myArray[r - 1][c].at(2) = ' ';
			myArray[r + 1][c].at(2) = ' ';
			myArray[r + 2][c].at(2) = ' ';
			stripFlag = true;
		}
	}

	if (r >= 2 && r <= 7)
	{
		if (myArray[r][c].at(2) == myArray[r - 2][c].at(2) && myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(1) = '$';
			myArray[r][c].at(2) = myArray[r][c].at(2);
			myArray[r - 2][c].at(2) = ' ';
			myArray[r - 1][c].at(2) = ' ';
			myArray[r + 1][c].at(2) = ' ';
			stripFlag = true;
		}
	}

	if (r >= 3 && r <= 8)
	{
		if (myArray[r][c].at(2) == myArray[r - 3][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2) && myArray[r][c].at(2) == myArray[r - 1][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(1) = '$';
			myArray[r][c].at(2) = myArray[r][c].at(2);
			myArray[r - 3][c].at(2) = ' ';
			myArray[r - 2][c].at(2) = ' ';
			myArray[r - 1][c].at(2) = ' ';
			stripFlag = true;


		}
	}

	//checking column for possible combination
	//& represents vertical strips
	if (c >= 0 && c <= 5)
	{
		if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2) && myArray[r][c].at(2) == myArray[r][c + 3].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(1) = '#';
			myArray[r][c].at(2) = myArray[r][c].at(2);
			myArray[r][c + 1].at(2) = ' ';
			myArray[r][c + 2].at(2) = ' ';
			myArray[r][c + 3].at(2) = ' ';
			stripFlag = true;
		}
	}

	if (c >= 1 && c <= 6)
	{
		if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(1) = '#';
			myArray[r][c].at(2) = myArray[r][c].at(2);
			myArray[r][c - 1].at(2) = ' ';
			myArray[r][c + 1].at(2) = ' ';
			myArray[r][c + 2].at(2) = ' ';
			stripFlag = true;
		}
	}

	if (c >= 2 && c <= 7)
	{
		if (myArray[r][c].at(2) == myArray[r][c - 2].at(2) && myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(1) = '#';
			myArray[r][c].at(2) = myArray[r][c].at(2);
			myArray[r][c - 2].at(2) = ' ';
			myArray[r][c - 1].at(2) = ' ';
			myArray[r][c + 1].at(2) = ' ';
			stripFlag = true;
		}
	}

	if (c >= 3 && c <= 8)
	{
		if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2) && myArray[r][c].at(2) == myArray[r][c - 3].at(2))
		{
			gameScore(myArray, 9, r, c);
			delay(1);
			myArray[r][c].at(1) = '#';
			myArray[r][c].at(2) = myArray[r][c].at(2);
			delay(1);
			myArray[r][c - 1].at(2) = ' ';
			delay(1);
			myArray[r][c - 2].at(2) = ' ';
			delay(1);
			myArray[r][c - 3].at(2) = ' ';
			stripFlag = true;
		}
	}

	if (stripFlag == true)
	{
		displaceCandy(myArray, 9);
		delay(2);
		fillRandcandy(myArray, 9);
	}
}

//crushing all row when stripped candy comes
void rowStripcandy(string myArray[][9], int size, int& r, int& c)
{
	bool rowFlag = false;

	//checking row combinations
	if (r >= 0 && r <= 6)
	{
		if (myArray[r][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}

		if (myArray[r + 1][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}

		}

		if (myArray[r + 2][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}
	}

	if (r >= 1 && r <= 7)
	{
		if (myArray[r][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}

		}

		if (myArray[r + 1][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}

		}

		if (myArray[r - 1][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}
	}

	if (r >= 2 && r <= 8)
	{
		if (myArray[r][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}

		if (myArray[r - 1][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}
		if (myArray[r - 2][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}
	}
	//column combinations

	if (c >= 0 && c <= 6)
	{
		if (myArray[r][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}

		if (myArray[r][c + 1].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c - 1] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}

		if (myArray[r][c + 2].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c + 2] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}
	}


	if (c >= 1 && c <= 7)
	{
		if (myArray[r][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}
		if (myArray[r][c - 1].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c - 1] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}
		if (myArray[r][c + 1].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c + 1] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}
	}

	if (c >= 2 && c <= 8)
	{
		if (myArray[r][c].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}

		if (myArray[r][c - 1].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c - 1] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}
		if (myArray[r][c - 2].at(1) == '$')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2))
			{
				for (int row = 0; row < 9; row++)
				{
					myArray[row][c - 2] = { ' ',' ',' ',' ',' ' };
				}
				rowFlag = true;
			}
		}
	}

	if (rowFlag == true)
	{
		fillRandcandy(myArray, 9);
	}
}

void columnStripcandy(string myArray[][9], int size, int& r, int& c)
{
	bool columnFlag = false;

	//checking row combinations
	if (r >= 0 && r <= 6)
	{
		if (myArray[r][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}

		if (myArray[r + 1][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r + 1][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}

		if (myArray[r + 2][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r + 2][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}
	}

	if (r >= 1 && r <= 7)
	{
		if (myArray[r][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}

		if (myArray[r - 1][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r - 1][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}

		if (myArray[r + 1][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r + 1][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}
	}

	if (r >= 2 && r <= 8)
	{
		if (myArray[r][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}

		if (myArray[r - 1][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r - 1][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}

		if (myArray[r - 2][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r - 2][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}
	}

	//checking for column combination

	if (c >= 0 && c <= 6)
	{
		if (myArray[r][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}

		if (myArray[r][c + 1].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}
		if (myArray[r][c + 2].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}
	}

	if (c >= 1 && c <= 7)
	{
		if (myArray[r][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}

		if (myArray[r][c - 1].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}
		if (myArray[r][c + 1].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}

	}

	if (c >= 2 && c <= 8)
	{
		if (myArray[r][c].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}

		if (myArray[r][c - 1].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}
		if (myArray[r][c - 2].at(1) == '#')
		{
			if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c - 2].at(2))
			{
				for (int col = 0; col < 9; col++)
				{
					myArray[r][col] = { ' ',' ',' ',' ',' ' };
				}
				columnFlag = true;
			}
		}
	}


}
//check 3 similar candies
void threeCombo(string myArray[][9], int size, int& r, int& c)
{
	bool threeFlag = false;
	//checking row combinations
	if (r >= 0 && r <= 6)
	{
		if (myArray[r][c].at(2) == myArray[r + 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 2][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = ' ';
			myArray[r + 1][c].at(2) = ' ';
			myArray[r + 2][c].at(2) = ' ';
			threeFlag = true;
		}
	}

	if (r >= 1 && r <= 7)
	{
		if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r + 1][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = ' ';
			myArray[r - 1][c].at(2) = ' ';
			myArray[r + 1][c].at(2) = ' ';
			//gameScore(myArray, 9, r, c);
			threeFlag = true;
		}
	}

	if (r >= 2 && r <= 8)
	{
		if (myArray[r][c].at(2) == myArray[r - 1][c].at(2) && myArray[r][c].at(2) == myArray[r - 2][c].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = ' ';
			myArray[r - 1][c].at(2) = ' ';
			myArray[r - 2][c].at(2) = ' ';
			threeFlag = true;
		}
	}

	//checking column combinations
	if (c >= 0 && c <= 6)
	{
		if (myArray[r][c].at(2) == myArray[r][c + 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 2].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = ' ';
			myArray[r][c + 1].at(2) = ' ';
			myArray[r][c + 2].at(2) = ' ';
			threeFlag = true;
		}
	}

	if (c >= 1 && c <= 6)
	{
		if (myArray[r][c].at(2) == myArray[r][c - 1].at(2) && myArray[r][c].at(2) == myArray[r][c + 1].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = ' ';
			myArray[r][c - 1].at(2) = ' ';
			myArray[r][c + 1].at(2) = ' ';
			threeFlag = true;
		}
	}

	if (c >= 2 && c <= 8)
	{
		if (myArray[r][c].at(2) == myArray[r][c - 2].at(2) && myArray[r][c].at(2) == myArray[r][c - 1].at(2))
		{
			gameScore(myArray, 9, r, c);
			myArray[r][c].at(2) = ' ';
			myArray[r][c - 2].at(2) = ' ';
			myArray[r][c - 1].at(2) = ' ';
			threeFlag = true;
		}
	}

	if (threeFlag == true)
	{
		displaceCandy(myArray, 9);
		delay(2);
		fillRandcandy(myArray, 9);
	}
}

//after crusing candies this fuction will displace candy from up to down
void displaceCandy(string myArray[][9], int size)
{
	string temp1;

	for (int col = 0; col <= 8; col++)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int row = 8; row > 0; row--)
			{
				if (myArray[row][col].at(2) == ' ')
				{
					temp1 = myArray[row][col];
					myArray[row][col] = myArray[row - 1][col];
					myArray[row - 1][col] = temp1;
				}

			}
		}
	}

}

//the function will randomly fill grid with candies 
void fillRandcandy(string myArray[][9], int size)
{
	char arr2[5] = { 'R','G','B','Y','O' };
	int x = 0;
	char candy;

	int i = 0;
	for (int row = 0; row < 9; row++)
	{

		if (myArray[row][i].at(2) == ' ')
		{
			x = (rand() % 5);
			candy = arr2[x];
			myArray[row][i].at(2) = candy;
		}

		if (myArray[row][i + 1].at(2) == ' ')
		{
			x = (rand() % 5);
			candy = arr2[x];
			myArray[row][i + 1].at(2) = candy;
		}
		if (myArray[row][i + 2].at(2) == ' ')
		{
			x = (rand() % 5);
			candy = arr2[x];
			myArray[row][i + 2].at(2) = candy;
		}

		if (myArray[row][i + 3].at(2) == ' ')
		{
			x = (rand() % 5);
			candy = arr2[x];
			myArray[row][i + 3].at(2) = candy;
		}

		if (myArray[row][i + 4].at(2) == ' ')
		{
			x = (rand() % 5);
			candy = arr2[x];
			myArray[row][i + 4].at(2) = candy;
		}

		if (myArray[row][i + 5].at(2) == ' ')
		{
			x = (rand() % 5);
			candy = arr2[x];
			myArray[row][i + 5].at(2) = candy;
		}

		if (myArray[row][i + 6].at(2) == ' ')
		{
			x = (rand() % 5);
			candy = arr2[x];
			myArray[row][i + 6].at(2) = candy;
		}

		if (myArray[row][i + 7].at(2) == ' ')
		{
			x = (rand() % 5);
			candy = arr2[x];
			myArray[row][i + 7].at(2) = candy;
		}

		if (myArray[row][i + 8].at(2) == ' ')
		{
			x = (rand() % 5);
			candy = arr2[x];
			myArray[row][i + 8].at(2) = candy;
		}

	}

}


//condition to win game
void winGame(int& score, int targetScore)
{
	if (score >= targetScore)
	{
		delay(2);
		cout << "			*******************************" << endl;
		delay(5);
		cout << "				   YOU WIN" << endl;
		delay(5);
		cout << "			*******************************" << endl;

	}
	if (score < targetScore)
	{
		delay(2);
		cout << "			*******************************" << endl;
		delay(5);
		cout << "				   YOU LOST" << endl;
		delay(5);
		cout << "			*******************************" << endl;

	}

}

//delay fuction
void delay(int a)
{
	int time = 0, add = 0;
	time = a * 10000000;

	for (int i = 0; i < time; i++)
	{
		add = add * i;
		add++;
		add++;
	}

}
