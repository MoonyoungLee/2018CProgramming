#include "AppController.h"
#include "AppIO.h"
#include "Ban.h"

#define MAX_NUMBER_OF_STUDENTS 100

struct _AppController{
	Ban* _ban;
};

AppController* AppController_new(void) {
	AppController* _this = NewObject(AppController);
	return _this;
}

void AppController_run(AppController* _this);

void AppController_delete(AppController* _this) {
	free(_this);
}