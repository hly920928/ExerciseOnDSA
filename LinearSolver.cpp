#include "stdafx.h"
#include "LinearSolver.h"
#include<iostream>
#include<cmath>
#define PRECISION 0.0001
using namespace std;
row::row(double *_a, double *_b, int _n):a(_a),b(_b),n(_n){}
row::row() : a(nullptr), b(nullptr), n(0){}
void row::operator*(double k)
{
	for (int i = 0; i < n; i++)a[i] *= k;
	*b *= k;
}
void row::operator-(const row & c)
{
	for (int i = 0; i < n; i++) a[i] -= c.a[i];
	*b -= *(c.b);
}
double & row::operator[](int i)
{
	if (i < n)return a[i];
	if (i == n)return *b;
}
void row::assign(double *_a, double *_b, int _n) {
	a = _a;b = _b;n = _n;
}
bool row::isAllZero()const
{
	for (int i = 0; i < n; i++) 
		if ((abs(a[i])) > PRECISION) return false; 
	return true;
}
void row::printOut(ostream& os)const
{
	for (int i = 0; i < n; i++)os << a[i] << " ";
	os << *b << endl;
}
void row::operator/(int i)
{
	double t = 1 / a[i];
	*this*t;
}
LinearSolver::LinearSolver(double * _M, double * _b, int _n)
	:M(_M),b(_b),n(_n)
{
    r = new row[n];
	for (int i = 0; i < n; i++)
		r[i].assign(M + n* i, b + i, n);
}
LinearSolver::~LinearSolver()
{
	delete[] r;
}
bool LinearSolver::solve()
{ 
	for (int i = 0; i < n; i++) {
		r[i] / i;
		for (int j = i+1; j < n; j++) {
			r[j] / i;
			r[j] - r[i];
			if (r[j].isAllZero()) { return false; }
		}
	}
	for (int i = n-1; i>=0; i--) {
		r[i] / i;
		for (int j = i -1; j >=0; j--) {
			r[j] / i;
			r[j] - r[i];}
	}
	return true;
}
void LinearSolver::printOutMatrix(std::ostream & os) const
{
	for (int i = 0; i < n; i++) {
		r[i].printOut(os);}
}
void LinearSolver::printOutAnswer(std::ostream & os)
{ 
	for (int i = 0; i < n; i++) 
		os << b[i] << " ";
	os << endl;
}
