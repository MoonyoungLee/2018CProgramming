#include "AppController.h"
#include "MagicSquare.h"
#include "AppIO.h"
#include <stdio.h>

struct _AppController {
	int object;
};

void AppController_showMain(AppController* _this, MagicSquare* magicSquare);

AppController* AppController_new(void) {
	AppController* _this;
	_this = NewObject(AppController);
	return _this;
}
void AppController_run(AppController* _this) 
{
	AppIO_out("<<< 마방진 풀이를 시작합니다 >>>\n");
	int inputOrder = AppIO_in_order();
	MagicSquare* magicSquare = MagicSquare_new();
	while (inputOrder != END_OF_RUN) {
		MagicSquare_setOrder(magicSquare, inputOrder);
		if (MagicSquare_orderIsValid(magicSquare)) {
			MagicSquare_solve(magicSquare);
			AppController_showMain(_this, magicSquare);
		}
		inputOrder = AppIO_in_order();
	}
	MagicSquare_delete(magicSquare);
	AppIO_out("\n<<< 마방진 풀이를 종료합니다 >>>\n\n");
}

void AppController_showMain(AppController* _this, MagicSquare* magicSquare)
{
	char messageBuffer[255];
	int order = MagicSquare_order(magicSquare);
	sprintf(messageBuffer, "Magic Square Board: Order %2d\n", order);
	AppIO_out(messageBuffer);
	AppIO_out("    ");
	for (int i = 0; i < order; i++) {
		printf(" [%2d]", i);
	}
	AppIO_out("\n");

	for (int i = 0; i < order; i++) {
		printf(" [%2d]", i);
		for (int j = 0; j < order; j++) {
			printf("%5d", MagicSquare_cell(magicSquare, i, j));
		}
		printf("\n");
	}
}

void AppController_delete(AppController* _this) {
	free(_this);
}