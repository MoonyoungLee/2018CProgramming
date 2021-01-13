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
	// ���� Ǯ�� ���θ� ���� ������ ��´�
	solvingIsRequested = AppIO_in_solvingIsRequested();
	while (solvingIsRequested) {
		// ���� �������� ����� �Է� �޴´�.
		AppIO_in_linearEquation(&c0, &c1);
		// ������������ �����ش�.
		AppIO_out_linearEquation(c0, c1);
		// �������� ����� 0�̸� �������� ����� 0�̶�� �޽����� ����Ѵ�.
		if (FloatValueIsZero(c1)) {
			AppIO_out_firstOrderTermCoefficientIsZero();
		}
		else {
			// �������� ����� 0�� �ƴϸ�, ������������ Ǭ��.
			root = LinearEquation_solve(c0, c1);
			// ������������ �ظ� ����Ѵ�.
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