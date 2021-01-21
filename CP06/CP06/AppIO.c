#include "AppIO.h"
#include <conio.h>
#include "GradeCounter.h"

void AppIO_out(char* aMessage) {
	printf("%s", aMessage);
}

void AppIO_out_averageScore(float anAverageScore) {
	printf("��� ������ %.1f �Դϴ�.\n", anAverageScore);
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
void AppIO_out_studentInfo(int aScore) {
	char aGrade;
	if(aScore >= '90' && '100' >= aScore){
		aGrade = 'A';
	}
	else if (aScore < 90 && aScore >= 80) {
		aGrade = 'B';
	}
	else if (aScore < 80 && aScore >= 70) {
		aGrade = 'C';
	}
	else if (aScore < 70 && aScore >= 60) {
		aGrade = 'D';
	}
	else {
		aGrade = 'F';
	}
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
	printf("- ������ �Է��Ͻÿ�: ");
	scanf("%d", &score);
	return score;
}