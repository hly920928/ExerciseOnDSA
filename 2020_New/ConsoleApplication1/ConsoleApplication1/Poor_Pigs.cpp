//LeetCode 458. Poor Pigs
#include "mainHeader.h"

#include<unordered_map>
#include<cmath>
using namespace std;

 

inline bool canTest(unsigned int  pigs, unsigned int buckets, unsigned int remainTurn) {
	if (pow((remainTurn + 1), pigs) >= buckets)return true;
	return false;
}
int binarySearch(unsigned int lo, unsigned int hi, unsigned int buckets, unsigned int remainTurn) {
	if (lo == hi)return hi;
	if (hi - lo == 1) {
		if (canTest(lo, buckets, remainTurn))return lo;
		return hi;
	}
	unsigned int mid = (lo + hi) / 2;
	if (canTest(mid, buckets, remainTurn)) {
		return binarySearch(lo, mid, buckets, remainTurn);
	}
	else {
		return binarySearch(mid, hi, buckets, remainTurn);
	}

}
int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
	if (buckets == 1)return 0;
	int ans = 1;
	while (!canTest(ans, buckets, minutesToTest / minutesToDie))ans++;
	return ans;
}