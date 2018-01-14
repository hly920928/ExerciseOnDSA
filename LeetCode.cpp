#include "stdafx.h"
#include "LeetCode.h"
using namespace std;
void reCursive(vector<string>& ans, const string& digits, const string* map, string& t) {
	int n = t.size(); int ds = digits.size();
	if (n == ds)return;
	for (char i : map[digits[n] - '0']) {
		t.push_back(i);
		if (n + 1 == ds) {
			ans.push_back(t);
		}else{ reCursive(ans, digits, map, t); }
		t.pop_back();
	}
}
vector<string> letterCombinations(string digits)
{
	vector<string> ans;
	string t = "";
	string map[10];
	map[2] = "abc";
	map[3] = "def";
	map[4] = "ghi";
	map[5] = "jkl";
	map[6] = "mno";
	map[7] = "pqrs";
	map[8] = "tuv";
	map[9] = "wxyz";
	reCursive(ans, digits, map, t);
	return ans;
}
