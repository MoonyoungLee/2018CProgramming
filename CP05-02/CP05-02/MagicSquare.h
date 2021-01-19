#pragma once
#include "Common.h"

typedef struct _MagicSquare MagicSquare;

MagicSquare* MagicSquare_new(void);
void MagicSquare_setOrder(MagicSquare* _this, int inputOrder);
void MagicSquare_solve(MagicSquare* _this);
void MagicSquare_delete(MagicSquare* _this);