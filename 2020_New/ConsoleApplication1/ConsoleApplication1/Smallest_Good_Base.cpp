//483. Smallest Good Base
#include "mainHeader.h"
using namespace std;
int binarySearch_re(unsigned long long n, int digit,int lo,int hi) {
	return -1;
}
int findSmallestGoodBase(unsigned long long n,int digit) {
	int ans = binarySearch_re(n, digit,2,n);
	if (ans != -1)return ans;
	return -1;
 }
string smallestGoodBase(string n) {
	unsigned long long _n = strtoull(n.data(),NULL,10);
	int max_digit = log2(_n);
	for (int i = max_digit; i >= 1; i--) {
		int ans = findSmallestGoodBase(_n, i);
		if (ans != -1)return to_string(ans);
	}
	return to_string(-1);
}