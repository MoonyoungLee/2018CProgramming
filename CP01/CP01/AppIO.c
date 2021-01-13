#include <stdio.h>
#include "AppIO.h"

void AppIO_out_msg_startSolvingLinearEquation(void) {
	printf("<<< 일차방정식 풀이를 시작합니다 >>>");
}

void AppIO_out_msg_endSolvingLinearEquation(void) {
	printf("<<< 일차방정식 풀이를 종료합니다 >>>");
}

void AppIO_out_linearEquation(float c0, float c1) {
	printf(">주어진 방정식: (%f)x + (%f) = 0 \n", c1, c0);
}

void AppIO_out_root(float root) {
	printf(">방정식의 해는 다음과 같습니다\n");
	printf("x = %f\n", root);
}
void AppIO_out_firstOrderTermCoefficientIsZero(void) {
	printf("[오류] 1차항의 계수가 0이어서, 문제를 풀 수 없습니다.\n");
}

Boolean AppIO_in_solvingIsRequested(void) {
	char answer;
	printf("방정식을 풀려면 'y', 풀이를 종료하려면 다른 아무키나 치시오: ");

	char inputLine[255];
	scanf("%s", inputLine);
	answer = inputLine[0];
	if (answer == 'y' || answer == 'Y') {
		return TRUE;
	}
	else {
		return FALSE;
	}
}


void AppIO_in_linearEquation(float* p_c0, float* p_c1) {
	printf("1차항의 계수를 입력하시오: ");
	scanf("%f", p_c1);
	printf("상수항의 계수를 입력하시오: ");
	scanf("%f", p_c0);
}