#pragma once
#include <stdlib.h>
#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define MAX_ORDER 99
#define END_OF_RUN -1

typedef enum{FALSE, TRUE} Boolean;

