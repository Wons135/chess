#include "Bishop.h"
#include <iostream>

int Bishop::move(int prevx, int prevy, int newx, int newy)
{
	int j = prevx - 1;
	for (int i = prevy - 1; i >= 0; i--)
	{
		if (cell[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (cell[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = prevx + 1;
	for (int i = prevy - 1; i >= 0; i--)
	{
		if (cell[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (cell[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = prevx - 1;
	for (int i = prevy + 1; i <= 7; i++)
	{
		if (cell[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (cell[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = prevx + 1;
	for (int i = prevy + 1; i <= 7; i++)
	{
		if (cell[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (cell[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Bishop::check(int x, int y, int kx, int ky)
{
	int j = x - 1;
	for (int i = y - 1; i >= 0; i--)
	{
		if (cell[i][j] >= 0 && (ky == i && kx == j))
		{
			return 1;
		}
		else if (cell[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = x + 1;
	for (int i = y - 1; i >= 0; i--)
	{
		if (cell[i][j] >= 0 && (ky == i && kx == j))
		{
			return 1;
		}
		else if (cell[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = x - 1;
	for (int i = y + 1; i <= 7; i++)
	{
		if (cell[i][j] >= 0 && (ky == i && kx == j))
		{
			return 1;
		}
		else if (cell[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = x + 1;
	for (int i = y + 1; i <= 7; i++)
	{
		if (cell[i][j] >= 0 && (ky == i && kx == j))
		{
			return 1;
		}
		else if (cell[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}



