#include "AppIO.h"

void AppIO_out(char* aMessage) {
	printf("%s\n", aMessage);
}

int AppIO_in_order(void) {
	int anOrder;
	printf("> 마방진의 차수를 입력하시오: ");
	scanf("%d", &anOrder);
	return anOrder;
}