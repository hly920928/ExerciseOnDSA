//491. Increasing Subsequences

#include "mainHeader.h"
using namespace std;
vector<vector<int>> findSubsequences(vector<int>& nums) {
	vector<vector<int>> temp;
	for (int i = 0; i < nums.size(); i++) {
		int post_len = temp.size();
		for (int j = 0; j < post_len; j++) {
			auto& v = temp[j];
			if (v[v.size() - 1] <= nums[i]) {
				temp.push_back(v);
				temp[temp.size() - 1].push_back(nums[i]);
			}
	   }
		temp.push_back(vector<int>({ nums[i] }));
	}
	sort(temp.begin(), temp.end());
	vector<vector<int>> ans;
	for (int i = 1; i < temp.size(); i++) {
		auto& v = temp[i];
		if (v.size() >= 2 && v != temp[i - 1]) {
			ans.push_back(v);
		}
	}
	return ans;
}