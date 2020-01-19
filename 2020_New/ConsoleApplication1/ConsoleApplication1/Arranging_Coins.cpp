#include "mainHeader.h"
#include <cmath>
int arrangeCoins(int n) {
	unsigned long long d = 1 + 4* 2* (unsigned long long)n;
	int ans = (1 + sqrt(d)) / 2;
	return  ans -1;
}