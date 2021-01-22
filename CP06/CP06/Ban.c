#include "Ban.h"

#define DEFAULT_CAPACITY 100
#define SWAP(TYPE, X, Y) {TYPE temp=X; X=Y; Y=temp;}

void Ban_quickSortRecursively(Ban* _this, int left, int right);
int Ban_partition(Ban* _this, int left, int right);
int Ban_sumOfScoresRecursively(Ban* _this, int left, int right);
int Ban_maxScoreRecursively(Ban* _this, int left, int right);
int Ban_minScoreRecursively(Ban* _this, int left, int right);


struct _Ban {
	int _capacity;
	int _size;
	int* _elements;
};

Ban* Ban_new(void) {
	Ban* _this = NewObject(Ban);
	_this->_capacity = DEFAULT_CAPACITY;
	_this->_size = 0;
	_this->_elements;
	return _this;
}
Ban* Ban_newWithCapacity(int givenCapacity) {
	Ban* _this = NewObject(Ban);
	_this->_capacity = givenCapacity;
	_this->_size = 0;
	_this->_elements = NewVector(int, _this->_capacity);
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

Boolean Ban_add(Ban* _this, int aScore) {
	if (Ban_isFull(_this)) {
		return FALSE;
	}
	else {
		_this->_elements[_this->_size] = aScore;
		_this->_size++;
		return TRUE;
	}
}

int Ban_elementAt(Ban* _this, int anOrder) {
	if (anOrder >= _this->_size) {
		return -1;
	}
	else {
		return (_this->_elements[anOrder - 1]);
	}
}

void Ban_sortStudentsByScore(Ban* _this) {
	int size = _this->_size;

	if (size >= 2) {
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if (_this->_elements[i] < _this->_elements[minPosition]) {
				minPosition = i;
			}
		}
		SWAP(int, _this->_elements[minPosition], _this->_elements[size - 1]);
		Ban_quickSortRecursively(_this, 0, size - 2);
	}
}

int Ban_minScore(Ban* _this) { 
	return Ban_minScoreRecursively(_this, 0, _this->_size-1);
}

int Ban_maxScore(Ban* _this) {
	return Ban_maxScoreRecursively(_this, 0, _this->_size - 1);
}

float Ban_averageScore(Ban* _this) {
	float sumOfScore = (float)Ban_sumOfScoresRecursively(_this, 0, _this->_size - 1);
	float average = sumOfScore / (float)_this->_size;
	return average;
}

void Ban_quickSortRecursively(Ban* _this, int left, int right) {
	if (left < right) {
		int mid = Ban_partition(_this, left, right);
		Ban_quickSortRecursively(_this, left, mid - 1);
		Ban_quickSortRecursively(_this, mid+1, right);
	}
}

Boolean Ban_scoreIsValid(int aScore) {
	if (aScore >= 0 && aScore <= 100) {
		return TRUE;
	}
	return FALSE;
}


int Ban_partition(Ban* _this, int left, int right) {
	int pivot = left;
	int pivotScore = _this->_elements[pivot];

	right++;
	do {
		do { left++; } while (_this->_elements[left] > pivotScore);
		do { right++; } while (_this->_elements[right] < pivotScore);
		if (left < right) {
			SWAP(int, _this->_elements[left], _this->_elements[right]);
		}
	} while (left < right);
	SWAP(int, _this->_elements[pivot], _this->_elements[right]);
	return right;
}

int Ban_sumOfScoresRecursively(Ban* _this, int left, int right) {
	if (left > right) {
		return 0;
	}
	else {
		return (_this->_elements[left] + Ban_sumOfScoresRecursively(_this, left + 1, right));
	}
}

int Ban_maxScoreRecursively(Ban* _this, int left, int right) {
	if (left == right) {
		return _this->_elements[left];
	}
	else {
		int mid = (left + right) / 2;
		int leftMax = Ban_maxScoreRecursively(_this, left, mid);
		int rightMax = Ban_maxScoreRecursively(_this, mid + 1, right);
		if (leftMax >= rightMax) {
			return leftMax;
		}
		else {
			return rightMax;
		}
	}
}

int Ban_minScoreRecursively(Ban* _this, int left, int right) {
	int minScore = _this->_elements[left];
	if (left == right) {
		return _this->_elements[left];
	}
	else {
		if (_this->_elements[left] > Ban_minScoreRecursively(_this, left + 1, right)) {
			return Ban_minScoreRecursively(_this, left + 1, right);
		}
		else {
			return _this->_elements[left];
		}
	}
}

int Ban_numberOfStudentsAboveAverage(Ban* _this) {
	float average = Ban_averageScore(_this);
	int n = _this->_size;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if ((float)_this->_elements[i] >= average) {
			cnt++;
		}
	}
	return cnt;
}

GradeCounter* Ban_countGrades(Ban* _this) {
	char currentGrade;
	GradeCounter* gradeCounter = GradeCounter_new();

	for (int i = 0; i < _this->_size; i++) {
		currentGrade = Ban_scoreToGrade(_this->_elements[i]);
		GradeCounter_count(gradeCounter, currentGrade);
	}
	return gradeCounter;
}

char Ban_scoreToGrade(int aScore) {
	char aGrade;
	if (aScore >= 90 && 100 >= aScore) {
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
	return aGrade;
}