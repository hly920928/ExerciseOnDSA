#include "mainHeader.h"
using namespace std;
vector<int>* n;
int compareAndMerge(int lo,int hi) {
	auto& nums = *n;
	if (hi == lo)return 0;
	if (hi - lo == 1) {
		int ans = 0;
		if ((long long) nums[lo] >((long long)nums[hi])* 2)ans=1;
		if (nums[lo] > nums[hi])swap(nums[lo], nums[hi]);
		return ans;
	}
	int mid = (lo + hi) / 2;
	int p1 = compareAndMerge(lo, mid-1);
	int p2 = compareAndMerge(mid, hi);
	//TODO compare two part
	int p3 = 0;
	for (int i = mid; i <= hi; i++) {
		long long t = 2 *(long long) nums[i] + 1;
		auto itr_t = lower_bound(nums.begin()+lo,nums.begin()+mid,t);
		p3 += (nums.begin() + mid) - itr_t;
	}
	inplace_merge(nums.begin()+lo,nums.begin()+mid, nums.begin()+hi+1);
	return p1 + p2 + p3;
}
int reversePairs(vector<int>& nums) {
	if (nums.size() == 0)return 0;
	n = &nums;
	return compareAndMerge(0,nums.size()-1);
}