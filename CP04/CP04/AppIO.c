#include "AppIO.h"
#include <stdio.h>

void AppIO_out_msg_startSolvingQuadEquation(void)
{
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>\n\n");
}
void AppIO_out_msg_endSolvingQuadEquation(void)
{
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>\n\n");
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
	printf("? 2������ ����� �Է��Ͻÿ�: ");
	scanf("%f", c2);
	printf("? 1������ ����� �Է��Ͻÿ�: ");
	scanf("%f", c1);
	printf("? ������� ����� �Է��Ͻÿ�: ");
	scanf("%f", c0);
}

void AppIO_out_msg_secondOrderTermCoefficientIsZero(void) {
	printf("[����] �������� ����� 0�̾, ���ڹ������� �ƴմϴ�.\n");
}
void AppIO_out_msg_determinantIsNegative(float determinant)
{
	printf("[����] �Ǻ����� ���� �������� �ذ� �������� �ʽ��ϴ�.\n");
}
void AppIO_out_quadEquation(float c0, float c1, float c2)
{
	printf("> �־��� ������: ");
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