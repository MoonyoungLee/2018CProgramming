#pragma warning(disable:4996)
#include "Common.h"
#include "AppIO.h"
#include "MagicSquare.h"
#include <stdio.h>

#define END_OF_RUN -1

void Main_showBoard(MagicSquare* _this);

int main(void) {
	MagicSquare magicSquare;

	AppIO_out("<<< 마방진 풀이를 시작합니다 >>>\n\n");
	int inputOrder = AppIO_in_order();
	while (inputOrder != END_OF_RUN) {
		MagicSquare_setOrder(&magicSquare, inputOrder);
		if (MagicSqure_orderIsValid(&magicSquare)) {
			MagicSquare_solve(&magicSquare);
			Main_showBoard(&magicSquare);
		}
		inputOrder = AppIO_in_order();
	}
	AppIO_out("\n<<< 마방진 풀이를 종료합니다 >>>\n");
	return 0;
}

void Main_showBoard(MagicSquare* _this) {
	printf(">MagicSquareBoard: order %d\n", _this->_order);
	printf("    ");
	for (int i = 0; i < _this->_order; i++) {
		printf(" [%2d]", i);
	}
	printf("\n");
	for (int i = 0; i < _this->_order; i++) {
		printf("[%2d]", i);
		for (int j = 0; j < _this->_order; j++) {
			printf(" %4d", _this->_board[i][j]);
		}
		printf("\n");
	}
}