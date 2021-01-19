#include "AppIO.h"

void AppIO_out(char* aMessage) {
	printf("%s", aMessage);
}
void AppIO_out_executionTime(int anOrder, double anExcutionTime) {
	printf("차수: %2d, 시간: %lf (마이크로 초)\n", anOrder, (double)anExcutionTime);
}