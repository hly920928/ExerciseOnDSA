#include "stdafx.h"
#include "Matrix.h"
Matrix Matrix::operator ()(MatrixOperator_V1& opr)
{
	return opr(*this);
}

Matrix Matrix::operator ()(MatrixOperator_V2& opr, Matrix & b)
{
	return opr(*this,b);
}

Matrix::Matrix(istream& in) {
	in >> n;
	table.resize(n);
	for (int i = 0; i < n; i++) {
		table[i].resize(n);
		for (int j= 0; j< n; j++) {
			in >> table[i][j];
		}
	}
 }

Matrix::Matrix(int n)
{
	table.resize(n);
	for (int i = 0; i < n; i++)table[i].resize(n);
		
}
ostream& operator<<(ostream & os, const Matrix & m)
{
	for (auto& r : m.table) {
		for (auto& c : r)
		{os << c << ' ';}
		os << endl;
	}
	return os;
}

Matrix Transpose::operator()(Matrix & m)
{
	Matrix neo(m.n);
	for (int i = 0; i < m.n; i++)
		for (int j = 0; j < m.n; j++)
			neo.table[i][j] = m.table[j][i];
	return neo;
}

Matrix Add::operator()(Matrix & m1, Matrix & m2)
{
	Matrix neo(m1.n);
	for (int i = 0; i < m1.n; i++)
		for (int j = 0; j < m1.n; j++)
			neo.table[i][j] = m1.table[i][j]+ m2.table[i][j];
	return neo;
}
