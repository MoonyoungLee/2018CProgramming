#include "AppIO.h"
#include <stdio.h>

void AppIO_out_msg_startSolvingQuadEquation(void) {
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>\n");
}

void AppIO_out_msg_endSolvingQuadEquation(void){
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>\n");
}

void AppIO_out_quadEquation(float c0, float c1, float c2)
{
	Boolean aNonZeroTermDoesExist = FALSE;
	printf("> �־��� ������: ");
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
	printf("[����] �������� ����� 0�̾, ������������ �ƴմϴ�.\n");
}

void AppIO_out_msg_determinantIsNegative(float determinant) {
	printf("[����] �Ǻ����� ���� �����̾ �ذ� �������� �ʽ��ϴ�.\n");
	printf("�Ǻ����� ��: %.1f\n", determinant);
}
void AppIO_out_solution(float root1, float root2)
{
	printf("�������� �ش� ������ �����ϴ�.\n");
	printf("x1 = %.2f\nx2 = %.2f\n", root1, root2);
}

Boolean AppIO_in_solvingIsRequested(void) {
	char answer;
	printf("�������� Ǯ���� 'y', Ǯ�̸� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�: ");

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
	printf("> 2������ ����� �Է��Ͻÿ�: ");
	scanf("%f", p_c2);
	printf("> 1������ ����� �Է��Ͻÿ�: ");
	scanf("%f", p_c1);
	printf("> ������� ����� �Է��Ͻÿ�: ");
	scanf("%f", p_c0);
}