#include "QuadEquation.h"

void QuadeEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation quadEquation)
{
	_this->_equation._c2 = quadEquation._c2;
	_this->_equation._c1 = quadEquation._c1;
	_this->_equation._c0 = quadEquation._c0;
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