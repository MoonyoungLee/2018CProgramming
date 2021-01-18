#pragma warning(disable:4996)

#include "Common.h"
#include "AppIO.h"
#include "MagicSquare.h"
#include <stdio.h>

#define END_OF_RUN -1

void Main_showBoard(MagicSquare aMagicSquare, int aBoard[MAX_ORDER][MAX_ORDER]);

void main() {
	MagicSquare aMagicSquare;
	int aBoard[MAX_ORDER][MAX_ORDER];
	
	AppIO_out("<<< 마방진 풀이를 시작합니다 >>>\n\n");
	aMagicSquare._order = AppIO_in_order();
	while (aMagicSquare._order != END_OF_RUN) {
		if (MagicSqure_orderIsValid(aMagicSquare)) {
			MagicSquare_solve(aMagicSquare, aBoard);
			Main_showBoard(aMagicSquare, aBoard);
		}
		aMagicSquare._order = AppIO_in_order();
	}
	AppIO_out("\n<<< 마방진 풀이를 종료합니다 >>>\n");

	return 0;
}

void Main_showBoard(MagicSquare aMagicSquare, int aBoard[MAX_ORDER][MAX_ORDER]) {
	printf(">MagicSquareBoard: order %d\n", aMagicSquare._order);
	printf("    ");
	for (int i = 0; i < aMagicSquare._order; i++) {
		printf(" [%2d]", i);
	}
	printf("\n");
	for (int i = 0; i < aMagicSquare._order; i++) {
		printf("[%2d]", i);
		for (int j = 0; j < aMagicSquare._order; j++) {
			printf(" %4d", aBoard[i][j]);
		}
		printf("\n");
	}
}