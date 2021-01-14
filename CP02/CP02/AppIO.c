#include "AppIO.h"
#include <stdio.h>

void AppIO_out_msg_startSolvingQuadEquation(void) {
	printf("<<< 이차방정식 풀이를 시작합니다 >>>\n");
}

void AppIO_out_msg_endSolvingQuadEquation(void){
	printf("<<< 이차방정식 풀이를 종료합니다 >>>\n");
}

void AppIO_out_quadEquation(float c0, float c1, float c2)
{
	Boolean aNonZeroTermDoesExist = FALSE;
	printf("> 주어진 방정식: ");
	if (!FloatValueIsZero(c2)) {
		aNonZeroTermDoesExist = TRUE;
		printf("(%.1f)x*x", c2);
	}
	if (!FloatValueIsZero(c1)) {
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%.1f)x", c1);
	}
	if (!FloatValueIsZero(c0)) {
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%.1f)", c0);
	}

	if (!aNonZeroTermDoesExist) {
		printf("0");
	}
	printf(" = 0\n");
}

void AppIO_out_msg_secondOrderTermCoefficientIsZero(void){
	printf("[오류] 이차항의 계수가 0이어서, 이차방정식이 아닙니다.\n");
}

void AppIO_out_msg_determinantIsNegative(float determinant) {
	printf("[오류] 판별식의 값이 음수이어서 해가 존재하지 않습니다.\n");
	printf("판별식의 값: %.1f\n", determinant);
}
void AppIO_out_solution(float root1, float root2)
{
	printf("방정식의 해는 다음과 같습니다.\n");
	printf("x1 = %.2f\nx2 = %.2f\n", root1, root2);
}

Boolean AppIO_in_solvingIsRequested(void) {
	char answer;
	printf("방정식을 풀려면 'y', 풀이를 종료하려면 다른 아무 키나 치시오: ");

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
void AppIO_in_QuadEquation(float* p_c0, float* p_c1, float* p_c2)
{
	printf("> 2차항의 계수를 입력하시오: ");
	scanf("%f", p_c2);
	printf("> 1차항의 계수를 입력하시오: ");
	scanf("%f", p_c1);
	printf("> 상수항의 계수를 입력하시오: ");
	scanf("%f", p_c0);
}