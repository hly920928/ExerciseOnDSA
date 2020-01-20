//442. Find All Duplicates in an Array
#include "mainHeader.h"
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
	vector<int> ans;
	for (int i = 0; i < nums.size(); i++) {
		int now = abs(nums[i]);
		if(nums[now-1]>0){
			nums[now - 1] = -nums[now -1];
		}
		else {
			ans.push_back(now);
		}
	
	}
	return 	 ans;
}