#include "Pawn.h"


int Pawn::whiteMove(int prevx, int prevy,int newx,int newy) 
{
	if (prevy == 6)
	{
		if ((newy == prevy - 1 && newx == prevx && cell[prevy - 1][prevx] == 0) || (newy == prevy - 2 && newx == prevx && cell[prevy - 1][prevx] == 0 && cell[prevy - 2][prevx] == 0))
		{
			return 1;
		}
	}
	else if (newy == prevy - 1 && newx == prevx && cell[prevy - 1][prevx] == 0)
	{
		return 1;
	}
	if (cell[prevy - 1][prevx - 1] > 0)
	{
		if (newy == prevy - 1 && newx == prevx - 1)
		{
			return 1;
		}
	}
	if (cell[prevy - 1][prevx + 1] > 0)
	{
		if (newy == prevy - 1 && newx == prevx + 1)
		{
			return 1;
		}
	}
	return 0;
}

int Pawn::blackMove(int prevx, int prevy, int newx, int newy)
{
	if (prevy == 1)
	{
		if ((newy == prevy + 1 && newx == prevx && cell[prevy + 1][prevx] == 0) || (newy == prevy + 2 && newx == prevx && cell[prevy + 1][prevx] == 0 && cell[prevy + 2][prevx] == 0))
		{
			return 1;
		}
	}
	else if (newy == prevy + 1 && newx == prevx && cell[prevy + 1][prevx] == 0)
	{
		return 1;
	}
	if (cell[prevy + 1][prevx - 1] < 0)
	{
		if (newy == prevy + 1 && newx == prevx + 1)
		{
			return 1;
		}
	}
	if (cell[prevy + 1][prevx + 1] < 0)
	{
		if (newy == prevy + 1 && newx == prevx + 1)
		{
			return 1;
		}
	}
	return 0;
}

int Pawn::whiteCheck(int x, int y, int kx, int ky)
{
	if (cell[y - 1][x - 1] >= 0)
	{
		if (y - 1 == ky && x - 1 == kx)
		{
			return 1;
		}
	}
	if (cell[y - 1][x + 1] >= 0)
	{

		if (y - 1 == ky && x + 1 == kx)
		{
			return 1;
		}
	}
	return 0;
}

int Pawn::blackCheck(int x, int y, int kx, int ky)
{
	if (cell[y + 1][x - 1] <= 0)
	{
		if (ky == y + 1 && kx == x - 1)
		{
			return 1;
		}
	}
	if (cell[y + 1][x + 1] <= 0)
	{
		if (ky == y + 1 && kx == x + 1)
		{
			return 1;
		}
	}
	return 0;
}