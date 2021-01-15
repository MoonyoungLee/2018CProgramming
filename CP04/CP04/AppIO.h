#pragma once
#include "Common.h"

void AppIO_out_msg_startSolvingQuadEquation(void);
void AppIO_out_msg_endSolvingQuadEquation(void);

Boolean AppIO_in_solvingIsRequested(void);
void AppIO_in_quadEquation(float* c0, float* c1, float* c2);

void AppIO_out_msg_secondOrderTermCoefficientIsZero(void);
void AppIO_out_msg_determinantIsNegative(float determinant);
void AppIO_out_quadEquation(float c0, float c1, float c2);
void AppIO_out_solution(Solution solution);