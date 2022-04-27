#include "Rook.h"

int Rook::move(int prevx, int prevy, int newx, int newy)
{
	for (int i = prevx - 1; i >= 0; i--)
	{
		if (cell[prevy][i] >= 0 && (newx == i && newy == prevy))
		{
			return 1;
		}
		else if (cell[prevy][i] != 0)
		{
			break;
		}
	}
	for (int i = prevy - 1; i >= 0; i--)
	{
		if (cell[i][prevx] >= 0 && (newy == i && newx == prevx))
		{
			return 1;
		}
		else if (cell[i][prevx] != 0)
		{
			break;
		}
	}
	for (int i = prevx + 1; i <= 7; i++)
	{
		if (cell[prevy][i] >= 0 && (newy == prevy && newx == i))
		{
			return 1;
		}
		else if (cell[prevy][i] != 0)
		{
			break;
		}
	}
	for (int i = prevy + 1; i <= 7; i++)
	{
		if (cell[i][prevx] >= 0 && (newy == i && newx == prevx))
		{
			return 1;
		}
		else if (cell[i][prevx] != 0)
		{
			break;
		}
	}
	return 0;
}

int Rook::check(int x, int y, int kx, int ky)
{
	for (int i = x - 1; i >= 0; i--) // top left
	{
		if (cell[y][i] >= 0 && (kx == i && ky == y))
		{
			return 1;
		}
		else if (cell[y][i] != 0)
		{
			break;
		}
	}
	for (int i = y - 1; i >= 0; i--) // top
	{
		if (cell[i][x] >= 0 && (ky == i && kx == x))
		{
			return 1;
		}
		else if (cell[i][x] != 0)
		{
			break;
		}
	}
	for (int i = x + 1; i < 8; i++) // top right
	{
		if (cell[y][i] >= 0 && (ky == y && kx == i))
		{
			return 1;
		}
		else if (cell[y][i] != 0)
		{
			break;
		}
	}
	for (int i = y + 1; i < 8; i++) // bottom
	{
		if (cell[i][x] >= 0 && (ky == i && kx == x))
		{
			return 1;
		}
		else if (cell[i][x] != 0)
		{
			break;
		}
	}
	return 0;
}