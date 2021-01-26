#pragma warning(disable:4996)
#include "AppController.h"

int main(void) {
	AppController* appController = AppController_new(appController);
	AppController_run(appController);
	AppController_delete(appController);
	return 0;
}