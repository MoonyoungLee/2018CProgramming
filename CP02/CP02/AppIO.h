#pragma once
#include "Common.h"

void AppIO_out_msg_startSolvingQuadEquation(void);
void AppIO_out_msg_endSolvingQuadEquation(void);
void AppIO_out_quadEquation(float c0, float c1, float c2);
void AppIO_out_msg_secondOrderTermCoefficientIsZero(void);
void AppIO_out_msg_determinantIsNegative(float determinant);
void AppIO_out_solution(float root1, float root2);

Boolean AppIO_in_solvingIsRequested(void);
void AppIO_in_QuadEquation(float* p_c0, float* p_c1, float* p_c2);