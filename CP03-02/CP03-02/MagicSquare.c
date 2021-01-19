#include "Common.h"
#include "MagicSquare.h"
#include "AppIO.h"
#include <stdio.h>

#define EMPTY_CELL -1

typedef struct {
	int _row;
	int _col;
}CellLocation;


Boolean MagicSqure_orderIsValid(MagicSquare magicSquare) {

	if (magicSquare._order < 3) {
		AppIO_out("[����]: ������ �ʹ� �۽��ϴ�. 3���� ũ�ų� ���ƾ� �մϴ�\n");
		return FALSE;
	}
	else if (magicSquare._order > MAX_ORDER) {
		char messageBuffer[255];
		sprintf(messageBuffer, "[����]: ������ �ʹ� Ů�ϴ�. %d���� �۾ƾ� �մϴ�.\n", MAX_ORDER);
		AppIO_out(messageBuffer);
		return FALSE;
	}
	else if (magicSquare._order % 2 == 0) {
		AppIO_out("[����]: ������ ¦���Դϴ�. Ȧ���̾�� �մϴ�.\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void MagicSquare_solve(MagicSquare magicSquare, int aBoard[MAX_ORDER][MAX_ORDER]) {
	CellLocation currentLoc;
	CellLocation nextLoc;
	int row, col = 0;

	// board initialization
	for (row = 0; row < magicSquare._order; row++) {
		for (col = 0; col < magicSquare._order; col++) {
			aBoard[row][col] = EMPTY_CELL;
		}
	}

	int cellValue = 1;
	currentLoc._row = 0;
	currentLoc._col = magicSquare._order / 2;
	aBoard[currentLoc._row][currentLoc._col] = cellValue;
	int maxCellValue = magicSquare._order * magicSquare._order;
	for (cellValue = 2; cellValue <= maxCellValue; cellValue++) {
		nextLoc._row = currentLoc._row - 1;
		if (nextLoc._row < 0) {
			nextLoc._row = magicSquare._order - 1;
		}
		nextLoc._col = currentLoc._col + 1;
		if (nextLoc._col >= magicSquare._order) {
			nextLoc._col = 0;
		}

		if (aBoard[nextLoc._row][nextLoc._col] != EMPTY_CELL) {
			nextLoc._row = currentLoc._row + 1;
			nextLoc._col = currentLoc._col;
		}

		aBoard[nextLoc._row][nextLoc._col] = cellValue;
		currentLoc = nextLoc;
	}
}