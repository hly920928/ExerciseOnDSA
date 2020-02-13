//LeetCode 455. Assign Cookies
#include "mainHeader.h"
#include <algorithm>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int ans = 0; int i1 = 0; int i2 = 0;
	while (true) {
		if (i1 >= g.size() || i2 >= s.size())break;
		if (s[i2]>=g[i1]) {
			ans++; i2++; i1++;
		}
		else {
			i2++;
		}
	}
	return ans;
}