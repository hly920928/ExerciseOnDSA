#pragma once
#include <iostream>
#include <string>   
using namespace std;
class longData {
private:
	string list;
	bool isNeg;
	int pointPos;
public:
	longData(string s);
	longData operator+(const  longData&  ld)const;
	longData operator-(const longData&  ld)const;
	longData operator*(const  longData&  ld)const;
	longData operator/(const longData&  ld)const;
	void init(string& s);
	string toString()const;
	void shiftLeft(int x);
private:
	bool isLarger(const string& b)const;
	string add(const string& b)const;
	string subtract(const string& b)const;
	friend istream& operator >> (istream& is, longData& ld);
	friend ostream& operator << (ostream& os, const longData& ld);
	void removeUselessZero();
};
