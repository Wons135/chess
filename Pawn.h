#pragma once
#include "Piece.h"
#include "Board.h"
#include<iostream>

class Pawn : public Piece
{
	public:

	int whiteMove(int prevx, int prevy, int newx, int newy);
	int blackMove(int prevx, int prevy, int newx, int newy);

	int whiteCheck(int x, int y, int kx, int ky);
	int blackCheck(int x, int y, int kx, int ky);

};

