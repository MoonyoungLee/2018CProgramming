#pragma once
#include "Common.h"

void QuadeEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation quadEquation);
Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem* _this);
Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem* _this);

QuadEquation QuadEquationProblem_equation(QuadEquationProblem* _this);
float QuadEquationProblem_determinant(QuadEquationProblem* _this);
Solution QuadEquationProblem_solve(QuadEquationProblem* _this);