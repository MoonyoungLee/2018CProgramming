#include "MagicSquare.h"
#include "AppIO.h"
#include <stdio.h>

#define EMPTY_CELL -1

typedef struct {
	int _row;
	int _col;
}CellLocation;


Boolean MagicSqure_orderIsValid(MagicSquare aMagicSquare){
	
	if (aMagicSquare._order < 3) {
		AppIO_out("[����]: ������ �ʹ� �۽��ϴ�. 3���� ũ�ų� ���ƾ� �մϴ�\n");
		return FALSE;
	}else if (aMagicSquare._order > MAX_ORDER) {
		char messageBuffer[255];
		sprintf(messageBuffer, "[����]: ������ �ʹ� Ů�ϴ�. %d���� �۾ƾ� �մϴ�.\n", MAX_ORDER);
		AppIO_out(messageBuffer);
		return FALSE;
	}else if (aMagicSquare._order % 2 == 0) {
		AppIO_out("[����]: ������ ¦���Դϴ�. Ȧ���̾�� �մϴ�.\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void MagicSquare_solve(MagicSquare* aMagicSquare, int aBoard[MAX_ORDER][MAX_ORDER]) {
	CellLocation currentLoc;
	CellLocation nextLoc;
	int row, col = 0;

	// board initialization
	for (row = 0; row < aMagicSquare->_order; row++) {
		for (col = 0; col < aMagicSquare->_order; col++) {
			aMagicSquare->_board[row][col] = EMPTY_CELL;
		}
	}

	int cellValue = 1;
	currentLoc._row = 0;
	currentLoc._col = aMagicSquare->_order / 2;
	aMagicSquare->_board[currentLoc._row][currentLoc._col] = cellValue;
	int maxCellValue = aMagicSquare->_order * aMagicSquare->_order;
	for (cellValue = 2; cellValue <= maxCellValue; cellValue++) {
		nextLoc._row = currentLoc._row - 1;
		if (nextLoc._row < 0) {
			nextLoc._row = aMagicSquare->_order - 1;
		}
		nextLoc._col = currentLoc._col + 1;
		if (nextLoc._col >= aMagicSquare->_order) {
			nextLoc._col = 0;
		}

		if (aMagicSquare->_board[nextLoc._row][nextLoc._col] != EMPTY_CELL) {
			nextLoc._row = currentLoc._row + 1;
			nextLoc._col = currentLoc._col;
		}

		aMagicSquare->_board[nextLoc._row][nextLoc._col] = cellValue;
		currentLoc = nextLoc;
	}
}