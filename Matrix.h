#pragma once
#include <vector>
#include <iostream>
using namespace std;
class MatrixOperator_V1;
class MatrixOperator_V2;
class Matrix {
 public:
	 vector<vector<int>> table;
	 int n;
	 Matrix(istream& in);
	 Matrix(int n);
	 Matrix operator ()(MatrixOperator_V1&  opr);
	 Matrix operator ()(MatrixOperator_V2&  opr,Matrix& b);
	 
};
ostream& operator <<(ostream& os,const Matrix& m);
class MatrixOperator_V1 {
public:
	virtual Matrix operator ()(Matrix& m1) = 0;
};

class MatrixOperator_V2 {
public:
	virtual Matrix operator ()(Matrix& m1, Matrix& m2) = 0;
};
class Transpose :public MatrixOperator_V1 {
public:
	virtual Matrix operator()(Matrix& m)override;
};
class Add :public MatrixOperator_V2 {
public:
	virtual Matrix  operator ()(Matrix& m1, Matrix& m2)override;
};