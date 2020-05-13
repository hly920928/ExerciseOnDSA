
//LeetCode 496. Next Greater Element I

#include "mainHeader.h"
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	stack<int>stk;
	unordered_map<int, int>table;
	for (int i = 0; i < nums2.size(); i++) {
		while (!stk.empty() && stk.top() < nums2[i]) {
			table[stk.top()] = nums2[i];
			stk.pop();
		}
		stk.push(nums2[i]);
	}
	while (!stk.empty()) {
		table[stk.top()] = -1;
		stk.pop();
	}
	vector<int>ans; ans.resize(nums1.size());
	for (int i = 0; i < nums1.size(); i++) {
		ans[i] = table[nums1[i]];
	}
	return ans;
}