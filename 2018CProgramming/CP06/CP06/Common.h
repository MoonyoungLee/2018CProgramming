#pragma once
#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)

typedef enum{FALSE, TRUE} Boolean;
