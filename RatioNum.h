#pragma once
#include "stdafx.h"
#include <string>
using namespace std;
class RatioNum {
private:
	int a;
	int b;
public:
	RatioNum(const string& _b);
	RatioNum();
	string toString()const;
	RatioNum operator +(const RatioNum& b);
	RatioNum operator -(const RatioNum& b);
	RatioNum operator *(const RatioNum& b);
	RatioNum operator /(const RatioNum& b);
	RatioNum& operator++();//care is ++a
	RatioNum operator++(int);//care is a++;
private:
	void simplify();
};
int gcd(int a, int b);
 ostream& operator <<(ostream& a, const RatioNum& rn);
 istream& operator >> (istream& is, RatioNum& rn);