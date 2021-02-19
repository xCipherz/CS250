/**
* Ethan Harper
* ChessBoard.cpp
**/

#include <iostream>
//#include <string>
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

    if(size > 12)
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
		    boardPtr[i][j] = '*';
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
    return placeQueens(0);
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

	if (column >= boardSize)
	{
        return true; //The board is filled, problem is solved. Return true.
	} 
	else
	{
		while (row <= boardSize) //unconsidered rows exist in column
		{
			if () //[row][column] is unattacked
			{
                //Place a queen in the un-attacked square.

				//Do a recursive call to try and place queens
				//in subsequent columns:
                if (!placeQueens(column + 1))
				{
                    //If we’re here, placement of the last queen resulted in a dead end; 
                    //no solution could be found. Remove the last queen placed.

                    //Move to next row so search can continue in next iteration.
				} 
				else
				{
                    //If we’re here, recursive calls were able to place queens in all columns 
                    //to the right of column, the problem is solved. Return true.
				} 
			} 
			else
			{
                //Square is attacked, move to next row.
			} 
		} 
        //All rows have been considered in column without a successful queen placement.  
        //Backtrack by returning false.
	} 

} 

bool isUnattacked(int, int)
{
    return false;
}

//char** boardPtr;
//int boardSize;
