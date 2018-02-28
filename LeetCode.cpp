#include "stdafx.h"
#include "LeetCode.h"
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <map>
#include <sstream>
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
