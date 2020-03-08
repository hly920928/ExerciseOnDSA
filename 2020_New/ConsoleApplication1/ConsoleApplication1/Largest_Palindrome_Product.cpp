//479. Largest Palindrome Product
#include "mainHeader.h"
using namespace std;
int largestPalindrome(int n) {
	if (n == 1)return 9;
	unsigned long long M = pow(10, n);
	unsigned long long a = 2;
	unsigned long long p = 0;
	while (a < M) {
		unsigned long long up = M - a;
		string str = to_string(up);
		reverse(str.begin(), str.end());
		unsigned long long low = stoull(str);
	
		if (a * a - low * 4 >= 0) {
			unsigned long long d = a * a - low * 4;
			unsigned long long sr = sqrt(d);
			if (sr * sr == d) {
				 p=up* M + low;
				 break;
			}
		}
		a++;
	}
	return p % 1337;
}