//LeetCode 461. Hamming Distance
#include "mainHeader.h"
int hammingDistance(int x, int y) {
 
	unsigned int t =  x ^ y;
	int ans = 0;
	while (t != 0) {
		ans += t & 1;
		t = t >> 1;
	}
	return ans;
}