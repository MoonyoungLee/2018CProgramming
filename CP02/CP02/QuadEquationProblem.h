#pragma once
#include "Common.h"

typedef struct {
	float _root1;
	float _root2;
}Solution;

typedef struct {
	float _c0;
	float _c1;
	float _c2;
}QuadEquation;

typedef struct {
	QuadEquation _equation;
}QuadEquationProblem;

Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem aProblem);
Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem aProblem);
float QuadEquation_determinant(QuadEquationProblem aProblem);
Solution QuaEquationProblem_solve(QuadEquationProblem aProblem);


