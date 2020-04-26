//LeetCode 494. Target Sum


#include "mainHeader.h"
#include <unordered_map>
using namespace std;

int* _ans;
vector<int>* _nums_1;
vector<int>* _part_sum;
vector<int>* _count_zero;
unordered_map<unsigned long long,int>* _record;
inline unsigned long long intToULL(int a,int b) {
	unsigned long long _a = a;
	unsigned long long _b = b;
		return (_a << 32) + _b;
}
int Sum;
int findTargetSumWays_re(int pos, int now_sum) {
	int ans = 0;
	vector<int>& nums = *_nums_1;
	vector<int>& part_sum= * _part_sum;
	vector<int>& count_zero = *_count_zero;

	unordered_map<unsigned long long, int>& record=*_record;
	auto itr = record.find(intToULL(pos, now_sum));
	if (itr != record.end())return itr->second;
	if (pos == nums.size() - 1) {
		if(now_sum+ nums[pos]==Sum)ans++;
		if(now_sum - nums[pos] == Sum)ans++;
		return ans;
	}
	if (part_sum[pos] == 0) {
		if (now_sum == Sum)ans += pow(2, count_zero[pos]);
		return ans;
	}
	if (now_sum + part_sum[pos] == Sum) {
		ans+= pow(2, count_zero[pos]); return ans;
	}
	if (now_sum- part_sum[pos] == Sum) {
		ans+= pow(2, count_zero[pos]); return ans;
	}
	if (now_sum + part_sum[pos]<Sum)return 0;
	if (now_sum - part_sum[pos] >Sum)return 0;
	int p1=findTargetSumWays_re(pos + 1, now_sum + nums[pos]);
	int p2 = findTargetSumWays_re(pos + 1, now_sum - nums[pos]);
	record[intToULL(pos, now_sum)] = p1 + p2;
	return p1 + p2;
}
int findTargetSumWays(vector<int>& nums, int S) {
	//int ans = 0; _ans = &ans;
	Sum = S;
	_nums_1 = &nums;
	int sum = 0;
	vector<int> part_sum; _part_sum = &part_sum;
	vector<int> count_zero; _count_zero = &count_zero;
	part_sum.resize(nums.size()); count_zero.resize(nums.size());
	int countZero = 0;
	unordered_map<unsigned long long, int>record; _record = &record;
	for (int i = nums.size() - 1; i >= 0; i--) {
		sum += nums[i];
		part_sum[i] = sum;
		if (nums[i] == 0)countZero++;
		count_zero[i] = countZero;
	}
	int ans=findTargetSumWays_re(0, 0);
	return ans;
}