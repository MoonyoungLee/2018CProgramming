#pragma once
#include "Common.h"

typedef struct {
	int _order;
	int _board[MAX_ORDER][MAX_ORDER];
}MagicSquare;

void MagicSquare_setOrder(MagicSquare* _this, int newOrder);
Boolean MagicSqure_orderIsValid(MagicSquare* _this);
void MagicSquare_solve(MagicSquare* _this);

