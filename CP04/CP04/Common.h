#pragma once

#define EPSILON 0.000001
#define FloatValueIsZero(NUMBER) (fabsf(NUMBER) < EPSILON)

typedef enum{FALSE, TRUE} Boolean;

typedef struct {
	float _c0;
	float _c1;
	float _c2;
}QuadEquation;

typedef struct {
	QuadEquation _equation;
}QuadEquationProblem;

typedef struct {
	float _root1;
	float _root2;
}Solution;