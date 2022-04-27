#pragma once
#include"Piece.h"
#include"Board.h"
#include"Queen.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Pawn.h"
#include<iostream>

class King : public Piece, public Queen, public Rook, public Knight, public Bishop, public Pawn
{
public: 
	//white pieces
	int wKing = 1, wQueen = 2, wRook = 3, wKnight = 4, wBishop = 5, wPawn = 6;

	//black pieces
	int bKing = 7, bQueen = 8, bRook = 9, bKnight = 10, bBishop = 11, bPawn = 12;

	int white = 0, black = 0, whitex = 0, whitey = 0, blackx = 0, blacky = 0;

	void whitePoz();
	void blackPoz();

	int whiteMove(int prevx, int prevy, int newx, int newy);
	int blackMove(int prevx, int prevy, int newx, int newy);

	int check(int x, int y, int kx, int ky);
	int whiteCheckTest(int x, int y);
	int blackCheckTest(int x, int y);
};

