#include "MagicSquare.h"
#include "AppIO.h"
#include <stdio.h>

#define EMPTY_CELL -1

typedef struct {
	int _row;
	int _col;
}CellLocation;


Boolean MagicSqure_orderIsValid(int inputOrder){
	
	if (inputOrder < 3) {
		AppIO_out("[오류]: 차수가 너무 작습니다. 3보다 크거나 같아야 합니다\n");
		return FALSE;
	}else if (inputOrder > MAX_ORDER) {
		char messageBuffer[255];
		sprintf(messageBuffer, "[오류]: 차수가 너무 큽니다. %d보다 작아야 합니다.\n", MAX_ORDER);
		AppIO_out(messageBuffer);
		return FALSE;
	}else if (inputOrder % 2 == 0) {
		AppIO_out("[오류]: 차수가 짝수입니다. 홀수이어야 합니다.\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void MagicSquare_solve(int inputOrder, int aBoard[MAX_ORDER][MAX_ORDER]) {
	CellLocation currentLoc;
	CellLocation nextLoc;
	int row, col = 0;

	// board initialization
	for (row = 0; row < inputOrder; row++) {
		for (col = 0; col < inputOrder; col++) {
			aBoard[row][col] = EMPTY_CELL;
		}
	}

	int cellValue = 1;
	currentLoc._row = 0;
	currentLoc._col = inputOrder / 2;
	aBoard[currentLoc._row][currentLoc._col] = cellValue;
	int maxCellValue = inputOrder * inputOrder;
	for (cellValue = 2; cellValue <= maxCellValue; cellValue++) {
		nextLoc._row = currentLoc._row - 1;
		if (nextLoc._row < 0) {
			nextLoc._row = inputOrder - 1;
		}
		nextLoc._col = currentLoc._col + 1;
		if (nextLoc._col >= inputOrder) {
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