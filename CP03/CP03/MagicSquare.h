#pragma once
#include "Common.h"

typedef struct {
	int _order;
	int _board[MAX_ORDER][MAX_ORDER];
}MagicSquare;

Boolean MagicSqure_orderIsValid(MagicSquare aMagicSquare);
void MagicSquare_solve(MagicSquare aMagicSquare, int aBoard[MAX_ORDER][MAX_ORDER]);

