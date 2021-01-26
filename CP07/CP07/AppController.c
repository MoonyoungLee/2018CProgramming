#include "AppController.h"
#include "Ban.h"
#include "AppIO.h"
#include "Student.h"

struct _AppController{
	Ban* _ban;
};

Boolean AppController_inputAndStoreStudents(AppController* _this);
void AppController_showStatistics(AppController* _this);
void AppController_showStudentsSortedByScore(AppController* _this);

AppController* AppController_new(void) {
	AppController* _this = NewObject(AppController);
	_this->_ban = Ban_new();
	return _this;
}

void AppController_delete(AppController* _this) {
	Ban_delete(_this->_ban);
	free(_this);
}

void AppController_run(AppController* _this);

Boolean AppController_inputIsValid(AppController* _this, char* aStudentID, int aScore) {
	Boolean inputIsValid = TRUE;
	if (!Student_studentIDIsValid(aStudentID)) {
		AppIO_out_msg_invalidStduentID(aStudentID, MAX_STUDENT_ID_LENGTH);
		inputIsValid = FALSE;
	}
	if (!Student_scoreIsValid(aScore)) {
		AppIO_out_msg_invalidScore(aScore);
		inputIsValid = FALSE;
	}
	return inputIsValid;
}

Boolean AppController_inputAndStoreStudents(AppController* _this) {
	int score;
	Boolean storingAStudentWasSuccessful = TRUE;
	char studentID[10];
	Student* student;
	while (storingAStudentWasSuccessful && AppIO_in_doesContinueToInputNextStudent()) {
		AppIO_in_studentID(studentID);
		score = AppIO_in_score();
		if (AppController_inputAndStoreStudents(studentID, score)) {
			student = Student_new(studentID, score);
			storingAStudentWasSuccessful = Ban_add(_this->_ban, student);
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
	Student* student;
	AppIO_out("학생들의 성적순 목록입니다.\n");
	for (int i = 0; i < Ban_size(_this->_ban); i++) {
		student = Ban_elementAt(_this->_ban, i);
		int score = Student_score(student);
		// from here !!!	
	}
}