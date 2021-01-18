#include "AppIO.h"

void AppIO_out(char* aMessage) {
	printf("%s\n", aMessage);
}

int AppIO_in_order(void) {
	int anOrder;
	scanf("%d", &anOrder);
	return anOrder;
}