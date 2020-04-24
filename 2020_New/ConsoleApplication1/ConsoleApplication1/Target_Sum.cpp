//LeetCode 494. Target Sum


#include "mainHeader.h"
using namespace std;

int* _ans;
vector<int>* _nums_1;
vector<int>* _part_sum;
vector<int>* _count_zero;
int Sum;
void findTargetSumWays_re(int pos, int now_sum) {
	int& ans = *_ans;
	vector<int>& nums = *_nums_1;
	vector<int>& part_sum= * _part_sum;
	vector<int>& count_zero = *_count_zero;
	if (pos == nums.size() - 1) {
		if(now_sum+ nums[pos]==Sum)ans++;
		if(now_sum - nums[pos] == Sum)ans++;
		return;
	}
	if (part_sum[pos] == 0) {
		if (now_sum == Sum)ans += pow(2, count_zero[pos]);
		return ;
	}
	if (now_sum + part_sum[pos] == Sum) {
		ans+= pow(2, count_zero[pos]); return;
	}
	if (now_sum- part_sum[pos] == Sum) {
		ans+= pow(2, count_zero[pos]); return;
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
	vector<int> count_zero; _count_zero = &count_zero;
	part_sum.resize(nums.size()); count_zero.resize(nums.size());
	int countZero = 0;
	for (int i = nums.size() - 1; i >= 0; i--) {
		sum += nums[i];
		part_sum[i] = sum;
		if (nums[i] == 0)countZero++;
		count_zero[i] = countZero;
	}
	findTargetSumWays_re(0, 0);
	return ans;
}