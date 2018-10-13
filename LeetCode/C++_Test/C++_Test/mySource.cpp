#include "stdafx.h"
#include "myHeader.h"
#include "iostream"
#include<algorithm>
using namespace std;
vector<int>*numsCRS;
vector<int>*sumCRS;
int countCRS;
int lowerCRS; int upperCRS;
bool inline inInterval(int x) {
	return (x >= lowerCRS&&x <= upperCRS);
}
void countRangeSumRe(int lo, int hi) {
	auto& nums = *numsCRS;
	auto& sums = *sumCRS;
	if (lo == hi) {
		if (inInterval(nums[lo]))countCRS++;
		return;
	}
	if (hi - lo == 1) {
		if (inInterval(nums[hi]))countCRS++;
		if (inInterval(nums[lo]))countCRS++;
		if (inInterval(nums[lo] + nums[hi]))countCRS++;
		return;
	}
	int mid = (hi + lo) / 2;
	countRangeSumRe(lo, mid);
	countRangeSumRe(mid + 1, hi);
	//merge

	inplace_merge(sums.begin() + lo, sums.begin() + mid + 1, sums.begin() + hi + 1);
}
int countRangeSum(std::vector<int>& nums, int lower, int upper) {
	numsCRS = &nums;
	int n = nums.size();
	if (n == 0)return 0;
	vector<int>sum;
	sumCRS = &sum; countCRS = 0;
	int cum = 0; lowerCRS = lower; upperCRS = upper;
	for (auto&i : nums) {
		cum += i; sum.push_back(cum);
	}
	return countCRS;
}