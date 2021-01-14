#pragma once
#include <math.h>
#define MAXFLOAT 1.0E+100
#define EPSILON 1.0E-6
#define FloatValueIsZero(NUMBER) (fabsf(NUMBER) < EPSILON)

typedef enum{FALSE, TRUE} Boolean;