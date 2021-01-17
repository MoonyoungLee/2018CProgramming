#include "AppIO.h"
#include <stdio.h>

void AppIO_out_msg_startSolvingQuadEquation(void)
{
	printf("<<< 이차방정식 풀이를 시작합니다 >>>\n\n");
}
void AppIO_out_msg_endSolvingQuadEquation(void)
{
	printf("<<< 이차방정식 풀이를 종료합니다 >>>\n\n");
}

Boolean AppIO_in_solvingIsRequested(void) {
	char answer;
	scanf("%c", &answer);
	if (answer == 'y' || answer == 'Y') {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
void AppIO_in_quadEquation(float* c0, float* c1, float* c2) {
	printf("? 2차항의 계수를 입력하시오: ");
	scanf("%f", c2);
	printf("? 1차항의 계수를 입력하시오: ");
	scanf("%f", c1);
	printf("? 상수항의 계수를 입력하시오: ");
	scanf("%f", c0);
}

void AppIO_out_msg_secondOrderTermCoefficientIsZero(void) {
	printf("[오류] 이차항의 계수가 0이어서, 이자방정식이 아닙니다.\n");
}
void AppIO_out_msg_determinantIsNegative(float determinant)
{
	printf("[오류] 판별식의 값이 음수여서 해가 존재하지 않습니다.\n");
}
void AppIO_out_quadEquation(float c0, float c1, float c2)
{
	printf("> 주어진 방정식: ");
	if (!FloatValueIsZero(c2)) {
		printf("(%f)x*x", c2);
	}
	else {
		if (!FloatValueIsZero(c1)) {
			printf(" + ");
			printf("(%f)x");
		}
		else {
			if (!FloatValueIsZero(c0)) {
			}
		}
	}
}
void AppIO_out_solution(Solution solution);