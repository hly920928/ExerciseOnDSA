#include "stdafx.h"
#include <string>
#include <algorithm> 
#include<iterator>
#include "LargeData.h"
#define precision 5
using namespace  std;
	LargeDate::LargeDate() {
		s = "";
		Neg_flag = false;
	}
	LargeDate::LargeDate(const LargeDate & ld)
	{
		s = ld.s;
		Neg_flag = ld.Neg_flag;
		pointPos = ld.pointPos;
	}
	LargeDate::LargeDate(const string& str) {
		s = str;
		pointPos = 0;
		toAbs();
	}
	LargeDate LargeDate::operator +(const LargeDate& b) {
		LargeDate ans;
		LargeDate temp(*this);
		if (temp.pointPos < b.pointPos) {
			temp.shiftLeft(b.pointPos- temp.pointPos);
		}
		ans.pointPos = temp.pointPos;
		if (Neg_flag == b.Neg_flag) {
			ans.Neg_flag = Neg_flag;
			if (temp>b) {
				ans.s = temp.s;
				ans.add(b.s);
			}
			else {
				ans.s = b.s;
				ans.add(temp.s);
			}
		}
		else {
			if (*this>b) {
				ans.Neg_flag = temp.Neg_flag;
				ans.s = temp.s;
				ans.subtract(b.s);
			}
			else {
				ans.Neg_flag = b.Neg_flag;
				ans.s = b.s;
				ans.subtract(temp.s);
			}
		}
		ans.repair();
		return ans;
	}
	LargeDate LargeDate::operator*(const LargeDate & b)
	{
		LargeDate ans;
		ans.s = "0";
		ans.Neg_flag = (Neg_flag^b.Neg_flag);
		ans.pointPos = 0;
		string k;
		string j;
		if (s.length() > b.s.length()) { k = s; j = b.s; }else { k = b.s; j = s; };
		reverse(k.begin(), k.end());
		for (int i = 0; i <j.size(); i++) {
			LargeDate temp(k);
			temp.Neg_flag = ans.Neg_flag;
			temp.shiftLeft(i); temp.pointPos -= i;
			temp.multiply(j[i]);
			ans = ans + temp;
		}
		ans.pointPos = pointPos + b.pointPos;
		ans.repair();
		return ans;
	}
	LargeDate LargeDate::operator-(const LargeDate& b) {
		LargeDate ans;
		ans.Neg_flag = !b.Neg_flag;
		ans.s = b.s;
		return *this + ans;
	}
	LargeDate LargeDate::operator/(const LargeDate & b)
	{
		return (*this)*b.inverse();
	}
	LargeDate LargeDate::inverse() const
	{
		LargeDate temp1("1");
		LargeDate temp2(*this); temp2.pointPos = 0; 
		temp2.repair(); temp1.shiftLeft(temp2.s.length());
		LargeDate ans("0");
		ans.pointPos = temp1.pointPos - pointPos;
		temp1.pointPos = 0; temp1.repair();
		while (ans.pointPos < precision + 1|| ans.s.length()< precision + 1) {
			while (temp1 > temp2 || temp1.s == temp2.s) {
				temp1.subtract(temp2.s);
				temp1.repair();
				ans.add("1");}
			if (temp1.s == "0") { break; }
			int shift = temp2.s.length() - temp1.s.length() + 1;
			temp1.shiftLeft(shift); temp1.pointPos = 0;
			ans.shiftLeft(shift);
		}
		ans.Neg_flag = Neg_flag;
		ans.repair();
		return ans;
	}
	string LargeDate::toString()const {
		string ans = s;
		ans.insert(pointPos, ".");
		reverse(ans.begin(), ans.end());
		if (Neg_flag&&s!="0") {
			ans = "-" + ans;
		}
		return ans;
	}
	inline void LargeDate::toAbs() {
		if (s[0] == '-') {
			Neg_flag = true;
			s = s.substr(1, s.length() - 1);
			reverse(s.begin(), s.end());
		}
		else {
			Neg_flag = false;
			reverse(s.begin(), s.end());
		}
		int pos = s.find(".");
		if (pos < s.size()) { pointPos = pos; s.erase(pos,1); }
	}
	//b.lenght() must be less than s.length()
	void LargeDate::add(const string& b) {
		int upFlag = 0;
		string::iterator a_itr = s.begin();
		string::const_iterator b_itr = b.begin();
		bool b_endFlag = (b_itr == b.end());
		while (upFlag || !b_endFlag) {
			int b_val;
			/////
			if (b_endFlag) {b_val = 0;}
			else {b_val = (*b_itr - '0');
			}
			///////
			if (upFlag && (*a_itr == '9')) {
				*a_itr = b_val + '0';
			}else {
				int sum = (*a_itr - '0') + b_val + upFlag;
				*a_itr = sum % 10 + '0';
				upFlag = (sum >= 10) ? true : false;
			}
			/////
			a_itr++;
			b_itr = (b_endFlag) ? b_itr : (b_itr + 1);
			b_endFlag = (b_itr == b.end());
			//assert s>b ,up highest bit,ended
			if (upFlag && (a_itr == s.end())) {
				s = s + "1";
				break;
			}
		}
	}
	void LargeDate::shiftLeft(int k)
	{
		string t="";
		for (int i = 0; i < k; i++) {
			t = t + "0";
			pointPos++;
		}
		s = t + s;
		
	}
	void LargeDate::multiply(const char & c)
	{
		if (c == '0') { s = "0"; return; }
		if (c == '1') { return; }
		int b = c - '0';
		string temp = s;
		for (int i = 0; i < b-1; i++) {
			add(temp);
		}
	}
	//b.lenght() must be less than s.length()
	void LargeDate::subtract(const string& b) {
		/*
		int downFlag = 0;
		string::iterator a_itr = s.begin();
		string::const_iterator b_itr = b.begin();
		bool b_endFlag = (b_itr == b.end());
		while ((downFlag) || !b_endFlag) {
			int b_val;
			// compute b_val
			if (b_endFlag) { b_val = 0; }
			else { b_val = (*b_itr - '0'); }
			//compute subtract and downFlag
			if ((downFlag) && (*a_itr == '0')) {
				*a_itr = '9' - b_val;
			}
			else {
				int diff = (*a_itr - '0') - downFlag - b_val;
				downFlag = (diff >= 0) ? false : true;
				*a_itr = (downFlag) ? (10 + diff + '0') : (diff + '0');
			}
			//forward and control flow
			a_itr++;
			b_itr = (b_endFlag) ? b_itr : (b_itr + 1);
			b_endFlag = (b_itr == b.end());
			//assert s>b ,down highest bit,ended
			if ((*(a_itr - 1) == '0') && (a_itr == s.end())) {
				int i = s.length() - 1;
				while (s[i] == '0'&&i >pointPos) { i--; }
				s = s.substr(0, i + 1);
				break;}
		}
		*/
		string complement = s;
		for (auto&t: complement) { t= '9'; }
		for (int i = 0; i < b.size();i++) {
			complement[i] = '9' - b[i]+'0';}
		add(complement); add("1");
		s.erase(s.size() - 1, s.size());
	}
	bool LargeDate::operator >(const LargeDate& b)const {
		if (s.length() > b.s.length()) return true;
		if (s.length() < b.s.length()) return false;
		int top = s.length() - 1;
		while (top>=0) {
			if (s[top] != b.s[top]) {
				return (s[top] > b.s[top]) ? true : false;
			}
			top--;
		}
		return false;
	}
	void LargeDate::repair()
	{
		while (pointPos < 0) { s = "0" + s; pointPos++; }
		if (s == "0") { return; }
		int l = 0;
		while (s[l] == '0'&&l < pointPos) {
			l++;
		}
	
		pointPos -= l;
		s.erase(0, l);
		int h = s.size() - 1;
		while (s[h] == '0'&&h> pointPos) {
			h--;
		}
		if(h+1!=s.size()){ s.erase(h + 1, s.size()); }
		while (pointPos >= s.size()) { s.append("0"); }
		
	}

	ostream & operator<<(ostream & os, const LargeDate & ld)
	{
		os << ld.toString();
		return os;
	}

	istream & operator >> (istream & is, LargeDate & ld)
	{
		string t;
		is >> t;
		ld = LargeDate(t);
		return is;
	}
