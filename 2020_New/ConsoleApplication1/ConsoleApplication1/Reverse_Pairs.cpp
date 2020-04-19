#include "mainHeader.h"
using namespace std;
vector<int>* n;
int compareAndMerge(int lo,int hi) {
	auto& nums = *n;
	if (hi == lo)return 0;
	if (hi - lo == 1) {
		if (nums[lo] > nums[hi] * 2)return 1;
		return 0;
	}
	int mid = (lo + hi) / 2;
	int p1 = compareAndMerge(lo, mid-1);
	int p2 = compareAndMerge(mid, hi);
	//TODO compare two part
	int p3 = 0;
	inplace_merge(nums.begin()+lo,nums.begin()+mid, nums.begin()+hi+1);
	return p1 + p2 + p3;
}
int reversePairs(vector<int>& nums) {
	n = &nums;
	return compareAndMerge(0,nums.size()-1);
}