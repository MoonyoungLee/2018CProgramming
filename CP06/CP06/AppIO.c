#include "AppIO.h"
#include <conio.h>
#include "GradeCounter.h"

char getcharDirectlyFromKeyboard(void);

void AppIO_out(char* aMessage) {
	printf("%s", aMessage);
}

void AppIO_out_averageScore(float anAverageScore) {
	printf("\n��� ������ %.1f �Դϴ�.\n", anAverageScore);
}
void AppIO_out_numberOfStudentsAboveAverage(int aNumber) {
	printf("��� �̻��� �л��� ��� %d�� �Դϴ�.\n", aNumber);
}
void AppIO_out_maxScore(int aMaxScore) {
	printf("�ְ����� %d �� �Դϴ�.\n", aMaxScore);
}
void AppIO_out_minScore(int aMinScore) {
	printf("�������� %d �� �Դϴ�\n", aMinScore);
}

void AppIO_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c������ %d���Դϴ�\n", aGrade, aCount);
}
void AppIO_out_studentInfo(int aScore, int aGrade) {
	printf("����: %d ����: %c\n", aScore, aGrade);
}

Boolean AppIO_in_doesContinueToInputNextStudent(void) {
	
	printf("? ������ �Է��Ϸ��� 'Y'��, �Է��� �����Ϸ��� �ٸ� �ƹ�Ű�� ġ�ÿ�: ");
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
	printf("\n- ������ �Է��Ͻÿ�: ");
	scanf("%d", &score);
	printf("\n");
	return score;
}