#include "MagicSquare.h"
#include "AppIO.h"
#define EMPTY_CELL -1

struct _MagicSquare {
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

int MagicSquare_order(MagicSquare* _this) {
	return _this->_order;
}

Boolean MagicSquare_orderIsValid(MagicSquare* _this) {
	if (_this->_order < 3) {
		AppIO_out("[����] ������ �ʹ� �۽��ϴ�. 3���� ũ�ų� ���ƾ��մϴ�.\n\n");
		return FALSE;
	}
	else if (_this->_order % 2 == 0) {
		AppIO_out("[����] ������ ¦���Դϴ�. Ȧ���̾���մϴ�.\n\n");
		return FALSE;
	}
	else if (_this->_order > MAX_ORDER) {
		AppIO_out("[����] ������ �ʹ� Ů�ϴ�. 99���� �۰ų� ���ƾ��մϴ�.\n\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void MagicSquare_solve(MagicSquare* _this) {
	int order = _this->_order;
	CellLocation currentLoc, nextLoc;
	int cellValue = 1;
	int maxCellValue = order * order;

	// ������ �ʱ�ȭ
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			_this->_board[i][j] = EMPTY_CELL;
		}
	}

	// ù��° ��ġ
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

int MagicSquare_cell(MagicSquare* _this, int row, int col) {
	if (0 <= row && row <= _this->_order && 0 <= col && _this->_order >= col) {
		return _this->_board[row][col];
	}
	else {
		return -1;
	}
}

void MagicSquare_delete(MagicSquare* _this) {
	free(_this);
}
