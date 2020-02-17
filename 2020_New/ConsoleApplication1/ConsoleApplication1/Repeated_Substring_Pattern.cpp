#include "mainHeader.h"
#include <stack>
using namespace std;

bool repeatedSubstringPattern(string s) {
	if (s.size() < 2)return false;
	int len = 1;
	while (true) {
		if (s.size() % len != 0) {
			len++; continue;
		}
		if(2*len> s.size())return false;
		for (int i = len; i < s.size(); i++) {
			if (s[i % len] != s[i]) goto f1;
		}
		return true;
	f1:
		len++;
	}
	return false;
}