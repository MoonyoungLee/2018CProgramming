#pragma warning(disable:4996)
#include "AppIO.h"
#include "Common.h"
#include "float.h"
#include <math.h>

float LinearEquation_solve(float c0, float c1);

void main() {

	Boolean solvingIsRequested;
	float c0, c1;
	float root;

	AppIO_out_msg_startSolvingLinearEquation();
	// 문제 풀이 여부를 묻고 응답을 얻는다
	solvingIsRequested = AppIO_in_solvingIsRequested();
	while (solvingIsRequested) {
		// 일차 방정식의 계수를 입력 받는다.
		AppIO_in_linearEquation(&c0, &c1);
		// 일차방정식을 보여준다.
		AppIO_out_linearEquation(c0, c1);
		// 일차항의 계수가 0이면 일차항의 계수가 0이라는 메시지를 출력한다.
		if (FloatValueIsZero(c1)) {
			AppIO_out_firstOrderTermCoefficientIsZero();
		}
		else {
			// 일차항의 계수가 0이 아니면, 일차방정식을 푼다.
			root = LinearEquation_solve(c0, c1);
			// 일차방정식의 해를 출력한다.
			AppIO_out_root(root);
		}
		solvingIsRequested = AppIO_in_solvingIsRequested();
	}
	AppIO_out_msg_endSolvingLinearEquation();
	return 0;
}

float LinearEquation_solve(float c0, float c1) {
	if (FloatValueIsZero(c1)) {
		if (c1 * c0 >= 0.0) {
			return -FLT_MAX;
		}
		else {
			return +FLT_MAX;
		}
	}
	else {
		return (-c0) / c1;
	}
}