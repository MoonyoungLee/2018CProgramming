#include <stdio.h>
#include "AppIO.h"

void AppIO_out_msg_startSolvingLinearEquation(void) {
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>");
}

void AppIO_out_msg_endSolvingLinearEquation(void) {
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>");
}

void AppIO_out_linearEquation(float c0, float c1) {
	printf(">�־��� ������: (%f)x + (%f) = 0 \n", c1, c0);
}

void AppIO_out_root(float root) {
	printf(">�������� �ش� ������ �����ϴ�\n");
	printf("x = %f\n", root);
}
void AppIO_out_firstOrderTermCoefficientIsZero(void) {
	printf("[����] 1������ ����� 0�̾, ������ Ǯ �� �����ϴ�.\n");
}

Boolean AppIO_in_solvingIsRequested(void) {
	char answer;
	printf("�������� Ǯ���� 'y', Ǯ�̸� �����Ϸ��� �ٸ� �ƹ�Ű�� ġ�ÿ�: ");

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
	printf("1������ ����� �Է��Ͻÿ�: ");
	scanf("%f", p_c1);
	printf("������� ����� �Է��Ͻÿ�: ");
	scanf("%f", p_c0);
}