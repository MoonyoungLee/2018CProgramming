#include "AppIO.h"

void AppIO_out(char* aString) {
	printf("%s", aString);
}
void AppIO_out_averageScore(float anAverageScore) {
	printf("��������� %.1f �Դϴ�.\n", anAverageScore);
}

void AppIO_out_numberOfStudentsAboveAverage(int aNumber) {
	printf("��� �̻��� �л��� ��� %d ���Դϴ�.\n", aNumber);
}
void AppIO_out_maxScore(int aMaxScore) {
	printf("�ְ����� %d �� �Դϴ�.\n", aMaxScore);
}
void AppIO_out_minScore(int aMinScore) {
	printf("�������� %d �� �Դϴ�\n", aMinScore);
}

void AppIO_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c ������ %d�� �Դϴ�.\n", aGrade, aCount);
}

void AppIO_out_stduentInfo(char* aStudentID, int aScore, char aGrade) {
	printf("�й�: %s, ����: %d, ����: %c", aStudentID, aScore, aGrade);
}
void AppIO_out_msg_invalidStduentID(char* aStudentID, int maxLength) {
	printf("[����] �й��� ���̰� �ʹ� ��ϴ�. �ִ� %d �Դϴ�.\n", maxLength);
}

void AppIO_out_msg_invalidScore(int aScore) {
	printf("[����] ������ 0���� �۰ų� 100���� Ŀ��, �������� ������ �ƴմϴ�\n");
}
void AppIO_in_studentID(char* aStudentID) {
	printf("- �й��� �Է��Ͻÿ�: ");
	scanf("%s", aStudentID);
}
Boolean AppIO_in_doesContinueToInputNextStudent(void) {
	printf("? �л������� �Է��Ϸ��� 'Y', �Է��� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�: ");
	char answer = getcharDirectlyFromKeyboard();
	return (answer == 'Y' || answer == 'y');
}

char getcharDirectlyFromKeyboard(void) {
	char charFromkeyboard;
	charFromkeyboard = _getch();
	return charFromkeyboard;
}

int AppIO_in_score(void) {
	int score;
	printf("- ������ �Է��Ͻÿ�: ");
	scanf("%d", &score);
	printf("\n");
	return score;
}