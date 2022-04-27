#pragma once
#include<iostream>

//Provides pieces with their identification values, so program can recognize them on board;
class Piece
{
	public:
		//information concerning posiiton; 
		int row = 0, rank = 0, prevRow = 0, prevRank = 0;

		//white pieces
		int wKing = 1, wQueen = 2, wRook = 3, wKnight = 4, wBishop = 5, wPawn = 6;
		
		//black pieces
		int bKing = 7, bQueen = 8, bRook = 9, bKnight = 10, bBishop = 11, bPawn = 12;

		virtual int move(int prevx, int prevy, int newx, int newy);
		virtual int whiteMove(int prevx, int prevy, int newx, int newy);
		virtual int blackMove(int prevx, int prevy, int newx, int newy);
	
		virtual int check(int x, int y, int kx, int ky);
		virtual int whiteCheck(int x, int y, int kx, int ky);
		virtual int blackCheck(int x, int y, int kx, int ky);
};

