#pragma once

#define EPSILON 1.0E-6
#define FloatValueIsZero(NUMBER) (fabsf(NUMBER) < EPSILON)

typedef enum { FALSE, TRUE } Boolean;