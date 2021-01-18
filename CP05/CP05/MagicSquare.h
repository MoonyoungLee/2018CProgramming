#pragma once
#include "Common.h"

typedef struct _MagicSquare MagicSquare;

MagicSquare* MagicSquare_new(void);
void MagicSquare_setOrder(MagicSquare* _this, int inputOrder);
Boolean MagicSquare_orderIsValid(MagicSquare* _this);
void MagicSquare_solve(MagicSquare* _this);
void MagicSquare_delete(MagicSquare* _this);
int MagicSquare_order(MagicSquare* _this);
int MagicSquare_cell(MagicSquare* _this, int row, int col);

