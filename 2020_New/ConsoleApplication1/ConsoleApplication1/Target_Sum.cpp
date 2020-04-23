//LeetCode 494. Target Sum


#include "mainHeader.h"
using namespace std;

int* _ans;
vector<int>* _nums_1;
vector<int>* _part_sum;
int Sum;
void findTargetSumWays_re(int pos, int now_sum) {
	int& ans = *_ans;
	vector<int>& nums = *_nums_1;
	vector<int>& part_sum= * _part_sum;
	if (pos == nums.size() - 1) {
		if(now_sum+ nums[pos]==Sum|| now_sum -nums[pos] == Sum)ans++;
		return;
	}
	if (now_sum + part_sum[pos] == Sum) {
		ans++; return;
	}
	if (now_sum- part_sum[pos] == Sum) {
		ans++; return;
	}
	if (now_sum + part_sum[pos]<Sum)return;
	if (now_sum - part_sum[pos] >Sum)return;
	findTargetSumWays_re(pos + 1, now_sum + nums[pos]);
	findTargetSumWays_re(pos + 1, now_sum - nums[pos]);
}
int findTargetSumWays(vector<int>& nums, int S) {
	int ans = 0; _ans = &ans; Sum = S;
	_nums_1 = &nums;
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