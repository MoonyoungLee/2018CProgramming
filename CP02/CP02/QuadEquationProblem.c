#include "QuadEquationProblem.h"

// ������������ 2������ 0������ �Ǵ��Ѵ�
Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem aProblem)
{
	if (FloatValueIsZero(aProblem._equation._c2)) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// ������������ �Ǻ����� ���������� �Ǻ��Ѵ�
Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem aProblem)
{
	if (QuadEquation_determinant(aProblem) < 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// ������������ �Ǻ����� ���� ����Ͽ� ��ȯ�Ѵ�
float QuadEquation_determinant(QuadEquationProblem aProblem) {
	float determinant = (aProblem._equation._c1 * aProblem._equation._c1) - (4 * aProblem._equation._c2 * aProblem._equation._c0);
	return determinant;
}

// ������������ �ظ� ��ȯ�Ѵ�
Solution QuaEquationProblem_solve(QuadEquationProblem aProblem){
	Solution solution;
	float determinant = QuadEquation_determinant(aProblem);
	float sqrtvalue = sqrt(determinant);
	solution._root1 = (-aProblem._equation._c1 + sqrtvalue) / (2.0 * aProblem._equation._c2);
	solution._root2 = (-aProblem._equation._c1 - sqrtvalue) / (2.0 * aProblem._equation._c2);

	return solution;
}