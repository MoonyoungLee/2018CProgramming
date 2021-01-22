#include "AppIO.h"
#include <conio.h>
#include "GradeCounter.h"

char getcharDirectlyFromKeyboard(void);

void AppIO_out(char* aMessage) {
	printf("%s", aMessage);
}

void AppIO_out_averageScore(float anAverageScore) {
	printf("\n평균 점수는 %.1f 입니다.\n", anAverageScore);
}
void AppIO_out_numberOfStudentsAboveAverage(int aNumber) {
	printf("평균 이상인 학생은 모두 %d명 입니다.\n", aNumber);
}
void AppIO_out_maxScore(int aMaxScore) {
	printf("최고점은 %d 점 입니다.\n", aMaxScore);
}
void AppIO_out_minScore(int aMinScore) {
	printf("최저점은 %d 점 입니다\n", aMinScore);
}

void AppIO_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c학점은 %d명입니다\n", aGrade, aCount);
}
void AppIO_out_studentInfo(int aScore, int aGrade) {
	printf("점수: %d 학점: %c\n", aScore, aGrade);
}

Boolean AppIO_in_doesContinueToInputNextStudent(void) {
	
	printf("? 성적을 입력하려면 'Y'를, 입력을 종료하려면 다른 아무키나 치시오: ");
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
	printf("\n- 점수를 입력하시오: ");
	scanf("%d", &score);
	printf("\n");
	return score;
}