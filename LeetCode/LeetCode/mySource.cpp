#include "stdafx.h"
#include "myHeader.h"
#include "iostream"
#include<algorithm>
using namespace std;
vector<int>*numsCRS;
vector<long long>*sumCRS;
int countCRS;
int lowerCRS; int upperCRS;
bool inline inInterval(long long x) {
	return (x >= lowerCRS&&x <= upperCRS);
}
void countRangeSumRe(int lo, int hi) {
	auto& nums = *numsCRS;
	auto& sums = *sumCRS;
	auto& count = countCRS;
	if (hi == lo)return;
	if (hi-lo==1) {
		if (inInterval(sums[hi] - sums[lo]))countCRS++;
		if (sums[lo] > sums[hi])swap(sums[lo], sums[hi]);
		return;
	}
    int mid = (hi + lo) / 2;
	countRangeSumRe(lo, mid);
	countRangeSumRe(mid+1,hi);
	//merge
	int lo_pos = mid + 1; int hi_pos = mid + 1;
	long long lo_bound = LONG_MAX; 	long long  hi_bound = LONG_MIN;
	for (int i = lo; i <= mid; i++) {
		lo_bound = lowerCRS+ sums[i];
		hi_bound = upperCRS + sums[i]; 
		while (lo_pos < hi + 1 && sums[lo_pos] < lo_bound)lo_pos++;
		while (hi_pos < hi+1 && sums[hi_pos] <=hi_bound)hi_pos++;
		if (lo_pos == hi + 1 && hi_pos == hi + 1)break;
		countCRS += hi_pos - lo_pos;
	}
	inplace_merge(sums.begin() + lo, sums.begin() + mid + 1, sums.begin() + hi + 1);
}
int countRangeSum(std::vector<int>& nums, int lower, int upper) {
	numsCRS = &nums;
	int n = nums.size();
	if (n == 0)return 0;
	vector<long long>sum;  
	sumCRS = &sum; countCRS = 0; sum.push_back(0);
	long long cum = 0; lowerCRS = lower; upperCRS = upper;
	for (auto&i : nums) {cum += i; sum.push_back(cum);}
	countRangeSumRe(0, n);
	return countCRS;
}