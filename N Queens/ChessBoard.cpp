/**
* Ethan Harper
* ChessBoard.cpp
**/

#include <iostream>
#include <string>
#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	setSize(8);
}
ChessBoard::ChessBoard(int size)
{
	setSize(size);
}
ChessBoard::~ChessBoard()  //Destructor
{
	deleteBoard();
}

void ChessBoard::deleteBoard()
{
	if (boardPtr != nullptr)
	{
		for (int i = 0; i < boardSize; i++)
		{
			delete[] boardPtr[i];
		}

		delete[] boardPtr;
	}
}

void ChessBoard::setSize(int size)
{
	if (boardPtr != nullptr) //If board exists, delete it
	{
		deleteBoard();
	}

	if (size > 12)
	{
		size = 12;
	}
	else if (size < 4)
	{
		size = 4;
	}

	boardPtr = new char* [size]; //Create a new board of given size

	for (int i = 0; i < size; i++)
	{
		boardPtr[i] = new char[size];
	}

	for (int i = 0; i < size; i++) //Initialize the table to all asterisks
	{
		for (int j = 0; j < size; j++)
		{
			boardPtr[i][j] = ' ';
		}
	}

	boardSize = size; //Reset board size
}

int ChessBoard::getSize()
{
	return boardSize;
}

bool ChessBoard::solve()
{
	placeQueens();
	if (placeQueens() == true)
	{
		return true;
	}
}

void ChessBoard::displayBoard()
{
	for (int i = 0; i < boardSize; i++) //Initialize the table to all asterisks
	{
		for (int j = 0; j < boardSize; j++)
		{
			cout << boardPtr[i][j] << " ";
		}
		cout << endl;
	}
}
bool ChessBoard::placeQueens(int column)
{
	int row = 0;
	//cout << "this is the " << row;

	if (column >= boardSize)
	{
		//cout << "This is the boardsize: " << boardSize;
		//cout << "This is the column: " << column;
		return true; //The board is filled, problem is solved. Return true.
	}
	else
	{
		while (row <= boardSize) //unconsidered rows exist in column
		{
			if (isUnattacked(row, column)) //[row][column] is unattacked
			{
				boardPtr[row][column] = 'Q';
				cout << "You made a queen";

				placeQueens(column + 1);

				//Do a recursive call to try and place queens
				//in subsequent columns:
				if (!placeQueens(column + 1))
				{
					boardPtr[row][column] = '*';
					//If we’re here, placement of the last queen resulted in a dead end; 
					//no solution could be found. Remove the last queen placed.

					//Move to next row so search can continue in next iteration.
				}
				else
				{
					return true;
					//If we’re here, recursive calls were able to place queens in all columns 
					//to the right of column, the problem is solved. Return true.
				}
			}
			else
			{
				placeQueens(row + 1);
				//Square is attacked, move to next row.
			}
		}
		return false;
		//All rows have been considered in column without a successful queen placement.  
		//Backtrack by returning false.
	}

}

bool ChessBoard::placeQueens()
{
	if (placeQueens(boardSize) == false) 
	{
		//printf("Solution does not exist");
		return false;
	}
	return true;
}

bool ChessBoard::isUnattacked(int row, int column)
{
	int rowCheck, columnCheck;
	for (rowCheck = 0; rowCheck < column; rowCheck++)
	{
		if (boardPtr[row][rowCheck])
		{
			return false;
		}
	}
	for (rowCheck = row, columnCheck = column; rowCheck >= 0 && columnCheck >= 0; rowCheck--, columnCheck--)
	{
		if (boardPtr[rowCheck][columnCheck])
		{
			return false;
		}
	}
	for (rowCheck = row, columnCheck = column; columnCheck >= 0 && rowCheck < boardSize; rowCheck++, columnCheck--)
	{
		if (boardPtr[rowCheck][columnCheck])
		{
			return false;
		}
	}
	return true;
}

//char** boardPtr;
//int boardSize;
