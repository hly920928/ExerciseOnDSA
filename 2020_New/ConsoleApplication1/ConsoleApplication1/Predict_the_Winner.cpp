//LeetCode 486. Predict the Winner
#include "mainHeader.h"
using namespace std;
class dataPTW {
public:
	unsigned int total;
	unsigned int max;
	dataPTW(unsigned int t = 0, unsigned int m = 0) :total(t), max(m) {};
};
vector<vector<dataPTW>>* _table;
vector<int>* _nums;

dataPTW findMax_re(int lo,int hi) {
	return dataPTW();
}

bool PredictTheWinner(vector<int>& nums) {
	vector<vector<dataPTW>> table; _table = &table;
	_nums = &nums;
	table.resize(nums.size());
	for(auto& v: table)v.resize(nums.size());
	auto rst = findMax_re(0, nums.size() - 1);
	return rst.max > rst.total - rst.max;

}