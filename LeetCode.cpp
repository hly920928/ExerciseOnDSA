#include "stdafx.h"
#include "LeetCode.h"
#include <algorithm>
using namespace std;
void twoSum(int twoSum,const vector<int>& nums, vector<int>&cur, int other_id, vector<vector<int>>& ans) {
	if (nums.size() - other_id<2)return;
	int head = other_id + 1; int tail = nums.size() - 1;
	int two_Sum = twoSum;
	while (true) {
		if (head >= tail)break;
		if ((nums[head] + nums[tail] > two_Sum) || (tail<nums.size() - 1 && nums[tail] == nums[tail + 1])) {
			tail--; continue;
		}
		if ((nums[head] + nums[tail] < two_Sum) || (head>other_id + 1 && nums[head] == nums[head - 1])) {
			head++; continue;
		}
		cur.push_back(nums[head]); cur.push_back(nums[tail]);
			ans.push_back(cur);
		cur.pop_back(); cur.pop_back();
		head++; tail--;
	}
}
void threeSum(int threeSum,const vector<int>& nums, vector<int>&cur, int head, vector<vector<int>>& ans) {
	for (int i = head +1; i < nums.size(); i++) {
		if (nums.size() - i<3)break;
		int now = nums[i];
		if (now + 2 * nums[i+1] > threeSum)break;
		if (now + 2 * nums[nums.size() - 1] <threeSum)continue;
		if (i!= head + 1 &&now ==nums[i-1])continue;
		cur.push_back(now);
		twoSum(threeSum-now, nums, cur, i, ans);
		cur.pop_back();
	}
};
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> ans;
	if (nums.size() == 0)return ans;
	vector<int> cur;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		if (nums.size() - i<4)break;
		int now = nums[i];
		if (now +3 * nums[i + 1] > target)break;
		if (now +3 * nums[nums.size() - 1] <target)continue;
		if (i != 0 && now == nums[i - 1])continue;
		cur.push_back(now);
		threeSum(target - now, nums, cur, i, ans);
		cur.pop_back();
	}
	return ans;
}
ListNode * removeNthFromEnd(ListNode * head, int n)
{
	ListNode* end= head; ListNode* nth=head; int cnt = 0;
	ListNode* pre = head;
	while (end != nullptr) {
		end = end->next;
		if (cnt <n)cnt++;
		else{pre = nth;
			nth = nth->next;}
	}
	if (nth == head) 
		head = head->next;
	else pre->next = nth->next;
	//delete nth;
	return head;
}
bool isValid(string s)
{
	stack<char> stk;
	char isPop='/';
	for (char c : s){ {
		isPop = '/';
		switch (c) {
		case '(': {
			isPop = 'u'; break; }
		case '[': {
			isPop = 'u'; break; }
		case '{': {
			isPop = 'u'; break; }
		case ')': {
			if (stk.empty() || stk.top() != '(') return false;
			isPop = 'o'; break; }
		case ']': {
			if (stk.empty() || stk.top() != '[') return false;
			isPop = 'o'; break; }
		case '}': {
			if (stk.empty() || stk.top() != '{') return false;
			isPop = 'o'; break; }
		}
				  if (isPop == 'o') stk.pop();
				  if (isPop == 'u') stk.push(c);
		}
	}
	return stk.empty();
}

void reCursive(vector<string>& ans, const string& digits, const string* map, string& t) {
	int n = t.size(); int ds = digits.size();
	if (n == ds)return;
	for (char i : map[digits[n] - '0']) {
		t.push_back(i);
		if (n + 1 == ds) {
			ans.push_back(t);
		}else{ reCursive(ans, digits, map, t); }
		t.pop_back();
	}
}
vector<string> letterCombinations(string digits)
{
	vector<string> ans;
	string t = "";
	string map[10];
	map[2] = "abc";
	map[3] = "def";
	map[4] = "ghi";
	map[5] = "jkl";
	map[6] = "mno";
	map[7] = "pqrs";
	map[8] = "tuv";
	map[9] = "wxyz";
	reCursive(ans, digits, map, t);
	return ans;
}


