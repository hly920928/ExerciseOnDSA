//LeetCode 473. Matchsticks to Square
#include "mainHeader.h"
using namespace std;

bool dfs(const vector<int>& nums, vector<int>& v, int target,int begin) {
    int n = nums.size();
    if (begin == n) {
        if ((v[0] == target) && (v[1] == target) && (v[2] == target) && (v[3] == target))  return true;
        else return false;
    }
    int max = *max_element(v.begin(), v.end());
    if (max<target && max + nums[n - 1]>target)return false;
    for (int i = 0; i < 4; i++) {
        if (v[i] <target && v[i] + nums[n - 1]>target)return false;
        if ((i != 0) && (v[i] == v[i - 1]))  continue;
        if (v[i] + nums[begin] > target)continue;



        v[i] += nums[begin];
        if (dfs(nums, v, target,begin + 1))  return true;
        v[i] -= nums[begin];
    }

    return false;
}

bool makesquare(vector<int>& nums) {
	if (nums.size()<4)return false;
	sort(nums.begin(), nums.end() );
	reverse(nums.begin(), nums.end());
	int sum = 0;
	for (int& i : nums)sum += i;
	if (sum % 4 != 0)return false;
	int target = sum / 4;
	vector<int> vals; vals.resize(4);
	vals[0] = 0; vals[1] = 0; vals[2] = 0; vals[3] = 0;
	return dfs(nums,vals,target,0);
}