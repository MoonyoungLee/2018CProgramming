#include "AppIO.h"
#include <stdio.h>

void AppIO_out(char* aMessage) {
	printf("%s", aMessage);
}

int AppIO_in_order(void){
	int anOrder;
	AppIO_out("? 마방진 차수를 입력하시오: ");
	scanf("%d", &anOrder);
	return anOrder;
}