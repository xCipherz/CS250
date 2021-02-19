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
    return false;
}
void ChessBoard::displayBoard()
{

}
bool ChessBoard::placeQueens(int)
{
    return false;
}
//char** boardPtr;
//int boardSize;
