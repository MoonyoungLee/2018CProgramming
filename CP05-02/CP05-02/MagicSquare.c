#include "MagicSquare.h"

#define EMPTY_CELL -1

struct _MagicSquare{
	int _order;
	int _board[MAX_ORDER][MAX_ORDER];
};

typedef struct {
	int _row;
	int _col;
}CellLocation;

MagicSquare* MagicSquare_new(void) {
	MagicSquare* _this = NewObject(MagicSquare);
	return _this;
}

void MagicSquare_setOrder(MagicSquare* _this, int inputOrder) {
	_this->_order = inputOrder;
}

void MagicSquare_solve(MagicSquare* _this) {
	int order = _this->_order;
	CellLocation currentLoc, nextLoc;
	int cellValue = 1;
	int maxCellValue = order * order;

	// 마방진 초기화
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			_this->_board[i][j] = EMPTY_CELL;
		}
	}

	// 첫번째 위치
	currentLoc._row = 0;
	currentLoc._col = order / 2;
	_this->_board[currentLoc._row][currentLoc._col] = cellValue;

	for (cellValue = 2; cellValue <= maxCellValue; cellValue++) {
		nextLoc._row = currentLoc._row - 1;
		if (nextLoc._row < 0) {
			nextLoc._row = order - 1;
		}
		nextLoc._col = currentLoc._col + 1;
		if (nextLoc._col > order - 1) {
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

void MagicSquare_delete(MagicSquare* _this) {
	free(_this);
}