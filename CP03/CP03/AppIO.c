#include "AppIO.h"
#include <stdio.h>

void AppIO_out(char* aMessage) {
	printf("%s", aMessage);
}

int AppIO_in_order(void){
	int anOrder;
	AppIO_out("? ������ ������ �Է��Ͻÿ�: ");
	scanf("%d", &anOrder);
	return anOrder;
}