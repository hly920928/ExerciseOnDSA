//483. Smallest Good Base
#include "mainHeader.h"
using namespace std;
unsigned long long getNum(unsigned long long base, int digit) {
	unsigned long long now = 1; unsigned long long sum = 0;
	for (int i = 0; i < digit; i++) {
		sum += now;
		now *= base;
	}
	return sum;
}
char isTarget(unsigned long long n, int digit, unsigned long long base) {
	if (base == 1634 && digit == 7) {
		auto num = getNum(1634, 7);
		auto num_1 = getNum(986, 7);
		int i = 0;
	}
	unsigned long long now = 1; unsigned long long sum = 0;
	for (int i = 0; i < digit; i++) {
		if (sum >=n)return 'H';

		unsigned long long p_sum = sum;
		sum += now;
		if(p_sum>sum)return 'H';//overflow
		unsigned long long p_now = now;
		now *= base;
		if (p_now > now)return 'H';//overflow
		
	}
	if (sum == n)return 'E';
	if (sum>n)return 'H';
	if (sum < n)return 'L';
	return 'U';
}
unsigned long long binarySearch_re(unsigned long long n, int digit, unsigned long long lo, unsigned long long hi) {
	if (lo == hi) {
		if (isTarget(n, digit, lo)=='E')return lo;
		return 0;
	  }
	if (hi - lo == 1) {
		if (isTarget(n, digit, lo) == 'E')return lo;
		if (isTarget(n, digit, hi) == 'E')return hi;
		return 0;
	}
	unsigned long long m = (hi + lo) / 2;
	char rtn = isTarget(n, digit, m);
	if (rtn == 'E')return m;
	if (rtn == 'H')return binarySearch_re(n, digit, lo, m - 1);
	if (rtn == 'L')return binarySearch_re(n, digit, m+1, hi);
	return 0;
}
unsigned long long findSmallestGoodBase(unsigned long long n,int digit) {
 
	unsigned long long ans = binarySearch_re(n, digit,2,n-1);
	if (ans !=0)return ans;
	return 0;
 }
string smallestGoodBase(string n) {
	if(n=="1")return "1";

	unsigned long long _n = strtoull(n.data(),NULL,10);
	int max_digit = log2(_n); 
	max_digit++;
	for (int i = max_digit; i >= 1; i--) {
		unsigned long long ans = findSmallestGoodBase(_n, i);
		if (ans != 0)return to_string(ans);
	}
	return "0";
}