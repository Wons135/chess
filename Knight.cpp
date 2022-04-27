#include "Knight.h"
#include <iostream>


int Knight::move(int prevx, int prevy, int newx, int newy)
{
	if (prevy - 2 >= 0 && prevx - 1 >= 0 && newy == prevy - 2 && newx == prevx - 1 && cell[newy][newx] >= 0)
	{
		return 1;
	}
	if (prevy - 2 >= 0 && prevx + 1 < 8 && newy == prevy - 2 && newx == prevx + 1 && cell[newy][newx] >= 0)
	{
		return 1;
	}
	if (prevy - 1 >= 0 && prevx + 2 < 8 && newy == prevy - 1 && newx == prevx + 2 && cell[newy][newx] >= 0)
	{
		return 1;
	}
	if (prevy + 1 >= 0 && prevx + 2 < 8 && newy == prevy + 1 && newx == prevx + 2 && cell[newy][newx] >= 0)
	{
		return 1;
	}
	if (prevy + 2 < 8 && prevx + 1 < 8 && newy == prevy + 2 && newx == prevx + 1 && cell[newy][newx] >= 0)
	{
		return 1;
	}
	if (prevy + 2 < 8 && prevx - 1 >= 0 && newy == prevy + 2 && newx == prevx - 1 && cell[newy][newx] >= 0)
	{
		return 1;
	}
	if (prevy + 1 < 8 && prevx - 2 >= 0 && newy == prevy + 1 && newx == prevx - 2 && cell[newy][newx] >= 0)
	{
		return 1;
	}
	if (prevy - 1 >= 0 && prevx - 2 >= 0 && newy == prevy - 1 && newx == prevx - 2 && cell[newy][newx] >= 0)
	{
		return 1;
	}
	return 0;
}

int Knight::check(int ox, int y, int kx, int ky)
{
	if (y - 2 >= 0 && ox - 1 >= 0 && ky == y - 2 && kx == ox - 1 && cell[ky][kx] >= 0)
	{
		return 1; // left top
	}
	if (y - 2 >= 0 && ox + 1 < 8 && ky == y - 2 && kx == ox + 1 && cell[ky][kx] >= 0)
	{
		return 1; // right top
	}
	if (y - 1 >= 0 && ox + 2 < 8 && ky == y - 1 && kx == ox + 2 && cell[ky][kx] >= 0)
	{
		return 1; // right 1
	}
	if (y + 1 >= 0 && ox + 2 < 8 && ky == y + 1 && kx == ox + 2 && cell[ky][kx] >= 0)
	{
		return 1; // right 2
	}
	if (y + 2 < 8 && ox + 1 < 8 && ky == y + 2 && kx == ox + 1 && cell[ky][kx] >= 0)
	{
		return 1; // bottom 1
	}
	if (y + 2 < 8 && ox - 1 >= 0 && ky == y + 2 && kx == ox - 1 && cell[ky][kx] >= 0)
	{
		return 1; //bottom 2
	}
	if (y + 1 < 8 && ox - 2 >= 0 && ky == y + 1 && kx == ox - 2 && cell[ky][kx] >= 0)
	{
		return 1; // left 1
	}
	if (y - 1 >= 0 && ox - 2 >= 0 && ky == y - 1 && kx == ox - 2 && cell[ky][kx] >= 0)
	{
		return 1;
	}
	return 0;
}