#pragma once
#include "Common.h"

typedef struct {
	int _order;
	int _board[MAX_ORDER][MAX_ORDER];
}MagicSquare;

Boolean MagicSqure_orderIsValid(int inputOrder);
void MagicSquare_solve(int inputOrder, int aBoard[MAX_ORDER][MAX_ORDER]);

