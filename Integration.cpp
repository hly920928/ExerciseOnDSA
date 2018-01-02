#include "stdafx.h"
#include <list>
#include<cmath>
#include "Integration.h"
using namespace std;

Integration::Integration(numFunc* _f) :f(_f) {}
double Integration:: operator ()(double a, double b, double precision) {
	numFunc & func = *f;
	double delta_x = b - a;
	double pre_intg = 0.5*(func(a) + func(b))*(delta_x);
	double step = delta_x;
	delta_x *= 0.5;
	int n = 0;
	double x_pos =a;
	double now_intg = 0;
	while (true) {
		for (x_pos =a+delta_x; x_pos < b; x_pos += step) 
			now_intg += func(x_pos);
		now_intg = now_intg*delta_x+ 0.5*pre_intg;
		if (abs(now_intg - pre_intg) < precision&&n>4)return now_intg;
		n++;
		pre_intg = now_intg;
		now_intg = 0;
		step *= 0.5; delta_x *= 0.5;
	};
};