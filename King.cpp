#include "King.h"

void King::whitePoz() 
{
	for (int i = 1; i < 8; i++)
	{
		for (int j = 0; i < 8; i++)
		{
			if (cell[i][j] == wKing) {
				whitex = j;
				whitey = i;
				break;
			}
		}
	}
}

void King::blackPoz()
{
	for (int i = 1; i < 8; i++)
	{
		for (int j = 0; i < 8; i++)
		{
			if (cell[i][j] == wKing) {
				whitex = j;
				whitey = i;
				break;
			}
		}
	}
}


int King::check(int x, int y, int kx, int ky)
{
	if (x - 1 >= 0 && y - 1 >= 0 && ky == y - 1 && kx == x - 1 && cell[ky][kx] <= 0)
	{
		return 1;
	}
	if (y - 1 >= 0 && kx == x && ky == y - 1 && cell[ky][kx] <= 0)
	{
		return 1;
	}
	if (y - 1 >= 0 && x + 1 < 8 && kx == x + 1 && ky == y - 1 && cell[ky][kx] <= 0)
	{
		return 1;
	}
	if (x + 1 < 8 && ky == y && kx == x + 1 && cell[ky][kx] <= 0)
	{
		return 1;
	}
	if (x + 1 < 8 && y + 1 < 8 && ky == y + 1 && kx == x + 1 && cell[ky][kx] <= 0)
	{
		return 1;
	}
	if (y + 1 < 8 && ky == y + 1 && kx == x && cell[ky][kx] <= 0)
	{
		return 1;
	}
	if (x - 1 >= 0 && y + 1 < 8 && kx == x - 1 && ky == y + 1 && cell[ky][kx] <= 0)
	{
		return 1;
	}
	if (x - 1 >= 0 && ky == y && kx == x - 1 && cell[ky][kx] <= 0)
	{
		return 1;
	}
	return 0;
}

int King::whiteCheckTest(int x, int y)
{
	int isValid = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (cell[i][j] > 0)
			{
				if (cell[i][j] == bPawn)
				{
					isValid = Pawn::blackCheck(j, i, x, y);
				}
				if (cell[i][j] == bRook)
				{
					isValid = Rook::check(j, i, x, y);
				}
				if (cell[i][j] == bKnight)
				{
					isValid = Knight::check(j, i, x, y);
				}
				if (cell[i][j] == bBishop)
				{
					isValid = Bishop::check(j, i, x, y);
				}
				if (cell[i][j] == bQueen)
				{
					isValid = Queen::check(j, i, x, y);
				}
				if (cell[i][j] == bKing)
				{
					isValid = check(j, i, x, y);
				}
				if (isValid == 1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int King::blackCheckTest(int x, int y)
{
	int isValid = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (cell[i][j] > 0)
			{
				if (cell[i][j] == wPawn)
				{
					isValid = Pawn::whiteCheck(j, i, x, y);
				}
				if (cell[i][j] == wRook)
				{
					isValid = Rook::check(j, i, x, y);
				}
				if (cell[i][j] == wKnight)
				{
					isValid = Knight::check(j, i, x, y);
				}
				if (cell[i][j] == wBishop)
				{
					isValid = Bishop::check(j, i, x, y);
				}
				if (cell[i][j] == wQueen)
				{
					isValid = Queen::check(j, i, x, y);
				}
				if (cell[i][j] == wKing)
				{
					isValid = check(j, i, x, y);
				}
				if (isValid == 1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}


int King::whiteMove(int prevx, int prevy, int newx, int newy)
{
	if (prevx - 1 >= 0 && prevy - 1 >= 0 && newy == prevy - 1 && newx == prevx - 1 && cell[newy][newx] >= 0)
	{
		if (whiteCheckTest(prevx - 1, prevy - 1) == 1)
		{
			return 1;  // top left
		}
	}
	if (prevy - 1 >= 0 && newx == prevx && newy == prevy - 1 && cell[newy][newx] >= 0)
	{
		
		if (whiteCheckTest(prevx, prevy - 1) == 1)
		{
			return 1; // top
		}  
	}
	if (prevy - 1 >= 0 && prevx + 1 < 8 && newx == prevx + 1 && newy == prevy - 1 && cell[newy][newx] >= 0)
	{
		if (whiteCheckTest(prevx + 1, prevy - 1) == 1)
		{
			return 1; // rop right
		}
	}
	if (prevx + 1 < 8 && newy == prevy && newx == prevx + 1 && cell[newy][newx] >= 0)
	{
		if (whiteCheckTest(prevx + 1, prevy) == 1)
		{
			return 1; // right
		}
	}
	if (prevx + 1 < 8 && prevy + 1 < 8 && newy == prevy + 1 && newx == prevx + 1 && cell[newy][newx] >= 0)
	{
		if (whiteCheckTest(prevx + 1, prevy + 1) == 1)
		{
			return 1; // right bottom
		}
	}
	if (prevy + 1 < 8 && newy == prevy + 1 && newx == prevx && cell[newy][newx] >= 0)
	{
		if (whiteCheckTest(prevx, prevy + 1))
		{
			return 1; // bottom
		}
	}
	if (prevx - 1 >= 0 && prevy + 1 < 8 && newx == prevx - 1 && newy == prevy + 1 && cell[newy][newx] >= 0)
	{
		if (whiteCheckTest(prevx - 1, prevy + 1))
		{
			return 1; // bottom left
		}
	}
	if (prevx - 1 >= 0 && newy == prevy && newx == prevx - 1 && cell[newy][newx] >= 0)
	{
		if (whiteCheckTest(prevx - 1, prevy) == 1)
		{
			return 1; // left
		}
	}
	// castle right
	if (white == 0 && whiteRight == 0 && cell[7][5] == 0 && cell[7][6] == 0 && newy == 7 && newx == 6)
	{
		if (whiteCheckTest(4, 7) == 1 && whiteCheckTest(5, 7) == 1 && whiteCheckTest(6, 7) == 1)
		{
			cell[7][7] = 0;
			cell[7][5] = wRook;
			white = 1;
			whiteRight = 1;
			return 1;
		}
	}
	// castle left
	if (white == 0 && whiteLeft == 0 && cell[7][3] == 0 && cell[7][2] == 0 && cell[7][1] == 0 && newy == 7 && newx == 2)
	{
		if (whiteCheckTest(4, 7) == 1 && whiteCheckTest(3, 7) == 1 && whiteCheckTest(2, 7) == 1 && whiteCheckTest(1,7) == 1)
		{
			cell[7][0] = 0;
			cell[7][3] = wRook;
			white = 1;
			whiteLeft = 1;
			return 1;
		}
	}
	return 0;
}

int King::blackMove(int prevx, int prevy, int newx, int newy)
{
	if (prevx - 1 >= 0 && prevy - 1 >= 0 && newy == prevy - 1 && newx == prevx - 1 && cell[newy][newx] >= 0)
	{
		if (blackCheckTest(prevx - 1, prevy - 1) == 1)
		{
			return 1;  // top left
		}
	}
	if (prevy - 1 >= 0 && newx == prevx && newy == prevy - 1 && cell[newy][newx] >= 0)
	{

		if (blackCheckTest(prevx, prevy - 1) == 1)
		{
			return 1; // top
		}
	}
	if (prevy - 1 >= 0 && prevx + 1 < 8 && newx == prevx + 1 && newy == prevy - 1 && cell[newy][newx] >= 0)
	{
		if (blackCheckTest(prevx + 1, prevy - 1) == 1)
		{
			return 1; // rop right
		}
	}
	if (prevx + 1 < 8 && newy == prevy && newx == prevx + 1 && cell[newy][newx] >= 0)
	{
		if (blackCheckTest(prevx + 1, prevy) == 1)
		{
			return 1; // right
		}
	}
	if (prevx + 1 < 8 && prevy + 1 < 8 && newy == prevy + 1 && newx == prevx + 1 && cell[newy][newx] >= 0)
	{
		if (blackCheckTest(prevx + 1, prevy + 1) == 1)
		{
			return 1; // right bottom
		}
	}
	if (prevy + 1 < 8 && newy == prevy + 1 && newx == prevx && cell[newy][newx] >= 0)
	{
		if (blackCheckTest(prevx, prevy + 1))
		{
			return 1; // bottom
		}
	}
	if (prevx - 1 >= 0 && prevy + 1 < 8 && newx == prevx - 1 && newy == prevy + 1 && cell[newy][newx] >= 0)
	{
		if (blackCheckTest(prevx - 1, prevy + 1))
		{
			return 1; // bottom left
		}
	}
	if (prevx - 1 >= 0 && newy == prevy && newx == prevx - 1 && cell[newy][newx] >= 0)
	{
		if (blackCheckTest(prevx - 1, prevy) == 1)
		{
			return 1; // left
		}
	}
	// castle right
	if (black == 0 && blackRight == 0 && cell[7][5] == 0 && cell[7][6] == 0 && newy == 7 && newx == 6)
	{
		if (blackCheckTest(4, 7) == 1 && blackCheckTest(5, 7) == 1 && blackCheckTest(6, 7) == 1)
		{
			cell[7][7] = 0;
			cell[7][5] = bRook;
			black = 1;
			blackRight = 1;
			return 1;
		}
	}
	// castle left
	if (white == 0 && whiteLeft == 0 && cell[7][3] == 0 && cell[7][2] == 0 && cell[7][1] == 0 && newy == 7 && newx == 2)
	{
		if (blackCheckTest(4, 7) == 1 && blackCheckTest(3, 7) == 1 && blackCheckTest(2, 7) == 1 && blackCheckTest(1, 7) == 1)
		{
			cell[7][0] = 0;
			cell[7][3] = bRook;
			black = 1;
			blackLeft = 1;
			return 1;
		}
	}
	return 0;
}

