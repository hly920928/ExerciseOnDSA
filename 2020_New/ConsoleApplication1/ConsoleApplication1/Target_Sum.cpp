//LeetCode 494. Target Sum


#include "mainHeader.h"
using namespace std;

int* _ans;
vector<int>* _nums;
vector<int>* _part_sum;
int Sum;
void findTargetSumWays_re(int pos, int now_sum) {

}
int findTargetSumWays(vector<int>& nums, int S) {
	int ans = 0; _ans = &ans; Sum = S;
	_nums = &nums;
	int sum = 0;
	vector<int> part_sum; _part_sum = &part_sum;
	part_sum.resize(nums.size());
	for (int i = nums.size() - 1; i >= 0; i--) {
		sum += nums[i];
		part_sum[i] = sum;
	}
	findTargetSumWays_re(0, 0);
	return ans;
}