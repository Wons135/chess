#include "Board.h"
#include <iostream>

//Global variable board stores the starting stte of a chessgame
//0 = empty space
//1 = White King
//2 = White Queen
//3 = White Rook
//4 = White Knight
//5= White Bishop
//6= White Pawn
//7= Black king
//8= Black Queen
//9= Black Rook
//10 = Black Knight
//11 = Black Bishop
//12 - Black Pawn
//Global variable board stores the starting stte of a chessgame

int cell[8][8] =
{
9, 10, 11, 8, 7, 11, 10, 9,
12, 12, 12, 12, 12, 12, 12, 12,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
6, 6, 6, 6, 6, 6, 6, 6,
3, 4, 5, 2, 1, 5, 4, 3,
};