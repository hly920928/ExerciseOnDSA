//LeetCode 462. Minimum Moves to Equal Array Elements II
#include "mainHeader.h"
#include <algorithm>
using namespace std;
int minMoves2(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	int  median = INT_MIN;
	if (nums.size() % 2 == 0) {
		int median_lo = (nums.size() - 1 - 1) / 2;
		int median_hi= (nums.size() - 1+ 1) / 2;
		median = (nums[median_lo] + nums[median_hi]) / 2;
	}
	else {
		int median_lo = (nums.size() - 1) / 2;
		median = (nums[median_lo]);
		
	}
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		ans += abs(nums[i] - median);
	}
	return ans;
}