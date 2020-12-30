#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

const int BEGINNER_DIMENSION = 8;
const int BEGINNER_MINES = 10;
const int INTERMEDIATE_DIMENSION = 16;
const int INTERMEDIATE_MINES = 40;
const int ADVANCED_DIMENSION = 20;
const int ADVANCED_MINES = 99;
const string BLANK = "-";
const string MINE = "X";

void displayBeginnerBoard(string playerBoard[BEGINNER_DIMENSION][BEGINNER_DIMENSION])
{
	cout << "Current playerBoard: \n \n";
	
	// print col num 
	cout << "  ";
	for (int colNum = 0; colNum < BEGINNER_DIMENSION; colNum++)
	{
		cout << colNum << " ";
	}
	cout << endl;
	
	// print other stuff
	for (int rowNum = 0; rowNum < BEGINNER_DIMENSION; rowNum++)
	{
		cout << rowNum << " ";
		for (int colNum = 0; colNum < BEGINNER_DIMENSION; colNum++)
		{
			cout << playerBoard[colNum][rowNum] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void displayIntermediateBoard(string playerBoard[INTERMEDIATE_DIMENSION][INTERMEDIATE_DIMENSION])
{
	cout << "Current playerBoard: \n \n";
	
	// print col num 
	cout << "   ";
	for (int colNum = 0; colNum < INTERMEDIATE_DIMENSION; colNum++)
	{
		cout << colNum << "  ";
	}
	cout << endl;
	
	// print other stuff
	
	for (int rowNum = 0; rowNum < INTERMEDIATE_DIMENSION; rowNum++)
	{
		if (rowNum < 10)
		{
			cout << rowNum << "  ";
		}
		
		else
		{
			cout << rowNum << " ";
		}
		
		for (int colNum = 0; colNum < INTERMEDIATE_DIMENSION; colNum++)
		{
			if (colNum < 10)
			{
				cout << playerBoard[colNum][rowNum] << "  ";				
			}
			
			else 
			{
				cout << playerBoard[colNum][rowNum] << "   ";		
			}
		}
		cout << endl;
	}
	cout << endl;
}

void displayAdvancedBoard(string playerBoard[ADVANCED_DIMENSION][ADVANCED_DIMENSION])
{
	cout << "Current playerBoard: \n \n";
	
	// print col num 
	cout << "   ";
	for (int colNum = 0; colNum < ADVANCED_DIMENSION; colNum++)
	{
		cout << colNum << "  ";
	}
	cout << endl;
	
	// print other stuff
	
	for (int rowNum = 0; rowNum < ADVANCED_DIMENSION; rowNum++)
	{
		if (rowNum < 10)
		{
			cout << rowNum << "  ";
		}
		
		else
		{
			cout << rowNum << " ";
		}
		
		for (int colNum = 0; colNum < ADVANCED_DIMENSION; colNum++)
		{
			if (colNum < 10)
			{
				cout << playerBoard[colNum][rowNum] << "  ";				
			}
			
			else 
			{
				cout << playerBoard[colNum][rowNum] << "   ";		
			}
		}
		cout << endl;
	}
	cout << endl;
}

void createBeginnerMines(string actualBoard[BEGINNER_DIMENSION][BEGINNER_DIMENSION])
{
	int mines = 0;
	while (mines < BEGINNER_MINES)
	{
		srand(time(0));
		int x = rand() % BEGINNER_DIMENSION;
		int y = rand() % BEGINNER_DIMENSION;
		if (actualBoard[x][y] != MINE)
		{
//			cout << "Mine at " << x << ", " << y << endl;
			actualBoard[x][y] = MINE;
			mines++;
		}
	}
}

void createIntermediateMines(string actualBoard[INTERMEDIATE_DIMENSION][INTERMEDIATE_DIMENSION])
{
	int mines = 0;
	while (mines < INTERMEDIATE_MINES)
	{
		srand(time(0));
		int x = rand() % INTERMEDIATE_DIMENSION;
		int y = rand() % INTERMEDIATE_DIMENSION;
		if (actualBoard[x][y] != MINE)
		{
//			cout << "Mine at " << x << ", " << y << endl;
			actualBoard[x][y] = MINE;
			mines++;
		}
	}
}

void createAdvancedMines(string actualBoard[ADVANCED_DIMENSION][ADVANCED_DIMENSION])
{
	int mines = 0;
	while (mines < ADVANCED_MINES)
	{
		srand(time(0));
		int x = rand() % ADVANCED_DIMENSION;
		int y = rand() % ADVANCED_DIMENSION;
		if (actualBoard[x][y] != MINE)
		{
//			cout << "Mine at " << x << ", " << y << endl;
			actualBoard[x][y] = MINE;
			mines++;
		}
	}
}

int findBeginnerMines(string actualBoard[BEGINNER_DIMENSION][BEGINNER_DIMENSION], int x, int y)
{
	int mines = 0;
	
	if (actualBoard[x][y] == MINE)
	{
		mines = -1;
	}
	
	else
	{
		if (x != 0 && y != 0 && actualBoard[x - 1][y - 1] == MINE)
		{
			mines++;
		}
		
		if (y != 0 && actualBoard[x][y - 1] == MINE)
		{
			mines++;
		}
		
		if (y != 0 && x != BEGINNER_DIMENSION - 1 && actualBoard[x + 1][y - 1] == MINE)
		{
			mines++;
		}
		
		if (x != 0 && actualBoard[x - 1][y] == MINE)
		{
			mines++;
		}
		
		if (x != BEGINNER_DIMENSION - 1 && actualBoard[x + 1][y] == MINE)
		{
			mines++;
		}
		
		if (x != 0 && y != BEGINNER_DIMENSION - 1 && actualBoard[x - 1][y + 1] == MINE)
		{
			mines++;
		}
		
		if (y != BEGINNER_DIMENSION - 1 && actualBoard[x][y + 1] == MINE)
		{
			mines++;
		}
		
		if (x != BEGINNER_DIMENSION - 1 && y != BEGINNER_DIMENSION - 1 && actualBoard[x + 1][y + 1] == MINE)
		{
			mines++;
		}
	}
	
	return mines;
}

int findIntermediateMines(string actualBoard[INTERMEDIATE_DIMENSION][INTERMEDIATE_DIMENSION], int x, int y)
{
	int mines = 0;
	
	if (actualBoard[x][y] == MINE)
	{
		mines = -1;
	}
	
	else
	{
		if (x != 0 && y != 0 && actualBoard[x - 1][y - 1] == MINE)
		{
			mines++;
		}
		
		if (y != 0 && actualBoard[x][y - 1] == MINE)
		{
			mines++;
		}
		
		if (y != 0 && x != INTERMEDIATE_DIMENSION - 1 && actualBoard[x + 1][y - 1] == MINE)
		{
			mines++;
		}
		
		if (x != 0 && actualBoard[x - 1][y] == MINE)
		{
			mines++;
		}
		
		if (x != INTERMEDIATE_DIMENSION - 1 && actualBoard[x + 1][y] == MINE)
		{
			mines++;
		}
		
		if (x != 0 && y != INTERMEDIATE_DIMENSION - 1 && actualBoard[x - 1][y + 1] == MINE)
		{
			mines++;
		}
		
		if (y != INTERMEDIATE_DIMENSION - 1 && actualBoard[x][y + 1] == MINE)
		{
			mines++;
		}
		
		if (x != INTERMEDIATE_DIMENSION - 1 && y != INTERMEDIATE_DIMENSION - 1 && actualBoard[x + 1][y + 1] == MINE)
		{
			mines++;
		}
	}
	
	return mines;
}

int findAdvancedMines(string actualBoard[ADVANCED_DIMENSION][ADVANCED_DIMENSION], int x, int y)
{
	int mines = 0;
	
	if (actualBoard[x][y] == MINE)
	{
		mines = -1;
	}
	
	else
	{
		if (x != 0 && y != 0 && actualBoard[x - 1][y - 1] == MINE)
		{
			mines++;
		}
		
		if (y != 0 && actualBoard[x][y - 1] == MINE)
		{
			mines++;
		}
		
		if (y != 0 && x != ADVANCED_DIMENSION - 1 && actualBoard[x + 1][y - 1] == MINE)
		{
			mines++;
		}
		
		if (x != 0 && actualBoard[x - 1][y] == MINE)
		{
			mines++;
		}
		
		if (x != ADVANCED_DIMENSION - 1 && actualBoard[x + 1][y] == MINE)
		{
			mines++;
		}
		
		if (x != 0 && y != ADVANCED_DIMENSION - 1 && actualBoard[x - 1][y + 1] == MINE)
		{
			mines++;
		}
		
		if (y != ADVANCED_DIMENSION - 1 && actualBoard[x][y + 1] == MINE)
		{
			mines++;
		}
		
		if (x != ADVANCED_DIMENSION - 1 && y != ADVANCED_DIMENSION - 1 && actualBoard[x + 1][y + 1] == MINE)
		{
			mines++;
		}
	}
	
	return mines;
}

int main() 
{
	int difficulty = 0;
	int dimension = 0;
	cout << "What difficulty would you like to play?" << endl;
	cout << "1 - Beginner: 8 x 8 with 10 mines" << endl;
	cout << "2 - Intermediate: 16 x 16 with 40 mines" << endl;
	cout << "3 - Advanced: 20 x 20 with 90 mines" << endl;
	
	while (difficulty < 1 || difficulty > 3) 
	{
		cin >> difficulty;
		if (difficulty < 1 || difficulty > 3)
		{
			cout << "Invalid difficulty" << endl;
		}
	}
	
	cout << endl;
	
	bool lost = false;
	int found = 0;
	
	if (difficulty == 1)
	{
		string playerBoard[BEGINNER_DIMENSION][BEGINNER_DIMENSION];
		string actualBoard[BEGINNER_DIMENSION][BEGINNER_DIMENSION];
		for (int colNum = 0; colNum < BEGINNER_DIMENSION; colNum++)
		{
			for (int rowNum = 0; rowNum < BEGINNER_DIMENSION; rowNum++)
			{
				playerBoard[colNum][rowNum] = BLANK;
				actualBoard[colNum][rowNum] = BLANK;
			}
		}
		
		displayBeginnerBoard(playerBoard);
		cout << "Setting mines..." << endl;
		createBeginnerMines(actualBoard);
		
		while (lost == false && found < 54)
		{
			int x = -1;
			int y = -1;
			int numMines = 0;
			stringstream ss;
			string mines;
			
			cout << "Enter coordinates: (first x, then y): ";
			
			while (x < 0 || y < 0 || x >= BEGINNER_DIMENSION || y >= BEGINNER_DIMENSION)
			{
				cin >> x >> y;
				if (x < 0 || y < 0 || x >= BEGINNER_DIMENSION || y >= BEGINNER_DIMENSION)
				{
					cout << "Invalid coordinates" << endl;
				}
				cout << endl;
			}
			
			
			numMines = findBeginnerMines(actualBoard, x, y);
			
			if (numMines == -1)
			{
				playerBoard[x][y] = "X";
				lost = true;
				cout << "You lose!" << endl << endl;
			}
			
			else
			{
				
				ss << numMines;
				ss >> mines;
				playerBoard[x][y] = mines;
				found++;
			}
			

			displayBeginnerBoard(playerBoard);			
			
			
			if (found == (pow(BEGINNER_DIMENSION, 2) - BEGINNER_MINES))
			{
				cout << "You win!" << endl << endl;
			}	
		}
	}
	
	else if (difficulty == 2)
	{
		string playerBoard[INTERMEDIATE_DIMENSION][INTERMEDIATE_DIMENSION];
		string actualBoard[INTERMEDIATE_DIMENSION][INTERMEDIATE_DIMENSION];
		for (int colNum = 0; colNum < INTERMEDIATE_DIMENSION; colNum++)
		{
			for (int rowNum = 0; rowNum < INTERMEDIATE_DIMENSION; rowNum++)
			{
				playerBoard[colNum][rowNum] = BLANK;
				actualBoard[colNum][rowNum] = BLANK;
			}
		}
		
		displayIntermediateBoard(playerBoard);
		cout << "Setting mines..." << endl;
		createIntermediateMines(actualBoard);
		
		while (lost == false && found < 54)
		{
			int x = -1;
			int y = -1;
			int numMines = 0;
			stringstream ss;
			string mines;
			
			cout << "Enter coordinates: (first x, then y): ";
			
			while (x < 0 || y < 0 || x >= INTERMEDIATE_DIMENSION || y >= INTERMEDIATE_DIMENSION)
			{
				cin >> x >> y;
				if (x < 0 || y < 0 || x >= INTERMEDIATE_DIMENSION || y >= INTERMEDIATE_DIMENSION)
				{
					cout << "Invalid coordinates" << endl;
				}
				cout << endl;
			}
			
			
			numMines = findIntermediateMines(actualBoard, x, y);
			
			if (numMines == -1)
			{
				playerBoard[x][y] = "X";
				lost = true;
				cout << "You lose!" << endl << endl;
			}
			
			else
			{
				
				ss << numMines;
				ss >> mines;
				playerBoard[x][y] = mines;
				found++;
			}
			

			displayIntermediateBoard(playerBoard);			
			
			
			if (found == (pow(INTERMEDIATE_DIMENSION, 2) - INTERMEDIATE_MINES))
			{
				cout << "You win!" << endl << endl;
			}	
		}
	}
	
	else
	{
		string playerBoard[ADVANCED_DIMENSION][ADVANCED_DIMENSION];
		string actualBoard[ADVANCED_DIMENSION][ADVANCED_DIMENSION];
		for (int colNum = 0; colNum < ADVANCED_DIMENSION; colNum++)
		{
			for (int rowNum = 0; rowNum < ADVANCED_DIMENSION; rowNum++)
			{
				playerBoard[colNum][rowNum] = BLANK;
				actualBoard[colNum][rowNum] = BLANK;
			}
		}
		
		displayAdvancedBoard(playerBoard);
		cout << "Setting mines..." << endl;
		createAdvancedMines(actualBoard);
		
		while (lost == false && found < 54)
		{
			int x = -1;
			int y = -1;
			int numMines = 0;
			stringstream ss;
			string mines;
			
			cout << "Enter coordinates: (first x, then y): ";
			
			while (x < 0 || y < 0 || x >= ADVANCED_DIMENSION || y >= ADVANCED_DIMENSION)
			{
				cin >> x >> y;
				if (x < 0 || y < 0 || x >= ADVANCED_DIMENSION || y >= ADVANCED_DIMENSION)
				{
					cout << "Invalid coordinates" << endl;
				}
				cout << endl;
			}
			
			
			numMines = findAdvancedMines(actualBoard, x, y);
			
			if (numMines == -1)
			{
				playerBoard[x][y] = "X";
				lost = true;
				cout << "You lose!" << endl << endl;
			}
			
			else
			{
				
				ss << numMines;
				ss >> mines;
				playerBoard[x][y] = mines;
				found++;
			}
			

			displayAdvancedBoard(playerBoard);			
			
			
			if (found == (pow(ADVANCED_DIMENSION, 2) - ADVANCED_MINES))
			{
				cout << "You win!" << endl << endl;
			}	
		}
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}
