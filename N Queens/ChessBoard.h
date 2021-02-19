/**
* Ethan Harper
* ChessBoard.h
**/

#pragma once
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

using namespace std;

class ChessBoard
{
public:
	ChessBoard();
    ChessBoard(int);
	~ChessBoard();  //Destructor
    void setSize(int);
    int getSize();
    bool solve();
    void displayBoard();

private:
    char** boardPtr;
    int boardSize;
    bool placeQueens(int);
    void deleteBoard();
};
#endif

