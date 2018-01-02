#pragma once
#include <list>
using namespace std;
class numFunc {
public:
	virtual double operator()(double)const = 0;
};
class Integration {
private:
	numFunc* f;
public:
	Integration(numFunc* _f);
	double operator ()(double a, double b, double precision);
};