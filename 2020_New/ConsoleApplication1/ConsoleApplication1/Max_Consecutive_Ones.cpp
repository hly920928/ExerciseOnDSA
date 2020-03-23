//LeetCode 485. Max Consecutive Ones
#include "mainHeader.h"
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
	int ans = 0; int len = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1)len++;
		if (nums[i] ==0 || i == nums.size() - 1) {
			ans = max(ans, len);
			len = 0;
		}
	}
	return ans;
}