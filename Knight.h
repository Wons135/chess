#pragma once
#include"Piece.h"
#include "Board.h"
#include<iostream>

class Knight : public Piece
{
public:

	int move(int prevx, int prevy, int newx, int newy);

	int check(int x, int y, int kx, int ky);
};

