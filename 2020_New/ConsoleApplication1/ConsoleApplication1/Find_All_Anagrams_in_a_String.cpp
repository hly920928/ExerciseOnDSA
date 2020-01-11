//LeetCode 438. Find All Anagrams in a Strings
#include "mainHeader.h"
#include <string>
#include <algorithm>
using namespace std;

bool isSame(const int a[], const int b[]) {
	for (int i = 0; i < 26; i++) {
		if (a[i] != b[i])return false;
	}
	return true;
}
std::vector<int> findAnagrams(std::string s, std::string p) {
    vector<int> ans;
    if (s.size() < p.size())return ans;
	long long   len = p.size();

	int fp[26];	int f_now[26];
	for (int& i : fp)i = 0;
	for (int& i : f_now)i = 0;

	for (char c : p)fp[c - 'a']++;
	for (int i = 0; i < len; i++)f_now[s[i] - 'a']++;
	if (isSame(fp, f_now))ans.push_back(0);
	for (int i = 1; s.size() - 1 - i + 1 >= len; i++) {
		f_now[s[i-1] - 'a']--;
		f_now[s[i +len-1] - 'a']++;
		if (isSame(fp, f_now))ans.push_back(i);
	}
	return ans;
}