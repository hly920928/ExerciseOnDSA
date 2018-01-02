#pragma once
#include<iostream>
struct row {
	double*a;
	int n;
	double* b;
	row(double*, double*, int);
	row();
	void operator*(double k);
	void operator-(const row & c);
	double& operator [](int i);
	void assign(double*, double*, int);
	bool isAllZero()const;
	void printOut(std::ostream& os)const;
	void operator/(int);
};
class LinearSolver {
private:
	double* M;
	double* b;
		int n;
		row* r;
public:
	LinearSolver(double* M, double* b, int n);
	~LinearSolver();
	bool solve();
	void printOutMatrix(std::ostream& os)const;
	void printOutAnswer(std::ostream& os);
};
