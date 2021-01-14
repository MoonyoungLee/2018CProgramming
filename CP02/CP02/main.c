#pragma warning(disable:4996) 
#include "Common.h"
#include "QuadEquationProblem.h"
#include "AppIO.h"

void main() {
	QuadEquationProblem qeProblem;
	Boolean solvingIsRequested;
	Solution solution;

	AppIO_out_msg_startSolvingQuadEquation();
	solvingIsRequested = AppIO_in_solvingIsRequested();
	while(solvingIsRequested) {
		AppIO_in_QuadEquation(&qeProblem.equation._c0, &qeProblem.equation._c1, &qeProblem.equation._c2);
		AppIO_out_quadEquation(qeProblem.equation._c0, qeProblem.equation._c1, qeProblem.equation._c2);
		if (QuadEquationProblem_secondOrderTermCoefficientIsZero(qeProblem)) {
			AppIO_out_msg_secondOrderTermCoefficientIsZero();
		}
		else {
			if (QuadEquationProblem_determinantIsNegative(qeProblem)) {
				float determinant = QuadEquation_determinant(qeProblem);
				AppIO_out_msg_determinantIsNegative(determinant);
			}
			else {
				solution = QuaEquationProblem_solve(qeProblem);
				AppIO_out_solution(solution._root1, solution._root2);
			}
		}
		solvingIsRequested = AppIO_in_solvingIsRequested();
	}

	AppIO_out_msg_endSolvingQuadEquation();
	return 0;
}