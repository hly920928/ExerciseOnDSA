#include "stdafx.h"
#include "RatioNum.h"
#include <sstream>
#include <cmath>
RatioNum::RatioNum(const string& _b)
{
	string t = _b;
	stringstream ss1;
	int i = t.find("/");
	if (i < t.size()) {
		string tt = t.substr(0, i);
		ss1 << tt;
		ss1 >> a;
		stringstream ss2;
		tt = t.substr(i + 1, t.size());
		ss2 << tt;
		ss2 >> b;
	}
	else {
		ss1 << t;
		ss1 >> a;
		b = 1;
	}
	simplify();
}

RatioNum::RatioNum():a(0),b(0){}

string RatioNum::toString() const
{
	string ans="";
	ans.append(to_string(a));
	if (b != 1) {
		ans.append("/");
		ans.append(to_string(b));
	}
	return ans;
}

RatioNum RatioNum::operator+(const RatioNum & _b)
{
	RatioNum ans;
	ans.a = a*_b.b + _b.a*b;
	ans.b = b*_b.b; 
	ans.simplify();
	return ans;
}

RatioNum RatioNum::operator-(const RatioNum & b)
{
	RatioNum _b=b;
	_b.a = _b.a*-1;
	return *this+_b;
}

RatioNum RatioNum::operator*(const RatioNum & _b)
{
	RatioNum ans;
	ans.a = a*_b.a;
	ans.b = b*_b.b;
	ans.simplify();
	return ans;
}

RatioNum RatioNum::operator/(const RatioNum & _b)
{
	RatioNum ans;
	ans.a = a*_b.b;
	ans.b = b*_b.a;
	ans.simplify();
	return ans;
}

RatioNum& RatioNum::operator++()
{
	RatioNum one("1");
	*this = *this + one;
	return *this;
}

RatioNum RatioNum::operator++(int)
{
	RatioNum ans = *this;
	RatioNum one("1");
	*this = *this + one;
	return ans;
}

void RatioNum::simplify()
{
	long long _gcd = gcd(a, b);
	a=a/_gcd;
	b=b/_gcd;
	if (b < 0) { a *= -1; b *= -1; }
}
ostream& operator <<(ostream& os, const RatioNum& rn) {
	os << rn.toString();
	return os;
}
istream& operator >>(istream& is, RatioNum& rn) {
	string t;
	is >> t;
	rn= RatioNum(t);
	return is;
}
int gcd(int a, int b)
{
	int _a = abs(a);
	int _b = abs(b);
	if (_b>_a) { return gcd(_b, _a); }
	if (_b ==0) { return _a; }
	return gcd(_b, _a%_b);
}


