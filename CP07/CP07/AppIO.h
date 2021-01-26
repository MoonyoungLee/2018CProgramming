#pragma once
#include "Common.h"

void AppIO_out(char* aString);
void AppIO_out_averageScore(float anAverageScore);
void AppIO_out_numberOfStudentsAboveAverage(int aNumber);
void AppIO_out_maxScore(int aMaxScore);
void AppIO_out_minScore(int aMinScore);
void AppIO_out_gradeCountFor(char aGrade, int aCount);
void AppIO_out_stduentInfo(char* aStudentID, int aScore, char aGrade);
void AppIO_out_msg_invalidStduentID(char* aStudentID, int maxLength);
void AppIO_out_msg_invalidScore(int aScore);
void AppIO_in_studentID(char* aStudentID);
Boolean AppIO_in_doesContinueToInputNextStudent(void);
char getcharDirectlyFromKeyboard(void);
int AppIO_in_score(void);
