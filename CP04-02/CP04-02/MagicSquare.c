#include "Common.h"
#include "MagicSquare.h"
#include "AppIO.h"
#include <stdio.h>

#define EMPTY_CELL -1

typedef struct {
	int _row;
	int _col;
}CellLocation;

void MagicSquare_setOrder(MagicSquare* _this, int newOrder) {
	_this->_order = newOrder;
}

Boolean MagicSqure_orderIsValid(MagicSquare* _this) {

	if (_this->_order < 3) {
		AppIO_out("[오류]: 차수가 너무 작습니다. 3보다 크거나 같아야 합니다\n");
		return FALSE;
	}
	else if (_this->_order > MAX_ORDER) {
		char messageBuffer[255];
		sprintf(messageBuffer, "[오류]: 차수가 너무 큽니다. %d보다 작아야 합니다.\n", MAX_ORDER);
		AppIO_out(messageBuffer);
		return FALSE;
	}
	else if (_this->_order % 2 == 0) {
		AppIO_out("[오류]: 차수가 짝수입니다. 홀수이어야 합니다.\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void MagicSquare_solve(MagicSquare*_this) {
	CellLocation currentLoc;
	CellLocation nextLoc;
	int row, col = 0;

	// board initialization
	for (row = 0; row < _this->_order; row++) {
		for (col = 0; col < _this->_order; col++) {
			_this->_board[row][col] = EMPTY_CELL;
		}
	}

	int cellValue = 1;
	currentLoc._row = 0;
	currentLoc._col = _this->_order / 2;
	_this->_board[currentLoc._row][currentLoc._col] = cellValue;
	int maxCellValue = _this->_order * _this->_order;
	for (cellValue = 2; cellValue <= maxCellValue; cellValue++) {
		nextLoc._row = currentLoc._row - 1;
		if (nextLoc._row < 0) {
			nextLoc._row = _this->_order - 1;
		}
		nextLoc._col = currentLoc._col + 1;
		if (nextLoc._col >= _this->_order) {
			nextLoc._col = 0;
		}

		if (_this->_board[nextLoc._row][nextLoc._col] != EMPTY_CELL) {
			nextLoc._row = currentLoc._row + 1;
			nextLoc._col = currentLoc._col;
		}

		_this->_board[nextLoc._row][nextLoc._col] = cellValue;
		currentLoc = nextLoc;
	}
}