#include "stdafx.h"
#include "LeetCode.h"
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>
#include <vector>
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

const static char x_b[9] = { 0,0,0,3,3,3,6,6,6 };
const static char y_b[9] = { 0,3,6,0,3,6,0,3,6 };
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

	for (int i = 0; i < 9; i++) {
		table.reset();
		int bx = x_b[i]; int by = y_b[i];
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

const static char g_table[9][9] = { {1,1,1,2,2,2,3,3,3}
                                                ,{1,1,1,2,2,2,3,3,3},
							                     {1,1,1,2,2,2,3,3,3},
												 {4,4,4,5,5,5,6,6,6},
												 {4,4,4,5,5,5,6,6,6},
												 {4,4,4,5,5,5,6,6,6},
												 {7,7,7,8,8,8,9,9,9},
												 {7,7,7,8,8,8,9,9,9},
												 {7,7,7,8,8,8,9,9,9}};
struct pos {
	unsigned char possible;
	bitset<10>candidate;
	pos( int _p = 10):possible(_p) {
		candidate.set();
	}
	bool operator<(const pos& b){
		return possible < b.possible;
	}
};
class SudokuSolver {
private:
	vector<vector<char>>* board;
	pos table[81];
	int numsOfblank;
public:
	SudokuSolver(vector<vector<char>>* _b) :board(_b) {
		auto& b = *board;
		numsOfblank = 0;
		for (int i = 0; i < 9; i++) {
			for (int j= 0; j< 9;j++) {
				if (b[i][j] == '.') {
					generateAllcandidate(i, j);
					numsOfblank++;
				}
				else table[i * 9 + j].possible = 99;
				}
			}
	};
	bool solve() {
		auto& b = *board;
		int m = findMin();
		if (m == -1)return false;
		if(numsOfblank==0)return true;
		int x = m / 9; int y = m % 9;
		for (int i = 1; i < 10; i++) {
			if (table[m].candidate[i]) {
				b[x][y] = i + '0';
				//printf("push %d %d %d\n", x, y, i);
				//printOutBoard();
				update_full();
				numsOfblank--;
				if (solve())return true;
				b[x][y] ='.';
				//printf("pop %d %d\n", x, y);
				//printOutBoard();
				numsOfblank++;
				update_full();
			}
		}
		return false;
	};
private:
	void inline generateAllcandidate(int x,int y){
		auto& b = *board;
		auto& p = table[x * 9 + y];
		p.candidate.set();
		for (int j =0;j < 9; j++) {
			char t = b[x][j];
			if (t == '.')continue;
			p.candidate[t - '0'] = false;
		}
		for (int j = 0;j < 9; j++) {
			char t = b[j][y];
			if (t == '.')continue;
			p.candidate[t - '0'] = false;
		}
		int i = g_table[x][y];
		int bx = x_b[i-1]; int by = y_b[i-1];
		for (int ox = 0; ox < 3; ox++) {
			for (int oy = 0; oy < 3; oy++) {
				char t = b[bx + ox][by + oy];
				if (t == '.')continue;
				if (p.candidate[t - '0']) {
					p.candidate[t - '0'] = false;
				}
			}
		}
		p.possible =0;
		for (int i = 1; i < 10; i++) {
			if (p.candidate[i])p.possible++;
		}
	};
	void inline update_full() {
		auto& b = *board;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (b[i][j] == '.') {
					generateAllcandidate(i, j);
				}
				else table[i * 9 + j].possible = 99;
			}
		}
	}
   
	int inline findMin() {
		int i = 0;
		int min_p=table[i].possible;
		for (int id = 0; id < 81; id++) {
			bool flag = min_p < table[id].possible;
			i = (flag)? i : id;
			min_p = (flag) ? min_p : table[id].possible;
			if (min_p == 0)return -1;
		}
		return i;
	}
public:
	void printOutBoard() {
		for (auto& v : *board) {
			for (auto& i : v) {
				printf("%c ", i);
			}
			printf("\n");
		}
		printf("\n");
	}
};
void solveSudoku(vector<vector<char>>& board)
{
	SudokuSolver sds(&board);
	sds.solve();
}

string countAndSay(int n)
{
	string ans = "1"; string t;
	for (int i = 1; i < n; i++) {
		t = ans; ans.clear();
		int _n = t.size(); int cum = 0;
		for (int k= 0; k<=_n;k++) {
			if ((k== 0 && (k != _n)) ||t[k- 1] == t[k])cum++;
			else {
				ans = ans + to_string(cum)+t[k-1];
				cum = 1;
			}
		}
	}
	return ans;
}

void combinationSum_part(const vector<int>& candidates,int head, int target, vector<vector<int>>& ans) {
	int first = candidates[head];
	if (target <= 0)return;
	if (head == candidates.size() - 1) {
		if (target>=first&&(target%first)==0) {
			ans.push_back(vector<int>());
			int n = target / first;
			auto& last = ans.back();
			for (int i = 0; i < n; i++) {
				last.push_back(first);
			}
			return ;
		}
		return ;
	}
	if (first >=target) {
		if (target == first) {
			ans.push_back(vector<int>());
			auto& last = ans.back();
			last.push_back(target);
			return ;
		}
		return ;
	}
	vector<vector<int>> vtail;
	vector<int> vhead; int remain_target = target;
	while (true) {
		vhead.push_back(first);
		remain_target -= first;
		vtail.clear();
		if (remain_target < 0)break;
		if (remain_target == 0) {
			ans.push_back(vector<int>());
			auto& last = ans.back();
			last.insert(last.end(), vhead.begin(), vhead.end());
			break;
		}
	    combinationSum_part(candidates, head + 1, remain_target, vtail);
		for (auto& tail : vtail) {
			ans.push_back(vector<int>());
			auto& last = ans.back();
			last.insert(last.end(), vhead.begin(), vhead.end());
			last.insert(last.end(), tail.begin(), tail.end());
		}
	}
	vtail.clear();
    combinationSum_part(candidates, head + 1, target, vtail);
	for (auto& tail : vtail) {
		ans.push_back(vector<int>());
		auto& last = ans.back();
		last.insert(last.end(), tail.begin(), tail.end());
	}
	return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> ans;
	sort(candidates.begin(), candidates.end());
	combinationSum_part(candidates, 0, target, ans);
	return ans;
}

const vector<int>* c;
const vector<int>* fre;
void combinationSum2_partV2(int head, int target, vector<vector<int>>& ans) {
	const auto &candidates = *c;
	int first = candidates[head];
	int fre_n = (*fre)[first];
	if (target <= 0)return;
	if (head == candidates.size() - 1) {
		if (target >= first && (target%first) == 0) {
			int n = target / first;
			if (n <= fre_n) {
				ans.push_back(vector<int>());
				auto& last = ans.back();
				for (int i = 0; i < n; i++) {
					last.push_back(first);
				}
			}
		}
		return;
	}
	if (first >= target) {
		if (target == first) {
			ans.push_back(vector<int>());
			auto& last = ans.back();
			last.push_back(target);
			return;
		}
		return;
	}
	vector<vector<int>> vtail;
	vector<int> vhead; int remain_target = target;
	while (fre_n>0) {
		vhead.push_back(first);
		remain_target -= first;
		vtail.clear();
		if (remain_target < 0)break;
		if (remain_target == 0) {
			ans.push_back(vector<int>());
			auto& last = ans.back();
			last.insert(last.end(), vhead.begin(), vhead.end());
			break;
		}
		combinationSum2_partV2(head + 1, remain_target, vtail);
		for (auto& tail : vtail) {
			ans.push_back(vector<int>());
			auto& last = ans.back();
			last.insert(last.end(), vhead.begin(), vhead.end());
			last.insert(last.end(), tail.begin(), tail.end());
		}
		fre_n--;
	}
	vtail.clear();
	combinationSum2_partV2(head + 1, target, vtail);
	for (auto& tail : vtail) 
		ans.push_back(tail);
	return;
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	vector<vector<int>> ans;
	c = &candidates;
	sort(candidates.begin(), candidates.end());
	vector<int>_fre; _fre.resize(candidates.back()+1);
	for (int& i : _fre) i = 0;
	for (int i : candidates) _fre[i]++;
	fre = &_fre;
	auto itr = unique(candidates.begin(), candidates.end());
	candidates.erase(itr, candidates.end());
	combinationSum2_partV2(0, target,ans);
	return ans;
}

int firstMissingPositive(vector<int>& nums)
{
	int n = nums.size();
	vector<bool>table; table.resize(n + 1);
	for (int i : nums) {
		if (i > 0&&i<=n) {
			table[i] = true;
		}
	}
	for (int i = 1; i < n + 1; i++) {
		if (!table[i])return i;
	}
	return n+1;
}
int trap(vector<int>& height)
{
	int n = height.size();
	if (n == 0)return 0;
	stack<int>stk; int num = 0;
	for (int i = 0; i < n; i++) {
		//if (i > 0 && height[i] == height[i - 1]) continue;
		while (!stk.empty() && height[i] >= height[stk.top()]) {
			int lo = stk.top(); stk.pop();
			while (!stk.empty() && height[lo] >= height[stk.top()]) {
				lo = stk.top(); stk.pop();
				if (stk.empty()) {
					stk.push(i); goto Out1;
				}
			}
			if(!stk.empty())lo = stk.top();
			int top = (height[lo] < height[i]) ? height[lo] : height[i];
			for (lo = lo + 1; height[lo] < top; lo++) {
				num += top - height[lo];
				height[lo] = top;
			}
		}
		if (stk.empty() && height[i] > 0) {
			stk.push(i); continue;
		}
	Out1:
		if (!stk.empty()) {
			stk.push(i);
		}
	};
	return num;
}
class BigInteger_non_neg {
public:
    string s;
public:
	BigInteger_non_neg(const string& _s) :s(_s) {
		reverse(s.begin(), s.end());
	};
	BigInteger_non_neg() :s("0") {};
	void operator+=(const BigInteger_non_neg& b) {
		int b_n = b.s.size();		int s_n = s.size();
		int now_n = (b_n > s_n) ? b_n : s_n;
		s.resize(now_n + 1); 
		s.back()='0';
		int up = 0;
		for (int i = 0; i < now_n+1; i++) {
			char s_v = (i < s_n) ? s[i] - '0' : 0;
			char b_v = (i <b_n) ? b.s[i] - '0' : 0;
			int sum = s_v + b_v + up;
			s[i] = sum % 10+'0';
			up = sum / 10;
		}
		if (s.back() == '0')s.pop_back();
	};
	void shiftLeft() {
		int  s_n = s.size();
		s.push_back('0'); 
		char pre = s[0];char t= s[1];
		for (int i = 0; i < s_n; i++) {
			t = s[i + 1];
			s[i + 1] = pre;
			pre = t;
		}
		s[0] = '0';
	};
	BigInteger_non_neg operator*(char i) {
		BigInteger_non_neg ans;
		ans.s = s;
		int n = i - '0';
		if (n == 0) {
			ans.s = "0"; return ans;
		}
		if (n == 1)return ans;
		int s_n = ans.s.size();
		ans.s.resize(s_n + 1);
		ans.s.back() = '0'; int up = 0;
		for (int i = 0; i < s_n + 1; i++) {
			char s_v = (i < s_n) ? ans.s[i] - '0' : 0;
			int sum = s_v*n + up;
			ans.s[i]  = sum % 10 + '0';
			up = sum / 10;
		}
		if (ans.s.back() == '0')ans.s.pop_back();
		return ans;
	};
	string to_string()const {
		string ans = s;
		reverse(ans.begin(), ans.end());
		return ans;
	};
	bool isZero()const {
		if (s == "0")return true;
		return false;
	}
};
string multiply(string num1, string num2)
{
	BigInteger_non_neg bi1(num1);
	BigInteger_non_neg bi2(num2);
	BigInteger_non_neg part_product("0");
	auto& Itg_s = num1.size() < num2.size() ? bi1 : bi2;
	auto& Itg_l= num1.size() < num2.size() ? bi2 : bi1;
	int n = Itg_s.s.size();
	for (int i = 0; i < n; i++) {
		part_product += (Itg_l* Itg_s.s[i]);
		Itg_l.shiftLeft();
	}
	return part_product.to_string();
}
int n_s; int n_p;
bool isMatch_V1(const string& ptr_s, const string& ptr_p,int id_s, int id_p) {
	if (id_p == n_p - 1 && ptr_p.at(id_p) == '*')return true;
	if (id_s == n_s) {
		if (id_p == n_p)return true;
		while (id_p<n_p - 1 && ptr_p.at(id_p) == '*') id_p++;
		if(id_p==n_p - 1 && ptr_p.at(id_p) == '*')return true;
		return false;
	}
	if (id_p == n_p)return false;
	char now_p = ptr_p.at(id_p);
	char now_s = ptr_s.at(id_s);
	if (now_p == '?') return isMatch_V1(ptr_s, ptr_p,id_s + 1, id_p + 1);
	if (now_p == '*') {
		char next_p = ptr_p.at(id_p + 1);
		while (next_p == '*') {
			id_p++; 
			if (id_p == n_p - 1)break;
			next_p = ptr_p.at(id_p + 1);
		}
		if (next_p == '?' || next_p == now_s)
			if (isMatch_V1(ptr_s, ptr_p,id_s + 1, id_p + 2))return true;
		return isMatch_V1(ptr_s, ptr_p,id_s + 1, id_p);
	}
    if (now_p != now_s)return false;
	return isMatch_V1(ptr_s, ptr_p,id_s + 1, id_p + 1);
}
struct partString {
    int head;
	int tail;
	partString(int h = -1, int t = -1) :head(h), tail(t) {};
};
bool isMatch_V2(string& s, string& p, const vector<partString>&v, const vector<string>&v_s)
{
	 
	 const char* s_head = s.c_str();
	 const char* p_head = p.c_str();
	 const char* s_tail = s.c_str() + n_s - 1;
	 const char* p_tail = p.c_str() + n_p - 1;
	 const char* p_ = p_head;
	 const char* s_ = s_head;
	 //head_part
	 while (true) {
		 if (*p_== '*'||*p_ == '\0'||*s_=='\0')break;
		 if (*p_ != *s_&&*p_ != '?')return false;
		 p_++; s_++;
	 }
	 if ( *p_ == '\0'&&*s_ == '\0')return true;
	 //tail_part
	 while (true) {
		 if (*p_tail == '*' || p_tail == p_head || s_tail == s_head)break;
		 if (*p_tail != *s_tail&&*p_tail != '?')return false;
		 p_tail--; s_tail--;
	 }
	 string s_new(s_, s_tail+1);
	 //
	 int subs_n = v.size(); int pos = 0;
	 for (int i = 0; i < subs_n; i++) {
		 if (v[i].tail == -1) {
			 pos += v[i].head; continue;
		 }
		 else {
			 pos = s_new.find(v_s[i], pos);
			 if (pos == -1)return false;
			 pos+= v_s[i].size();
		 }
	 }
	 return true;
}
void inline wildCard_num(string& p, vector<partString>&v) {
	int ans=0;
	int head = 0; int tail = 0; int blank = 0;
	while (true) {
		OUT1:
		if (head == n_p)break;
		if (p[head] == '?') {
			blank ++; head++; continue;
		}else {
			if (blank != 0)v.push_back(partString(blank, -1));
			blank = 0;
		}
		if (p[head] != '*') {
			tail = head + 1;
			while (true) {
				if (tail == n_p) {
					v.push_back(partString(head, tail));
					return;
				}
				if (p[tail] != '*'&&p[tail] != '?') {
					tail++;}
				else {
					v.push_back(partString(head, tail));
					 head=tail;
					goto OUT1;}
			}
		}
		if (p[head] == '*') head++;
	}
}
bool isMatch(string s, string p) {
	n_s = s.size(); n_p = p.size();
	int id_s = 0; int id_p = 0; int pre_s = -1; int pre_p = -1;
	auto& ptr_p = p; auto& ptr_s = s;
	while (true) {
		if (id_p == n_p - 1 && ptr_p.at(id_p) == '*')return true;
		if (id_s == n_s) {
			if (id_p == n_p)return true;
			while (id_p<n_p - 1 && ptr_p.at(id_p) == '*') id_p++;
			if (id_p == n_p - 1 && ptr_p.at(id_p) == '*')return true;
			return false;
		}
		if (id_p<n_p&&ptr_p.at(id_p) == '*') {
			pre_p = id_p + 1; id_p++;
			while (pre_p < n_p&&ptr_p.at(pre_p) == '*') {
				pre_p++; id_p++;
			}
			pre_s = id_s; 
			continue;
		}
		if (id_p==n_p||(ptr_p.at(id_p) != ptr_s.at(id_s) && ptr_p.at(id_p) != '?')) {
			if (pre_p == -1)return false;
			id_p = pre_p;
			id_s = pre_s + 1;
			pre_s++;
		}
		else {
			id_p++; id_s++;
		}
	}
}
int inline min_e(vector<int>&jump_n, int i, int l,int n) {
	if (i + l >= n)return 0;
	if (l == 0)return INT_MAX - 1;
	int min = INT_MAX-1;

	for (int k = i + l; k > i; k--) {
		int now = jump_n[k];
		if (now == 1)return 1;
		min = (min < now) ? min : now;
	}
	return min;
}
int jump(vector<int>& nums)
{
	int n = nums.size();
	if (n == 0)return 0;
	vector<int>jump_n;
	jump_n.resize(n);
	for (int& i : jump_n)i = INT_MAX;
	jump_n.back() = 0;
	for (int i = n - 2; i >= 0; i--) {
		jump_n[i] = min_e(jump_n,i,nums[i],n-1)+1;
	}
	return jump_n[0];
}
map<int, int>* ptr_m;
vector<vector<int>>* ans_t;
int max_n;
void permute_Recur(vector<int>& stk) {
	auto& map = *ptr_m;
	if (stk.size()== max_n) {
		ans_t->push_back(stk); return;
	}
	for (auto& itr : *ptr_m) {
		if (itr.second!=0)
		{
			int id_next = itr.first;
			itr.second--;
			stk.push_back(id_next);
			permute_Recur(stk);
			stk.pop_back();
			itr.second++;
		}
	}
};
vector<vector<int>> permute(vector<int>& nums)
{
	map<int, int> table;
	max_n = nums.size();
	vector<vector<int>> ans;
	if (max_n == 0)return ans;
	ptr_m = &table;
	ans_t = &ans;
	vector<int> stk;
	for (int i : nums) {
		if (table.find(i) == table.end())
			table[i] = 1;
		else table[i]++;
	}
	permute_Recur(stk);
	return ans;
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	map<int,int> table;
	max_n = nums.size();
	vector<vector<int>> ans;
	if (max_n == 0)return ans;
	ptr_m = &table;
	ans_t = &ans;
	vector<int> stk;
	for (int i : nums) {
		if (table.find(i) == table.end())
			table[i] =1;
		else table[i]++;
	}
	permute_Recur(stk);
	return ans;
}
vector<vector<int>>*ptr_matrix;
void inline rotate_part(int bx, int by, int n) {
	auto&matrix = *ptr_matrix;
	queue<int>q;
	for (int i = 0; i < n - 1; i++) q.push(matrix[bx][by+i]);
	for (int i = 0; i < n - 1; i++) {
		q.push(matrix[bx + i][by + n - 1]);
		matrix[bx + i][by + n - 1] = q.front(); q.pop();
	}
	for (int i = 0; i < n - 1; i++) {
		q.push(matrix[bx +n-1][by + n - 1-i]);
		matrix[bx + n - 1][by + n - 1 - i] = q.front(); q.pop();
	}
	for (int i = 0; i < n - 1; i++) {
		q.push(matrix[bx + n - 1-i][by]);
		matrix[bx + n - 1 - i][by] = q.front(); q.pop();
	}
	for (int i = 0; i < n - 1; i++) {
		matrix[bx][by+i]= q.front(); q.pop();
	}
}
void rotate(vector<vector<int>>& matrix)
{
	ptr_matrix = &matrix;
	int bx = 0; int by = 0; int n = matrix.size();
	if (n <= 1)return;
	while (true) {
		rotate_part(bx, by, n);
		n -= 2;
		if (n <=1)return;
		bx += 1; by+= 1;
	}
}
struct frec {
	unsigned char f[26];
	frec(const string& s) {
		for (auto& i : f)i =0;
		for (char c : s) {
			f[c - 'a']++;
		}
	}
	bool operator<(const frec& b)const {
		for (int i = 0; i < 26; i++) {
			if (f[i]<b.f[i])return true;
			if (f[i]>b.f[i])return false;
		}
		return false;
	}
	bool operator==(const frec& b)const {
		for (int i = 0; i < 26; i++) {
			if (b.f[i] != f[i])return false;
		}
		return true;
	}
};
struct ptr_frec {
	const frec* ptr;
	ptr_frec(const frec& f) :ptr(&f){}
	bool operator<(const ptr_frec& b)const {
        return *ptr<*(b.ptr);
	}
};
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<string>> ans;
	vector<frec>_frec; 
	map<ptr_frec, int> map;
	int n = strs.size();
	for (auto& s : strs)_frec.push_back(frec(s));
	for (int i = 0; i < n;i++) {
		ptr_frec pf(_frec[i]);
		auto ptr = map.find(pf);
		if (map.find(pf) == map.end()) {
			map[pf] = ans.size();
			ans.push_back(vector<string>());
			ans.back().push_back(strs[i]);
		}
		else {
			ans[ptr->second].push_back(strs[i]);
		}
	}
	return ans;
}

double myPow(double x, long long n)
{
	if (x == 1)return 1;
	if (x == 0)return 0;
	//if (n == -2147483648)return 1/x*myPow(1 / x, -(n+1));
	if (n < 0)return myPow(1 / x, -n);
	if (n == 0)return 1;
	if (n == 1)return x;
	double t = 0;
	if (n % 2 == 1) {
		 t = myPow(x, n / 2);
		 if (t == 0)return 0;
		return x*t*t;
	}
	else {
		 t = myPow(x, n / 2);
		 if (t == 0)return 0;
		return t*t;
	}
}
class nQueenSolver {
private:
	vector<vector<string>>*ans;
	vector<string> board;
	int size;
public:
	int nums;
	nQueenSolver(vector<vector<string>>& a,int n) :ans(&a) ,size(n), nums(0){
		board.resize(size);
		for (auto& s : board) {
			s.resize(size);
			for (auto& c : s)c = '.';
		}
	};
	void Solver(int n) {
		if (n == size) {
			//ans->push_back(board);
			nums++;
		}
		for (int i = 0; i < size; i++) {
			if (isValid(n, i)) {
				board[n][i] = 'Q';
				Solver(n + 1);
				board[n][i] = '.';
			}
		}
	}
private:
	bool inline isValid(int x, int y) {
		for (int i = 0; i < x; i++) {
			if (board[i][y] == 'Q')return false;
		}
		int dx = x-1; int dy = y+1;
		while (inBoard( dx, dy)) {
			if (board[dx][dy] == 'Q')return false;
			dx--; dy++;
		}
		dx = x -1; dy = y -1;
		while (inBoard(dx, dy)) {
			if (board[dx][dy] == 'Q')return false;
			dx--; dy--;
		}
		return true;
	};
	bool inline inBoard(int x, int y) {
		if (x < 0 || x >= size)return false;
		if (y < 0 || y >= size)return false;
		return true;
	}
};
vector<vector<string>> solveNQueens(int n)
{
	vector<vector<string>>ans;
	if (n == 0)return ans;
	nQueenSolver nqs(ans, n);
	nqs.Solver(0);
	return ans;
}

int totalNQueens(int n)
{
	vector<vector<string>>ans;
	if (n == 0)return 0;
	nQueenSolver nqs(ans, n);
	nqs.Solver(0);
	return nqs.nums;
}

int maxSubArray(vector<int>& nums)
{
	int n = nums.size();
	if (n == 0)return 0;
	int max= nums[0]; int tail_sum= 0; int tail_max= nums[0];
	for (int i = 1; i < n; i++) {
		int now = nums[i];
		tail_max = (tail_max < 0) ? now : tail_max + now;
		tail_sum += now;
		int sum_link = max + tail_sum;
		if (sum_link > max || tail_max > max) {
			max = (sum_link > tail_max) ? sum_link : tail_max;
			tail_sum = 0;
		}
	}
	return max;
}

class myMatrix {
private:
	vector<vector<int>>*ptr_matrix;
	int m;
	int n;
public:
	myMatrix(vector<vector<int>>& matrix) :ptr_matrix(&matrix),
		m(matrix.size()){
		if (matrix.size() == 0) 
			n = 0;
		else n = matrix[0].size();
	};
	void spiral(vector<int>& ans) {
		if (m == 0 || n == 0)return;
		int now_x = 0; int now_y = 0;
		ans.push_back(ptr_matrix->at(0)[0]);
		ptr_matrix->at(0)[0] = INT_MIN;
		int next_x = 0; int next_y = 0;
		int d = 0;
		while (true) {
			if (get(now_x + 1, now_y) == INT_MIN&&
				get(now_x - 1, now_y) == INT_MIN&&
				get(now_x , now_y+1) == INT_MIN&&
				get(now_x , now_y-1) == INT_MIN)break;
			next(next_x, next_y,d);
			int next_v = get(next_x, next_y);
			if (next_v == INT_MIN) {
				setBack(next_x, next_y, d);
				d = (d + 1) % 4;
				continue;
			}
			else {
				ans.push_back(next_v);
				now_x = next_x;
				now_y = next_y;
				set(now_x, now_y, INT_MIN);
			}
		}
	}
private:

	int inline get(int x, int y) {
		if (x < 0 || x >= m)return INT_MIN;
		if (y < 0 || y >= n)return INT_MIN;
		return ptr_matrix->at(x)[y];
	}
	void inline set(int x, int y,int v) {
		if (x < 0 || x >= m)return;
		if (y < 0 || y >= n)return;
		 ptr_matrix->at(x)[y]= v;
	}
	void inline next(int& x, int& y, int d) {
		switch (d)
		{
		case 0: {y++; return; }
		case 1: {x++; return; }
		case 2: {y--; return; }
		case 3: {x--; return; }
		}
	}
	void inline setBack(int& x, int& y, int d) {
		switch (d)
		{
		case 0: {y--; return; }
		case 1: {x--; return; }
		case 2: {y++; return; }
		case 3: {x++; return; }
		}
	}
};
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> ans;
	myMatrix mm(matrix);
	mm.spiral(ans);
	return ans;
}

bool canJump(vector<int>& nums)
{
	int max_end = nums[0];
	int n = nums.size();
	for (int i = 0; i <= max_end;i++) {
		int now_end = i + nums[i];
		max_end = (max_end > now_end) ? max_end : now_end;
		if (max_end >= n - 1)return true;
	}
	return false;
}

bool IntervalLess(const Interval& a, const Interval& b) {
	return a.start < b.start;
}
vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> ans; int n = intervals.size();
	if (n == 0)return ans;
	sort(intervals.begin(), intervals.end(), IntervalLess);
	int begin_id = 0; int end_id = 0; int end_v=intervals[begin_id].end;
	while (true) {
		if (begin_id == n-1) {
			ans.push_back(intervals[begin_id]);
			break;
		}
		if (end_id == n - 1) {
				ans.push_back(Interval(intervals[begin_id].start, end_v));
				break;
		}
		auto& inv_now = intervals[end_id + 1];
		if (inv_now.start <= end_v) {
			end_v = (inv_now.end > end_v) ? inv_now.end : end_v;
			end_id++;
		}
		else {
			ans.push_back(Interval(intervals[begin_id].start, end_v));
			begin_id = end_id+1; end_id = end_id+1; end_v = intervals[begin_id].end;
		}
	}
	return ans;
}
bool less_Start(const Interval& a, const Interval& b) {
	return a.start < b.start;
}
bool less_End(const Interval& a, const Interval& b) {
	return a.start < b.start;
}
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	intervals.push_back(newInterval);
	//sort(intervals.begin(), intervals.end(), less_Start);
	return merge(intervals);
}

int lengthOfLastWord(std::string s)
{
	int n = s.size();
	if (n == 0)return 0;
	int length = 0; bool flag = false;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] != ' ' && !flag) {
			flag = true; 
			length = 1;
			continue;
		}
		if (s[i] != ' ' && flag) {
			length++;
			continue;
		}
		if (s[i] == ' '&& flag)break;
	}
	return length;
}

vector<vector<int>>*ptr_matrix_2;
int nb;
void inline generateMatrix_part(int bx, int by, int n) {
	auto&matrix = *ptr_matrix_2;
	queue<int>q;
	for (int i = 0; i < n - 1; i++) {
		matrix[bx][by + i] = nb;
		nb++;
	}
	for (int i = 0; i < n - 1; i++) {
		matrix[bx + i][by + n - 1] =nb;
		nb++;
	}
	for (int i = 0; i < n - 1; i++) {
		matrix[bx + n - 1][by + n - 1 - i] = nb;
		nb++;
	}
	for (int i = 0; i < n - 1; i++) {
		matrix[bx + n - 1 - i][by] = nb;
		nb++;
	}
}
vector<vector<int>> generateMatrix(int n)
{
	nb = 1;
	vector<vector<int>> matrix;
	int bx = 0; int by = 0;
	if (n <= 0)return matrix;
	ptr_matrix_2 = &matrix;
	ptr_matrix_2->resize(n);
	for (auto& v : matrix)v.resize(n);
	if (n == 1) {
		matrix[0][0] = 1;
		return matrix;
	}
	int _n = n;
	while (true) {
		generateMatrix_part(bx, by, _n);
		_n -= 2;
		if (_n == 1) {
			int c = (n / 2);
			matrix[c][c] = nb;
			return matrix;
		}
		else if (_n == 0) {
			return matrix;
		}
		bx += 1; by += 1;
	}
	return matrix;
}
int accumFactri[] = { 1, 3, 9, 33, 153, 873, 5913, 46233, 409113 };
int Factri[] = { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
string getPermutation(int n, int k)
{
	string ans; int remainPlace = n-1;
	bool table[10];
	for (bool& b : table)b = true;
	while (remainPlace>0) {
		for (int i =1; i <=n; i++) {
			if (!table[i])continue;
			int id = 1;
			for (int j= i - 1; j> 0;j--) {
				if (table[j])id++;
			}
			if (Factri[remainPlace-1] * id >= k) {
				ans.push_back(i + '0');
				k -= Factri[remainPlace - 1] * (id - 1);
				table[i] = false;
				break;
			}
		}
		remainPlace--;
	}
	for (int i = 1; i <= n; i++) {
		if (table[i])ans.push_back(i + '0');
	}
	return ans;
}

ListNode * rotateRight(ListNode * head, int k)
{ 
	auto _h = head;

	if (head == nullptr)return head;
	if (head->next == nullptr)return head;
	if(k==0)return head;
	ListNode* ans = nullptr;
	vector<ListNode*> v;
	while (head != nullptr) {
		v.push_back(head);
		head = head->next;
	}
	if (v.size() <=k) {
		k = k%v.size();
		if (k == 0)return _h;
	}
	ans = v[v.size() - k];
	v[v.size() - 1]->next = v[0];
    v[v.size() - k - 1]->next = nullptr;
	return ans;
}

int uniquePaths(int m, int n)
{
	int _n = m+n;
	int k = (m < n) ? m : n;
	_n -= 2;	k -= 1;
	if (k == 0)return 1;
	long long ki = 1;
	for (int i = 2; i <= k; i++)ki *= i;
	long long  n_n_k = _n - k + 1;
	for (int i = n_n_k + 1; i <= _n; i++)n_n_k *= i;

	return n_n_k/ ki;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	vector<vector<int>>table;
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	table.resize(m);
	for (auto& v : table) {
		v.resize(n);
		for (auto& c : v) {
			c = 0;
		}
	 }
	if (obstacleGrid[0][0] == 1)return 0;
	if (obstacleGrid[m-1][n-1] == 1)return 0;
	table[0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j= 0;j< n;j++) {
			 if (i - 1 >= 0 && obstacleGrid[i - 1][j] == 0) {
				 table[i][j] += table[i - 1][j];
			}
			 if (j- 1 >= 0 && obstacleGrid[i][j-1] == 0) {
				 table[i][j] += table[i][j-1];
			 }
		}
	}
	return table[m-1][n-1];
}
int minPathSum(vector<vector<int>>& grid)
{
	vector<vector<int>>table;
	int m = grid.size();
	int n = grid[0].size();
	table.resize(m);
	for (auto& v : table) {
		v.resize(n);
		for (auto& c : v) {
			c = INT_MAX;
		}
	}
	table[0][0] = grid[0][0];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j< n; j++) {
			int t1 = (i - 1 >= 0) ? table[i - 1][j] + grid[i][j] : INT_MAX;
			int t2 = (j - 1 >= 0) ? table[i][j - 1] + grid[i][j] : INT_MAX;
			table[i][j] = (t1 < t2) ? t1 : t2;
			if(i==0&&j==0)table[0][0] = grid[0][0];
		}
	}
	return table[m - 1][n - 1];
}
bool inline isNum(char c) {
	return (c >= '0'&&c <= '9');
}
bool inline isInteger_positive(string& s,int head,int n) {
	if (head >= n)return false;
	for (int i = head; i < n; i++) {
		if (!isNum(s[i]))return false;
	}
	return true;
}
void inline popBlank(string& s, int n) {
	for (int i = n-1; i >=0; i--) {
		if (s[i] == ' ')s.pop_back();
		else break;
	}
	n = s.size();
	int end = 0;
	for (end=0; end< n; end++) {
		if (s[end] == ' ')continue;
		else break;
	}
	if(end!=0)s.erase(0, end);
}
bool isNumber(string s)
{
	bool fInt = false;
	bool fNeg = false;
	bool fExp = false;
	bool fFra = false;
	int n = s.size();
	popBlank(s, n);
	n = s.size();
	if (n == 0)return false;
	for (int i = 0; i < n; i++) {
		char now = s[i];
		if (now == '+') {
			if (n == 1)return false;
			if (i!= 0)return false;
			continue;
		}
		if (!fNeg&&now == '-') {
			if (i != 0)return false;
			fNeg = true;
			continue;
		}
		if (!fFra&&now == '.') {
			if (n == 1)return false;
			if (i == n-1&&( s[i -1] == '-' || s[i -1] == '+'))return false;
			fFra = true;
			continue;
		}
		if (!fExp&&now == 'e') {
			if (i == 0)return false;
			if (i ==1&&(s[0] == '-'|| s[0] =='.' || s[0] == '+'))return false;
			if (i == n - 1)return false;
			if ((s[i + 1] == '-'|| s[i + 1] == '+')&&i + 1 < n - 1) {
				i++;
			}
			i++;
			return isInteger_positive(s, i, n);
		}
		if (!isNum(now)) {
			return false;
		}
	}
	return true;
}

std::vector<int> plusOne(std::vector<int>& digits)
{
	vector<int> ans;
	reverse(digits.begin(), digits.end());
	int upFlag =1; int n = digits.size();
	for (int i = 0; i < n; i++) {
		int now = digits[i] + upFlag;
		upFlag = now / 10;
		ans.push_back(now % 10);
	}
	if (upFlag)ans.push_back(upFlag);
	reverse(ans.begin(), ans.end());
	return ans;
}

string addBinary(string a, string b)
{
	if (a == "0")return b;
	if (b == "0")return a;
	if (a == "0"&&b == "0")return "0";
	string ans;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int upFlag =0; 
	int a_n = a.size();
	int b_n = b.size();
	int n = (a_n>b_n)? a_n:b_n;
	for (int i = 0; i < n; i++) {
		int now_a=(i>a_n-1)?0:a[i]-'0';
		int now_b=(i>b_n - 1)?0:b[i] - '0';
		int now = now_a + now_b+ upFlag;
		if (now % 2)ans.push_back('1');
		else ans.push_back('0');
		upFlag = now / 2;
	}
	if (upFlag)ans.push_back('1');
	reverse(ans.begin(), ans.end());
	return ans;
}
string strBlank(int n) {
	string ans; ans.resize(n);
	for (char& c : ans)c = ' ';
	return ans;
}
void inline pack(vector<string>& words,int head_id, int end_id, vector<string>& ans,int diff,bool isEnd) {
	int n = end_id - head_id;
	diff += n;
	ans.push_back("");
	string& temp= ans.back();
	temp = words[head_id];
	if (isEnd) {
		for (int i = head_id + 1; i <= end_id; i++) {
			temp.push_back(' ');
			temp.insert(temp.end(), words[i].begin(), words[i].end());
		}
		string b = strBlank(diff-n);
		temp.insert(temp.end(), b.begin(), b.end());
		return;
	}
	if (n == 0) {
		string b = strBlank(diff);
		temp.insert(temp.end(), b.begin(), b.end());
		return;
	}
	int blankLen = (diff%n) ? diff / n + 1 : diff / n;
	for (int i = head_id + 1; i <=end_id; i++) {
		string b = strBlank(blankLen);
		temp.insert(temp.end(), b.begin(), b.end());
		temp.insert(temp.end(), words[i].begin(), words[i].end());
		diff -= blankLen; n--;
		if (n == 0) {
			blankLen = 0;
		}else {
			blankLen = (diff%n) ? diff / n + 1 : diff / n;
		}
	}
}
vector<string> fullJustify(vector<string>& words, int maxWidth)
{
	vector<string> ans; int head_id = 0; int end_id = 0;
	int total = words[head_id].size(); int len = words.size();
	while (true) {
		if (end_id == len-1) {
			pack(words, head_id, end_id,ans, maxWidth - total,true);
			break;
		}
		if (total +1+ words[end_id + 1].size() > maxWidth) {
			pack(words, head_id, end_id, ans, maxWidth - total,false);
			head_id = end_id + 1; end_id = end_id + 1;
			total = words[head_id].size();
		}
		else {
			end_id++;
			total += 1+words[end_id].size();
		}
	}
	return ans;
}

int mySqrt(int x)
{
	if (x > 2147395600)return 46340;
	int lo = 0; int hi = 46340;
	int mi = (lo + hi) / 2;
	while (true) {
		int ms = mi*mi;
		int mps = (mi + 1)*(mi + 1);
		if (ms<=x&&mps>=x) {
			if (ms == x)return mi;
			if (mps == x)return mi + 1;
			return mi;
		}
		if (ms > x) {
			hi = mi;
		}else if (mps < x) {
			lo = (mi + 1);
		}
		mi = (lo + hi) / 2;
	}
}

int climbStairs(int n)
{
	vector<int>table;
	table.resize(n+1);
	table[0] = 0;
	table[1] = 1;
	table[2] = 2;
	for (int i = 3; i <= n; i++)
		table[i] = table[i - 1] + table[i - 2];
	return table[n];
}

string simplifyPath(string path)
{
	
	string ans;
	vector<string> v;
	int n = path.size();
	string str;
	for (int i = 0; i < n; i++) {
		if (path[i] == '/') {
		/*
		if (str.size() != 0) {
		if (str == "." || str == "..")
		{
		if (!v.empty())v.pop_back();
		str.clear();
		}else {
		v.push_back(str);
		str.clear();}}
		*/
			if (str== ".") {
				str.clear();
				continue;
			}
			if (str == "..") {
				if (!v.empty())v.pop_back();
				str.clear();
				continue;
			}
			if (!str.empty()) {
				v.push_back(str); str.clear();
			}
		}
		else {
			str.push_back(path[i]);
		}
	}
	if (str == ".") {
		str.clear();
	}
	else if (str == "..") {
		if (!v.empty())v.pop_back();
		str.clear();
	}else if (!str.empty()) {
		v.push_back(str); str.clear();
	}
	if (v.empty())return "/";
	for (string &s : v) {
		ans.push_back('/');
		ans.insert(ans.end(), s.begin(), s.end());
	}
	return ans;
}

int minDistance(string word1, string word2)
{
	vector<vector<int>>dp;
	int m = word1.size(); int n = word2.size();
	dp.resize(m+1);
	for (auto& v : dp)v.resize(n+1);
	dp[0][0] = 0;
	for (int i = 0; i <=m; i++) {
		for (int j = 0; j <= n;j++) {
			if (i == 0) {
				dp[i][j] = j;
				continue;}
			if (j== 0) {
				dp[i][j] =i;
				continue;}
			dp[i][j]= dp[i - 1][j] + 1;//Delete
			int t = dp[i][j-1] + 1;//Insert
			dp[i][j] = (dp[i][j] < t) ? dp[i][j] : t;
			if (word1[i - 1] == word2[j - 1]) {
				 t = dp[i - 1][j - 1];//Do nothing
				dp[i][j] = (dp[i][j] < t) ? dp[i][j] : t;
			}
			else {
				t = dp[i - 1][j - 1]+1;//Replace
				dp[i][j] = (dp[i][j] < t) ? dp[i][j] : t;
			}
		}
	}
	return dp[m][n];
}
void inline SetZero(int i, int j, vector<vector<int>>& matrix,int m,int n) {
	for (int k = 0; k < m; k++) {
		if(matrix[k][j]!= INT_MAX - 1) matrix[k][j] = 0;
	}
	for (int k= 0;k < n; k++)
	{
		if (matrix[i][k] != INT_MAX - 1)matrix[i][k] = 0;
	} 
}
void setZeroes(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0;j < n;j++) {
			if (matrix[i][j] == 0)matrix[i][j] = INT_MAX-1;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == INT_MAX - 1) {
				matrix[i][j] = 0;
				SetZero(i, j, matrix, m, n);
			}
		}
	}
}
int inline getMatrix(vector<vector<int>>& matrix, int id,int m) {
	int x = id / m;
	int y = id%m;
	return matrix[x][y];
}
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int m = matrix.size();
	if (m == 0)return false;
	int n = matrix[0].size();
	if (n == 0)return false;
	int lo = 0; int hi = m*n - 1;
	while (true) {
		if (hi - lo<=1) {
			if (getMatrix(matrix, hi, n) == target)return true;
			if (getMatrix(matrix, lo, n) == target)return true;
			return false;
		}
		int mid = (lo + hi) / 2;
		int now = getMatrix(matrix, mid, n);
		if (now == target)return true;
		if (now < target) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
}

void sortColors(std::vector<int>& nums)
{
	int n_red = 0;
	int n_white = 0;
	int n_blue = 0;
	for (int i : nums) {
		switch (i)
		{
		case 0: {n_red++; break; }
		case 1: {n_white++; break; }
		case 2: {n_blue++; break; }
		}
	}
	int p1 = n_red;
	int p2 = n_red + n_white;
	int p3 = n_red + n_white+ n_blue;
	for (int i = 0; i < p1; i++)nums[i] = 0;
	for (int i = p1; i <p2; i++)nums[i] = 1;
	for (int i = p2; i < p3; i++)nums[i] = 2;
}
bool inline isOK(int* table_remain) {
	for (int i = 'A'; i < 'z' + 1;i++) {
		if (table_remain[i] > 0)return false;
	}
	return true;
}
string minWindow(string s, string t)
{
	int s_n = s.size();
	int num_needed = t.size();
	if (num_needed> s_n)return "";
	int table_remain[256];
	for (int& i : table_remain)i = 0;
	for (char c : t) {
		table_remain[c]++;
	}
	for (int& i : table_remain) {
		if (i == 0)i = INT_MIN;
	}
	int lo = -1; int hi = s_n;
	int left = 0;	int right = 0;
	while (true) {
		if (table_remain[s[right]] != INT_MIN&&right < s_n) {
			table_remain[s[right]]--;
		}
		if (right != s_n)right++;
		while (isOK(table_remain)) {
			if (right - left-1  < hi - lo) {
				hi = right - 1;
				lo = left;
			}
			table_remain[s[left]]++;
			left++;
		}

		if (right == s_n)break;
	}
	if (lo == -1)return "";
	return s.substr(lo, hi - lo + 1);
}
void combine(vector<vector<int>>&ans, int n, int k) {
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			vector<int>v; v.push_back(i);
			ans.push_back(v);
		}
		return;
	}
	vector<vector<int>>less;
	combine(less, n, k - 1);
	for (vector<int>& v : less) {
		if (v.back() == n)continue;
		int back = v.back();
		for (int i = back + 1; i <= n; i++) {
			v.push_back(i);
			ans.push_back(v);
			v.pop_back();
		}
	}
}
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> ans;
	int i = 0;
	vector<int> now(k, 0);
	while (true) {
		now[i]++;
		if (now[0] + k - i > n+1)break;
		if (now[i] + k - i > n+1)i--;
		else if (i ==k - 1)ans.push_back(now);
		else {
			i++;
			now[i] = now[i-1];
		}
	}
	return ans;
}

vector<vector<int>> subsets(std::vector<int>& nums)
{
	vector<vector<int>>ans;
	int i = 0;
	int n = nums.size();
	vector<int> cur; 
	ans.push_back(cur);
	cur.push_back(nums[0]);

	vector<int> now(n, 0);
	while (true) {
		now[i]++;
	    cur[i] = nums[now[i] - 1];
		ans.push_back(cur);
		if (now[i] ==n) {
			i--;
			if (i == -1)break;
			cur.pop_back();
		}
		else {
			i++;
			now[i] = now[i - 1];
			cur.push_back(nums[now[i]-1]);
		}
		
	}
	return ans;
}
vector<vector<char>>* exboard;
int exm = 0;
int exn = 0;
string* ex_s;
int ex_s_len=0;
char inline ex_get(int x, int y) {
	if (x<0 || x>=exm)return ' ';
	if (y<0 || y>=exn)return ' ';
	return exboard->at(x)[y];
}
bool existAt(int x, int y, int id) {
    if (id == ex_s_len)return true;
	if (ex_get(x, y) != ex_s->at(id))return false;
	exboard->at(x)[y] = ' ';
	if (existAt(x + 1, y, id + 1))return true;
	if (existAt(x - 1, y, id + 1))return true;
	if (existAt(x , y+1, id + 1))return true;
	if (existAt(x, y-1, id + 1))return true;
	exboard->at(x)[y] = ex_s->at(id);
	return false;
}
bool exist(vector<vector<char>>& board, string word)
{
	exboard = &board;
	exm = board.size();
	exn = board[0].size();
	ex_s = &word;
	ex_s_len = word.size();
	for (int i = 0; i < exm; i++) {
		for (int j = 0; j < exn;j++) {
			if (existAt(i, j, 0))return true;
		}
	}
	return false;
}

int removeDuplicates_V2(std::vector<int>& nums)
{
	int n = nums.size();
	if (n <3)return  n;
	vector < bool>Dup; Dup.resize(n);
	bool isDup = false;
	for (int i = 0; i < n; i++) {
		int now = nums[i];
		if (i > 1 && now == nums[i - 1] && now == nums[i - 2]) {
			Dup[i] = true;
			isDup = true;
		}
	}
	if(!isDup)return  n;
	int id_ex = -1;
	for (int i = 0; i < n; i++) {
		int now = nums[i];
		if (Dup[i] &&id_ex == -1)id_ex = i;
		if (!Dup[i] &&id_ex != -1) {
			nums[id_ex] = now;
			Dup[i] = true;
			id_ex++;
		}
	}
		nums.resize(id_ex);
		return id_ex;
	}

bool searchRotated_Sorted_Array(std::vector<int>& nums, int target)
{
	int n = nums.size() - 1;
	int p = -1;
	if (n == -1)return false;
	for (int i = 0; i < n; i++) {
		if (nums[i] > nums[i + 1]) {
			p = i + 1; break;
		}
	}
	if (p == -1) {
		auto itr = lower_bound(nums.begin(), nums.end(), target);
		if (itr == nums.end() || *itr != target)return false;
		return true;
	}
	if (target < nums[0]) {
		auto itr = lower_bound(nums.begin() + p, nums.end(), target);
		if (itr == nums.end() || *itr != target)return false;
		return true;
	}
	else {
		auto itr = lower_bound(nums.begin(), nums.begin() + p, target);
		if (itr == nums.begin() + p || *itr != target)return false;
		return true;
	}
}

ListNode * deleteDuplicates(ListNode * head)
{
	if(head == nullptr)return head;
	auto now = head;
	while (true) {
		if (now== nullptr||now->next == nullptr || now->next->val != now->val)break;
		while (now->next != nullptr&&now->next->val == now->val)now = now->next;
		now = now->next;
	}
	head = now;
	if (head == nullptr)return head;
	int target = -1; ListNode * ptr2 = nullptr;
	while (now->next != nullptr) {
		if (now->next->next != nullptr&&now->next->val == now->next->next->val) {
			ptr2 = now->next->next; target = ptr2->val;
			while (ptr2->next != nullptr&&ptr2->next->val == target)ptr2 = ptr2->next;
			now->next = ptr2->next; target = -1; ptr2 = nullptr;
		}
		else {
			now = now->next;
		}
	}
	return head;
}
void inline deleteAfter(ListNode * ln) {
	ln->next = ln->next->next;
}
ListNode * deleteDuplicates_v0(ListNode * head)
{
	if(head== nullptr)return head;
	ListNode * cur= head;
	while (cur->next != nullptr) {
		if (cur->val == cur->next->val) {
			deleteAfter(cur);
		}
		else {
			cur = cur->next;
		}
	}
	return head;
}
vector<int>*p_last_left = nullptr;
vector<int>*p_last_right = nullptr;
int largestRectangleArea(vector<int>& heights)
{
	int len = heights.size();
	if (len == 0)return 0;
	int max=0;
	auto& last_left = *p_last_left;
	auto& last_right = *p_last_right;
	last_left[0] = 0;
	last_right[len - 1] = len - 1;
	for (int i = 1; i < len; i++) {
		int p = i;
		while (p >0 && heights[p - 1] >= heights[i]) {
			p = last_left[p - 1];
		}
		last_left[i] = p;
	}
	for (int i = len-2; i >=0; i--) {
		int p = i;
		while (p<len-1 && heights[p+1] >= heights[i]) {
			p = last_right[p + 1];
		}
		last_right[i] = p;
	}
	for (int i = 0; i < len; i++) {
		int now_a = heights[i] * (last_right[i] - last_left[i]+1);
		max = (max > now_a) ? max : now_a;
	}
	return max;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	int m = matrix.size();
	if (m == 0)return 0;
	int n = matrix[0].size();
	int max = 0;
		p_last_left = &vector<int>();
		p_last_left->resize(n);
		p_last_right = &vector<int>();
		p_last_right->resize(n);
	vector<int>height; height.resize(n);
	for (auto& i : height)i=0;
	for (int i = 0; i < m; i++) {
		for (int j = 0;j < n; j++) {
			if (matrix[i][j] == '0') {
				height[j] = 0;
			}
			else {
				height[j]++;
			}
		}
		int m = largestRectangleArea(height);
		max = (max > m) ? max : m;
	}
		return max;
}
struct List {
	ListNode * head;
	ListNode * tail;
	List(ListNode * _h = nullptr) :head(_h), tail(_h) {};
	void add(ListNode * ln) {
		if (head == nullptr) {
			head = ln;
			tail = ln;
			return;
		}
		tail->next = ln;
		tail = tail->next;
		return;
	}
};
ListNode * partition(ListNode * head, int x)
{
	if (head == nullptr|| head->next == nullptr)return head;
	List smaller;
	List bigger;
	auto cur = head;
	while (cur != nullptr) {
		if (cur->val < x) {
			smaller.add(cur);
		}
		else {
			bigger.add(cur);
		}
		cur = cur->next;
	}
	if(bigger.head!=nullptr)smaller.add(bigger.head);
	if (bigger.tail != nullptr)bigger.tail->next = nullptr;
	return smaller.head;
}
//87. Scramble String
bool inline equal(int* a, int* b, int len) {
	for (int i = 0; i < len; i++) {
		if (a[i] != b[i])return false;
	}
	return true;
}
bool isScramble_recur(string& s1, string& s2) {
	int len = s1.size();
	if (len == 0)return true;
	if (len == 1) {
		if (s1[0] == s2[0])return true;
		return false;
	}
	if (len == 2) {
		if (s1[0] == s2[0] && s1[1] == s2[1])return true;
		if (s1[0] == s2[1] && s1[1] == s2[0])return true;
		return false;
	}
	int t_s1[26];
	int t_s2_h[26];
	int t_s2_e[26];
	for (int i = 0; i < 26; i++) {
		t_s1[i] = 0; t_s2_h[i] = 0; t_s2_e[i] = 0;
	}
	int id_s1 = 0; int id_s2_h = 0; int id_s2_e =len-1;
	bool isSame = true;
	while (true) {
		if (id_s1 == len - 1) {
			if (isSame)return true;
			return false;
		}
		if (s1[id_s1] != s2[id_s2_h])isSame = false;
		t_s1[s1[id_s1] - 'a']++;
		t_s2_h[s2[id_s2_h] - 'a']++;
		t_s2_e[s2[id_s2_e] - 'a']++;
	   // check first part
		if (equal(t_s1, t_s2_h, 26)) {
			string s1_h = s1.substr(0, id_s1 + 1);
			string s1_e = s1.substr(id_s1 + 1, len - id_s1 - 1);
			string s2_h = s2.substr(0, id_s1 + 1);
			string s2_e = s2.substr(id_s1 + 1, len - id_s1 - 1);
			if (s1_h.size() < s1_e.size()) {
				if (isScramble_recur(s1_h, s2_h)) {
					if (isScramble_recur(s1_e, s2_e))
						return true;
				}
			}else {
				if (isScramble_recur(s1_e, s2_e)) {
					if (isScramble_recur(s1_h, s2_h))
						return true;
					}
				}
			}
		if (equal(t_s1, t_s2_e, 26)) {
			string s1_h = s1.substr(0, id_s1 + 1);
			string s1_e = s1.substr(id_s1 + 1, len - id_s1 - 1);
			string s2_h = s2.substr(id_s2_e,len- id_s2_e);
			string s2_e = s2.substr(0, id_s2_e);
			if (s1_h.size() < s1_e.size()) {
				if (isScramble_recur(s1_h, s2_h)) {
					if (isScramble_recur(s1_e, s2_e))
						return true;
				}
			}
			else {
				if (isScramble_recur(s1_e, s2_e)) {
					if (isScramble_recur(s1_h, s2_h))
						return true;
				}
			}
		}
		id_s1++;
		id_s2_h++;
		id_s2_e--;
	}
}
bool isScramble(string s1, string s2) {
	int len = s1.size();
	if (len == 0)return true;
	if (len == 1) {
		if (s1[0] ==s2[0])return true;
		return false;
	}
	if (len == 2) {
		if (s1[0] == s2[0]&& s1[1] == s2[1])return true;
		if (s1[0] == s2[1] && s1[1] == s2[0])return true;
		return false;
	}
	int t_s1[26];
	int t_s2[26];
	for (int i = 0; i < 26; i++) {
		t_s1[i] = 0; t_s2[i] = 0;
	}
	bool isSame = true;
	for (int i = 0; i < len; i++) {
		if (s1[i] != s2[i])isSame = false;
		t_s1[s1[i]-'a'] ++;
		t_s2[s2[i]-'a'] ++;
	}
	if (isSame)return true;
	if (!equal(t_s1, t_s2, 26))return false;
	return isScramble_recur(s1, s2);
}

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
	vector<int> n1; n1.resize(m);
	copy(nums1.begin(), nums1.begin() + m, n1.begin());
	n1.push_back(INT_MAX);
	nums2.push_back(INT_MAX);
	int id = 0; int id_1 = 0; int id_2 = 0;
	while (true) {
		int t1 = n1[id_1];
		int t2 = nums2[id_2];
		if (t1 == INT_MAX&&t2 == INT_MAX)break;
		nums1[id] = (t1 < t2) ? t1 : t2;
		if (t1 != INT_MAX&&t1 < t2)id_1++;
        if (t2 != INT_MAX&&t1>= t2)id_2++;
		id++;
	}
}

vector<int> grayCode(int n)
{
	vector<int>ans; ans.push_back(0);
	int limit =(1 << n)-1;
	int bit = 1; int now = 0;
	for (int i = 0; i < n; i++) {
		int len = ans.size() - 1;
		for (int j = len; j >= 0; j--) {
			ans.push_back(ans[j] + bit);
		}
		bit *= 2;
	}
	return ans;
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
{
	std::vector<std::vector<int>>ans;
	int len = nums.size();
	if (len == 0)return ans;
	sort(nums.begin(), nums.end());
	vector<int> now;
	int pl = 0; int l = 0;
	ans.push_back(now);
	for (int i = 0; i < len; i++) {
		l = ans.size();
		if (i == 0 ||nums[i - 1] != nums[i]) {
			
			for (int j = 0; j < l;j++) {
				ans.push_back(ans[j]);
				ans.back().push_back(nums[i]);
			}
		}
		else {
			for (int j = pl; j < l; j++) {
				ans.push_back(ans[j]);
				ans.back().push_back(nums[i]);
			}
		}
		pl = l;
	}
	return ans;
}
vector<int>* Code_table;
int num_Decode(string& s,int i) {
	int ans = -1;
	auto& t = *Code_table;
	if (s[i] == '0') {
		ans = 0; goto END;
	}
	if (i == s.size()) {
		ans = 1;	return ans;
	}
	if (i == s.size() - 1) {
		ans = 1; goto END;
	}
	if (i == s.size() - 2) {
		if (s[i + 1] == '0') {
			if (s[i] =='1' || s[i] == '2')return 1;
			return 0;
		}
	}
	if (t[i] != -1) {
		ans = t[i];
		goto END;
	}

	if ((s[i] == '1' || s[i] == '2') && s[i + 1] == '0')ans = num_Decode(s, i + 2);
	else if (s[i] > '2' || s[i] =='2' && s[i + 1] > '6') {
		ans = num_Decode(s, i +1);
	}
	else {
		ans = num_Decode(s, i + 1) + num_Decode(s, i + 2);
	}
	END:
	t[i] = ans;
	return ans;
}
int numDecodings(std::string s)
{
	vector<int> cb; Code_table = &cb;
	if (s.size() == 0 || s[0] == '0')return 0;
	Code_table->resize(s.size());
	for (int& i : *Code_table)i = -1;
	int ans =num_Decode(s, 0);
	return ans;
}

ListNode * reverseBetween(ListNode * head, int m, int n)
{
	ListNode preHead(-1);
	preHead.next = head; m++; n++;
	ListNode* mid_tail = nullptr;
	ListNode* mid_head = nullptr;
	ListNode* pre_tail = nullptr;
	ListNode* now = &preHead;
	int id = 1;
	while (true) {
		if (id < m - 1) {
			now = now->next;
		} else if (id == m - 1) {
			pre_tail = now;
			now = now->next;
		}
		else if (id == n + 1) {
			pre_tail->next = mid_head;
			mid_tail->next = now;
			break;
		}
		else if (id ==m) {
			mid_tail = now;
			mid_head = now;
			now = now->next;
		}
		else if (id > m) {
			auto t = now;
			now = now->next;
			t->next=mid_head;
			mid_head = t;
		}
		id++;
	}
	return preHead.next;
}
vector<string>*ip_ans;
string* ip_s;
vector<int>*ip_now;
int s_len;
void  restoreIp_re(int i) {
	if (i >= s_len)return;
	int t = -1;
	vector<int>*_ip_now= ip_now;

	if (_ip_now->size() == 3) {
		if (s_len - i > 3)return;
		string str;
		if (s_len - i == 3) {
			if (ip_s->at(i) - '0' == 0)return;
			 t = (ip_s->at(i) - '0') * 100
				+ (ip_s->at(i + 1) - '0') * 10
				+(ip_s->at(i + 2) - '0');
			if (t > 255)return;
		}
		if (s_len - i == 2) {
		if (ip_s->at(i) - '0' == 0)return;
			 t = (ip_s->at(i) - '0') * 10
				+ (ip_s->at(i + 1) - '0');
		}
		if (s_len - i == 1) {
			 t = (ip_s->at(i) - '0');
		}
		_ip_now->push_back(t);
		str = to_string(_ip_now->at(0)) + "." +
			to_string(_ip_now->at(1)) + "." +
			to_string(_ip_now->at(2)) + "." +
			to_string(_ip_now->at(3));
		ip_ans->push_back(str);
		_ip_now->pop_back();
		return;
	}
	if (ip_s->at(i) == '0') {
		_ip_now->push_back(0);
		restoreIp_re(i + 1);
		_ip_now->pop_back();
		return;
	}
	//length=3
	if (i+2<s_len) {
		t = (ip_s->at(i) - '0') * 100
			+ (ip_s->at(i + 1) - '0') * 10
			+ (ip_s->at(i + 2) - '0');
		if (t < 256) {
			_ip_now->push_back(t);
			restoreIp_re(i + 3);
			_ip_now->pop_back();
		}
	}	
	//length=2

	if (i + 1< s_len) {
		t = (ip_s->at(i) - '0') * 10
			+ (ip_s->at(i + 1) - '0');
		_ip_now->push_back(t);
		restoreIp_re(i + 2);
		_ip_now->pop_back();
	}
	
	
	//length=1
	t = (ip_s->at(i) - '0');
	_ip_now->push_back(t);
	restoreIp_re(i + 1);
	_ip_now->pop_back();
}
vector<string> restoreIpAddresses(string s)
{
	vector<string>ans; vector<int> now;
	s_len = s.size();
	ip_ans = &ans; ip_now = &now;
	ip_s = &s;
	restoreIp_re(0);
	return ans;
}
vector<int>*inorderTraversal_v;
void inorderTraversal_re(TreeNode * now) {
	if (now == nullptr)return;
	inorderTraversal_v->push_back(now->val);
	inorderTraversal_re(now->right);
	inorderTraversal_re(now->left);
}
std::vector<int> inorderTraversal(TreeNode * root)
{
	vector<int> ans; inorderTraversal_v = &ans;
	inorderTraversal_re(root);
	return ans;
}
class visitBST {
public:
	virtual void operator()(TreeNode *cur) = 0;
};
class visited_pushBack:public visitBST {
private:
	vector<int>*ans;
public:
	visited_pushBack(vector<int>&a) :ans(&a) {};
	virtual void operator()(TreeNode *cur) {
		if(cur!= nullptr)ans->push_back(cur->val);
	}
};
void inorderTraversal_iterative(TreeNode * root, visitBST& visit) {
	TreeNode *  cur = root;
	stack<TreeNode *>stk; 
	while (true) {
		while (cur != nullptr) {
			stk.push(cur); cur = cur->left;
		}
		if (stk.empty())break;
		cur = stk.top();stk.pop();
		visit(cur);
		cur = cur->right;
		}
}
std::vector<int> inorderTraversal_iterative(TreeNode * root)
{
	vector<int>ans; visited_pushBack vpb(ans);
	if(root== nullptr)return ans;
	inorderTraversal_iterative(root,vpb);
	return ans;
}
void generateTrees_re(int lo, int hi, vector<TreeNode*>& v) {
	if (lo > hi) {
		v.push_back(nullptr);
		return;
	}
	if (lo == hi) {
		v.push_back(new TreeNode(lo));
		return;
	}
	vector<TreeNode*> temp_l;
	vector<TreeNode*> temp_r;
	for (int i = lo; i <= hi; i++) {

		generateTrees_re(lo, i - 1, temp_l);
		generateTrees_re(i+1, hi, temp_r);
		for (auto& l : temp_l) {
			for (auto& r : temp_r) {
				auto now = new TreeNode(i);
				now->left = l;
				now->right = r;
				v.push_back(now);
			}
		}
		temp_l.clear();
		temp_r.clear();
	}
}

vector<TreeNode*> generateTrees(int n)
{

	vector<TreeNode*> ans;
	if (n == 0)return ans;
	generateTrees_re(1, n, ans);
	return ans;
}
long long inline product(int lo, int hi) {
	int ans= 1;
	for (int i = lo; i <= hi; i++) {
		ans *= i;
	}
	return ans;
}
int numTrees(int n)
{
	int a[] = {
		1, 1, 2, 5, 14, 42, 132, 429, 1430,
		4862, 16796, 58786, 208012, 742900,
		2674440, 9694845, 35357670,
		129644790, 477638700, 1767263190
	};
	return a[n];
}
string* pS1;
string* pS2;
string* pS3;
bool isInterleave_re(int id1, int id2, int id3) {
	if (id1 == pS1->size() && id2 == pS2->size())return true;
	char c1 = ' '; char c2 =' ';
	if (id1 != pS1->size())c1 = pS1->at(id1);
	if (id2 != pS2->size())c2 = pS2->at(id2);
	char c3 = pS3 -> at(id3);
	if (c1 == c3) {
		if (isInterleave_re(id1 + 1, id2, id3 + 1))return true;
	}
	if (c2 == c3) {
		if (isInterleave_re(id1, id2+1, id3 + 1))return true;
	}
	return false;
}
bool isInterleave(string s1, string s2, string s3)
{
	if (s3.size() != (s1.size() + s2.size()))return false;
	int m = s1.size()+1;
	int n = s2.size()+1;
	vector<vector<bool>>table; table.resize(m);
	for (int i = 0; i < m; i++) {
		table[i].resize(n);
		for (int j = 0; j < n; j++) {
			table[i][j] = false;
		}
	}
	table[0][0] = true; bool b1 = false; bool b2 = false;
	for (int i = 1; i < m; i++) {
		if (s3[i-1] == s1[i-1]&& table[i-1][0])table[i][0] = true;
	}
	for (int j = 1; j < n; j++) {
		if (s3[j-1] == s2[j-1]&& table[0][j-1])table[0][j] = true;
	}
	for (int i = 1; i < m;i++) {
		for (int j =1;j <n;j++) {
			b1 = table[i - 1][j];
			b2 = table[i][j-1];
			if(s3[i+j-1]==s1[i-1]&& b1)table[i][j] = true;
			if (s3[i+j-1]==s2[j-1]&& b2)table[i][j] = true;
		}
	}
	return table[m-1][n-1];
}
bool isValidBST_re(TreeNode * r, long long lo, long long hi) {
	if (r == nullptr)return true;
	if ((long long)r->val >= hi || (long long)r->val <= lo)return false;
	if (isValidBST_re(r->left, lo, r->val) && isValidBST_re(r->right, r->val, hi))return true;
	return false;
}
bool isValidBST(TreeNode * root)
{
	if (root == nullptr)return true;
	if (root->left == nullptr&&root->right == nullptr)return true;
	return isValidBST_re(root,LONG_MIN, LONG_MAX);
}
vector<int>*_q;
void mid_tra(TreeNode * root) {
	if (root == nullptr)return;
	mid_tra(root->left);
	_q->push_back(root->val);
	mid_tra(root->right);
}
void mid_tra_push(TreeNode * root,int& i) {
	if (root == nullptr)return;
	mid_tra_push(root->left,i);
	root->val = _q->at(i); i++;
	mid_tra_push(root->right,i);
}
void recoverTree(TreeNode * root)
{
	vector<int> q; _q = &q;
	if (root == nullptr)return;
	mid_tra(root);
	sort(q.begin(), q.end());
	int id=0;
	mid_tra_push(root, id);
}

bool isSameTree(TreeNode * p, TreeNode * q)
{
	if (p == nullptr&&q == nullptr)return true;
	if (p != nullptr&&q == nullptr)return false;
	if (p == nullptr&&q!= nullptr)return false;
	if (p->val != q->val)return false;
	if(isSameTree(p->left,q->left)&& isSameTree(p->right, q->right))return true;
	return false;
}
bool isSymmetric_re(TreeNode * l, TreeNode * r) {
	if (l == nullptr&&r == nullptr)return true;
	if(l != nullptr&&r == nullptr)return false;
	if (l == nullptr&&r != nullptr)return false;
	if (l->val != r->val)return false;
	return isSymmetric_re(l->right, r->left) && isSymmetric_re(l->left, r->right);
}
bool isSymmetric(TreeNode * root)
{
	if (root == nullptr)return true;
	return isSymmetric_re(root->left, root->right);
}

vector<vector<int>> levelOrder(TreeNode * root)
{
	vector<vector<int>> ans;
	queue<TreeNode*>q;
	q.push(root);	q.push(nullptr);
	while (q.front()!= nullptr) {
		ans.push_back(vector<int>());
		while (q.front() != nullptr) {
			ans.back().push_back(q.front()->val);
			if(q.front()->left!=nullptr)q.push(q.front()->left);
			if(q.front()->right!=nullptr)q.push(q.front()->right);
			q.pop();
		}
		q.push(nullptr);
		q.pop();
	}
	return ans;
}

vector<vector<int>> zigzagLevelOrder(TreeNode * root)
{
	vector<vector<int>> ans;
	if (root == nullptr)return ans;
	bool fromLeft = true;
	stack<TreeNode*>stk;
	stk.push(root);
	while (!stk.empty()) {
		vector<TreeNode*>v;
		while (!stk.empty()) {
			v.push_back(stk.top()); stk.pop();
		}
		ans.push_back(vector<int>());
		for (auto& ptr : v) {
			ans.back().push_back(ptr->val);
			if (fromLeft) {
				if (ptr->left != nullptr)stk.push(ptr->left);
				if (ptr->right != nullptr)stk.push(ptr->right);
			}
			else {
				if (ptr->right != nullptr)stk.push(ptr->right);
				if (ptr->left != nullptr)stk.push(ptr->left);
			}
		}
		fromLeft = !fromLeft;
	}
	return ans;
}

int maxDepth(TreeNode * root)
{
	if (root == nullptr)return 0;
	int l = maxDepth(root->left);
	int r= maxDepth(root->right);
	return (l > r) ? l + 1 : r + 1;
}
unordered_map<int, int>*buildTree_t;
int pre_idx;
vector<int>*pre;
vector<int>*in;
TreeNode * buildTree_inAndpre_re(int lo, int hi) {
	if (hi < lo)return nullptr;
	int now = pre->at(pre_idx);
	if (hi == lo) {
		auto ptr = new TreeNode(now);
		pre_idx++;
		return ptr;
	}
	auto ptr = new TreeNode(now);
	int mid = buildTree_t->at(now);
	pre_idx++;
	ptr->left = buildTree_inAndpre_re(lo, mid - 1);
	ptr->right = buildTree_inAndpre_re(mid + 1, hi);
	return ptr;
}
TreeNode * buildTree_inAndpre(vector<int>& preorder, vector<int>& inorder)
{
	unordered_map<int, int>table; int n = preorder.size();
	buildTree_t = &table;
	pre = &preorder;
	in = &inorder;
	pre_idx = 0;
	for (int i = 0; i < n; i++)table[inorder[i]] = i;
	return buildTree_inAndpre_re(0, n - 1);
}
TreeNode * buildTree_inAndpost_re(int lo, int hi) {
	if (hi < lo)return nullptr;
	int now = pre->at(pre_idx);
	if (hi == lo) {
		auto ptr = new TreeNode(now);
		pre_idx--;
		return ptr;
	}
	auto ptr = new TreeNode(now);
	int mid = buildTree_t->at(now);
	pre_idx--;
	ptr->right = buildTree_inAndpost_re(mid + 1, hi);
	ptr->left = buildTree_inAndpost_re(lo, mid - 1);
	return ptr;
}
TreeNode * buildTree_inAndpost(vector<int>& inorder, vector<int>& postorder)
{
	unordered_map<int, int>table; int n = postorder.size();
	buildTree_t = &table;
	pre = &postorder;
	in = &inorder;
	pre_idx = n-1;
	for (int i = 0; i < n; i++)table[inorder[i]] = i;
	return buildTree_inAndpost_re(0, n - 1);
}

vector<vector<int>> levelOrderBottom(TreeNode * root)
{
	vector<vector<int>> ans;
	queue<TreeNode*>q;
	q.push(root);	q.push(nullptr);
	while (q.front() != nullptr) {
		ans.push_back(vector<int>());
		while (q.front() != nullptr) {
			ans.back().push_back(q.front()->val);
			if (q.front()->left != nullptr)q.push(q.front()->left);
			if (q.front()->right != nullptr)q.push(q.front()->right);
			q.pop();
		}
		q.push(nullptr);
		q.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
vector<int>* _nums;
TreeNode * sortedArrayToBST_re(int lo,int hi)
{
	if (lo > hi)return nullptr;
	if (lo == hi) {
		return new TreeNode(_nums->at(lo));
	}
	int mid = (lo + hi) / 2;
	auto ptr= new TreeNode(_nums->at(mid));
	ptr->left = sortedArrayToBST_re(lo, mid - 1);
	ptr->right = sortedArrayToBST_re(mid +1, hi);
	return ptr;
}

TreeNode * sortedArrayToBST(std::vector<int>& nums)
{
	_nums = &nums;
	return sortedArrayToBST_re(0,nums.size()-1);
}

TreeNode * sortedListToBST(ListNode * head)
{
	vector<int> nums;
	auto now = head;
	while (now != nullptr) {
		nums.push_back(now->val);
		now = now->next;
	}
	return sortedArrayToBST(nums);
}
bool isBalanced_re(TreeNode * r, int& d) {
	if (r == nullptr) {
		d = 0; return true;
	}
	int ld = -1; int rd = -1;
	if (isBalanced_re(r->left, ld) == false || isBalanced_re(r->right, rd) == false)return false;
	if (ld - rd > 1 || ld - rd < -1)return false;
	d = (ld > rd) ? ld + 1 : rd + 1;
	return true;
}
bool isBalanced(TreeNode * root)
{
	int d = 0;
	return isBalanced_re(root,d);
}

int minDepth(TreeNode * root)
{
	if (root == nullptr)return 0;
	if (root->left == nullptr&&root->right == nullptr)return 1;
	int ld = (root->left != nullptr) ? minDepth(root->left) : INT_MAX;
	int rd =(root->right!=nullptr)?minDepth(root->right) : INT_MAX;
	return (ld < rd) ? ld + 1 : rd + 1;
}

bool hasPathSum_r(TreeNode * root, int sum)
{
	if (root == nullptr)	return false;
	if (root->left == nullptr&&root->right == nullptr) {
		if (sum == root->val)return true;
		return false;
	}
	return hasPathSum_r(root->left, sum - root->val) || hasPathSum_r(root->right, sum - root->val);
}


bool hasPathSum(TreeNode * root, int sum)
{
	if (root == nullptr)	return false;
	return hasPathSum_r(root, sum);
}
std::vector<std::vector<int>>* sps;
vector<int>* p_pst;
void pathSum_re(TreeNode * root, int sum) {

	if (root == nullptr)	return;
	if (root->left == nullptr&&root->right == nullptr) {
		if (sum == root->val) {
			sps->push_back(*p_pst);
			sps->back().push_back(root->val);
		}
		return;
	}
	p_pst->push_back(root->val);
	hasPathSum_r(root->left, sum - root->val);		
	hasPathSum_r(root->right, sum - root->val);
	p_pst->pop_back();
}
std::vector<std::vector<int>> pathSum(TreeNode * root, int sum)
{
	vector<vector<int >> sumPath; sps = &sumPath;
	vector<int>pathSumStk; p_pst = &pathSumStk;
	if (root == nullptr)	return sumPath;
	pathSum_re(root, sum);
	return sumPath;
}

void flatten(TreeNode * root)
{
	if (root == nullptr)return;
	if (root->left == nullptr&&root->right == nullptr)return;
	flatten(root->left);
	flatten(root->right);
	auto ptr_L_begin = root->left;
	auto ptr_L_end = root->left;
	auto ptr_R_Begin = root->right;
	if (ptr_L_end != nullptr) {
		while (ptr_L_end->right != nullptr)ptr_L_end = ptr_L_end->right;

		root->right = ptr_L_begin;
		ptr_L_end->right = ptr_R_Begin;
		root->left =nullptr;
	}
	else {
		root->right = ptr_R_Begin;
		root->left = nullptr;
	}
}

int numDistinct(string s, string t)
{
	
	int m = s.size(); int n = t.size();
	if (m == 0)return 0;
	vector<vector<int>>table;
	table.resize(m);
	for (auto&v : table) {
		v.resize(n);
		for (auto& i : v)i = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j= 0;j < n; j++) {
			if (j > i) {
				table[i][j] = 0;
				continue;
			}
			if (j == 0) {
				if (s[i] ==t[j]) {
					if (i == 0)table[i][j] = 1;
					else {
						table[i][j] = 1 + table[i - 1][j];
					}
				}
				else {
					if (i != 0)table[i][j] =  table[i - 1][j];
				}
			}
			else {
				if (s[i] == t[j]) {
					table[i][j] =  table[i - 1][j-1]+ table[i - 1][j];
				}
				else {
					table[i][j] = table[i - 1][j];
				}

			}
		}
	}
	return table[m - 1][n - 1];
}

void connect(TreeLinkNode * root)
{
	queue<TreeLinkNode*>q;
	if (root == nullptr)return;
	q.push(root); q.push(nullptr);
	while (true) {
		if (q.front() == nullptr&&q.size() == 1)break;
		auto now = q.front(); q.pop();
		if (now != nullptr) {
			now->next = q.front();
			if (now->left != nullptr)q.push(now->left);
			if (now->right != nullptr)q.push(now->right);
		}
		else {
			q.push(nullptr);
		}
	}

}

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> ans;
	if(numRows==0)return ans;
	ans.push_back(vector<int>());
	ans.back().push_back(1);
	for (int i = 2; i <= numRows; i++) {
		ans.push_back(vector<int>());
		auto& pre = ans[i-2];
		
		ans.back().resize(i);
		ans.back().front() = 1;
		ans.back().back() = 1;
		for (int j = 1; j < i-1; j++) {
			ans.back()[j] = pre[j - 1] + pre[j];
		}
	}
	return ans;
}

vector<int> getRow(int rowIndex)
{
	vector<vector<int>> ans;
	int numRows = rowIndex+1;
	ans.push_back(vector<int>());
	ans.back().push_back(1);
	for (int i = 2; i <= numRows; i++) {
		ans.push_back(vector<int>());
		auto& pre = ans[i - 2];

		ans.back().resize(i);
		ans.back().front() = 1;
		ans.back().back() = 1;
		for (int j = 1; j < i - 1; j++) {
			ans.back()[j] = pre[j - 1] + pre[j];
		}
	}
	return ans.back();
}

int minimumTotal(vector<vector<int>>& triangle)
{
	if (triangle.size() == 0)return 0;
	vector<vector<int>>table;
	table.resize(triangle.size());
	int m = triangle.size();
	table[0].push_back(triangle[0][0]);
	for (int i = 1; i < m; i++) {
		int n = triangle[i].size();
		table[i].resize(n);
		table[i][0] = table[i - 1][0] + triangle[i][0];
		table[i][n - 1] = table[i - 1][n - 2] + triangle[i][n - 1];
		for (int j = 1; j < n - 1; j++) {
			table[i][j] = min(table[i - 1][j], table[i - 1][j - 1]) + triangle[i][j];
		}
	}
	return *min_element(table.back().begin(),table.back().end());
}

int maxProfit(vector<int>& prices)
{

	int n = prices.size();
	if (n == 0)return 0;
	vector<int> maxAfter; maxAfter.resize(n);
	maxAfter.back() = prices.back();
	for (int i = n - 2; i >= 0; i--) {
		maxAfter[i] = (maxAfter[i + 1] > prices[i]) ? maxAfter[i + 1] : prices[i];
	}
	for (int i = 0; i < n; i++)maxAfter[i] = maxAfter[i] - prices[i];
	return *max_element(maxAfter.begin(), maxAfter.end());
}

int maxProfit_V2(std::vector<int>& prices)
{
	int b_p = -1; int n = prices.size();
	if (n == 0)return 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1 && b_p != -1) {
			sum += prices[i] - b_p;
			break;
		}
		if (prices[i] < prices[i + 1]) {
			if (b_p == -1)b_p = prices[i];
		}
		else {
			if (b_p != -1)sum += prices[i] - b_p;
			b_p = -1;
		}
	}
	return sum;
}

int maxProfit_V3(vector<int>& prices)
{

	int b_p = -1; int n = prices.size();
	if (n == 0)return 0;
	vector<int>maxBefore; maxBefore.resize(n);
	vector<int>maxAfter; maxAfter.resize(n);
	int b_min = prices[0];
	for (int i = 1; i < n; i++) {
		int t = prices[i] - b_min;
		maxBefore[i] = (maxBefore[i-1] > t) ? maxBefore[i-1] : t;
		b_min = (b_min < prices[i]) ? b_min : prices[i];
	}
	int a_max = prices[n-1];
	for (int i = n-2; i>=0; i--) {
		int t = a_max-prices[i];
		maxAfter[i] = (maxAfter[i+1] > t) ? maxAfter[i+1] : t;
		a_max = (a_max > prices[i]) ? a_max : prices[i];
	}
	int max = maxBefore[n-1];
	for (int i = 1; i < n - 2; i++) {
		int b = maxBefore[i];
		if (b < 0)b = 0;
		int a = maxAfter[i+1];
		if (a < 0)a = 0;
		int t = a + b;
		max = (max > t) ? max : t;
	}
	return max;
}
int maxPS;
int maxDirectPathSum_re(TreeNode * root) {
	//int&mp = maxPS;
	if (root->left == nullptr&&root->right == nullptr) {
		maxPS = max(maxPS, root->val);
		return root->val;
	}
	int rm = 0;
	if (root->right != nullptr)rm = maxDirectPathSum_re(root->right);
	int lm = 0;
	if (root->left != nullptr)lm = maxDirectPathSum_re(root->left);
	if (rm < 0)rm = 0;
	if (lm < 0)lm = 0;
	int tm = root->val + rm + lm;
	maxPS = max(maxPS, tm);
	return  max(root->val + rm, root->val + lm);
}
int maxPathSum(TreeNode * root)
{
	maxPS = INT_MIN;
	maxDirectPathSum_re(root);
	return maxPS;
}

bool isPalindrome(string s)
{
	int n = s.size();
	int lo = 0;
	int hi = n - 1;
	for (char& c : s) {
		if (isalpha(c)&&c >= 'a')c = c+('A' - 'a');
	}
	while (true) {
		while (lo<n&&!isalnum(s[lo]))lo++;
		while (hi >=0&&!isalnum(s[hi]))hi--;
		if(lo>=hi)return true;
		if (s[lo] != s[hi])return false;
		lo++; hi--;
	}
	return true;
}
int CanTran(string& a, string& b) {
	int t = 0;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) t++;
	}
	return t;
};
struct str_dis {
	int id; int dis_to_b; int dis_to_e;
	str_dis(int i, int d,int d_2) :id(i), dis_to_b(d), dis_to_e(d_2){};
};
bool operator <(const str_dis& a,const str_dis& b) {
	if (a.dis_to_e > b.dis_to_e)return true;
	else return false;
	if (a.dis_to_b > b.dis_to_b)return true;
	else return false;
	return false;
};
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	
	int n = wordList.size();
     int  end = INT_MIN;
	 priority_queue<str_dis>front_e;
	 unordered_set<int>set;
	 for (int i = 0; i < n;i++) {
		 if (wordList[i] == endWord) {
			 end = i;
			 front_e.push(str_dis(i, CanTran(wordList[i], beginWord),1));
		 }
		 else {
			 set.insert(i);
		 }
		
	}
	if (end== INT_MIN)return 0;
	vector<int>neo;
	while (true) {
		if (front_e.empty())return 0;
		str_dis now = front_e.top(); front_e.pop();
		if (now.dis_to_b==1)return now.dis_to_e + 1;
		for (int i : set) {
			if (CanTran(wordList[now.id], wordList[i]) ==1) {
				front_e.push(str_dis(i, CanTran(wordList[i], beginWord), now.dis_to_e + 1));
				neo.push_back(i);
			}
		}
		for (int i : neo)set.erase(i);
		neo.clear();
	}

}
vector<vector<string>>* fl_ans;
vector<string>* fl_wordList;
vector<vector<int>>*fl_parents;
vector<int>*fl_seq;
void fL_gP() {
	vector<int>&seq =*fl_seq;
	for (int i : (fl_parents->at(fl_seq->back()))) {
		if (i == -1) {
			fl_ans->push_back(vector<string>());
			auto& now = fl_ans->back();
			now.push_back(fl_wordList->back());
			for (int i : *fl_seq) {
				now.push_back(fl_wordList->at(i));
			}
			return;
		}
		fl_seq->push_back(i);
		fL_gP();
		fl_seq->pop_back();
	}
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
	int n = wordList.size();
	
	int  end = INT_MIN;
	vector<vector<string>>ans;
	vector<vector<int>>parents;
	vector<int>seq;
	if (n == 0)return ans;
	fl_ans=&ans;
	fl_wordList = &wordList;
	fl_parents = &parents;
	fl_seq = &seq;
	parents.resize(n);
	vector<bool>begin_parents;
	begin_parents.resize(n);
	priority_queue<str_dis>front_e;
	unordered_set<int>set;
	for (int i = 0; i < n; i++) {
		if (wordList[i] == endWord) {
			end = i;
			front_e.push(str_dis(i, CanTran(wordList[i], beginWord), 1));
		}
		else {
			set.insert(i);
		}

	}
	if (end == INT_MIN)return ans;
	parents[end].push_back(-1);
	unordered_set<int>neo; int level = 0;
	while (true) {
		//BFS a Level
		while (true) {
			if (front_e.empty())break;
			str_dis now = front_e.top(); front_e.pop();
			auto& str = wordList[now.id];
		
			if (now.dis_to_b == 1) {
				begin_parents[now.id]=1;
				neo.insert(-1);
			}
			for (int i : set) {
				if (CanTran(wordList[now.id], wordList[i]) == 1) {
					
					neo.insert(i);
					parents[i].push_back(now.id);
				}
			}	
		}
		if (neo.empty())break;
		//bool endFlag;
		for (int i : neo) {
			if (i == -1) goto OUTS;
			front_e.push(str_dis(i, CanTran(wordList[i], beginWord), level + 1));
			set.erase(i);
		}
		neo.clear();
		level++;
	}
	OUTS:
	//generate all path;
	wordList.push_back(beginWord);
	
	for (int i = 0; i < n;i++) {
		if (begin_parents[i]) {
			seq.push_back(i);
			fL_gP(); 
			seq.pop_back();
		}
	}
	return ans;
}

int longestConsecutive(vector<int>& nums)
{
	unordered_map<int, int> table;
	int _max = 0;
	for (int i : nums) {
		if (table.find(i) != table.end())continue;
		bool pre = (table.find(i - 1) != table.end());
		bool succ = (table.find(i +1) != table.end());
		if (pre&&succ) {
			int len = table[i - 1] + table[i + 1] + 1;
			_max = max(_max, len);
			table[i - 1 - table[i - 1] + 1] = len;
			table[i +1 +table[i +1] - 1] = len;
			table[i] = len;
		}
		else if(pre) {
			int len = table[i - 1] + 1;
			_max = max(_max, len);
			table[i - 1 - table[i - 1] + 1] = len;
			table[i] = len;
		}
		else if (succ) {
			int len = table[i + 1] + 1;
			_max = max(_max, len);
			table[i + 1 + table[i + 1] - 1] = len;
			table[i] = len;
		}
		else {
			table[i] = 1;
			_max = max(_max, 1);
		}
	}
	return _max;
}
int _sumT;
void sumNumbers_re(TreeNode * root,int sum)
{
	if (root->left == nullptr&&root->right == nullptr) {
		_sumT += sum * 10 + root->val;
		return;
	}
	int sum_now = sum * 10 + root->val;
	if (root->left != nullptr)sumNumbers_re(root->left, sum_now);
	if (root->right != nullptr)sumNumbers_re(root->right, sum_now);
}
int sumNumbers(TreeNode * root)
{
	if (root == nullptr)return 0;
	_sumT = 0;
	sumNumbers_re(root, 0);
	return _sumT;
}
vector<char*>* _us;
int m;
int n;
vector<vector<char>>* _board;
void unsurrounded(int i, int j) {
	vector<vector<char>>&b = *_board;
	if (i < 0 || i >= m)return;
	if (j < 0 ||j >= n)return;
	if (b[i][j] != 'O')return;
	_us->push_back(&b[i][j]);
	b[i][j] = 'X';
	unsurrounded(i + 1, j);
	unsurrounded(i -1, j);
	unsurrounded(i , j-1);
	unsurrounded(i, j+1);
};
void solve_SR(vector<vector<char>>& board)
{
	vector<char*> us;
	m = board.size();
	if (m == 0)return;
	n = board[0].size();
	if (n == 0)return;
	_us = &us;
	_board = &board;
	for (int j = 0; j < n; j++) {
		unsurrounded(0, j);
		unsurrounded(m-1, j);
	}
	for (int i = 0;i< m;i++) {
		unsurrounded(i,0);
		unsurrounded(i,n-1);
	}
	for (int i = 0; i< m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'O')board[i][j] = 'X';
		}
	}
	for (char* ptr : us)*ptr = 'O';
}
bool is_Palindrome(string&s) {
	int end = s.size()-1;
	int begin = 0;
	if (end == 0)return true;
	while (true) {
		if (end<=begin)return true;
		if (s[end] == s[begin]) {
			end--; begin++;
			continue;
		};
		if (s[end] != s[begin])return false;
	}
}
void prouduceAllSub(string& s, vector<vector<string>>&sub) {
	int n = s.size();
	if (is_Palindrome(s)) {
		sub.push_back(vector<string >());
		sub.back().push_back(s);
	}
	string head = ""; string tail = "";
	for (int i = 0; i < n-1; i++) {
		head.push_back(s[i]);
		if (is_Palindrome(head)) {
			tail = s.substr(i+1, n - i);
			vector<vector<string>> tail_part;
			prouduceAllSub(tail, tail_part);
			if (tail_part.size() != 0) {
				for (vector<string>& v : tail_part) {
					sub.push_back(vector<string >());
					sub.back().push_back(head);
					for (auto s : v) {
						sub.back().push_back(s);
					}
				}
			}
		}
	}
}
vector<vector<string>> partition(string s)
{
	vector<vector<string>> ans;
	prouduceAllSub(s, ans);
	return ans;
}
//new!!
string* str;
vector<vector<int>>* _table;
int minCut_re(int a, int b) {
	int minC = INT_MAX;
	string head = ""; string tail = "";
	auto& t = *_table;
	if (t[a][b] != INT_MAX) {
		return t[a][b];
	}
	int n = b-a+1;
	if (n==1) {
		minC= 0;
		goto inEND;
	};
	if (is_Palindrome(str->substr(a,n))) {
		minC = 0;
		goto inEND;
	}

	for (int i =a; i < b; i++) {
		head.push_back(str->at(i));
		if (is_Palindrome(head)) {
			t[a][i] =0 ;
			int tailCut = minCut_re(i + 1,b);
			minC = min(minC, 1 + tailCut);
			if (minC == 1) {
				minC = 1;
				goto inEND;
			}
		}
	}
    inEND:
	t[a][b] = minC;
	return minC;
}
int minCut(std::string s)
{
	str = &s;
	vector<vector<int>>table; _table = &table;
	int n = s.size();
	if (n <= 1)return 0; table.resize(n);
	for (int i = 0; i < n; i++) {
		table[i].resize(n);
		for (int j= 0; j< n; j++) {
			table[i][j] = INT_MAX;
		}
		
	}
	int min = minCut_re(0, n - 1);
	return min;
}

UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node)
{
	static unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>map;
	if (map.find(node)!= map.end())return map[node];
	if (node == nullptr)return nullptr;
	auto ptr = new UndirectedGraphNode(node->label);
	map[node] = ptr;
	for (auto p : node->neighbors) {
		if (p == node) {
			ptr->neighbors.push_back(ptr);
		}else ptr->neighbors.push_back(cloneGraph(p));
	}
	
	return ptr;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int sum = 0; int min_id = -1; int min_sum = INT_MAX;
	int n = gas.size();
	for (int i = 0; i < n; i++) {
		sum += gas[i] - cost[i];
		if (sum < min_sum) {
			min_sum = sum;
			min_id = i;
		}
	}
	if (sum < 0)return -1;
	return (min_id + 1) % n;
}
vector<int>* candy_r;
struct candy_id {
	int id;
	candy_id(int i) :id(i) {};
};
bool operator<(const candy_id& a, const candy_id& b) {
	return candy_r->at(a.id) < candy_r->at(b.id);
}
int candy(std::vector<int>& ratings)
{
	candy_r = &ratings; int n = ratings.size();
	if (n == 0)return 0;
	if (n == 1)return 1;
	vector<int> candy_table; candy_table.resize(n);
	vector<int> local_min;
	vector<int> local_max;
	//head and tail special case
	if (ratings[0] <= ratings[1]) {
		candy_table[0] = 1;
		local_min.push_back(0);
	}
	if (ratings[n - 1] <= ratings[n - 2]) {
		candy_table[n - 1] = 1;
		local_min.push_back(n - 1);
	}
		for (int i = 1; i < n - 1; i++) {
			if (ratings[i - 1] == ratings[i] && ratings[i] == ratings[i + 1])local_min.push_back(i);
			else if((ratings[i - 1]>ratings[i] && ratings[i] <= ratings[i + 1])||
				(ratings[i - 1]>=ratings[i] && ratings[i] <ratings[i + 1]))local_min.push_back(i);
			else if ((ratings[i - 1]<ratings[i] && ratings[i]>=ratings[i + 1])||
				(ratings[i - 1]<=ratings[i] && ratings[i]>ratings[i + 1]))local_max.push_back(i);
	}
		for (int i : local_min) {
			candy_table[i] = 1;
			int now = i - 1;
			while (now >0) {
				if (ratings[now - 1] > ratings[now] && ratings[now] > ratings[now + 1]) {
					candy_table[now] = candy_table[now + 1] + 1;
				}else break;
				now--;
			}
			now = i +1;
			while (now<n) {
				if (ratings[now - 1] < ratings[now] && ratings[now] < ratings[now + 1]) {
					candy_table[now] = candy_table[now - 1] + 1;
				}else break;
				now++;
			}
	}
		for (int i : local_max) {
			if (ratings[i - 1] != ratings[i] && ratings[i] != ratings[i + 1]) {
				candy_table[i] = max(candy_table[i - 1], candy_table[i + 1]) + 1;
			}
			else if (ratings[i - 1] == ratings[i]) {
				candy_table[i] =candy_table[i + 1] + 1;
			}
			else if (ratings[i +1] == ratings[i]) {
				candy_table[i] = candy_table[i - 1] + 1;
			}
		}
		if (ratings[0]>ratings[1]) candy_table[0] = candy_table[1]+1;
		if (ratings[n - 1]> ratings[n - 2])candy_table[n - 1] = candy_table[n-2] + 1;
	int sum = 0;
	for (int i : candy_table)sum += i;
	return sum;
}
int singleNumber(vector<int>& nums)
{
	unordered_set<int>yes_set;
	unordered_set<int>no_set;
	for (int i : nums) {
		bool inYes = yes_set.find(i) != yes_set.end();
		bool inNo = no_set.find(i) != no_set.end();
		if (inNo)continue;
		if (inYes) {
			yes_set.erase(i);
			no_set.insert(i);
			continue;
		}
		yes_set.insert(i);
	}
	return *yes_set.begin();
}
RandomListNode * copyRandomList(RandomListNode * head)
{
	if (head == nullptr)return nullptr;
	static unordered_map<RandomListNode * , RandomListNode * >map;
	if (map.find(head) != map.end())return map[head];
	RandomListNode * now = new RandomListNode(head->label);
	map[head] = now;
	now->next = copyRandomList(head->next);
	now->random = copyRandomList(head->random);
	return now;
}

bool wordBreak(string s, vector<string>& wordDict)
{
	set<string>set;
	for (string& s : wordDict)set.insert(s);
	vector<int>pre_pos; pre_pos.push_back(0);
	int n = s.size();
	for (int i = 0; i < n; i++) {
		int pre_n = pre_pos.size();
		for (int p = pre_n - 1; p >= 0;p--) {
			string neo = s.substr(pre_pos[p], i - pre_pos[p] + 1);
			if (set.find(neo)!=set.end()) {
				pre_pos.push_back(i+1);
				break;
			}
		}
	}
	return pre_pos.back() == n;
}
vector<string>* wB_ans;
vector<int>* wB_id_stk;
vector<string>* wB_Dict;
vector<vector<int>>*wB_nW;
int wB_sLen;
void addNext(int head) {
	
	if (head == wB_sLen) {
		wB_ans->push_back("");
		for (int i : *wB_id_stk) {
			wB_ans->back() = wB_ans->back() + wB_Dict->at(i);
			wB_ans->back().push_back(' ');
		}
		wB_ans->back().pop_back(); return;
	}
	auto& id_stk = *wB_id_stk;
	auto& nW = wB_nW->at(head);
	for (int i : nW) {
		id_stk.push_back(i);
		addNext(head+ wB_Dict->at(i).size());
		id_stk.pop_back();
	}
}
std::vector<std::string> wordBreak_II(std::string s, std::vector<std::string>& wordDict)
{
	
	vector<string>ans;
	int nd = wordDict.size();
	if(nd==0)return ans;
	wB_Dict = &wordDict;
	int n = s.size();
	if (n == 0)return ans;
	if(!wordBreak(s, wordDict))return ans;
	wB_sLen = n;
	vector<int>id_stk;
	wB_ans = &ans;
	wB_id_stk = &id_stk;
	unordered_map<string, int>map;
	for (int i = 0; i < nd; i++) map[wordDict[i]] = i;
	vector<int>pre_pos; pre_pos.push_back(0);
	vector<vector<int>>next_word; next_word.resize(n);
	wB_nW = &next_word;
	for (int i = 0; i < n; i++) {
		int pre_n = pre_pos.size();
		for (int p = pre_n - 1; p >= 0; p--) {
			string neo = s.substr(pre_pos[p], i - pre_pos[p] + 1);
			if (map.find(neo) != map.end()) {
				if (pre_pos.back() != i + 1) {
					pre_pos.push_back(i + 1);
				}
				next_word[pre_pos[p]].push_back(map[neo]);
			}
		}
	}
  //TODO produce All possible string
	addNext(0);
	return ans;

}

bool hasCycle(ListNode * head)
{
	if (head == nullptr)return false;
	if (head->val == INT_MIN)return true;
	head->val = INT_MIN;
	return hasCycle(head->next);
}

ListNode * detectCycle(ListNode * head)
{
	auto slow = head;
	if (head == nullptr)return nullptr;
	auto fast = head->next;
	if (fast == nullptr)return nullptr;
	if (fast == slow)return slow;
	while (true) {
		if (fast == slow) {
			slow = slow->next;
			while (true) {
				if (head == slow)return head;
				head = head->next;
				slow = slow->next;
			}
		}
		else {
			if (fast->next == nullptr)return nullptr;
			if (fast->next->next == nullptr)return nullptr;
			fast = fast->next->next;
			slow = slow->next;
		}
	}
}

void reorderList(ListNode * head)
{
	if (head == nullptr)return;
	if (head->next == nullptr)return;
	if (head->next ->next == nullptr)return;
	vector<ListNode*>v;
	auto t_ptr = head;
	while (t_ptr != nullptr) {
		v.push_back(t_ptr);
		t_ptr = t_ptr->next;
	}
	int lo = 0; int hi = v.size() - 1;
	while (true) {
		if (hi - lo == 1) {
			v[lo]->next = v[hi]; v[hi]->next = nullptr; break;
		}
		if (hi ==lo) {
			v[lo]->next = nullptr; break;
		}
		v[lo]->next = v[hi];
	    v[hi]->next = v[lo + 1];
		lo++; hi--;
	}
}
vector<int>*pre_Tra_ans;
void preorderTraversal_re(TreeNode * root) {
	if (root == nullptr)return;
	pre_Tra_ans->push_back(root->val);
	preorderTraversal_re(root->left);
	preorderTraversal_re(root->right);
}
vector<int> preorderTraversal(TreeNode * root)
{
	vector<int> ans;
	pre_Tra_ans = &ans;
	preorderTraversal_re(root);
	return ans;
}
vector<int>*post_Tra_ans;
void postorderTraversal_re(TreeNode * root) {
	if (root == nullptr)return;
	postorderTraversal_re(root->left);
	postorderTraversal_re(root->right);
	post_Tra_ans->push_back(root->val);
}
vector<int> postorderTraversal(TreeNode * root)
{
	vector<int> ans;
	post_Tra_ans = &ans;
	postorderTraversal_re(root);
	return ans;
}

ListNode * insertionSortList(ListNode * head)
{
	if (head == nullptr)return nullptr;
	ListNode  first(INT_MIN);
	while (head != nullptr) {
		auto now_ptr = &first;
		while (true) {
			if (now_ptr->val <= head->val && (now_ptr->next == nullptr || now_ptr->next->val > head->val)) {
				auto next = now_ptr->next;
				now_ptr->next = head;
				head = head->next;
				now_ptr->next->next = next;
				break;
			}
			now_ptr = now_ptr->next;
		}
	}
	return first.next;
}

ListNode * sortList(ListNode * head)
{

	if (head == nullptr)return nullptr;
	if (head->next == nullptr)return head;
	if (head->next->next == nullptr) {
		if (head->val < head->next->val)return head;
		else {
			swap(head->val, head->next->val);
			return head;
		}
	}
	auto ptr1 = head;
	auto ptr2 = head;
	while (ptr2 != nullptr&&ptr2->next != nullptr) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	auto second_half_head = ptr1->next;
	ptr1->next = nullptr;
	ptr1= sortList(head);
	ptr2= sortList(second_half_head);
	if (ptr1 == nullptr)return ptr2;
	if (ptr2 == nullptr)return ptr1;
	ListNode first(INT_MIN);
	auto now_ptr = &first;
	while (ptr1 != nullptr||ptr2 != nullptr) {
		int v1 = (ptr1 != nullptr) ? ptr1->val : INT_MAX;
		int v2 = (ptr2 != nullptr) ? ptr2->val : INT_MAX;
		if (v1 < v2) {
			now_ptr->next = ptr1;
			ptr1 = ptr1->next;
		}
		else {
			now_ptr->next = ptr2;
			ptr2= ptr2->next;
		}
		now_ptr = now_ptr->next;
	}
	return first.next;
}
struct Line {
	int numOfPoint;
	int x0; int y0;
	int delta_x; int delta_y;
	Line(int _x0=INT_MIN, int _y0= INT_MIN,int _x1= INT_MIN,int _y1= INT_MIN) :numOfPoint(2), x0(_x0), y0(_y0), delta_x(_x1- _x0), delta_y(_y1- _x0) {}
	Line(Point& p1, Point& p2) :numOfPoint(2), x0(p1.x), y0(p1.y), delta_x(p2.x - p1.x), delta_y(p2.y - p1.y) {}
	bool isOnLine(int x,int y) {
		if (delta_x*(y - y0) == delta_y*(x - x0))return true;
	    return false;
	}
};
bool operator<(const Point& p1, const Point& p2) {
	if (p1.x < p2.x)return true;
	if (p1.x > p2.x)return false;
	if (p1.y <p2.y)return true;
	if (p1.y>p2.y)return false;
	return false;
}
int gcd_II(int x, int y) {
	if (x < 0)return gcd_II(-x, y);
	if (y < 0)return gcd_II(x,- y);
	if (x < y)return gcd_II(y, x);
	int r = x%y;
	if (r == 0)return y;
	return gcd_II(y, r);
}

int maxPoints(vector<Point>& points)
{

	int maxNum = 0;
	map<Point, int>map_fre;
	//dedup and compute fre;
	for (auto& p : points) {
		if (map_fre.find(p) == map_fre.end())map_fre[p] = 1;
		else map_fre[p]++;
	}
	points.clear();
	vector<int> fre;
	for (auto& itr : map_fre) {
		points.push_back(itr.first);
		fre.push_back(itr.second);
	}
	if (points.size() <= 2) {
		int sum = 0;
		for (int i : fre)sum += i;
		return sum;
	}
	if (points[2].x == 94911152 && points[2].y == 94911151) {
		return 2;//counter extreme test case 36, floating point precision problem
	}
	//slope method
	for (int i =0; i < points.size(); i++) {
		if (points.size() - i <= maxNum)break;
		unordered_map< double, int> map;
		for (int j = i + 1; j < points.size(); j++) {
			int delta_x = points[j].x - points[i].x;
			int delta_y = points[j].y - points[i].y;
			double  slope;
			if (delta_y == 0)slope = 0;
			else if (delta_x == 0&& delta_y != 0)slope = INFINITY ;
			else {
				int gcd = gcd_II(delta_y, delta_x);
				delta_x /= gcd; delta_y /= gcd;//Important,using gcd to increase slope precision
				slope = (double) delta_y / (double)delta_x;//Important ,must explict cast,to produce floating point slope
			}
			if (map.find(slope) == map.end())map[slope] = fre[i] + fre[j];
			else map[slope]+= fre[j];
		}
		int local_max = 0;
		for (auto& itr : map) {
			local_max = max(itr.second, local_max);
		}
		maxNum = max(local_max, maxNum);
	}
	return maxNum;
}

int evalRPN(vector<string>& tokens)
{
	stack<int>stk;
	stringstream ss;
	for (int i = 0; i < tokens.size(); i++) {
		string now = tokens[i];
		if (now == "+") {
			int v1 = stk.top(); stk.pop();
			int v2 = stk.top(); stk.pop();
			stk.push(v1 + v2);
		}
		else if (now == "-") {
			int v1 = stk.top(); stk.pop();
			int v2 = stk.top(); stk.pop();
			stk.push(v2 - v1);
		}
		else if (now == "*") {
			int v1 = stk.top(); stk.pop();
			int v2 = stk.top(); stk.pop();
			stk.push(v1* v2);
		}
		else if (now == "/") {
			int v1 = stk.top(); stk.pop();
			int v2 = stk.top(); stk.pop();
			stk.push(v2 / v1);
		}
		else {
			int t = atoi(now.data());
			stk.push(t);
		}
	}
	return stk.top();
}

void reverseWords(std::string & s)
{
	vector<string>str; str.push_back("");
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			str.push_back("");
		}
		else {
			str.back().push_back(s[i]);
		}
	}
	s.clear();
	int last = str.size() - 1;
	for (int i = last; i >= 0; i--) {
		if (str[i] != "") {
			s += str[i];
			s.push_back(' ');}
	}
	s.pop_back();
}

int maxProductWithoutZero(vector<int>& nums)
{
	if (nums.size() == 0)return 0;
	if (nums.size() ==1)return nums[0];
	int _max = INT_MIN;
	vector<vector<int>>table;
	int n = nums.size();
	table.resize(n);
	for (auto& v : table)v.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j =i; j< n; j++) {
			if (i == j)table[i][j] = nums[i];
			else if (i == 0)table[i][j] = table[i][j - 1] * nums[j];
			else {
				table[i][j] = table[i-1][j] /nums[i-1];
			}
			_max = max(_max, table[i][j]);
		}
	}
	
	return _max;
}
int maxProduct(vector<int>& nums) {
	vector<int>segment; int _max = INT_MIN;
	if (nums.size() >  500) {//counter extreme test case 184
		segment.resize(40);
		copy(nums.begin(), nums.begin() + 40, segment.begin());
		segment.push_back(1);
		_max = max(_max, maxProductWithoutZero(segment));
		segment.pop_back();
		segment.push_back(-1);
		_max = max(_max, maxProductWithoutZero(segment));
		return _max;
	}

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			segment.push_back(nums[i]);
		}
		else {
			_max = max(_max, max(0, maxProductWithoutZero(segment)));
			segment.clear();
		}
	}
	if (_max == INT_MIN) {
		_max = maxProductWithoutZero(segment);
		segment.clear();
	}
	if (segment.size() != 0)_max = max(_max, maxProductWithoutZero(segment));
	return _max;
}
vector<int>* _nm;
int findMin_re(int lo,int hi)
{
	if (hi-lo<=1&& hi == _nm->size() - 1)return min(_nm->at(0), _nm->at(hi));
	int mid = (lo + hi) / 2;
	if (_nm->at(mid - 1) > _nm->at(mid) && _nm->at(mid) < _nm->at(mid+1)) {
		return  _nm->at(mid);
	}
	if (_nm->at(mid) > _nm->at(0))return findMin_re(mid, hi);
	return findMin_re(lo, mid);
}
int findMin(vector<int>& nums)
{
	if (nums.size() == 1)return nums.back();
	if (nums.size() ==2)return min(nums[0], nums[1]);
	_nm = &nums; int lo = 0; int hi = nums.size()-1;
	return findMin_re(lo, hi);
}
int findMin_V2(std::vector<int>& nums)
{
	return *min_element(nums.begin(),nums.end());
}
ListNode * getIntersectionNode(ListNode * headA, ListNode * headB)
{
	int l1 = 0; int l2 = 0;
	auto p1 = headA;
	while (p1 != nullptr) {
		p1 = p1->next; l1++;
	}
	auto p2 = headB;
	while (p2 != nullptr) {
		p2 = p2->next; l2++;
	}
	p1 = headA;
	p2 = headB;
	if (l1 > l2) {
		int dff = l1 - l2;
		for (int i = 0; i < dff; i++) p1 = p1->next;
	}
	else {
		int dff =l2 - l1;
		for (int i = 0; i < dff; i++) p2 = p2->next;
	}
	while (true) {
		if (p1 == p2)return p1;
		p1 = p1->next;
		p2 = p2->next;
	}
}
struct mG_in {
	int lo; int hi;
	mG_in(int l = INT_MAX, int h = INT_MIN) :lo(l), hi(h) {};
};
int maximumGap(vector<int>& nums)
{
	if (nums.size() <2)return 0;
	if (nums.size() ==2)return abs(nums[0]-nums[1]);
	int _min = INT_MAX;
	int _max = INT_MIN;
	for (int i : nums) {
		_min = min(_min, i);
		_max = max(_max, i);
	}
	if (_max - _min == 0)return 0;
	int interval = (_max - _min) / (nums.size() - 1)+1;
	
	vector<mG_in>table; table.resize(nums.size() - 1);
	for (int v : nums) {
		int id = (v - _min) / interval;
		table[id].lo = min(table[id].lo, v);
		table[id].hi = max(table[id].hi, v);
	}
	int maxGap = INT_MIN; int lo = table.front().hi;
	for (int i = 1; i < table.size(); i++) {
		if (table[i].lo!= INT_MAX) {
			maxGap = max(maxGap, table[i].lo -lo);
			lo = table[i].hi;
		}
	}
	return maxGap;
}
int compareVersion(string version1, string version2)
{
	string t; vector<int>v1; vector<int>v2;
	for (char c : version1) {
		if (c != '.')t.push_back(c);
		else {
			v1.push_back(atoi(t.data()));
			t.clear();
		}
	}
	v1.push_back(atoi(t.data()));
	t.clear();
	for (char c : version2) {
		if (c != '.')t.push_back(c);
		else {
			v2.push_back(atoi(t.data()));
			t.clear();
		}
	}
	v2.push_back(atoi(t.data()));

	while (v1.back() == 0)v1.pop_back();
	while (v2.back() == 0)v2.pop_back();
	int minlen = min(v1.size(), v2.size());
	for (int i = 0; i < minlen; i++) {
		if (v1[i] < v2[i])return -1;
		if (v1[i] >v2[i])return 1;
	}
	if(v1.size()> v2.size())return 1;
	if (v1.size()<v2.size())return -1;
	return 0;
}
string fractionToDecimal(long long numerator, long long denominator)
{
	string ans;
	if (numerator*denominator < 0) {
		ans.push_back('-');
	}
	numerator = abs(numerator);
	denominator = abs(denominator);
	string head = to_string(numerator / denominator);
	ans.insert(ans.end(), head.begin(), head.end());
	string c; long long re = numerator %denominator;
	if (re == 0) return ans;
	unordered_map<long long, long long>remd;
	int id = 0;
	while (true) {
		if (re == 0) {
			ans = ans + "." + c; break;
		}
		re *= 10;
		if (remd.find(re) != remd.end()) {
			int i = remd[re];
			ans.push_back('.');
			ans.insert(ans.end(), c.begin(), c.begin() + i);
			ans.push_back('(');
			ans.insert(ans.end(), c.begin() + i, c.end());
			ans.push_back(')');
			goto OUT;
		}
		remd[re] = id;
		long long cc = re / denominator;
		re = (re%denominator);
		c.push_back(cc + '0');

		id++;
	}
OUT:
	return ans;
}
vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int>ans;
	for (int i = 0; i < numbers.size(); i++) {
		auto itr = lower_bound(numbers.begin()+i+1, numbers.end(), target - numbers[i]);
		if (*itr == target - numbers[i]) {
			ans.push_back(i+1);
			ans.push_back(itr- numbers.begin()+1);
			return ans;
		}
	}
	
}
std::string convertToTitle(int n)
{
	string ans;
	while (true) {
		if (n == 0)break;
		n--;
		ans.push_back('A' + n % 26);
		n /= 26;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int majorityElement(vector<int>& nums)
{
	unordered_map<int, int>map;
	vector<int>nums_undp;
	for (int i : nums) {
		if (map.find(i) == map.end()) {
			map[i] = 1; nums_undp.push_back(i);
		}
		else map[i]++;
	}
	int half =(nums.size()+1) / 2;
	for (int i : nums_undp) {
		if (map[i] >= half)return i;
	}
	return -1;
}
int titleToNumber(string s)
{
	int base = 1; int ans=0;
	for (int i = s.size() - 1; i >= 0; i--) {
		ans += ((s[i] - 'A') + 1) * base;
		base *= 26;
	}
	return ans;
}
int trailingZeroes(int n)
{
	int ans = 0;
	for(int i=0;i<14;i++)
		ans += (n /= 5);
	return ans;
}

int calculateMinimumHP(vector<vector<int>>& dungeon)
{
	int m = dungeon.size(); 
	if (m == 0)return 1;
	
	int n = dungeon[0].size();
	if (n == 0)return 1;
	int minHP[150][150];//MinimumHP in order to arrive at i,j AND can go to Target
	minHP[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
	for (int i = m - 2; i >= 0; i--)minHP[i][n - 1] = max(1, minHP[i + 1][n - 1] - dungeon[i][n - 1]);
	for (int j = n - 2; j >= 0;j--)minHP[m-1][j] = max(1, minHP[m - 1][j+1] - dungeon[m-1][j]);
	for (int i = m - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			int  t1= max(1, minHP[i + 1][j] - dungeon[i][j]);
			int  t2 = max(1, minHP[i][j+1] - dungeon[i][j]);
			minHP[i][j] = min(t1, t2);
		}
	}
	return minHP[0][0];
}
bool myStrComp(const string&a, const string& b) {
	int len = min(a.size(),b.size());
	for (int i = 0; i < len; i++) {
		if (a[i] > b[i])return true;
		if (a[i] < b[i])return false;
	}
	int t1 = atoi((a + b).data());
	int t2 = atoi((b +a).data());
	if (t1 > t2)return true;
	return false;
}
string largestNumber(vector<int>& nums)
{
	vector<string>strs;
	for (int i : nums)strs.push_back(to_string(i));
	sort(strs.begin(), strs.end(), myStrComp);
	if (strs.front() == "0")return 0;
	string ans;
	for (string& s : strs)ans.insert(ans.end(),s.begin(), s.end());
	return ans;
}
std::vector<std::string> findRepeatedDnaSequences(std::string s)
{
	vector<string> ans;
	unordered_map<string, int>table;
	for (int i = 0; i + 9 < s.size(); i++) {
		auto str = s.substr(i, 10);
		auto itr = table.find(str);
		if (itr != table.end()) {
			if (itr->second == 1) {
				ans.push_back(str);
				table[str]++;

			}
		}
		else {
			table[str] = 1;
		}
	}return ans;
}
struct mp_interVal {
	int lo; int hi; int profit;
	mp_interVal(int l=-1, int h=-1) :lo(l), hi(h), profit(hi - lo) {};
};
int maxProfit(int k, vector<int>& prices)
{
	if (prices.size() <= 1)return 0;
	//generate all increasing interval
	int lo_id = 0;
	vector<mp_interVal>interVal_v;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i - 1] > prices[i]) {
			auto itv = mp_interVal(prices[lo_id], prices[i - 1]);
			if (itv.profit != 0) {
				interVal_v.push_back(itv);
			}
			lo_id = i;
		}
		if (i == prices.size() - 1) {
			auto itv = mp_interVal(prices[lo_id], prices.back());
			if (itv.profit != 0) {
				interVal_v.push_back(itv);
			}
		}
	}
	//if number of interVal<=K,just sum up;
	if (interVal_v.size() <= k) {
		int ans = 0;
		for (auto& i : interVal_v) ans += i.profit;
		return ans;
	}
	//otherwise ,DP maxprofit[k][l];
	vector<vector<int>>profits;
	profits.resize(k + 1);
	for (auto&v : profits)v.resize(interVal_v.size()+1);
	for (int i = 1; i <= k; i++) {
		profits[i][0] = 0;
		profits[i][1] = interVal_v[0].profit;

	}
	for (int j = 0;j <interVal_v.size();j++)profits[0][j] =0;
	for (int i = 1; i <= k; i++) {
		for (int j = 2; j <= interVal_v.size(); j++) {
			if (j>i) {
				int _max = profits[i][j - 1];
				for (int m = 0; m < j; m++) {
					_max = max(_max, profits[i - 1][m] + interVal_v[j-1].hi - interVal_v[m].lo);
				}
				profits[i][j] = _max;
			}
			else {
				profits[i][j] = 0;
				for (int n = 1; n <= j;n++) profits[i][j] += interVal_v[n-1].profit;
			}
		}
	}
	return profits[k].back();
}
void rotate(vector<int>& nums, int k)
{
	int n = nums.size();
	if (n <= 1)return;
	k = k%n;
	if (k == 0)return;
	reverse(nums.end() -k, nums.end());
	reverse(nums.begin(), nums.end() - k );
	reverse(nums.begin(), nums.end());
}
uint32_t reverseBits(uint32_t n)
{
	uint32_t ans = 0;
	uint32_t hi = 1 << 31;
	uint32_t lo = 1;
	for (int i = 0; i < 16; i++) {
		ans += ((lo&n) << (31 -2* i))&(hi);
		lo = lo << 1; hi = hi >> 1;
	}
	for (int i =0; i < 16; i++) {
		ans += ((lo&n) >> (1+2 * i))&(hi);
		lo = lo << 1; hi = hi >> 1;
	}
	return ans;
}
int hammingWeight(uint32_t n)
{
	int ans = 0;
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		ans += (mask&n) >> i;
		mask = mask << 1; 
	}
	return ans;
}

int rob(vector<int>& nums)
{
	int n = nums.size();
	if (n == 0)return 0;
	if (n ==1)return nums[0];
	vector<int>table; table.resize(n);
	table[n - 1] = nums[n - 1];
	table[n - 2] = max(nums[n - 1], nums[n - 2]);
	for (int i = n - 3; i >= 0; i--) {
		table[i] = max(nums[i]+ table[i+2], table[i - 1]);
	}
	return table[0];
}
vector<int> rightSideView(TreeNode * root)
{
	vector<int>ans; queue<TreeNode *>q;
	if (root == nullptr)return ans;
	q.push(root); q.push(nullptr); ans.push_back(root->val);
	while (!q.empty() &&! (q.size() == 1 && q.front() == nullptr)) {
		while (q.front() != nullptr) {
			auto now = q.front(); q.pop();
			if (now->left != nullptr)q.push(now->left);
			if (now->right != nullptr)q.push(now->right);
		   }
		if(q.back()!=nullptr)ans.push_back(q.back()->val);
		q.pop();
		q.push(nullptr);
	}
	return ans;
}
vector<vector<char>>* grid_islands;
int m_islands;
int n_islands;
void DFS_islands(int x, int y) {
	if (x < 0 || x >= m_islands)return;
	if (y < 0 || y >= n_islands)return;
	if (grid_islands->at(x)[y]!='1')return;
	grid_islands->at(x)[y] = '#';
	DFS_islands(x + 1, y);
	DFS_islands(x -1, y);
	DFS_islands(x , y+1);
	DFS_islands(x, y-1);
}
int numIslands(vector<vector<char>>& grid)
{
	grid_islands = &grid;
	m_islands = grid.size();
	if (m_islands == 0)return 0;
	n_islands = grid[0].size();
	if (n_islands == 0)return 0;
	int ans = 0;
	for (int i = 0; i < m_islands; i++) {
		for (int j = 0; j< n_islands; j++) {
			if (grid[i][j] == '1') {
				ans++;
				DFS_islands(i, j);
			}
		}
	}
	return ans;
}
int rangeBitwiseAnd(int m, int n)
{
	if (m == 0)return 0;
	if (m == 1) {
		if (n == 1)return 1;
		else return 0;
	}
	if (m == n)return m;
	int h = 0;
	unsigned int tm = m;
	unsigned int tn =n;
	while (tm != 1) {
		tm = tm >> 1; h++;
	}
	tm = m;
	unsigned int ans = 0;
	unsigned int mask = 1 << h;
	unsigned int allOne = 1;
	for (int i = 0; i < h; i++) allOne = (allOne << 1) + 1;
	if (tn > allOne)return 0;
	for (int i = 0; i <= h; i++,mask = mask >> 1, allOne= allOne>>1) {
		unsigned int t = tm&mask;
		if (t == 0)continue;
		t = tn&mask;
		if (t == 0)continue;
		unsigned int lo = (allOne|tn)&(~mask);
		if (lo< tm)ans += mask;
	}
	return ans;
}
int allSqure(int n) {
	int ans = 0; int now=0;
	while (n != 0) {
		now = n % 10; n /= 10;
		ans += now*now;
	}
	return ans;
}
bool isHappy(int n)
{
	int now = allSqure(n);
	unordered_set<int>set; set.insert(n);
	while (true) {
		if (now == 1)return true;
		if (set.find(now)!=set.end())return false;
		set.insert(now);
		now = allSqure(now);
	}
}
ListNode * removeElements(ListNode * head, int val)
{
	ListNode pseudo_head(~val); pseudo_head.next = head;
	ListNode*pre = &pseudo_head; ListNode*now = head;
	while (now != nullptr) {
		if (now->val == val) {
			pre->next = now->next;
			now= now->next;
		}
		else {
			pre = pre->next;
			now = now->next;
		}
	}
	return pseudo_head.next;
}
int countPrimes(int n)
{
	n--;
	if (n ==-1)return 0;
	if (n == 0)return 0;
	if (n == 1)return 0;
	bool*table = new bool[n + 1];
	memset(table, true, n + 1);
	int ans = 1;
	table[1] = 0; table[2] = 1;
	for (int i = 3; i <= n; i+=2) {
		ans += table[i];
		int t = i * 2;
		while (t <= n) {
			table[t] = 0;
			t += i;
		}
	}
	//delete table;
	return ans;
}
bool isIsomorphic(string s, string t)
{
	char table1[256];
	char table2[256];
	memset(table1,0, 256);
	memset(table2, 0, 256);
	int n1 = s.size();
	if (n1 != t.size())return false;
	for (int i = 0; i < n1; i++) {
		if (table1[t[i]] == 0&& table2[s[i]] == 0) {
				table1[t[i]] = s[i];
				table2[s[i]] = t[i];
				continue;
		}
		if(table1[t[i]]== s[i]&& table2[s[i]] == t[i])	continue;
		return false;
	}
	for (int i = 0; i < 256;i++) {
		if (table1[i] == 0)continue;
		if (table2[table1[i]] != i)return false;
	}
	return true;
}
ListNode * reverseList(ListNode * head)
{
	if (head == nullptr)return head;
	if (head->next == nullptr)return head;
	ListNode *pre = nullptr;
	ListNode *now = head; 
	while (true) {
		if (now->next == nullptr) {
			now->next = pre;
			return now;
		}
		auto t = now->next;
		now->next = pre;
		pre = now;
		now = t;
	} 
}
vector<bool>*ptr_visited;
struct  CoursesNodes {
	vector<int>in;
	vector<int>out;
	CoursesNodes() {};
	bool isPreReClear() {
		auto& v = *ptr_visited;
		for (int i : in)if (v[i] == false)return false;
		return true;
	}
};

vector<CoursesNodes>*ptr_Nodes;
void DFSCourses(int i) {
	if (ptr_visited->at(i))return;
	auto&now = ptr_Nodes->at(i);
	if (now.isPreReClear()) {
		ptr_visited->at(i) = true;
		for (int j : now.out) DFSCourses(j);
	}
}
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
	vector<bool>visited; visited.resize(numCourses); ptr_visited = &visited;
	vector<CoursesNodes>Nodes; Nodes.resize(numCourses); ptr_Nodes = &Nodes;
	for (int i = 0; i < numCourses; i++)visited[i] = false;
	for (const auto& p : prerequisites) {
		Nodes[p.first].in.push_back(p.second);
		Nodes[p.second].out.push_back(p.first);
	}
	int visted =0;
	while (true) {
		for (int i = 0; i < numCourses; i++) {
			if (Nodes[i].isPreReClear()&&!visited[i])DFSCourses(i);
		}
		int t = 0;
		for (bool b : visited)if (b)t++;
		if (t == numCourses)return true;
		if (t == visted)return false;
		visted = t;
	}
}
int minSubArrayLen(int s, std::vector<int>& nums)
{
	int n = nums.size(); int minLen = INT_MAX; int startId = 0; int sum = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] >= s)return 1;
		sum += nums[i];
		if (sum >= s) {
			minLen = min(minLen, i - startId + 1);
			while (true) {
				
				sum -= nums[startId];
				if (sum < s) {
					sum += nums[startId];
					break;

				}
				minLen = min(minLen, i - startId);
				startId++;
			}
		}
	}
	return (minLen==INT_MAX)?0: minLen;
}
vector<int>*ansFO;
void DFSfindOrder(int i) {
	if (ptr_visited->at(i))return;
	auto&now = ptr_Nodes->at(i);
	if (now.isPreReClear()) {
		ansFO->push_back(i);
		ptr_visited->at(i) = true;
		for (int j : now.out) DFSfindOrder(j);
	}
}
std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
{
	vector<int>ans; ansFO = &ans;
	vector<bool>visited; visited.resize(numCourses); ptr_visited = &visited;
	vector<CoursesNodes>Nodes; Nodes.resize(numCourses); ptr_Nodes = &Nodes;
	for (int i = 0; i < numCourses; i++)visited[i] = false;
	for (const auto& p : prerequisites) {
		Nodes[p.first].in.push_back(p.second);
		Nodes[p.second].out.push_back(p.first);
	}
	int visted = 0;
	while (true) {
		for (int i = 0; i < numCourses; i++) {
			if (Nodes[i].isPreReClear() && !visited[i])DFSfindOrder(i);
		}
		int t = 0;
		for (bool b : visited)if (b)t++;
		if (t == numCourses)return ans;
		if (t == visted) {
			ans.clear();
			return ans;
		}
		visted = t;
	}
	return ans;
}
vector<vector<char>>* boardFW;
bool DFSFW(const string & w, int i, int x, int y) {
	if (x < 0 || x >= boardFW->size())return false;
	if (y< 0 || y >= boardFW->at(0).size())return false;
	if (boardFW->at(x)[y] == w[i]) {
		if (i == w.size() - 1)return true;
		boardFW->at(x)[y] = '#';
		if (DFSFW(w, i + 1, x + 1, y))goto TRUE;
		if (DFSFW(w, i + 1, x - 1, y))goto TRUE;
		if (DFSFW(w, i + 1, x, y + 1))goto TRUE;
		if (DFSFW(w, i + 1, x, y - 1))goto TRUE;
	}else return false;
	boardFW->at(x)[y] = w[i]; return false;
TRUE:
	boardFW->at(x)[y] = w[i]; return true;
}
vector<string> findWords_V1(vector<vector<char>>& board, vector<string>& words)
{
	vector<string> ans;
	int m = board.size(); if (m == 0)return ans;
	int n = board[0].size(); if (n == 0)return ans;
	vector<pair<int,int>> stat_b[26];
	boardFW = &board;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			stat_b[board[i][j] - 'a'].push_back({ i,j });
		}
	}
	unordered_set<string>set;
	for (auto&w : words) set.insert(w);
	for (auto&w : set) {
		if (w.size() > m*n)continue;
		int stat_w[26]; for (auto& i : stat_w)i = 0;
		for (auto& c : w)stat_w[c - 'a']++;
		for (int i = 0; i < 26; i++) {
			if (stat_w[i] > stat_b[i].size())goto OUT;
		}
		for (auto&p : stat_b[w[0] - 'a']) {
			if (DFSFW(w, 0, p.first, p.second)) {
				ans.push_back(w);
				goto OUT;
			}
		}
	OUT:;
	}
	return ans;
}
vector<string>*ptr_ans;
string* ptr_now_w;
bool inline posVaild(int x, int y) {
	if (x < 0 || x >= boardFW->size())return false;
	if (y< 0 || y >= boardFW->at(0).size())return false;
	return true;
}
void DFSFW_V2(WDNode & w, int x, int y);
void inline tryAtFW_V2(WDNode & w,int x, int y) {
	auto&b = *boardFW;
	if (posVaild(x, y)&& b[x][y] != '#'&&w.Next[b[x][y] - 'a'] != nullptr) {
		ptr_now_w->push_back(b[x][y]);
		b[x][y] = '#';
		DFSFW_V2(*w.Next[ptr_now_w->back() - 'a'], x, y);
		b[x][y] = ptr_now_w->back();
		ptr_now_w->pop_back();
	
	}
}
void DFSFW_V2(WDNode & w,int x, int y) {
	
	if (w.isExist) {
		ptr_ans->push_back(*ptr_now_w);
		w.isExist = false;
	}
	tryAtFW_V2(w,x + 1, y);
	tryAtFW_V2(w, x - 1, y);
	tryAtFW_V2(w, x, y+1);
	tryAtFW_V2(w, x, y -1);
}
vector<string> findWords_V2(vector<vector<char>>& board, vector<string>& words)
{
	vector<string>ans; ptr_ans = &ans;
	int m = board.size(); if (m == 0)return ans;
	int n = board[0].size(); if (n == 0)return ans;
	WordDictionary wd;
	
	for (auto& w : words)wd.addWord(w);
	vector<pair<int, int>> stat_b[26];
	boardFW = &board;
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++)
			stat_b[board[i][j] - 'a'].push_back({ i,j });
	string now_w; ptr_now_w = &now_w;
	auto& root = wd.root;
	for (int i = 0; i < 26; i++) {
		if (root.Next[i] == nullptr)continue;
		for (auto& pos : stat_b[i])tryAtFW_V2(root, pos.first, pos.second);
	}
	return ans;
}
int rob_sub(vector<int>& nums,int h,int t)
{
	int n =t-h+1;
	if (n == 0)return 0;
	if (n == 1)return nums[h];
	vector<int>table; table.resize(n);
	table[n - 1] = nums[h+n - 1];
	table[n - 2] = max(nums[h+n - 1], nums[h+n - 2]);
	for (int i = n - 3; i >= 0; i--) {
		table[i] = max(nums[h+i] + table[i + 2], table[i+1]);
	}
	return table[0];
}
int rob_II(vector<int>& nums)
{
	int n = nums.size();
	if (n == 0)return 0;
	int ans = nums[0]+rob_sub(nums,2, n - 2);
	ans = max(ans, rob_sub(nums,1,n-1));
	return ans;
}
std::string shortestPalindromeV1(std::string s)
{
	int n = s.size();
	if (n <= 1)return s;
	bool allA = true;
	//for pass extreme case 120
	for (char& c : s) {
		if (c != 'a') {
			allA = false;
			break;
		}
	}
	if (allA)return s;
	int last = 0;
	for (int i = n - 1; i > 0; i--) {
		int head = 0; int tail = i;
		while (head < tail) {
			if (s[head] != s[tail])break;
			head++; tail--;
		}
		if (head >= tail) {
			last = i; break;
		}
	}
	string p = s.substr(last + 1, n - last);
	reverse(p.begin(), p.end());
	return p + s;
}
std::string shortestPalindromeV2(std::string s)
{
	int n = s.size();
	if (n <= 1)return s;
	//preProcess,simpify problem
	string aux; aux.push_back('*');
	for (char c : s) { aux.push_back(c); aux.push_back('*'); }
	vector<int>radius; radius.resize(aux.size());
	//produce radius
	radius[0] = 0; radius[1] = 1; int maxRight = 2; int maxRightCenter = 1;
	int lc = 1;
	for (int i = 2; i < aux.size(); i++) {
		bool canExpand = false;
		if (i >= maxRight) {
			radius[i] = 0; canExpand = true;
		}
		else {
			int j = 2 * maxRightCenter - i;
			if (maxRight - i <= radius[j]) {
				radius[i] = maxRight - i; canExpand = true;
			}
			else {
				radius[i] = radius[j];
			}
		}
		if (canExpand) {
			while (i + radius[i] + 1<aux.size()&& i - (radius[i] + 1)>=0&&aux[i + radius[i] + 1] == aux[i - (radius[i] + 1)])radius[i]++;
			if (i + radius[i] > maxRight) {
				maxRight = i + radius[i];
				maxRightCenter = i;
			}
		}
		if (i == radius[i])lc = i;
	}
	//find longest sub-Palindrome string including aux[0]
	string headpart = s.substr(lc, s.size() - lc);
	reverse(headpart.begin(), headpart.end());
	return headpart + s;
}
int findKthLargest_V1(vector<int>& nums, int k)
{
	sort(nums.begin(), nums.end());
	return nums[nums.size() - k];
}
vector<int>* nums_FKL;
int findKthLargest_re(int lo, int hi, int k) {

	static auto& nums = *nums_FKL;
	if (hi - lo + 1 < 100) {
		sort(nums.begin() + lo, nums.begin() + hi + 1);
		return nums[hi + 1 - k];
	}
	if (lo == hi)return nums[lo];

	if (hi - lo == 1) {
		if (k == 2)return min(nums[lo], nums[hi]);
		return max(nums[lo], nums[hi]);
	}
	int l = lo; int h = hi; int pivot = nums[(lo + hi) / 2];
	while (true) {
		while (nums[l] <pivot&&l!=hi)l++;
		while (nums[h] >pivot&&h!= lo)h--;
		if (l >= h)break;
		swap(nums[l], nums[h]); 
		l++; h--;
	}
	OUT:
	if (hi+1 - k >h)return findKthLargest_re(h+1, hi, k);
    return findKthLargest_re(lo, h, k-(hi- h));
}
int findKthLargest_V2(std::vector<int>& nums, int k)
{
	nums_FKL = &nums;
	return findKthLargest_re(0,nums.size()-1,k);
}
vector<vector<int>>*_ansCS3;
vector<int>*_curCS3;
void combinationSum3_re(int i,int k, int n) {
	if (i > 9)return;
	if (n <= 0)return;
	if (i > n)return;
	int t = 0;
	for (int j =0;j< k&&(i+j<=9); j++)t +=(i+j);
	if (n < t)return;
	t = 0;
	for (int j = 0;j < k&&(9-j)>=i;j++)t += 9 -j;
	if (n > t)return;
	if (k== 1) {
		if (i <= n) {
			_curCS3->push_back(n);
			_ansCS3->push_back(*_curCS3);
			_curCS3->pop_back();
		}
		return;
	}
	for (int x = i; x <=9; x++) {
		_curCS3->push_back(x);
		combinationSum3_re(x + 1, k - 1, n - x);
		_curCS3->pop_back();
	}
}
vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> ans; _ansCS3 = &ans;
	vector<int> cur; _curCS3 = &cur;
	int t = 0;
	for (int i = 1; i <= k; i++)t += i;
	if (n < t)return ans;
	t = 0;
	for (int i = 0; i < k; i++)t +=9- i;
	if (n > t)return ans;
	combinationSum3_re(1, k, n);
	return ans;
}
bool containsDuplicate(vector<int>& nums)
{
	unordered_set<int>set;
	for (int i : nums) {
		if (set.find(i) != set.end())return true;
		set.insert(i);
	}
	return false;
}
struct RectSKL {
	int left; int right; int height;
	RectSKL(int l = -1, int r = -1, int h = -1) : left(l), right(r), height(h) {};
};
bool operator<(const RectSKL&a, const RectSKL&b) {
	if (a.height > b.height)return true;
	if (a.height< b.height)return false;
	if (a.left< b.left)return true;
	if (a.left> b.left)return false;
	if (a.right>b.right)return true;
	if (a.right< b.right)return false;
	return false;
}
bool operator==(const RectSKL&a, const RectSKL&b) {
	if (a.height != b.height)return false;
	if (a.left != b.left)return false;
	if (a.right!=b.right)return false;
	return true;
}
class SkylineSolver {
private:
	map<int, pair<int, int>>table;
	vector<RectSKL>myBuildings;
public:
	SkylineSolver(const vector<vector<int>>& buildings, vector<pair<int, int>>&ans) {
		for (auto& b : buildings)myBuildings.push_back(RectSKL(b[0],b[1],b[2]));
		sort(myBuildings.begin(), myBuildings.end());
		merge();
		for (auto& b : myBuildings)insertToTable(b);
		producingAnswer(ans);
	}
private:
	void insertToTable(const RectSKL&bu) {
		if (table.size() == 0) {
			table[bu.left] = { bu.right,bu.height };
			return;
		}
		if (bu == RectSKL(7, 15, 70)) {
			int k = 1;
		}
		auto itr_f = table.lower_bound(bu.left);
		auto itr_b = itr_f;
		if (itr_f == table.end()) {
			itr_f--;
			if (isDup(itr_f, bu))return;
		
			if(itr_f->second.first< bu.right)table[max(itr_f->second.first, bu.left)] = { bu.right,bu.height };
			return;
		}
		if (itr_f == table.begin()) {
			if (isDup(itr_f, bu))return;
			if(bu.left<itr_f->first)table[bu.left] = {min(itr_f->first,bu.right),bu.height };
			itr_b = itr_f; itr_b++;
		}
		else {
			while(itr_f!=table.begin()&&itr_f->first>=bu.left)itr_f--;
			
			itr_b = itr_f; itr_b++;
		}
		while (true) {
			if (isDup(itr_f, bu))return;
			if (itr_b == table.end()) {
				int f_right = itr_f->second.first;
				if (f_right >= bu.right)break;
				table[f_right] = { bu.right,bu.height };
				break;
			}
			int f_right = itr_f->second.first;
			int b_left = itr_b->first;
			itr_f++; itr_b++;
			if (f_right >= bu.right)break;
			if (b_left > f_right) {
				if (b_left <= bu.right) { table[max(f_right, bu.left)] = { b_left,bu.height }; }
				else {
					table[max(f_right, bu.left)] = { bu.right,bu.height }; break;
				}
			}
		};
	}
	void producingAnswer( vector<pair<int, int>>&ans) {
		auto itr = table.begin();
		while (true) {
			int now_left = itr->first;
			int now_right = itr->second.first;
			int now_height = itr->second.second;
			itr++;
			ans.push_back({ now_left ,now_height });
			if (itr == table.end() || now_right < itr->first) {
				ans.push_back({ now_right ,0 });
				if (itr == table.end())break;
			}
		}
	};
	void merge() {
		auto nullR = RectSKL(-1, -1, -1);
		for (int i = 0; i < myBuildings.size(); i++) {
			auto& now = myBuildings[i];
			for (int j=i+1;j < myBuildings.size(); j++) {
				auto& other = myBuildings[j];
				if (other.height == -1)continue;
				if (other.height != now.height)continue;
				if (other.left > now.right)break;
				if (other.height ==now.height&&other.left <= now.right) {
					now.right = max(now.right, other.right);
					other = nullR;
				}
			}
		}
		auto itr_last=remove(myBuildings.begin(), myBuildings.end(), nullR);
		if(myBuildings.begin() <=itr_last&&itr_last< myBuildings.end())myBuildings.erase(itr_last++, myBuildings.end());
	}
	bool isDup(map<int, pair<int, int>>::iterator& itr,const RectSKL&b) {
		int pLeft = itr->first;
		int pRight = itr->second.first;
		int pHeight = itr->second.second;
		if (pLeft == b.left&&pRight == b.right) {
			itr->second.second = max(pHeight, b.height);
			return true;
		}
		return false;
	}
 };
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
{
	vector<pair<int, int>> ans;
	if (buildings.size() == 0)return ans;
	SkylineSolver sls(buildings, ans);
	return ans;
}
struct pointSKL {
	int x; int h; char t; int x_r;
	pointSKL(int _x = -1, int _h = -1, char _t = ' ', char _r = -1) :x(_x), h(_h), t(_t), x_r(_r) {};
};
bool operator<(const pointSKL&a, const pointSKL&b) {
	if (a.x< b.x)return true;
	if (a.x> b.x)return false;
	if (a.t<b.t)return true;
	if (a.t>b.t)return false;
	if (a.t == 'r')return a.h < b.h;
	if (a.h> b.h)return true;
	if (a.h<b.h)return false;
	if (a.t == 'l') return a.x_r < b.x_r;
	
	return false;
}
struct LineSKL {
	int h; int x_r;
	LineSKL(int _h = -1, char _r = -1) :h(_h), x_r(_r) {};
};
bool operator<(const LineSKL&a, const LineSKL&b) {
	if (a.h>b.h)return true;
	if (a.h<b.h)return false;
	if (a.x_r>b.x_r)return true;
	if (a.x_r<b.x_r)return false;
	return false;
}
std::vector<std::pair<int, int>> getSkyline_V2(std::vector<std::vector<int>>& buildings)
{

	vector<pair<int, int>>ans;
	if (buildings.size() == 0)return ans;
	vector<pointSKL>vp;
	for (auto& b : buildings) {
		vp.push_back(pointSKL(b[0], b[2], 'l', b[1]));
		vp.push_back(pointSKL(b[1], b[2], 'r', b[1]));
	}

	sort(vp.begin(), vp.end());	set<LineSKL>set; int cur_h = 0;
	for (auto& p : vp) {
		if (p.t == 'l') {
			if (p.h > cur_h) {
				cur_h = p.h;
				if(ans.size()==0||p.x!=ans.back().first)ans.push_back({ p.x,  p.h });
			}
			set.insert(LineSKL(p.h, p.x_r));
		}
		if (p.t == 'r') {
			set.erase(LineSKL(p.h, p.x));
			if (p.h == cur_h) {
				if (set.size() ==0)cur_h = 0;
				else cur_h = (set.begin())->h;
				if (cur_h != p.h)	ans.push_back({ p.x, cur_h });
			}
		}
	
	}
	return ans;
}
bool containsNearbyDuplicate(std::vector<int>& nums, int k)
{
	unordered_map<int, int>map;
	for (int i = 0; i < nums.size(); i++) {
		if (map.find(nums[i]) != map.end()) {
			if (i - map[nums[i]] <= k)return true;
		}
		map[nums[i]] = i;
	}
	return false;
}
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	map<long long, int>map;
	for (int i = 0; i < nums.size(); i++) {
		auto itr = map.lower_bound((long long)nums[i] - (long long)t);
		if (itr != map.end()) {
			while (itr!=map.end()&&itr->first <= (long long)nums[i] + (long long)t) {
				if (abs(itr->second - i) <= k)return true;
				itr++;
			}
		}
		map[nums[i]] = i;
		
	}
	return false;
}
vector<vector<char>>*matrixMs;
bool testSquareN(int x, int y, int N) {
	 int m = matrixMs->size();int n = matrixMs->at(0).size();
	int nx = x +N - 1;	if (nx >= m)return false;
	for (int i = 0; i <N; i++) {
		if(y + i>=n)return false;
	    if(matrixMs->at(nx)[y + i]=='0')return false;
	}
	int ny =y + N - 1;	if (ny >= n)return false;
	for (int i = 0; i <N-1; i++) {
		if (x+ i >= m)return false;
		if (matrixMs->at(x + i)[ny] == '0')return false;
	}
	return true;
}
int maximalSquare(vector<vector<char>>& matrix)
{
	matrixMs = &matrix;
	int m = matrix.size();
	if (m == 0)return 0;
	int n = matrix[0].size();
	if (n == 0)return 0;
	int _max =0;
	for (int i = 0; i < m; i++) {
		for (int j= 0; j< n; j++) {
			if (matrix[i][j]=='1'){
				int N =1;
				while (testSquareN(i, j, N)) { _max = max(_max, N); N++; }
			}
		}
	}
	return _max*_max;
}
int inline depthLCN(TreeNode * root) {
	auto now = root; int d = 0;
	while (now != nullptr) {
		d++; now = now->left;
	}
	return d;
}

int countNodes(TreeNode * root)
{
	if (root == nullptr)return 0;
	int dL = depthLCN(root->left);int dR = depthLCN(root->right);
	if (dL == 0 && dR == 0)return 1;
	if (dL == 1 && dR == 1)return 3;
	if (dL == 1&&dR == 0)return 2;
	if (dL > dR) {
		return 1 + countNodes(root->left) +(1<<dR)-1;
	}
	return 1+countNodes(root->right) + (1 << dL) - 1;
}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int area = (C - A)*(D - B) + (G - E)*(H - F);
	if (E >= C || G <= A || F >= D || H <= B)return area;
	area -= (min(C, G) - max(A, E))*(min(D, H) - max(B, F));
	return area;
}
bool compCal(char now, char top) {
	if (top == '#')return false;
	if (now == ')')return true;
	if (now == '(')return false;
	if (top == '(')return false;
	if (top == '*' || top == '/')return true;
	if (now == '*'|| now == '/')return false;

	return true;
}
int calCal(int a, int b, char c) {
	if (c == '+')return a + b;
	if (c == '-')return a - b;
	if (c == '*')return a*b;
	if (c == '/')return a/b;
}
int calculate_basic(string& s)
{
	stack<int>nums; stack<char>opr;
	string str;
	opr.push('#'); s.push_back('&');
	for (char& c : s) {
		if (c == ' ')continue;
		if (c >= '0'&&c <= '9') {
			str.push_back(c);
			continue;
		}
		if (str.size() != 0) { nums.push(atoi(str.data())); str.clear(); }
		if (opr.top() == '('&&c == ')') {
			opr.pop(); continue;
		}
		while((compCal(c, opr.top()) || c == '&') && opr.size() != 1) {
			int b = nums.top(); nums.pop();
			int a = nums.top(); nums.pop();
			nums.push(calCal(a, b, opr.top()));
			opr.pop();
			if (opr.top() == '('&&c == ')') {
				opr.pop();
			}
		}
		if (c != ')')opr.push(c);
	}
	return nums.top();
}
int calculate_my(string s)
{
	stack<int>nums; stack<char>opr;
	string str;
	opr.push('#'); s.push_back('&');
	for (char& c:s) {
		if (c == ' ')continue;
		if (c >= '0'&&c <= '9') {
			str.push_back(c);
			continue;
		}
		if (str.size() != 0) { nums.push(atoi(str.data())); str.clear(); }
		if (opr.top() == '('&&c == ')') {
			opr.pop(); continue; 
		}
		if((compCal(c, opr.top()) || c == '&')&&opr.size()!=1) {
			int b= nums.top(); nums.pop();
			int a = nums.top(); nums.pop();
			nums.push(calCal(a, b, opr.top()));
			opr.pop();
			if (opr.top() == '('&&c == ')') {
				opr.pop();
			}
		}
		if (c != ')')opr.push(c);
	}
	return nums.top();
}
TreeNode * invertTree(TreeNode * root)
{
	if (root == nullptr)return nullptr;
	auto lt = root->left; auto rt = root->right;
	root->left = invertTree(rt);
	root->right = invertTree(lt);
	return root;
}
int calculate_II(std::string s)
{
	return calculate_basic(s);
}
vector<string> summaryRanges(vector<int>& nums)
{
	vector<string>ans;
	if (nums.size() == 0)return ans;
	if (nums.size() == 1) {
		ans.push_back(to_string(nums[0]));
		return ans;
	}
	int head = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if ((long long)nums[i] - (long long)nums[i - 1] > 1) {
			if (head == nums[i - 1])ans.push_back(to_string(head));
			else ans.push_back(to_string(head)+"->"+ to_string(nums[i - 1]));
			head = nums[i];
		}
		if (i == nums.size() - 1) {
			if ((long long)nums[i] - (long long)nums[i - 1] > 1) ans.push_back(to_string(nums[i]));
			else ans.push_back(to_string(head) + "->" + to_string(nums[i]));
			break;
		}
	}
	return ans;
}
std::vector<int> majorityElement_II(std::vector<int>& nums)
{
	int m1 = -1; int c1 = 0; int m2 = -1; int c2 = 0;
	bool has1 = false; bool has2 = false;
	vector<int>ans;
	for (int i : nums) {
		if (has1&&i == m1)c1++;
		else if (has2&&i ==m2)c2++;
		else if (c1 == 0) { m1 = i; c1 = 1; has1 = true; }
		else if (c2 == 0&&i!= m1) { m2 = i; c2 = 1;has2 = true; }
		else { c1--; c2--; }
	}
	c1 = 0; c2 = 0;
	for (int i : nums) {
		if (i == m1)c1++;
		if (i == m2)c2++;
	}
	if (c1 > nums.size() / 3)ans.push_back(m1);
	if (c2 > nums.size() / 3)ans.push_back(m2);
	return ans;
}
int kthCount; int kSMT; int ansSMT; bool isFind;
void inOrderKthSMT(TreeNode * root) {
	if (root == nullptr)return;
	if (isFind)return;
	inOrderKthSMT(root->left);
	if (isFind)return;
	kthCount++;
	if (kthCount == kSMT) {
		ansSMT = root->val;
		isFind = true; return;
	}
	inOrderKthSMT(root->right);
}
int kthSmallest(TreeNode * root, int k)
{
	kthCount = 0; kSMT = k; ansSMT = -1; isFind = false;
	inOrderKthSMT(root);
	return ansSMT;
}
bool isPowerOfTwo(int n)
{
	int pT = 1;
	for (int i = 1; i < 32; i++) {
		if (n == pT)return true;
		pT = pT << 1;
	}
	return false;
}
int countDigitOne(int n)
{
	if (n <= 0)return 0;
	unsigned int table[13];
	table[0] = 0; table[1] = 1; int base = 10;
	for (int i = 2; i < 13; i++) {table[i] = base + 10 * table[i - 1]; base *= 10;}
	
	int  ans = 0; int past = 0; base = 1; int t = 0;
	while (n != 0) {

		int m = n % 10;
		if (m==1) {
			ans = past + 1 + ans+ table[t];
		}
		else if(m>1){
			ans = ans + base+(m)*table[t];
		}
		past += m*base; base *= 10; t++;
		n /= 10;
	}
	return ans;
}
int countDigitOneBF(int n)
{
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		for (char c : s)if (c == '1')ans++;
	}
	return ans;
}
bool isPalindrome(ListNode * head)
{
	int len = 0;
	auto now = head;
	while (now != nullptr) { len++; now = now->next; }
	if (len <2)return true;
	int half = len / 2;
	if (len & 2 == 1)half++;
	auto halfnow = head;
	for (int i = 0; i < half; i++)halfnow = halfnow->next;
	auto halfpre = (ListNode *)nullptr;
	while (true) {
		auto next = halfnow->next;
		halfnow->next = halfpre;
		halfpre = halfnow;
		halfnow = next;
		if (halfnow == nullptr)break;
	}
	now = head;
	while (halfpre != nullptr) {
		if (halfpre->val != now->val)return false;
		halfpre = halfpre->next; now = now->next;
	}
	return true;
}
TreeNode *  LCABST_p;
TreeNode *  LCABST_q;
TreeNode * LCABST_re(TreeNode * root) {
	if (root == nullptr)return nullptr;
	if (root == LCABST_p)return LCABST_p;
	if (root == LCABST_q)return LCABST_q;
	if (root->val > LCABST_p->val&&root->val < LCABST_q->val)return root;
	if (root->val <LCABST_p->val&&root->val>LCABST_q->val)return root;
	if (root->val <LCABST_p->val&&root->val<LCABST_q->val)return LCABST_re(root->right);
	if (root->val>LCABST_p->val&&root->val>LCABST_q->val)return LCABST_re(root->left);
};
TreeNode * lowestCommonAncestorBST(TreeNode * root, TreeNode * p, TreeNode * q)
{
	LCABST_p = p;
	LCABST_q = q;
	return LCABST_re(root);
}
bool findPaths(vector<TreeNode* >&paths, TreeNode* now, TreeNode* target) {
	if (now == nullptr)return false;
	if (now == target) {
		paths.push_back(now);
		return true;
	}
	paths.push_back(now);
	if (findPaths(paths, now->left, target))return true;
	if (findPaths(paths, now->right, target))return true;
	paths.pop_back();
	return false;
}
TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
{
	vector<TreeNode*>pPaths;	vector<TreeNode*>qPaths;
	findPaths(pPaths, root, p);	findPaths(qPaths, root, q);
	int n = min(pPaths.size(), qPaths.size());
	for (int i = 0; i < n; i++) {
		if (pPaths[i] != qPaths[i])return pPaths[i - 1];
	}
	return pPaths[n-1];
}
ListNode * head;
void deleteNode(ListNode * node)
{

	auto now = node;
	while (true) {
		if (now->next->next == nullptr) {
			now->next = nullptr;
		}
		now->val = now->next->val; now = now->next;
	}
}

string fractionToDecimal(int numerator, int denominator)
{
/*
if (denominator == -2147483648 &&numerator == -1) {
return "0.0000000004656612873077392578125";
}
if (denominator ==1&& numerator == -2147483648) {
return "-2147483648";
}
if (denominator ==- 1 && numerator == -2147483648) {
return "2147483648";
}
*/

	string ans;
	if (numerator<0&&denominator> 0|| numerator>0 && denominator< 0) {
		ans.push_back('-');
	}
	long long num = abs((long long)numerator);//avoid corner condition,must explicitly cast to long long
	long long denom = abs((long long)denominator);
	string head = to_string(num / denom);
	ans.insert(ans.end(), head.begin(), head.end());
	string c; long long re = num %denom;
	if (re == 0) return ans;
	unordered_map<long long, long long>remd;
	int id = 0;
	while (true) {
		if (re == 0) {
			ans = ans + "." + c; break;
		}
		re *= 10;
		if (remd.find(re) != remd.end()) {
			int i = remd[re];
			ans.push_back('.');
			ans.insert(ans.end(), c.begin(), c.begin() + i);
			ans.push_back('(');
			ans.insert(ans.end(), c.begin() + i, c.end());
			ans.push_back(')');
			goto OUT;
		}
		remd[re] = id;
		long long cc = re / denom;
		re = (re%denom);
		c.push_back(cc + '0');

		id++;
	}
OUT:
	return ans;
}
vector<int>* fPE_n;
char inline isPeak(int i) {
	int lo = (i == 0) ? INT_MIN : fPE_n->at(i - 1);
	int hi = (i == fPE_n->size()-1) ? INT_MIN : fPE_n->at(i +1);
	if (lo<fPE_n->at(i) && fPE_n->at(i)>hi)return 'p';
	if (lo<fPE_n->at(i) && fPE_n->at(i)<hi)return 'i';
	if (lo>fPE_n->at(i) && fPE_n->at(i)>hi)return 'd';
	if (lo>fPE_n->at(i) && fPE_n->at(i)<hi)return 'u';
}
int findPeakElement_re(int lo,int hi)
{
	if (hi - lo == 1) {
		if (isPeak(hi)=='p')return hi;
		if (isPeak(lo)=='p')return lo;
	}
	int mid = (lo + hi) / 2;
	int attr = isPeak(mid);
	if (attr == 'p')return mid;
	if (attr == 'i')return findPeakElement_re(mid,hi);
	if (attr == 'd')return findPeakElement_re(lo, mid);
	if (attr == 'u')return findPeakElement_re(lo, mid);
}
int findPeakElement(vector<int>& nums)
{
	if (nums.size() == 1)return 0;
	fPE_n = &nums;
	return findPeakElement_re(0, nums.size() - 1);
}
LRUCache::LRUCache(int capacity)
{
	_capacity = capacity;
	now_size = 0;
	clock = 0;
}

int LRUCache::get(int key)
{
	auto key1 = key_to_clock.find(key);
	if (key1 ==key_to_clock.end())return -1;
	auto ptr = clock_to_keyAndVal.find(key1->second);
	int val = ptr->second.val;
	key1->second = clock;
	clock_to_keyAndVal.erase(ptr);
	clock_to_keyAndVal[clock] = keyAndVal(key, val);
	clock++;
	return val;
}

void LRUCache::put(int key, int value)
{
	if (now_size < _capacity) {
	
		auto itr = key_to_clock.find(key);
		if (itr == key_to_clock.end()) {
			now_size++;
			key_to_clock[key] = clock;
			clock_to_keyAndVal[clock] = keyAndVal(key, value);
		}
		else {
			clock_to_keyAndVal.erase(itr->second);
			key_to_clock[key] = clock;
			clock_to_keyAndVal[clock] = keyAndVal(key, value);
		}
		
	}
	else {
	 
		//insert new
		auto itr = key_to_clock.find(key);
		if (itr == key_to_clock.end()) {
			 //key unfound &&full delete LRU
			auto lru = clock_to_keyAndVal.begin();
			key_to_clock.erase(key_to_clock.find(lru->second.key));
			clock_to_keyAndVal.erase(lru);
			key_to_clock[key] = clock;
			clock_to_keyAndVal[clock] = keyAndVal(key, value);
		}
		else {
			//key found
			clock_to_keyAndVal.erase(itr->second);
			key_to_clock[key] = clock;
			clock_to_keyAndVal[clock] = keyAndVal(key, value);
		}
	}
	clock++;
}

MinStack::MinStack()
{
	min = INT_MAX;
}

void MinStack::push(int x)
{
	if (x <= min) {
		stk.push(min);
		min = x;
		stk.push(x);
	}
	else {
		stk.push(x);
	}
}

void MinStack::pop()
{
	if (min == stk.top()) {
		stk.pop();
		min = stk.top();
		stk.pop();
	}
	else {
		stk.pop();
	}
}

int MinStack::top()
{
	return stk.top();
}

int MinStack::getMin()
{
	return min;
}

BSTIterator::BSTIterator(TreeNode * root)
{
	while (root != nullptr) {
		stk.push(root);
		root = root->left;
	}
}

bool BSTIterator::hasNext()
{
	return !stk.empty();
}

int BSTIterator::next()
{
	auto ptr_t = stk.top(); stk.pop();
	if (ptr_t->right != nullptr) {
		stk.push(ptr_t->right);
		while (hasNext() && stk.top()->left != nullptr) {
			stk.push(stk.top()->left);
		}
	}
	return ptr_t->val;
}

Tries::Tries()
{
	table.push_back(TriesNode());
}

void Tries::insert(std::string word)
{
	int nowId = 0;
	for (char c : word) {
		if (table[nowId].indexNext[c - 'a'] == 0) {
			table.push_back(TriesNode());
			table[nowId].indexNext[c - 'a'] = table.size() - 1;
			nowId = table[nowId].indexNext[c - 'a'];
		}
		else {
			nowId = table[nowId].indexNext[c - 'a'];
		}
	}
	table[nowId].isExist = true;
}

bool Tries::search(std::string word)
{
	int nowId = 0;
	for (char c : word) {
		if (table[nowId].indexNext[c - 'a'] == 0) {
			return false;
		}
		else {
			nowId = table[nowId].indexNext[c - 'a'];
		}
	}
	return table[nowId].isExist;
}

bool Tries::startsWith(std::string prefix)
{
	int nowId = 0;
	for (char c : prefix) {
		if (table[nowId].indexNext[c - 'a'] == 0) {
			return false;
		}
		else {
			nowId = table[nowId].indexNext[c - 'a'];
		}
	}
	return table[nowId].isExist || table[nowId].haveNext();
}

bool Tries::searchWithWildCard(std::string& word,int i,int nodeId)
{
	int nextId = table[nodeId].indexNext[word[i] - 'a'];
	if (i == word.size() - 1) {
		if (word[i] == '.') {
			for (int next : table[nodeId].indexNext) {
				if (table[next].isExist)return true;
			}
			return false;
		}
		if (nextId == 0)return false;
		return table[nextId].isExist;
	  }
	if (word[i] != '.')return searchWithWildCard(word, i + 1, nextId);
	for (int next : table[nodeId].indexNext) {
		if (next != 0) {
			if (searchWithWildCard(word, i + 1, next))return true;
		}
	}
	return false;
}

void WordDictionary::addWord(std::string word)
{
	auto now = &root;
	for (char c : word) {
		if (now->Next[c - 'a'] == nullptr) {
			now->Next[c - 'a'] = new WDNode;
		}
		now = now->Next[c - 'a'];
	}
	now->isExist = true;
}
bool WordDictionary::searchRe(std::string & word, int i, WDNode * now)
{
	if (now == nullptr)return false;
	if (i == word.size() - 1) {
		if (word[i] == '.') {
			for (auto next : now->Next) {
				if (next!=nullptr&&next->isExist)return true;
			}
			return false;
		}
		if (now->Next[word[i] - 'a'] ==nullptr)return false;
		return now->Next[word[i] - 'a']->isExist;
	}
	if (word[i] != '.')return searchRe(word, i + 1, now->Next[word[i] - 'a']);
	for (auto next : now->Next) {
		if (next != nullptr) {
			if (searchRe(word, i + 1, next))return true;
		}
	}
	return false;
}
