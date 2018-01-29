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
struct heapIndex {
	int index;
	int val;
	ListNode* ptr;
	heapIndex(int i, ListNode* v) :index(i), ptr(v) , val(v->val){};
	bool  operator <(const heapIndex &b)const {
		return val > b.val;
	}
};
ListNode * mergeKLists(vector<ListNode*>& lists)
{
	ListNode *header = nullptr; int n = lists.size();
	ListNode *cur = nullptr;
	priority_queue<heapIndex> pq;
	for (int i = 0; i < n; i++) {
		if (lists[i] != nullptr) {
			pq.push(heapIndex(i, lists[i]));
			lists[i] = lists[i]->next;}
	}
	if (pq.size() != 0) {
		header = pq.top().ptr;
		cur= pq.top().ptr;}
	if (pq.empty())return header;
	while (true) {
		heapIndex top = pq.top(); pq.pop();
		if (pq.empty())break;
		if (lists[top.index] != nullptr)
		{
			pq.push(heapIndex(top.index, lists[top.index]));
			lists[top.index] = lists[top.index]->next;}
		cur->next = pq.top().ptr;
		cur = cur->next;
	}
	return header;
}
ListNode * mergeTwoLists(ListNode * l1, ListNode * l2)
{
	if (l1 == nullptr&&l2== nullptr)return nullptr;
	ListNode* curl1 = l1; ListNode* curl2 = l2;
	int vL1 = 0; int vL2 = 0;
	if (curl1 != nullptr)vL1 = curl1->val;
	else vL1 = INT_MAX;
	if (curl2 != nullptr)vL2 = curl2->val;
	else vL2 = INT_MAX;
	ListNode* header = nullptr;
	if (vL1 < vL2) {
		header = curl1;
		curl1 = curl1->next;
	}else {
		header = curl2;
		curl2 = curl2->next;
	}
	ListNode* cur = header;
	while (curl1 != nullptr&&curl2 != nullptr) {
		if (curl1->val < curl2->val) {
			cur->next = curl1;
			curl1 = curl1->next;}
		else {
			cur->next = curl2;
			curl2 = curl2->next;}
		cur = cur->next;
	}
	if(curl1 != nullptr)cur->next = curl1;
	if (curl2 != nullptr)cur->next = curl2;
	return header;
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
vector<string> ans;
string s;
int _n;
void gP_reCur(int nL,int nR,int p) {
	if (s.size() == _n * 2) {
		ans.push_back(s);
		return;
	}
	if (nL > 0) {
		s.push_back('(');
		gP_reCur(nL - 1, nR, p + 1);
		s.pop_back();
	}
	if (nR > 0 && p > 0) {
		s.push_back(')');
		gP_reCur(nL, nR-1, p - 1);
		s.pop_back();
	}
}
vector<string> generateParenthesis(int n) {
	_n = n;
	s.clear();
	ans.clear();
	gP_reCur(_n, _n, 0);
	return ans;
 }

ListNode * swapPairs(ListNode * head)
{
	auto ans = head;
	auto cur = head;
	if (cur == nullptr)return ans;
	while (true) {
		if (cur == nullptr|| cur->next == nullptr)break;
		swap(cur->val, cur->next->val);
		cur = cur->next;
		if (cur == nullptr)break;
		cur = cur->next;
		if (cur == nullptr)break;
	}
	return ans;
}

ListNode * reverseKGroup(ListNode * head, int k)
{
	auto ans = head;
	auto ptr1 = head;
	auto ptr2 = head;
	stack<int>stk;
	if (head == nullptr)return head;
	while (true) {
		for (int i = 0; i < k; i++) {
			stk.push(ptr2->val);
			ptr2 = ptr2->next;
			if (ptr2 == nullptr)goto End;
		}
		ptr2 = ptr1;
		for (int i = 0; i < k; i++) {
			ptr2->val = stk.top(); stk.pop();
			ptr2 = ptr2->next;
		}
		ptr1 = ptr2;
	}
	End:
	return ans;
}

