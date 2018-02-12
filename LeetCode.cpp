#include "stdafx.h"
#include "LeetCode.h"
#include <algorithm>
#include <bitset>
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
			if (ptr2 == nullptr)goto End;
			stk.push(ptr2->val);
			ptr2 = ptr2->next;
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

int removeDuplicates(vector<int>& nums)
{ 
	if (nums.size() == 0)return 0;
	int n = 0;
	for (int cur = 0; cur < nums.size(); cur++) {
		if (nums[cur] != nums[n]) {
			nums[n + 1] = nums[cur];
			n++;
		}
	}
	nums.resize(n+1);
	return n+1;
}

int removeElement(vector<int>& nums, int val)
{
	if (nums.size() == 0)return 0;
	int id1 = 0; 
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		if (nums[i] != val) {
			nums[id1] = nums[i];
			id1++;
		}
	}
	nums.resize(id1);
	return id1;
}
void buildNext_v2(vector<int>& next, const string& p, int j) {
	if (j == 0) { next[j] = -1; return; }
	int tryPos = next[j - 1];
	while (true) {
		if (tryPos == -1) {
			next[j] = 0; break;
		}
		if (p[tryPos] == p[j - 1]) {
			next[j] = tryPos + 1; break;
		}
		tryPos = next[tryPos];
	}
}
int strStr(string m, const string p) {
	vector<int>next; next.resize(p.size());
	int size_n = p.size(); int size_m = m.size();
	for (int i = 0; i < size_n; i++)buildNext_v2(next, p, i);
	int i = 0; int j = 0;
	while (true) {
		if (i == size_n) {
			if (j <= size_m)return j - i;
			else return j;
		}
		if (j == size_m)return -1;
		if (m[j] == p[i]) { i++; j++; }
		else {
			i = next[i];
			if (i == -1) { i++; j++; };
		}
	};
}

int divide(long long dividend, int divisor)
{
	 int n = 0;
	bool isNeg = true;
	if ((dividend > 0 && divisor > 0) ||
		(dividend < 0 && divisor < 0))
		isNeg = false;
	unsigned int dd = abs(dividend);
	unsigned int dr = abs(divisor);
	if (dd == 0 || dr > dd)return 0;
	unsigned int one = 1;
	while (dr << 1> dr) {
		dr = dr<< 1;
		one=one<<1;
	}
	while(one>0){
		if (dd >=dr) {
			n += one;
			dd -= dr;
		}
		dr = dr >>1;
		one = one>>1;
	}
	return isNeg?n*-1:n;
}
vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> ans;
	sort(words.begin(), words.end());
	unordered_map<string,int>hashmap;
	
	int word_n = words.size(); int o_word_n = word_n;
	for (int i = 0; i < word_n; i++)
		hashmap[words[i]]++;
	auto itr = unique(words.begin(), words.end());
	words.erase(itr, words.end());
	 word_n = words.size();
	vector<int>fre; fre.resize(word_n);
	for (int i = 0; i < word_n; i++) {
		fre[i] = hashmap[words[i]];
		hashmap[words[i]] = i;
	}

	int word_size = words[0].size();
	string t; t.resize(word_size);
	int s_n = s.size();
	vector<int> table; table.resize(s_n);
	for (int i = 0; i < s_n; i++) {
		if (i + word_size >s_n) {
			table[i] =-1; continue;
		}
		copy(s.begin()+i,s.begin()+i + word_size, t.begin());
		auto itr = hashmap.find(t);
		if (itr != hashmap.end()) {
			table[i] = (itr->second);
		}
		else table[i] = -1;
	}


	int hasFound = 0;
   vector<int>Found;
	for (int i = 0; i < s_n; i++) {
		hasFound = 0; Found.clear(); Found.resize(word_n);
		copy(fre.begin(), fre.end(), Found.begin());
	if (table[i] == -1)continue;
	int cur = i;
	while (true) {
		int id_cur = table[cur];
	if (Found[id_cur] == 0)break;
	Found[id_cur]--;
	cur = cur + word_size;
	hasFound++;
	if (hasFound == o_word_n)ans.push_back(i);
	if (cur >= s_n || table[cur] == -1)break;
	}
	}
	return ans;
}

void nextPermutation(vector<int>& nums)
{
	int n = nums.size();
	if (n < 2)return;
	n--; int id = -1;
	for (int i = n; i > 0; i--) {
		if (nums[i - 1] < nums[i]) {
			id = i - 1; break;
		}
	}
	if (id == -1) {
		reverse(nums.begin(), nums.end());
		return;
	}
	sort(nums.begin() + id + 1, nums.end());
	auto itr = lower_bound(nums.begin() + id + 1, nums.end(),nums[id]);
	int t = nums[id];
	while (*itr == t)itr++;
	swap(nums[id], *itr);
}
void inline expand(vector<int>& table,string& s, int& lo, int& hi) {
	int n = s.size() - 1; bool isExpand = false;
	while (true) {
		isExpand = false;
		if (lo >= 0 && hi <= n&&s[lo] == '('&&s[hi] == ')') {
			s[lo] = '.'; s[hi] = '.';
			lo--; hi++; isExpand = true;
		}
		if (lo>0&&s[lo]==')'&&s[lo-1] == '(') {
			s[lo] = '.'; s[lo-1] = '.';
			lo=lo-2; isExpand = true;
		}
		if (hi<n&& s[hi] == '('&&s[hi+1] == ')') {
			s[hi] = '.'; s[hi + 1] = '.';
			hi=hi+2; isExpand = true;
		}
		if (!isExpand) {
			if (lo >= 0 && lo <= n&&table[lo] != -2) {
				lo = table[lo];
			}else break;
		}
	}
}
int longestValidParentheses(string s)
{
	int n = s.size()-1; int lo = 0; int hi = 0;
	int i = 0; int max_l = 0;
	vector<int> table; table.resize(n + 1);
	while (true) {
		if (i >=n)break;
		if (s[i] == '('&&s[i + 1] == ')') {
			lo = i; hi = i + 1;
			expand(table,s, lo, hi);
			table[hi - 1] = lo;
			int len = hi - lo - 1;
			max_l = (max_l > len) ? max_l : len;
			i = hi;
		}
		else {
			table[i] = -2; i++;
		}
	}
	return max_l;
}

int search(vector<int>& nums, int target)
{

	 int n = nums.size()-1;
	 int p =-1;
	if (n == -1)return -1;
	for (int i = 0; i < n; i++) {
		if (nums[i] > nums[i + 1]) {
			p = i + 1; break;
		}
	}
	if (p == -1) {
		auto itr = lower_bound(nums.begin(), nums.end(), target);
		if (itr == nums.end() || *itr != target)return -1;
		return itr - nums.begin();
	}
	if (target < nums[0]) {
		auto itr = lower_bound(nums.begin() + p, nums.end(), target);
		if (itr==nums.end()||*itr != target)return -1;
		return itr - nums.begin();
	}
	else {
		auto itr = lower_bound(nums.begin(), nums.begin() + p, target);
		if (itr == nums.begin() + p||*itr != target)return -1;
		return itr - nums.begin();
	}
}
vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> ans;
	int lo = 0; int hi = nums.size() - 1;

	int lb = -1; int hb = -1;
	if (hi == -1)goto End;
	while (true) {
		if (hi - lo <= 1) {
			if (nums[lo] == target) {
				lb = lo; break;
			}
			if (nums[hi] == target) {
				lb = hi; break;
			}
			break;
		  }
		int min = (hi + lo) / 2;
		if (nums[min] >= target) {
			hi = min;
		}
		else if (nums[min] < target) {
			lo = min;
		}
	}
	lo = 0; hi = nums.size() - 1;
	while (true) {
		if (hi - lo <= 1) {
			if (nums[hi] == target) {
				hb = hi; break;
			}
			if (nums[lo] == target) {
				hb = lo; break;
			}
			break;
		}
		int min = (hi + lo) / 2;
		if (nums[min] >target) {
			hi = min;
		}
		else if (nums[min] <= target) {
			lo = min;
		}
	}
	End:
	ans.push_back(lb); ans.push_back(hb);
	return ans;
}

int searchInsert(vector<int>& nums, int target)
{
	int lo = 0; int hi = nums.size() - 1;
	if (hi == -1)return 0;
	while (true) {
		if (hi - lo <= 1) {
			if (nums[lo] >= target) {
				return lo;
			}
			if (nums[hi] >= target) {
				return hi;
			}
			return hi+1;
		}
		int min = (hi + lo) / 2;
		if (nums[min] >= target) {
			hi = min;
		}
		else if (nums[min] < target) {
			lo = min;
		}
	}

	//return  	lower_bound(nums.begin(), nums.end(), target)-nums.begin();
}

bool isValidSudoku(vector<vector<char>>& board)
{
	bitset<10>table; table.reset();
	for (int i = 0; i < 9; i++) {
		table.reset();
		for (int j= 0; j < 9;j++) {
			char t = board[i][j];
			if (t== '.')continue;
			if (table[t - '0'])return false;
			table[t - '0'] = true;
		}
	}
	for (int i = 0; i < 9; i++) {
		table.reset();
		for (int j = 0; j < 9; j++) {
			char t = board[j][i];
			if (t == '.')continue;
			if (table[t - '0'])return false;
			table[t - '0'] = true;
		}
	}
	char x[] = { 0,0,0,3,3,3,6,6,6 };
	char y[] = { 0,3,6,0,3,6,0,3,6 };
	for (int i = 0; i < 9; i++) {
		table.reset();
		int bx = x[i]; int by = y[i];
		for (int ox= 0; ox < 3; ox++) {
			for (int oy = 0; oy < 3; oy++) {
				char t = board[bx+ox][by+oy];
				if (t == '.')continue;
				if (table[t - '0'])return false;
				table[t - '0'] = true;
			}
		}
	}
	return true;
}
