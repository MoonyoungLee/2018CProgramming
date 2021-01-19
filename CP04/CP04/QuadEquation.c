#include "QuadEquation.h"


/*
* CP02 과제에서는 qeProblem._equation = equation으로 main 함수에서 객체의 속성값을 직접 변경했다면,
* CP04 과제에서는 QuadeEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation quadEquation) 함수를 통해
* main함수에서 직접 객체의 속성 값을 변경하는 일을 하지 않아도 된다.
*/
void QuadeEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation quadEquation)
{
	_this->_equation = quadEquation;
}
Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem* _this) {
	if (FloatValueIsZero(_this->_equation._c2)) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem* _this) {
	if (QuadEquationProblem_determinant(_this) < 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

QuadEquation QuadEquationProblem_equation(QuadEquationProblem* _this);
float QuadEquationProblem_determinant(QuadEquationProblem* _this) {
	return (_this->_equation._c1 * _this->_equation._c1) - ( 4 * _this->_equation._c2 * _this->_equation._c0);
}
Solution QuadEquationProblem_solve(QuadEquationProblem* _this) {
	Solution solution;
	float sqrtValue = sqrt(QuadEquationProblem_determinant(_this));
	solution._root1 = (-_this->_equation._c1 + sqrtValue) / (2 * _this->_equation._c2);
	solution._root2 = (-_this->_equation._c1 - sqrtValue) / (2 * _this->_equation._c2);
	return solution;
}