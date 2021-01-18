#pragma warnings(disable:4996)
#include "Common.h"
#include "AppIO.h"
#include "QuadEquation.h"


int main(void) {
	QuadEquationProblem qeProblem;
	QuadEquation equation;
	Solution solution;
	Boolean solvingIsRequested;

	AppIO_out_msg_startSolvingQuadEquation();
	solvingIsRequested = AppIO_in_solvingIsRequested();
	while (solvingIsRequested) {
		AppIO_in_quadEquation(&equation._c0, &equation._c1, &equation._c2);
		QuadeEquationProblem_setEquation(&qeProblem, equation);
		AppIO_out_quadEquation(equation._c0, equation._c1, equation._c2);
		if (QuadEquationProblem_secondOrderTermCoefficientIsZero(&qeProblem)) {
			AppIO_out_msg_secondOrderTermCoefficientIsZero();
		}
		else {
			if (QuadEquationProblem_determinantIsNegative(&qeProblem)) {
				float determinant = QuadEquationProblem_determinant(&qeProblem);
				AppIO_out_msg_determinantIsNegative(determinant);
			}
			else {
				solution = QuadEquationProblem_solve(&qeProblem);
				AppIO_out_solution(solution);
			}
		}
		solvingIsRequested = AppIO_in_solvingIsRequested();
	}
	AppIO_out_msg_endSolvingQuadEquation();
	return 0;
}