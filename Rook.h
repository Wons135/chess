#pragma once
#include"Piece.h"
#include"Board.h"
#include<iostream>

class Rook : public Piece
{
public:
	int whiteLeft = 0, whiteRight = 0;
	int blackLeft = 0, blackRight = 0;

	int move(int prevx, int prevy, int newx, int newy);

	int check(int x, int y, int kx, int ky);

};

