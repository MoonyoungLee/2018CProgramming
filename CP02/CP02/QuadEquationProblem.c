#include "QuadEquationProblem.h"

// 이차방정식의 2차항이 0인지를 판단한다
Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem aProblem)
{
	if (FloatValueIsZero(aProblem._equation._c2)) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// 이차방정식의 판별식이 음수인지를 판별한다
Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem aProblem)
{
	if (QuadEquation_determinant(aProblem) < 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// 이차방정식의 판별식을 값을 계산하여 반환한다
float QuadEquation_determinant(QuadEquationProblem aProblem) {
	float determinant = (aProblem._equation._c1 * aProblem._equation._c1) - (4 * aProblem._equation._c2 * aProblem._equation._c0);
	return determinant;
}

// 이차방정식의 해를 반환한다
Solution QuaEquationProblem_solve(QuadEquationProblem aProblem){
	Solution solution;
	float determinant = QuadEquation_determinant(aProblem);
	float sqrtvalue = sqrt(determinant);
	solution._root1 = (-aProblem._equation._c1 + sqrtvalue) / (2.0 * aProblem._equation._c2);
	solution._root2 = (-aProblem._equation._c1 - sqrtvalue) / (2.0 * aProblem._equation._c2);

	return solution;
}