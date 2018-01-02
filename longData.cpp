#include "stdafx.h"
#include <iostream>
#include <algorithm>  
#include <string>   
#include "longData.h"
longData::longData(string s) { init(s); }
longData longData::operator+(const  longData&  ld)const {
	longData neo=*this;longData other = ld;
	//for floating point
	int diff = neo.pointPos - other.pointPos;
	if (diff > 0)other.shiftLeft(diff);
	else neo.shiftLeft(diff*-1);
	//
	if (neo.isNeg == other.isNeg) {
		neo.isNeg = isNeg;
		neo.list = neo.add(other.list);
	}else {
		if (neo.isLarger(other.list)) {
			neo.isNeg = isNeg;
			neo.list = neo.subtract(other.list);
		}else {
			neo.isNeg = !isNeg;
			neo.list = other.subtract(list);}
	}
	if (neo.isNeg&&neo.list == "0") neo.isNeg = false;
	//for floating point
	neo.removeUselessZero();
	//
	return neo;
}
longData longData::operator-(const longData&  ld)const {
	longData t = ld;
	t.isNeg = !t.isNeg;
	return *this + t;
}
longData longData::operator*(const longData & ld) const
{
	longData ans("0");
	ans.isNeg = (isNeg == ld.isNeg) ? false : true;
	longData n("0"); longData one("1");
	while (ld.isLarger(n.list)) {
		ans = ans + *this;
		n = n + one;
	}
	return ans;
}
longData longData::operator/(const longData & ld) const
{
	longData ans("0");
	ans.isNeg = (isNeg == ld.isNeg) ? false : true;
	longData temp= *this;
	longData one("1");
	while (!ld.isLarger(temp.list) || ld.list == temp.list) {
		ans = ans + one;
		temp = temp - ld;
	}
	return ans;
}
void longData::init(string& s) {
	pointPos = 0;
	if (s.size() == 0)return;
	if (s == "-")return;
	if (s == "-0") { isNeg = false; list = "0"; return; }
	list = s;
	reverse(list.begin(), list.end());
	if (*(list.end() - 1) == '-') {
		isNeg = true;
		list.pop_back();
	}
	else isNeg = false;
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == '.') {
			pointPos = i;
			list.erase(i,1);
			break;}
	}
	if (*(list.end() - 1) == '0'&&list.size()>1)list.pop_back();
}
bool longData::isLarger(const string& b)const {
	if (list.size() != b.size())return list.size() > b.size();
	for (int i = list.size() - 1; i >= 0; i--)
		if (list[i] != b[i])return list[i] > b[i];
	return false;
}
string longData::add(const string& b)const {
	string neo;
	int l1 = list.size(); int l2 = b.size();
	int max = l1>l2 ? l1 : l2;
	bool upFlag = false;
	char c1 = ' '; char c2 = ' '; char sum = ' ';
	for (int i = 0; i <=max; i++) {
		c1 = (i >= l1) ? 0 : list[i] - '0';
		c2 = (i >= l2) ? 0 : b[i] - '0';
		sum = c1 + c2 + upFlag;
		neo.push_back(sum % 10 + '0');
		upFlag = sum >= 10;
	}
	if (*(neo.end() - 1) == '0')neo.pop_back();
	return neo;
}
string longData::subtract(const string& b)const {
	if (b.size() == 0 || b == "0")return list;
	string com;
	char t = ' ';
	for (int i =0; i <list.size(); i++) {
		t = (i >= b.size()) ? '9' : 9 - (b[i] - '0') + '0';
		com.push_back(t);
	}
	longData neo("0");
	neo.list = add(com);
	neo = neo+ longData("1");
    neo.list.pop_back();
	while (*(neo.list.end() - 1) == '0'&&neo.list.size()>1)neo.list.pop_back();
	return neo.list;
}
void longData::removeUselessZero()
{
	int n = 0;
	for (int i = 0; i < pointPos; i++) {
		if (list[i] !='0')break;
		n++;
	}
	list.erase(0, n);
	pointPos -= n;
}
void longData::shiftLeft(int x)
{
	string s="";
	for (int i = 0; i < x; i++)s.push_back('0');
	list.insert(0,s);
	pointPos += x;
}
string longData::toString() const
{
	string ans = list;
	if (isNeg)ans.push_back('-');
	if (pointPos == ans.size())ans.push_back('0');
	if (pointPos > 0)ans.insert(ans.begin()+pointPos, '.');
	reverse(ans.begin(), ans.end());
	return ans;
}
//assure *this>b;
ostream& operator << (ostream& os, const longData& ld) {
	if (ld.list.size() == 0)return os;
	os<< ld.toString();
	return os;
}
istream& operator >> (istream& is, longData& ld) {
	if (is.eof())return is;
	string t;
	is >> t;
	if (t.size() == 1 && t[0] == '-') {
		t.clear(); return is;
	}
	ld.init(t);
	return is;
}