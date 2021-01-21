#include "AppController.h"
#include "AppIO.h"
#include "Ban.h"
#include "GradeCounter.h"

#define MAX_NUMBER_OF_STUDENTS 100

Boolean AppController_inputAndStoreStudents(AppController* _this);
void AppController_showStatistics(AppController* _this);
void AppController_showStudentsSortedByScore(AppController* _this);


struct _AppController{
	Ban* _ban;
};

AppController* AppController_new(void) {
	AppController* _this = NewObject(AppController);
	return _this;
}

void AppController_run(AppController* _this) {
	AppIO_out("<<< 성적처리를 시작합니다 >>>\n");

	Boolean inputAndStoreWasSuccessful;
	inputAndStoreWasSuccessful = AppController_inputAndStoreStudents(_this);
	if (inputAndStoreWasSuccessful) {
		if (Ban_isEmpty(_this->_ban)) {
			AppIO_out("[오류] 학생 정보가 전혀 입력되지 않았습니다.\n");
		}
		else {
			AppController_showStatistics(_this);
			Ban_sortStudentsByScore(_this->_ban);
			AppController_showStudentsSortedByScore(_this);
		}
	}
	else {
		AppIO_out("[오류] 성적이 정상적으로 저장되지 않았습니다.\n");
	}

	AppIO_out("<<< 성적 처리를 종료합니다 >>\n");
}

void AppController_delete(AppController* _this) {
	free(_this);
}

Boolean AppController_inputAndStoreStudents(AppController* _this) {
	int score;
	Boolean storingAStudentWasSuccessful = TRUE;

	while (storingAStudentWasSuccessful && AppIO_in_doesContinueToInputNextStudent()) {
		score = AppIO_in_score();
		if (Ban_scoreIsValid(score)) {
			storingAStudentWasSuccessful = Ban_add(_this, score);
		}
		else {
			AppIO_out("[오류] 0보다 작거나 100보다 커서, 정상적인 점수가 아닙니다.\n");
		}
	}
	return storingAStudentWasSuccessful;
}

void AppController_showStatistics(AppController* _this) {
	AppIO_out_averageScore(Ban_averageScore(_this->_ban));
	AppIO_out_numberOfStudentsAboveAverage(Ban_numberOfStudentsAboveAverage(_this->_ban));
	AppIO_out_maxScore(Ban_maxScore(_this->_ban));
	AppIO_out_minScore(Ban_minScore(_this->_ban));

	GradeCounter* gradeCounter = Ban_countGrades(_this->_ban);
	AppIO_out_gradeCountFor('A', GradeCounter_numberOfA(gradeCounter));
	AppIO_out_gradeCountFor('B', GradeCounter_numberOfB(gradeCounter));
	AppIO_out_gradeCountFor('C', GradeCounter_numberOfC(gradeCounter));
	AppIO_out_gradeCountFor('D', GradeCounter_numberOfD(gradeCounter));
	AppIO_out_gradeCountFor('F', GradeCounter_numberOfF(gradeCounter));
	GradeCounter_delete(gradeCounter);
}

void AppController_showStudentsSortedByScore(AppController* _this) {
	AppIO_out("학생들의 성적순 목록입니다.\n");

	int score;
	char grade;
	for (int order = 0; order < Ban_size(_this->_ban); order++) {
		score = Ban_elementAt(_this->_ban, order);
		grade = Ban_scoreToGrade(score);
		AppIO_out_studentInfo(score, grade);
	}
}