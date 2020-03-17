//481. Magical String
#include "mainHeader.h"
using namespace std;


int magicalString(int n) {
	if (n <= 1)return n;
	string s = "122";
	int ans = 1; int groupID = 1;
	while (s.size() < n) {
		char l1 = s[s.size() - 1];
		char l2 = s[s.size() - 2];
		if (l1 == l2) {
			if (l1 == '1') {
				s.push_back('2');
			}
			else {
				s.push_back('1');
			}
			groupID++;
		}
		else {
			if (s[groupID] == '1') {
				if (l1 == '1') {
					s.push_back('2');
				}
				else {
					s.push_back('1');
				}
				groupID++;
			}
			else {
				s.push_back(l1);
			}
		}
		if (s[s.size() - 1] == '1')ans++;
	}
	return ans;
}