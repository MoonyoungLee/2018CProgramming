#pragma once
#include "Common.h"
#include "GradeCounter.h"

typedef struct _Ban Ban;

Ban* Ban_new(void);
Ban* Ban_newWithCapacity(int givenCapacity);
void Ban_delete(Ban* _this);
int Ban_capacity(Ban* _this);
int Ban_size(Ban* _this);
Boolean Ban_isEmpty(Ban* _this);
Boolean Ban_isFull(Ban* _this);
Boolean Ban_add(Ban* _this, int aScore);
int Ban_elementAt(Ban* _this, int anOrder);
void Ban_sortStudentsByScore(Ban* _this);
int Ban_minScore(Ban* _this);
int Ban_maxScore(Ban* _this);
float Ban_averageScore(Ban* _this);
Boolean Ban_scoreIsValid(int aScore);
int Ban_numberOfStudentsAboveAverage(Ban* _this);
GradeCounter* Ban_countGrades(Ban* _this);
char Ban_scoreToGrade(int aScore);