#pragma once
#include <string>
using namespace std;
class LargeDate {
public:
	bool Neg_flag;
	string s;
	int pointPos;
	LargeDate();
	LargeDate(const LargeDate& ld);
	LargeDate(const string& str);
	LargeDate operator +(const LargeDate& b);
	LargeDate operator *(const LargeDate& b);
	LargeDate operator -(const LargeDate& b);
	LargeDate operator/(const LargeDate& b);
	LargeDate inverse()const;
	string toString()const;
	void shiftLeft(int i);
	void repair();
private:
	inline void toAbs();
	//b.lenght() must be less than s.length()
	void add(const string& b);
	void multiply(const char& c);
	//b.lenght() must be less than s.length()
	void subtract(const string& b);
	bool operator >(const LargeDate& b)const;
};
ostream& operator <<(ostream&, const LargeDate&);
istream& operator >> (istream&, LargeDate&);