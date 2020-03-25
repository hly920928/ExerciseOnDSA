//LeetCode 486. Predict the Winner
#include "mainHeader.h"
using namespace std;
class dataPTW {
public:
	unsigned int total;
	unsigned int max;
	dataPTW(unsigned int t = 0, unsigned int m = 0) :total(t), max(m) {};
	bool isZero()const {
		return total == 0 && max == 0;
	}
};
vector<vector<dataPTW>>* _table;
vector<int>* _nums;

dataPTW findMax_re(int lo,int hi) {
	auto& nums = *_nums;
	auto& table = *_table;
	auto rst = table[lo][hi];
	if (!rst.isZero())return rst;
	if (lo == hi) {
		dataPTW ans(nums[lo], nums[lo]);
		table[lo][hi] = ans;
		return ans;
	}
	auto rst_lo = findMax_re(lo + 1, hi);
	auto rst_hi = findMax_re(lo, hi-1);
	int total = rst_lo.total + nums[lo];
	int sum_lo = rst_lo.total - rst_lo.max+ nums[lo];
	int sum_hi = rst_hi.total - rst_hi.max+ nums[hi];
	if (sum_lo > sum_hi) {
		dataPTW ans(total, sum_lo);
		table[lo][hi] = ans;
		return ans;
	}
	else {
		dataPTW ans(total, sum_hi);
		table[lo][hi] = ans;
		return ans;
	}
}

bool PredictTheWinner(vector<int>& nums) {
	if (nums.size() == 1)return true;
	vector<vector<dataPTW>> table; _table = &table;
	_nums = &nums;
	table.resize(nums.size());
	for(auto& v: table)v.resize(nums.size());
	auto rst = findMax_re(0, nums.size() - 1);
	return rst.max >= rst.total - rst.max;

}