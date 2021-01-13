#pragma once
#include "Common.h"

void AppIO_out_msg_startSolvingLinearEquation(void);
void AppIO_out_msg_endSolvingLinearEquation(void);
void AppIO_out_linearEquation(float c0, float c1);
void AppIO_out_root(float root);
void AppIO_out_firstOrderTermCoefficientIsZero(void);

Boolean AppIO_in_solvingIsRequested(void);
void AppIO_in_linearEquation(float* p_c0, float* p_c1);