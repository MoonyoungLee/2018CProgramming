#include "AppIO.h"

void AppIO_out(char* aMessage) {
	printf("%s", aMessage);
}
void AppIO_out_executionTime(int anOrder, double anExcutionTime) {
	printf("����: %2d, �ð�: %lf (����ũ�� ��)\n", anOrder, (double)anExcutionTime);
}