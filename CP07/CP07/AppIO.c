#include "AppIO.h"

void AppIO_out(char* aString) {
	printf("%s", aString);
}
void AppIO_out_averageScore(float anAverageScore) {
	printf("평균점수는 %.1f 입니다.\n", anAverageScore);
}

void AppIO_out_numberOfStudentsAboveAverage(int aNumber) {
	printf("평균 이상인 학생은 모두 %d 명입니다.\n", aNumber);
}
void AppIO_out_maxScore(int aMaxScore) {
	printf("최고점은 %d 점 입니다.\n", aMaxScore);
}
void AppIO_out_minScore(int aMinScore) {
	printf("최저점은 %d 점 입니다\n", aMinScore);
}

void AppIO_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c 학점은 %d명 입니다.\n", aGrade, aCount);
}

void AppIO_out_stduentInfo(char* aStudentID, int aScore, char aGrade) {
	printf("학번: %s, 점수: %d, 학점: %c", aStudentID, aScore, aGrade);
}
void AppIO_out_msg_invalidStduentID(char* aStudentID, int maxLength) {
	printf("[오류] 학번의 길이가 너무 깁니다. 최대 %d 입니다.\n", maxLength);
}

void AppIO_out_msg_invalidScore(int aScore) {
	printf("[오류] 성적이 0보다 작거나 100보다 커서, 정상적인 점수가 아닙니다\n");
}
void AppIO_in_studentID(char* aStudentID) {
	printf("- 학번을 입력하시오: ");
	scanf("%s", aStudentID);
}
Boolean AppIO_in_doesContinueToInputNextStudent(void) {
	printf("? 학생정보를 입력하려면 'Y', 입력을 종료하려면 다른 아무 키나 치시오: ");
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
	printf("- 성적을 입력하시오: ");
	scanf("%d", &score);
	printf("\n");
	return score;
}