#include "Ban.h"

#define DEFAULT_CAPACITY 100

struct _Ban {
	int _capacity;
	int _size;
	Student** _elements;
	GradeCounter* _gradeCounter;
};

int Ban_sumOfScoresRecursively(Ban* _this, int left, int right);
int Ban_maxScoreRecursively(Ban* _this, int left, int right);
int Ban_minScoreRecursively(Ban* _this, int left, int right);
char Ban_scoreToGrade(int aScore);

Ban* Ban_new(void) {
	Ban* _this = NewObject(Ban);
	_this->_capacity = DEFAULT_CAPACITY;
	_this->_size = 0;
	_this->_elements = NewVector(Student**, _this->_capacity);
	return _this;
}
Ban* Ban_newWithCapacity(int givenCapacity) {
	Ban* _this = NewObject(Ban);
	_this->_capacity = givenCapacity;
	_this->_size = 0;
	_this->_elements = NewVector(Student**, _this->_capacity);
	return _this;
}
void Ban_delete(Ban* _this) {
	free(_this->_elements);
	free(_this);
}
int Ban_capacity(Ban* _this) {
	return _this->_capacity;
}
int Ban_size(Ban* _this) {
	return _this->_size;
}
Boolean Ban_isEmpty(Ban* _this) {
	return (_this->_size == 0);
}
Boolean Ban_isFull(Ban* _this) {
	return (_this->_size == _this->_capacity);
}


float Ban_averageScore(Ban* _this) {
	float average = 0;
	float sum = 0;
	for (int i = 0; i < _this->_size; i++) {
		sum += (float) Student_score(_this->_elements[i]);
	}
	average = sum / (float)_this->_size;
	return average;
}

Boolean Ban_add(Ban* _this, Student* aStudent) {
	if (Ban_isFull(_this)) {
		return FALSE;
	}
	else {
		_this->_elements[_this->_size] = aStudent;
		_this->_size++;
		return TRUE;
	}
}
Student* Ban_elementAt(Ban* _this, int anOrder) {
	if (anOrder >= _this->_size) {
		return NULL;
	}else{
		return _this->_elements[anOrder];
	}
}
void Ban_sortStudentsByScore(Ban* _this) {
	Ban_quickSort(_this);
}
void Ban_quickSort(Ban* _this) {
	int size = Ban_size(_this);

	if (size >= 2) {
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if (Student_score(_this->_elements[i]) < Student_score(_this->_elements[minPosition]))
			{
				minPosition = i;
			}
		}
		SWAP(Student*, _this->_elements[minPosition], _this->_elements[size - 1]);
		Ban_quickSortRecursively(_this, 0, size - 2);
	}
}
void Ban_quickSortRecursively(Ban* _this, int left, int right) {
	int mid;
	if (left < right) {
		mid = Ban_partition(_this, left, right);
		Ban_quickSortRecursively(_this, left, mid-1);
		Ban_quickSortRecursively(_this, mid + 1, right);
	}
}
int Ban_partition(Ban* _this, int left, int right) {
	int pivot = left;
	int pivotScore = Student_score(_this->_elements[pivot]);
	int toLeft = right + 1;
	int toRight = left;
	do {
		do { toRight++; } while (Student_score(_this->_elements[toRight]) > pivotScore);
		do { toLeft--; } while (Student_score(_this->_elements[toLeft]) < pivotScore);
		if (toRight < toLeft) {
			SWAP(Student*, _this->_elements[toRight], _this->_elements[toLeft]);
		}
	} while (toRight < toLeft);
	SWAP(Student*, _this->_elements[pivot], _this->_elements[toLeft]);
	return toLeft;
}

int Ban_numberOfStudentsAboveAverage(Ban* _this) {
	float average = Ban_averageScore(_this);
	int numberOfStudentsAboveAverage = 0;

	for (int i = 0; i < _this->_size; i++) {
		if ((float)Stduent_score(_this->_elements[i]) >= average) {
			numberOfStudentsAboveAverage++;
		}
	}
	return numberOfStudentsAboveAverage;
}

GradeCounter* Ban_countGrade(Ban* _this) {
	char currentGrade;
	int score;
	GradeCounter* gradeCounter = GradeCounter_new();
	for (int i = 0; i < _this->_size; i++) {
		score = Student_score(_this->_elements[i]);
		currentGrade = Ban_scoreToGrade(score);
		GradeCounter_count(gradeCounter, currentGrade);
	}
	return gradeCounter;
}

int Ban_sumOfScoresRecursively(Ban* _this, int left, int right);
int Ban_maxScoreRecursively(Ban* _this, int left, int right);
int Ban_minScoreRecursively(Ban* _this, int left, int right);

char Ban_scoreToGrade(int aScore) {
	if (aScore <= 100 && aScore >= 90) {
		return 'A';
	}
	else if (aScore < 90 && aScore >= 80) {
		return 'B';
	}
	else if (aScore < 80 && aScore >= 70) {
		return 'C';
	}
	else if (aScore < 70 && aScore >= 60) {
		return 'D';
	}
	else {
		return 'F';
	}
}