#pragma once
#include "Common.h"
#include "Student.h"
#include "GradeCounter.h"

typedef struct _Ban Ban;

Ban* Ban_new(void);
Ban* Ban_newWithCapacity(int givenCapacity);
void Ban_delete(Ban* _this);
int Ban_capacity(Ban* _this);
int Ban_size(Ban* _this);
Boolean Ban_isEmpty(Ban* _this);
Boolean Ban_isFull(Ban* _this);
float Ban_averageScore(Ban* _this);
Boolean Ban_add(Ban* _this, Student* aStudent);
Student* Ban_elementAt(Ban* _this, int anOrder);
void Ban_sortStudentsByScore(Ban* _this);
void Ban_quickSort(Ban* _this);
void Ban_quickSortRecursively(Ban* _this, int left, int right);
int Ban_partition(Ban* _this, int left, int right);
int Ban_numberOfStudentsAboveAverage(Ban* _this);
GradeCounter* Ban_countGrade(Ban* _this);