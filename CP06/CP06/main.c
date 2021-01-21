#pragma warning(disable:4996)
#include "AppController.h"

int main(void) {
	AppController* appcontroller = AppController_new();
	AppController_run(appcontroller);
	AppController_delete(appcontroller);
	return 0;
}