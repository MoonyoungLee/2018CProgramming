#include "Timer.h"
#include <Windows.h>

struct _Timer{
	LARGE_INTEGER _frequency;
	LARGE_INTEGER _startCounter;
	LARGE_INTEGER _stopCounter;
};
