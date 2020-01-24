//LeetCode 448. Find All Numbers Disappeared in an Array
#include "mainHeader.h"

using namespace std;
std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {


	for (int i = 0; i < nums.size(); i++) {
		int now = abs(nums[i]);
		if (nums[now - 1] > 0) {
			nums[now - 1] = -1 * nums[now - 1];
		}
	}

	vector<int>ans;
	for (int i = 0; i < nums.size(); i++) {
		 
		if (nums[i] > 0) {
			ans.push_back(i + 1);
		}
	}
	return ans;
}