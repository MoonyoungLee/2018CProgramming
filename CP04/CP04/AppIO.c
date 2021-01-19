#include "AppIO.h"
#include <stdio.h>

void AppIO_out_msg_startSolvingQuadEquation(void)
{
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>\n\n");
}
void AppIO_out_msg_endSolvingQuadEquation(void)
{
	printf("\n<<< ���������� Ǯ�̸� �����մϴ� >>>\n");
}

Boolean AppIO_in_solvingIsRequested(void) {
	char answer;
	printf("? �������� Ǯ���� 'y', Ǯ�̸� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�: ");
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
void AppIO_in_quadEquation(float* c0, float* c1, float* c2) {
	printf("? 2������ ����� �Է��Ͻÿ�: ");
	scanf("%f", c2);
	printf("? 1������ ����� �Է��Ͻÿ�: ");
	scanf("%f", c1);
	printf("? ������� ����� �Է��Ͻÿ�: ");
	scanf("%f", c0);
}

void AppIO_out_msg_secondOrderTermCoefficientIsZero(void) {
	printf("[����] �������� ����� 0�̾, ������������ �ƴմϴ�.\n\n");
}
void AppIO_out_msg_determinantIsNegative(float determinant)
{
	printf("[����] �Ǻ����� ���� �������� �ذ� �������� �ʽ��ϴ�.\n");
	printf("> �Ǻ����� ��: %.1f\n\n", determinant);
}
void AppIO_out_quadEquation(float c0, float c1, float c2)
{
	printf("> �־��� ������: ");
	if (!FloatValueIsZero(c2)) {
		printf("(%.1f)x*x", c2);
		if (!FloatValueIsZero(c1)) {
			printf(" + ");
			printf("(%.1f)x", c1);
			if (!FloatValueIsZero(c0)) {
				printf(" + ");
				printf("(%.1f)", c1);
			}
		}
		else {
			if (!FloatValueIsZero(c0)) {
				printf(" + ");
				printf("(%.1f)", c0);
			}
		}
	}
	else {
		if (!FloatValueIsZero(c1)) {
			printf("(%.1f)x", c1);
			if (!FloatValueIsZero(c0)) {
				printf(" + ");
				printf("(%.1f)", c0);
			}
		}
		else {
			if (!FloatValueIsZero(c0)) {
				printf("(%f)", c0);
			}
		}
	}
	printf(" = 0\n");
}
void AppIO_out_solution(Solution solution) {
	printf("> �������� �ش� ������ �����ϴ�\n");
	printf("x1 = %.2f\nx2 = %.2f\n\n", solution._root1, solution._root2);
}