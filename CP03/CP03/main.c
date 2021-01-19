#pragma warning(disable:4996)

#include "Common.h"
#include "AppIO.h"
#include "MagicSquare.h"
#include <stdio.h>

#define END_OF_RUN -1

void Main_showBoard(int inputOrder, int aBoard[MAX_ORDER][MAX_ORDER]);

void main() {
	int inputOrder;
	int board[MAX_ORDER][MAX_ORDER];
	
	AppIO_out("<<< 마방진 풀이를 시작합니다 >>>\n\n");
	inputOrder = AppIO_in_order();
	while (inputOrder != END_OF_RUN) {
		if (MagicSqure_orderIsValid(inputOrder)) {
			MagicSquare_solve(inputOrder, board);
			Main_showBoard(inputOrder, board);
		}
		inputOrder = AppIO_in_order();
	}
	AppIO_out("\n<<< 마방진 풀이를 종료합니다 >>>\n");

	return 0;
}

void Main_showBoard(int inputOrder, int aBoard[MAX_ORDER][MAX_ORDER]) {
	printf(">MagicSquareBoard: order %d\n", inputOrder);
	printf("    ");
	for (int i = 0; i < inputOrder; i++) {
		printf(" [%2d]", i);
	}
	printf("\n");
	for (int i = 0; i < inputOrder; i++) {
		printf("[%2d]", i);
		for (int j = 0; j < inputOrder; j++) {
			printf(" %4d", aBoard[i][j]);
		}
		printf("\n");
	}
}