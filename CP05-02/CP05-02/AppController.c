#include "Common.h"
#include "AppController.h"

struct _AppController{
	int object;
};

AppController* AppController_new(void) {
	AppController* _this = NewObject(AppController);
	return _this;
}

void AppController_run(AppController* _this);
void AppController_delete(AppController* _this)
{
	free(_this);
}