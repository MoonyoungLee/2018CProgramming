#include "Common.h"
#include "AppController.h"
#include "MagicSquare.h"
#include "Timer.h"
#include "AppIO.h"

struct _AppController{
	int object;
};

AppController* AppController_new(void) {
	AppController* _this = NewObject(AppController);
	return _this;
}

void AppController_run(AppController* _this) {
	MagicSquare* magicSquare;
	int order, count;
	Timer* timer;
	double executionTime;

	timer = Timer_new();
	AppIO_out("<<< ������ Ǯ���� ���� ������ �����մϴ� >>>\n\n");
	AppIO_out("�ϳ��� ������ ���� 100ȸ �ݺ� ������ �ð��� �����մϴ�.\n");

	for (order = 9; order <= MAX_ORDER; order += 10) {
		Timer_start(timer);
		for (count = 0; count < 100; count++) {
			magicSquare = MagicSquare_new();
			MagicSquare_setOrder(magicSquare, order);
			MagicSquare_solve(magicSquare);
			MagicSquare_delete(magicSquare);
		}
		Timer_stop(timer);
		executionTime = Timer_duration(timer);
		AppIO_out_executionTime(order, executionTime);
	}
	Timer_delete(timer);
	AppIO_out("<<< ���� ������ ��Ĩ�ϴ� >>>\n");

}
void AppController_delete(AppController* _this)
{
	free(_this);
}