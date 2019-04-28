#include "stdafx.h"
#include "myHeader.h"
#include "iostream"
#include "sstream"
#include<algorithm>
#include<queue>
#define US_MAX 65500
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<bitset>
#include<functional>
#include <math.h>
#include <set>
using namespace std;
vector<int>*numsCRS;
vector<long long>*sumCRS;
int countCRS;
int lowerCRS; int upperCRS;
bool inline inInterval(long long x) {
	return (x >= lowerCRS&&x <= upperCRS);
}
void countRangeSumRe(int lo, int hi) {
	auto& nums = *numsCRS;
	auto& sums = *sumCRS;
	auto& count = countCRS;
	if (hi == lo)return;
	if (hi-lo==1) {
		if (inInterval(sums[hi] - sums[lo]))countCRS++;
		if (sums[lo] > sums[hi])swap(sums[lo], sums[hi]);
		return;
	}
    int mid = (hi + lo) / 2;
	countRangeSumRe(lo, mid);
	countRangeSumRe(mid+1,hi);
	//merge
	int lo_pos = mid + 1; int hi_pos = mid + 1;
	long long lo_bound = LONG_MAX; 	long long  hi_bound = LONG_MIN;
	for (int i = lo; i <= mid; i++) {
		lo_bound = lowerCRS+ sums[i];
		hi_bound = upperCRS + sums[i]; 
		while (lo_pos < hi + 1 && sums[lo_pos] < lo_bound)lo_pos++;
		while (hi_pos < hi+1 && sums[hi_pos] <=hi_bound)hi_pos++;
		if (lo_pos == hi + 1 && hi_pos == hi + 1)break;
		countCRS += hi_pos - lo_pos;
	}
	inplace_merge(sums.begin() + lo, sums.begin() + mid + 1, sums.begin() + hi + 1);
}
int countRangeSum(std::vector<int>& nums, int lower, int upper) {
	numsCRS = &nums;
	int n = nums.size();
	if (n == 0)return 0;
	vector<long long>sum;  
	sumCRS = &sum; countCRS = 0; sum.push_back(0);
	long long cum = 0; lowerCRS = lower; upperCRS = upper;
	for (auto&i : nums) {cum += i; sum.push_back(cum);}
	countRangeSumRe(0, n);
	return countCRS;
}

ListNode * buildList(vector<int>& v)
{
	ListNode*head;
	ListNode* now = new ListNode(v[0]);
	head = now;
	for (int i = 1; i < v.size(); i++) {
		now->next = new ListNode(v[i]);
		now = now->next;
	}
	return head;
}

ListNode * oddEvenList(ListNode * head)
{
	if (head==nullptr||head->next == nullptr)return head;
	auto odd = head;
	
	auto even = head->next; 
	auto evenHead = even;
	auto now = head->next->next;
	bool isEven = false;
	while (now != nullptr) {
		if (isEven) {
			even->next = now;
			even = even->next;
		}
		else {
			odd->next = now;
			odd = odd->next;
		}
		isEven = !isEven;
		now = now->next;
	}
	even->next = nullptr;
	odd->next = evenHead;
	return head;
}
struct pos_my {
	unsigned short x;
	unsigned short y;
};
union pos_u{
	pos_my pos;
	int i;
};
struct nodeDataIIP {
	int depth;
	char up;
	char down;
	char left;
	char right;
	nodeDataIIP(int _d = INT_MIN, char u = ' ', char d = ' ', char l = ' ', char r = ' ') :
		depth(_d), up(u), down(d), left(l), right(r){};
};
class lIPSolver {
private:
	std::vector<std::vector<int>>*ptr_m;
	std::vector<std::vector<int>>table;
	std::vector<std::vector<nodeDataIIP>>tableNode;
	int  m; int n; int ans;
public:
	lIPSolver(std::vector<std::vector<int>>&matrix) :ptr_m(&matrix) {
		m = 0; n = 0; ans = 0;
		m = ptr_m->size();
		if (m != 0)n = ptr_m->at(0).size();
	}
	int solver() {
		if (m == 0 || n == 0)return 0;
		unordered_set<int>q1; 	unordered_set<int>q2;
		unordered_set<int>*qnow; unordered_set<int>*qnext;
		qnow = &q1; qnext = &q2;
		int now = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int up = get(i - 1, j);
				int down = get(i + 1, j);
				int left = get(i, j - 1);
				int right = get(i, j + 1);
				int now = get(i, j);
				if (up <= now&&down <= now&&up <= now&&right <= now) {
					//table[i][j] = 1;
					pos_u p; p.pos.x = i; p.pos.y = j;
					q1.insert(p.i);
				}
			}
		}
		while (!qnow->empty()) {
			now++;
			for (auto& i : *qnow) {
				pos_u p;
				p.i = i;
				int now_x = p.pos.x;
				int now_y = p.pos.y;
				int val_now = get(now_x, now_y);
				tryAt(now_x + 1, now_y, val_now, *qnext);
				tryAt(now_x - 1, now_y, val_now, *qnext);
				tryAt(now_x, now_y + 1, val_now, *qnext);
				tryAt(now_x, now_y - 1, val_now, *qnext);
			}
			swap(qnow, qnext);
			qnext->clear();
		}
		return now;
	};
	int solverV2() {
		if (m == 0 || n == 0)return 0;
		table.resize(m);
		for (auto& v : table) {
			v.resize(n);
			for (auto& i : v)i = 0;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int up = get(i - 1, j);
				int down = get(i + 1, j);
				int left = get(i, j - 1);
				int right = get(i, j + 1);
				int now = get(i, j);
				if (up <= now&&down <= now&&up <= now&&right <= now) {
					table[i][j] = 1;
				}
			}
		}
		int now = 1;
		bool hasNext = true;
		while (hasNext) {
			hasNext = false;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					int val = get(i, j);
					bool b1 = tryAtV2(i + 1, j, val, now);
					bool b2 = tryAtV2(i - 1, j, val, now);
					bool b3 = tryAtV2(i, j + 1, val, now);
					bool b4 = tryAtV2(i, j - 1, val, now);
					if (b1 || b2 || b3 || b4) {
						table[i][j] = now + 1;
						hasNext = true;
					}
				}
			}
			if (hasNext)now++;
		}
		return now;
	};
	int solverV3() {
	//build graph
		if (m == 0 || n == 0)return 0;
		buildGraph();
		vector<pair<int, int>>peaks;
		findPeaks(peaks);
		int ans = INT_MIN;
		for (auto&p : peaks) {
			ans = max(ans, depth(p.first, p.second));
		}
		return ans;
	}
private:
	int get(int x, int y) {
		if (x < 0 ||x >= m)return INT_MIN;
		if (y < 0 || y>= n)return INT_MIN;
		return ptr_m->at(x)[y];
	}
	void tryAt(int x, int y, int v, unordered_set<int>&set) {
		int v_now = get(x, y);
		if (v_now == INT_MIN)return;
		if (v_now < v) {
			pos_u p; p.pos.x = x; p.pos.y = y;
			set.insert(p.i);
		}
	}
	bool tryAtV2(int x,int y,int val,int now) {
		int v_now = get(x, y);
		if (v_now == INT_MIN)return false;
		if (v_now <= val) return false;
		if (v_now>val){
			if (table[x][y] ==now)return true;
			else return false;
		}
	}
	void buildGraph() {
		tableNode.resize(m);
		for (auto& v : tableNode) {
			v.resize(n);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				auto& nodeData = tableNode[i][j];
				int center = get(i , j);
				buildEdge(nodeData.up, center, get(i - 1, j));
				buildEdge(nodeData.down, center, get(i+ 1, j));
				buildEdge(nodeData.left, center, get(i, j - 1));
				buildEdge(nodeData.right, center, get(i, j + 1));
			}
		}
	}
	void buildEdge(char&r, int val, int next) {
		if (next == INT_MIN||val==next) {
			r = '#';
		}
		else if (next > val) { r = 'u'; }
		else r = 'd';
	}
	void findPeaks(vector<pair<int,int>>&v) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int up = get(i - 1, j);
				int down = get(i + 1, j);
				int left = get(i, j - 1);
				int right = get(i, j + 1);
				int now = get(i, j);
				if (up <= now&&down <= now&&up <= now&&right <= now) {
					v.push_back({i,j});
				}
			}
		}
	}
	int depth(int x,int y){
		if (get(x, y) == INT_MIN)return 0;
		auto& n = tableNode[x][y];
		if (n.depth != INT_MIN)return n.depth;
		int up = (n.up == 'd') ? depth(x - 1, y) : 0;
		int down = (n.down == 'd') ? depth(x + 1, y) : 0;
		int left = (n.left == 'd') ? depth(x, y-1) : 0;
		int right = (n.right == 'd') ? depth(x, y +1) : 0;
		n.depth = max(max(up, down), max(left, right))+1;
		return 	n.depth;
	}
};
int longestIncreasingPath(std::vector<std::vector<int>>& matrix)
{
	lIPSolver sv(matrix);
	return sv.solverV3();
}
vector<bool>*tableIVS;
bool isValidSerialization_re(int id, int numOfnull) {
	auto&table = *tableIVS;
	if (id == -1)return numOfnull==1;
	if (table[id] == false) {
	  return isValidSerialization_re(id - 1, numOfnull + 1);
	}
	else {
		if (numOfnull >= 2) {
			return isValidSerialization_re(id - 1, numOfnull - 1);
		}return false;
	}
}
bool isValidSerialization(string preorder)
{    

	//to vector
	vector<bool>table; tableIVS = &table;
	if (preorder.back() != '#')return false;
	for (int i = 0; i < preorder.size(); i++) {
		if (preorder[i]== ',') {
			if (preorder[i - 1] == '#')table.push_back(false);
			else table.push_back(true);
		}
	}
	table.push_back(false);
	return isValidSerialization_re(table.size() - 1,0);
}

int minPatches(vector<int>& nums, int n)
{
	long long top = 1; int ans = 0; int id = 1;
	if (nums.size() == 0) {
		while(n != 0) {
			n = n >> 1;
			ans++;
		}
		return ans;
	}
	if (nums.front() != 1) { ans = 1; id = 0; }
	for (int i = id; i < nums.size(); i++) {
		if (nums[i] <= top + 1) {
			top += nums[i];
			if (top >= n)return ans;
		}
		else {
			while (top + 1 < nums[i]) {
				top = top * 2 + 1;
				ans++;
				if (top >= n)return ans;
			}
			top += nums[i];
			if (top >= n)return ans;
		}

	}
	while(top < n) {
		top = top * 2 + 1;
		ans++;
	}
	return ans;
}
unordered_map<string, map<string, int>>*p_tableFI;
vector<string>*ansFI; int targetLenFI;
bool findItinerary_re(string now) {
	auto&table = *p_tableFI; auto& ans = *ansFI;
	if (ans.size() == targetLenFI)return true;
	auto&map = table[now];
	if (map.size() == 0) {
		if (ans.size() == targetLenFI)return true;
		else return false;
	}
	for (auto itr : map) {
		if (itr.second == 0)continue;
		ans.push_back(itr.first);
		now = itr.first;
		map[itr.first]--;
		if (findItinerary_re(now))return true;
		ans.pop_back();
		map[itr.first]++;
	}
	return false;
}
std::vector<std::string> findItinerary(std::vector<pair<std::string, std::string>> tickets)
{
	unordered_map<string, map<string, int>>table;		p_tableFI = &table;
	vector<string>ans; ansFI = &ans; 
	targetLenFI = tickets.size() + 1;
	if (tickets.size() == 0)return ans;
	for (auto& t : tickets) {
		auto& map= table[t.first];
		if (map.find(t.second)== map.end()) {
			map[t.second] = 1;
		}
		else map[t.second]++;
	}

	string now = "JFK"; ans.push_back(now);
	findItinerary_re(now);
	return ans;
}

bool increasingTriplet(std::vector<int>& nums)
{
	int n = nums.size();
	if (n<3)return false;
	vector<int>minBefore;
	vector<int>maxAfter;
	int _min = INT_MAX; minBefore.push_back(_min);
	for (int i = 1; i < n; i++) {
		_min = min(_min, nums[i - 1]);
		minBefore.push_back(_min);
	}
	int _max= INT_MIN; maxAfter.push_back(_max);
	for (int i =n-2; i>=0; i--) {
		_max = max(_max, nums[i +1]);
		maxAfter.push_back(_max);
	}
	reverse(maxAfter.begin(), maxAfter.end());
	for (int i = 1; i < n - 1; i++) {
		if (minBefore[i] < nums[i] && nums[i] < maxAfter[i])return true;
	}
	return false;
}
bool inBetween(int a, int b, int x) {
	if (a > b)swap(a, b); 
	if (a <= x&&x <= b)return true;
	return false;
}
bool isSelfCrossing(std::vector<int>& x)
{ 
	int n = x.size();
	for (int i = 3; i < n; i++) {
		if (i >= 5) {
			int a = x[i - 5]; int b = x[i -4]; int c = x[i - 3];
			int d = x[i - 2]; int e = x[i - 1]; int f = x[i];
			if (d >= b&&a<=c) {
				if (e >= c - a&&e <= c&&f >= d - b)return true;
			}
		}
		if (i >=4) {
			int a = x[i - 4]; int b = x[i - 3]; int c = x[i - 2];
			int d = x[i - 1]; int e = x[i];
			if (b == d && (a + e) >= c)return true;
		}
		int a = x[i - 3];	int b = x[i - 2]; int c = x[i - 1]; int d = x[i];
		if (d >= b&&a>=c)return true;
	}
	return false;
}
void robIII_re(TreeNode * root, int& valT, int& valF) {
	if (root!= nullptr&&root->left == nullptr&&root->right == nullptr) {
		valT = root->val; valF = 0; return;
	}
	int TR = 0; int FR = 0; int TL = 0; int FL = 0;
	if (root->left != nullptr)robIII_re(root->left, TL, FL);
	if (root->right != nullptr)robIII_re(root->right, TR, FR);
	valT = FL + FR+ root->val;
	valF =max(TL, FL)+ max(TR, FR);
	return;
}
int robIII(TreeNode * root)
{
	if (root == nullptr)return 0;
	if (root->left == nullptr&&root->right == nullptr)return root->val;
	int valT = 0; int valF = 0;
	robIII_re(root, valT, valF);
	return max(valT,valF);
}
bool isPalindrome(const string& str, int lo, int hi) {
	while (true) {
		if (lo >= hi)return true;
		if (str[lo] != str[hi])return false;
		lo++; hi--;
	}
	return true;
}
//Tries method
#define US_MAX 65500
class TrieNodePP;
vector<TrieNodePP>*tablePP;
class TrieNodePP {
	
public:
	unsigned short next[26];
	unsigned short  idFull;
	unsigned short  idFull_f;
	vector<unsigned short> strID;
	TrieNodePP() {
		idFull = US_MAX; idFull_f = US_MAX;
		for (auto &i : next)i = US_MAX;
	}

};
TrieNodePP*  getNext(int& nowID,char c) {
		auto &table = *tablePP;
		if (nowID == US_MAX)return nullptr;
		if (table[nowID].next[c - 'a'] == US_MAX) {
			tablePP->push_back(TrieNodePP());
			table[nowID].next[c - 'a'] = tablePP->size() - 1;
		}

		auto ans=  &table[table[nowID].next[c - 'a']];
		nowID = table[nowID].next[c - 'a'];
		return ans;
}
void addToTrie_FF(string& str, TrieNodePP*root, int id) {
	auto &table = *tablePP;
	if (str == "") { root->idFull_f = id; return; }
	int len = str.size();
	auto now = root; int nowID = 0;
	for (int i =0; i <len -1; i++) {
		now = getNext(nowID, str[i]);
	}
	now = getNext(nowID, str[len - 1]);
	now->idFull_f = id;
	return;
};
void addToTrie(string& str,  TrieNodePP*root,int id) {
	auto &table = *tablePP;
	if (str == "") { root->idFull = id; return; }
	int len = str.size();
	if (root->idFull_f!= US_MAX) {
		if(isPalindrome(str, 0, len - 1))root->strID.push_back(id);
		
	}
	auto now = root; int nowID = 0;
	for (int i = len - 1; i > 0; i--) {
		 now = getNext(nowID,str[i]);
		 if (now->idFull_f != US_MAX) {
			 if(isPalindrome(str, 0, i - 1))now->strID.push_back(id);
		 }
	}
	now = getNext(nowID, str[0]);
	now->idFull = id;
	return;
};
void findPair(int now_id, const string& str, vector<vector<int>>&ans, TrieNodePP*root, int size) {
	auto &tableN = *tablePP;
	vector<bool>table; table.resize(size);
	for (int i = 0; i < size; i++)table[i] = false;
	table[now_id] = true;
	if (str == "") {
		for (int i : root->strID) {
			if (!table[i]) {
				ans.push_back(vector<int>({ now_id,i }));
				table[i] = true;
			}
		}
		return;
	}
	int len = str.size();
	if (root->idFull != US_MAX && !table[root->idFull]) {
		if (isPalindrome(str, 0, len - 1)) {
			ans.push_back(vector<int>({ now_id,root->idFull }));
			table[root->idFull] = true;
		}

	}
	auto now = root; int nowID = 0;
	for (int i =0; i <len-1; i++) {
		now = getNext(nowID, str[i]);
		if (now->idFull != US_MAX && !table[now->idFull]) {
				if (isPalindrome(str, i + 1, len - 1)) {
					ans.push_back(vector<int>({ now_id,now->idFull }));
					table[now->idFull] = true;
				}
		}
	}
	now = getNext(nowID, str[len-1]);
	if (now->idFull != US_MAX && !table[now->idFull]) {
		ans.push_back(vector<int>({ now_id,now->idFull }));
		table[now->idFull] = true;
	}
	for (int i : now->strID) {
		if (!table[i]) {
			ans.push_back(vector<int>({ now_id,i }));
			table[i] = true;
		}
	}
	return;
};
vector<vector<int>> palindromePairs(vector<string>& words)
{
	vector<vector<int>>ans; vector<TrieNodePP>table; tablePP = &table;
	TrieNodePP root; int size = words.size(); 
	table.push_back(root);
	for (int id = 0; id < words.size(); id++)addToTrie_FF(words[id], &table[0], id);
 for (int id = 0; id < words.size(); id++)addToTrie(words[id], &table[0], id);
 for (int id = 0; id < words.size(); id++)findPair(id,words[id],ans, &table[0], size);
	return ans;
}

std::vector<int> countBits(int num)
{
	vector<int>ans;
	ans.push_back(0);
	if (num == 0)return ans;

	int step = 1;
	for (int i = 1; i <= num; i++) {
		if (i == step) {
			ans.push_back(1);
			step = step << 1;
		}
		else {
			ans.push_back(1+ans[i-step/2]);
		}

	}
	return ans;
}

bool isPowerOfFour(int num)
{
	if (num <= 0)return false;
	int msk = (1 | 1 << 2 | 1 << 4 | 1 << 6 | 1 << 8 |
		1 << 10 | 1 << 12 | 1 << 14 | 1 << 16 |1<<18|
		1 << 20 | 1 << 22 | 1 << 24 | 1 << 26 | 1 << 28 |
		1 << 30
		);
	int n = num&msk;
	return (n==num)&&((num&(num - 1))==0);
}
int integerBreakN(int n, int p) {
	int n1 = n / p; int n2 = n1 + 1;
	int m1 = pow(n1, p - 1)*(n - n1*(p - 1));
	int m2 = INT_MIN;
	if (n2 < n) {
		m2= pow(n2, p - 1)*(n - n2*(p - 1));
	}
	return max(m1,m2);
}
int integerBreak(int n)
{
	int _max = 1;
	for (int i = 2; i < n; i++) {
		_max = max(_max, integerBreakN(n, i));
	}
	return _max;
}

string reverseString(string s)
{
	string ans;
	for (int i = s.size() - 1; i >= 0; i--)ans.push_back(s[i]);
	return ans;
}

string reverseVowels(string s)
{
	vector<int>v;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'||
			s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
			v.push_back(i);
		}
	}
	string ans = s;
	int lo = 0; int hi = v.size() - 1;
	while (lo < hi) {
		swap(ans[v[lo]], ans[v[hi]]);
		lo++; hi--;
	}
	return ans;
}

std::vector<int> topKFrequent(std::vector<int>& nums, int k)
{
	unordered_map<int, int>map;
	for (auto i : nums) {
		if (map.find(i) == map.end())map[i] = 1;
		else map[i]++;
	}
	vector<vector<int>>bucket; bucket.resize(nums.size() + 1);
	for (auto itr : map) {
		bucket[itr.second].push_back(itr.first);
	}
	int _k = k; vector<int>ans;
	for (int i = nums.size(); i >= 0; i--) {
		if (bucket[i].size() != 0) {
			for (auto i : bucket[i]) {
				ans.push_back(i);
				_k--;
				if (_k == 0)goto OUT;
			}
		}
	}
	OUT:
	return ans;
}

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
	vector<int>ans;
	if (nums1.size() == 0 || nums2.size() == 0)return ans;
	unordered_set<int>set;
	for (auto i : nums1)set.insert(i);
	for (auto i : nums2) {
		if (set.find(i) != set.end()) {
			ans.push_back(i);
			set.erase(i);
		}
	}
	return ans;
}

std::vector<int> intersectionII(std::vector<int>& nums1, std::vector<int>& nums2)
{
	vector<int>ans;
	if (nums1.size() == 0 || nums2.size() == 0)return ans;
	unordered_map<int,char>map;
	for (auto i : nums1) {
		if (map.find(i) == map.end()) {
			map[i] = 1;
		}
		else map[i]++;
	}
	for (auto i : nums2) {
		auto itr = map.find(i);
		if (itr != map.end()) {
			if (itr->second != 0) {
				ans.push_back(i);
				map[i]--;
		   }
		}
	}
	return ans;
}
class Envelope {
public:
	unsigned char num;
	unsigned short x; unsigned short y;
	Envelope(int _x = 0, int _y = 0) :x(_x), y(_y), num(1) {};
	bool canInto(const Envelope&b) {
		if (x > b.x&&y>b.y) { return true; };
		return false;
	}
};
bool operator<(const Envelope&a, const Envelope&b) {
	if (a.num < b.num) { return true; };
	if (a.num > b.num) { return false; };
	if (a.x> b.x) { return true; };
	if (a.y> b.y) { return true; };
	if (a.x< b.x) { return false; };
	if (a.y< b.y) { return false; };
	return false;
}
int maxEnvelopes(vector<pair<int, int>>& envelopes)
{
	if (envelopes.size() <= 1)return envelopes.size();
	sort(envelopes.begin(), envelopes.end());
	set<Envelope>set;
	for (auto&p : envelopes) {
		Envelope now(p.first, p.second);
		if (set.size() == 0)set.insert(now);
		else {
			auto itr = set.end(); itr--;
			while (itr != set.begin()) {
				if (now.canInto(*itr)) {
					break;
				}
				itr--;
			}
			if (now.canInto(*itr)) {
				now.num = itr->num + 1;
			}
			set.insert(now);
		}
	}
	auto itr = set.end(); itr--;
	return itr->num;
};
vector<vector<int>>*bME;
vector<pair<int, int>>* evsME;
bool searchAtEnv(int eID, int n) {
	auto& nowEnvs = bME->at(n);
	auto& nowEn = evsME->at(eID);
	bool isFind = false;
	for (auto id : nowEnvs) {
		auto&p = evsME->at(id);
		if (p.first < nowEn.first&&p.second < nowEn.second) {
			return true;
		}
		if (p.first*p.second >= nowEn.first*nowEn.second)break;
	}
	return false;
}

int searchEnvBin(int eID, int lo, int hi,bool isLoSearched,bool isHiSearched) {
	if (lo > hi)return 0;
	if (eID == 0) {
		return 1;
}
	if (lo == hi) {
		if (hi == 1)return 1;
		if (isLoSearched) {
			return lo;
		}
		else {
			if (searchAtEnv(eID, hi-1))return hi;
			return 0;
		}
	}
	if (hi - lo == 1) {
		if (isHiSearched)return hi;
		if (searchAtEnv(eID, hi-1))return hi;
		if (lo == 1|| isLoSearched)return lo;
		if (searchAtEnv(eID, lo-1))return lo;
		return 0;
	}
	if (searchAtEnv(eID, hi - 1))return hi;
	hi--;
	if (hi - lo == 1) {
		if (isHiSearched)return hi;
		if (searchAtEnv(eID, hi - 1))return hi;
		if (lo == 1 || isLoSearched)return lo;
		if (searchAtEnv(eID, lo - 1))return lo;
		return 0;
	}
	int mid = (lo+hi)/2;
	if (searchAtEnv(eID, mid)) return searchEnvBin(eID, mid + 1, hi, true, isHiSearched);
	else {
		int ansh = searchEnvBin(eID, mid + 2, hi, false, isHiSearched);
		if (ansh != 0)return ansh;
		return searchEnvBin(eID, lo, mid, isLoSearched, false);
	}
};
int searchLinear(int eID, int hi,int reMain) {
	int max = hi - 1;
	for (int i = hi - 1; i >= 1; i--) {
		if (i + 1 + reMain <= max)return 0;
		if (searchAtEnv(eID, i))return i + 1;
	}
	return 1;
}
bool areaCompare(const pair<int, int>&a, pair<int, int>&b) {
	return a.first*a.second < b.first*b.second;
}
int maxEnvelopes_V2(vector<pair<int, int>>& envelopes)
{
	if (envelopes.size() <= 1)return envelopes.size();
	int maxEvs = 0;
	sort(envelopes.begin(), envelopes.end(), areaCompare);
	vector<vector<int>>bucket; bME = &bucket; bucket.resize(envelopes.size() + 1);
	evsME = &envelopes;
	for (int i = 0; i < envelopes.size(); i++) {
		//lo+1+ envelopes.size()-i-1>= maxEvs + 1
		int ans= searchEnvBin(i,max(1, maxEvs + 1 + i - (int)envelopes.size()),maxEvs+1, false,false);
		bucket[ans].push_back(i);
		maxEvs = max(maxEvs, ans);
	}
	return maxEvs;
}

int factorial10(int n) {
	int table[11] = { 1,1,2,6,24,120,720,5040,40320,362880,3628800 };
	return table[n];
}
int combination10(int m, int n) {
	int ans = 1;
	for (int i = m - n + 1; i <= m; i++)ans *= i;
	return ans / factorial10(n);
}
int countNumbersWithUniqueDigitsN(int n)
{
	int digit = n;
	if (n >= 10)digit = 10;
	int ans = 0;
	//no 0
	if (digit != 10)ans += combination10(9, digit)*factorial10(digit);
	// have 0
	if (digit != 1)ans += combination10(9, digit - 1)*(digit - 1)*factorial10(digit - 1);
	return ans;
}
int countNumbersWithUniqueDigits(int n) {
	int ans = 0;
	for (int i = 1; i <= min(10, n); i++) {
		ans += countNumbersWithUniqueDigitsN(i);
	}
	return ans + 1;
}
unordered_set<unsigned long long>*setCMW;
unsigned int xCMW; unsigned int yCMW; unsigned int zCMW;
bool canMeasureWaterRe(unsigned int x, unsigned int y) {
	auto&set = *setCMW;
	if (x + y == zCMW)return true;
	unsigned long long code = x; code = code << 32; code += y;
	if (set.find(code) != set.end())return false;
	set.insert(code);
	if (x + y > zCMW) {
		if (canMeasureWaterRe(0, y))return true;
		if (canMeasureWaterRe(x, 0))return true;
		if (canMeasureWaterRe(xCMW, y))return true;
		if (canMeasureWaterRe(x, yCMW))return true;
	}
	else {
		if (canMeasureWaterRe(xCMW, y))return true;
		if (canMeasureWaterRe(x, yCMW))return true;
		if (canMeasureWaterRe(0, y))return true;
		if (canMeasureWaterRe(x, 0))return true;
	}
	//y into x
	int xNow = min(y + x, xCMW);
	if (canMeasureWaterRe(xNow, x + y - xNow))return true;
	//x into y;
	int yNow = min(y + x, yCMW);
	if (canMeasureWaterRe(y + x - yNow, yNow))return true;
	return false;
}
bool canMeasureWater(int x, int y, int z)
{
	if (z == 0)return true;
	if (x == 0 || y == 0) {
		if (y != 0 && z == y)return true;
		if (x != 0 && z == x)return true;
		return false;
	}
	if (z<0 || z>x + y)return false;
	int _max = max(x, y); int _min = min(x, y);
	int mod = _max%_min;
	if (mod == 0)return z%_min == 0;
	if (_min%mod == 0)return z%mod == 0;
	return true;
}
void produceRowSumTable(vector<vector<int>>& matrix) {
	int m = matrix.size(); int n = matrix[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			matrix[i][j] = matrix[i][j] + matrix[i][j - 1];
		}
	}
};
void producePartailRowSum(vector<int>& v, int lo, int hi, vector<vector<int>>& matrix) {
	int m = matrix.size();
	for (int i = 0; i < m; i++) {
		if (lo == 0) {
			v[i]=matrix[i][hi];
		}
		else {
			v[i]=matrix[i][hi] - matrix[i][lo - 1];
		}
	}

};
int findRowInterval(vector<int>& v, int k) {
	map<int, int>map;
	for (int j = 1; j < v.size(); j++) { v[j] = v[j] + v[j - 1]; }
	for (auto i : v) {
		if (map.find(i) != map.end())map[i]++;
		else map[i] = 1;
	}
	auto itr1 = map.upper_bound(k); 
	int ans = INT_MIN;
	if (itr1 != map.begin()){
	   itr1--;
	   ans = itr1->first;
}
	for (auto i : v) {
		if (map[i] == 1) {
			map.erase(i);
		}else map[i]--;
		int upper = k + i;
		auto itr = map.upper_bound(upper);
		if (itr != map.begin()) {
			itr--;
			ans = max(ans,itr->first-i);
			if (ans == k)return k;
		}
	}
	return ans;
};
int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
{
	//
	int m = matrix.size(); if (m == 0)return 0;
	int n = matrix[0].size(); if (n == 0)return 0;
	produceRowSumTable(matrix); int ans =INT_MIN;
	vector<int>partialSum; partialSum.resize(m);
	for (int i = 0; i <n; i++) {
		for (int j=i; j < n; j++) {
			
			producePartailRowSum(partialSum,i,j, matrix);
			ans = max(findRowInterval(partialSum,k), ans);
			if (ans == k)return k;
		}
	}
	return ans;
}
bool isPerfectSquare_re( int lo,int hi,int num)
{
	if (lo == hi) {
		if (lo*lo==num)return true;
		return false;
	}
	if (hi - lo == 1) {
		if (lo*lo == num)return true;
		if (hi*hi == num)return true;
		return false;
	}
	long long mid = (hi + lo) / 2;
	long long sq =mid*mid;
	if (sq > num)return isPerfectSquare_re(lo, mid, num);
	return isPerfectSquare_re(mid, hi, num);;
}
bool isPerfectSquare(int num)
{
	return isPerfectSquare_re(0, 2 << 16, num);
}
#define U_MAX 65500
vector<int> largestDivisibleSubset(vector<int>& nums)
{
	vector<int>ans; int n = nums.size();
	if (nums.size() == 0)return ans;
	sort(nums.begin(), nums.end());
	vector<unsigned short>next; next.resize(n);
	for (auto&i : next)i = U_MAX;
	vector<vector<int>>bucket; bucket.resize(2);
	bucket[1].push_back(nums.size()-1);
	for (int id= n - 2; id >= 0; id--) {
		int now = nums[id]; 
		int nowlen = 0; 
		int nextID = U_MAX;
		for (int len = bucket.size()-1; len >= 1; len--) {
			auto& v = bucket[len];
			for (auto& x : v) {
				int in = nums[x];
				if (in%now == 0) {
					nowlen = len + 1;
					nextID = x;
					break;
				}
			}
			if (nowlen != 0)break;
		}
		if (nowlen == 0)nowlen++;
		if (nowlen > bucket.size() - 1) {
			bucket.push_back(vector<int>());
			bucket.back().push_back(id);
			next[id] = nextID;
		}
		else {
			bucket[nowlen].push_back(id);
			next[id] = nextID;
		}
	}
	int nowID = bucket.back().front();
	while (nowID != U_MAX) {
		ans.push_back(nums[nowID]);
		nowID = next[nowID];
	}
	return ans;
}
#define U_MAX 65500
vector<int>* p1KSP; vector<int>* p2KSP;
class dataKSP {
public:
	unsigned short i; unsigned short j;
	int sum;
	dataKSP(int _i = U_MAX, int _j = U_MAX) :i(_i), j(_j) {
		const auto& nums1 = *p1KSP;	const auto& nums2 = *p2KSP;
		sum = nums1[i] + nums2[j];
	};
	void addPair(std::vector<std::pair<int, int>>&ans)const {
		const auto& nums1 = *p1KSP;	const auto& nums2 = *p2KSP;
		ans.push_back({ nums1[i] , nums2[j] });
	}
};
bool operator<(const dataKSP&a,const  dataKSP&b) {
	if (a.sum< b.sum)return true;
	if (a.sum> b.sum)return false;
	if (a.i< b.i)return true;
	if (a.i> b.i)return false;
	if (a.j< b.j)return true;
	if (a.j> b.j)return false;
	return false;
}
std::vector<std::pair<int, int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k)
{
	p1KSP = &nums1; p2KSP = &nums2;
	std::vector<std::pair<int, int>>ans;
	if (nums1.size() == 0 || nums2.size() == 0)return ans;
	set<dataKSP>set;
	for (int i = 0; i < nums1.size(); i++) {
		set.insert(dataKSP(i, 0));
	
	}
	for (int i = 0; i < k; i++) {
		if (set.empty())break;
		auto itr = set.begin();
		itr->addPair(ans);
		if(itr->j<nums2.size()-1)set.insert(dataKSP(itr->i,itr->j+1));
		set.erase(itr);
	}
	return ans;
}

int wiggleMaxLength(std::vector<int>& nums1)
{
		 if (nums1.size() < 2) return nums1.size();
		 vector<int>nums; nums.push_back(nums1[0]);
		 for (int i = 1; i < nums1.size(); i++) {
			 if (nums1[i - 1] != nums1[i])nums.push_back(nums1[i]);
		 }
		 if (nums.size() <= 2) return nums.size();
		 int remove = 0;
		 for (int i = 1; i < nums.size() - 1; i++) {
			 if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) remove++;
			 if (nums[i - 1] > nums[i] && nums[i] > nums[i + 1]) remove++;
		 }
		int ans = nums.size() - remove;
		return ans;
}

int combinationSum4(std::vector<int>& nums, int target)
{
	vector<int>table; table.resize(target + 1);
	for (auto&i : table)i = 0;
	for (auto&i : nums) {
		if (i <= target)table[i] = 1;
	}
	for (int t_now = 1; t_now <= target; t_now++) {
		for (auto&n_now : nums) {
			int diff = t_now - n_now;
			if (diff > 0)table[t_now] += table[diff];
		}
	}
	return table.back();
}
class dataKSM {
public:
	int val; int i; int j;
	dataKSM(int v = INT_MAX, int _i = -1, int _j = -1) :val(v), i(_i), j(_j) {};
};
bool operator<(const dataKSM&a, const dataKSM&b) {
	return a.val > b.val;

}
int kthSmallest(std::vector<std::vector<int>>& matrix, int k)
{
	int m = matrix.size();	
	if (k == 1)return matrix[0][0];
	if(m==1)return matrix[0][k - 1];
	int n = matrix[0].size(); 
	if (n ==1 )return matrix[k - 1][0];
	priority_queue<dataKSM>pq;
	for (int i = 0; i < m; i++)pq.push(dataKSM(matrix[i][0], i, 0));
	for (int i = 1; i <= k - 1; i++) {
		auto top = pq.top(); pq.pop();
		if (top.j != n - 1) {
			pq.push(dataKSM(matrix[top.i][top.j + 1], top.i, top.j + 1));
		}
	}
	return pq.top().val;
}
void lexicalOrder_re(int now, int max, vector<int>&ans) {
	if (now > max)return;
	ans.push_back(now);
	lexicalOrder_re(now * 10, max, ans);
		if (now % 10 != 9)	lexicalOrder_re(now+1, max, ans);
}
std::vector<int> lexicalOrder(int n)
{
	vector<int>ans;
	lexicalOrder_re(1, n, ans);
	return ans;
}

bool canConstruct(std::string ransomNote, std::string magazine)
{
	int table[255];
	for (int&i : table)i = 0;
	for (char c : magazine) {
		table[c]++;
	}
	for (char c : ransomNote) {
		if (table[c]==0)return false;
		else table[c] --;
	}
	return true;
}

int firstUniqChar(std::string s)
{
	int first[26];
	int null = s.size() + 5;
	for (int&i : first)i = null;
	for (int i = 0; i < s.size();i++) {
		char c = s[i];
		if (first[c - 'a'] != null) {
			if(first[c - 'a']!=null+1)first[c - 'a'] = null + 1;
		}
		else first[c - 'a'] = i;
	}
	int ans = *min_element(first, first + 26);
	return (ans<null)?ans:-1;
}

int lengthLongestPath(std::string input)
{
	int ans = 0;
	if (input.find('\n') == input.npos) {
		if (input.find('.') != input.npos) {
			return input.size();
		}
		return 0;
	}
	input.push_back('\n');  int pre_d = 0; int id = 0;
	string now; vector<int>path; int acc_len = 0;
	while (true) {
		if (input[id] == '\n') {
			//compute pathLen
			if (pre_d == 0) {
				acc_len += now.size();
				path.push_back(now.size());
			}
			else {
				acc_len += (now.size() + 1);
				path.push_back(now.size() + 1);
			}
			if (now.find('.') != input.npos) {
				ans = max(ans, acc_len);
			}

			if (id + 1 == input.size())break;
			//next word
			id++; int nowD = 0;
			while (input[id] == '\t') { id++; nowD++; }

			if (pre_d + 1 != nowD) {
				while (true) {
					if (pre_d == nowD) {
						acc_len -= path.back();
						path.pop_back();
						break;
					}
					else {
						acc_len -= path.back();
						path.pop_back();
						pre_d--;
					}
				}
			}
			pre_d = nowD;
			now.clear();
		}
		else {
			now.push_back(input[id]); id++;
		}
	}
	return ans;
}

char findTheDifference(string s, string t)
{
	int t1[26];	int t2[26];
	for (int i = 0; i < 26; i++) {
		t1[i] = 0;	t2[i] = 0;
	}
	for (char c : s)t1[c - 'a']++;
	for (char c : t)t2[c - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (t1[i] != t2[i]) {
			return i + 'a';
		}
	}
	return 0;
}
int lastRemaining(int n)
{
	if (n == 1)return 1;
	if (n == 2)return 2;
	if (n % 2)return lastRemaining(n - 1);
	int half = n / 2;
	int x = lastRemaining(half);
	return 2 * (half + 1) - 2 * x;
}

bool isSubsequence(std::string s, std::string t)
{
	vector<int>table[26];
	//preprocess t
	for (int i = 0; i < t.size(); i++)table[t[i] - 'a'].push_back(i);

	//determine s
	if (s.size() == 0)return true;
	if (table[s[0] - 'a'].size() == 0)return false;
	int now = table[s[0] - 'a'].front();
	for (int i = 1; i < s.size(); i++) {
		auto& v = table[s[i] - 'a'];
		auto itr = upper_bound(v.begin(), v.end(), now);
		if (itr == v.end())return false;
		now = *itr;
	}
	return true;
}
bool validUtf8test(std::vector<int>& data, int begin, int len) {
	int min = 1 << 7; int max = (1 << 7) + (1 << 6);
	//bitset<8>mn = min; bitset<8>mx = max;
	for (int i = begin; i < begin + len; i++) {
		unsigned char now = data[i];
		bitset<8>n = now;
		if (!(now >= min&&now < max))return false;

	}
	return true;
};
bool validUtf8(std::vector<int>& data)
{
	int nowHead = 0;
	while (true) {
		if (nowHead == data.size())return true;
		unsigned char head = data[nowHead];
		bitset<8>nw = head;
		int n = 0;
		if (head < 1 << 7) {
			nowHead++; continue;
		}
		else {
			if (head < (1 << 7) + (1 << 6))return false;
			while (head >= 1 << 7) {
				n++; head = head << 1; nw = head;
			}
			if (n > 4)return false;
			if (nowHead + n - 1 >= data.size())return false;
			if (!validUtf8test(data, nowHead + 1, n - 1))return false;
			nowHead = nowHead + n;
		}
	}
	return false;
}
bool isNumDS(char c) { return c >= '0'&&c <= '9'; }
string repeatDS(string& str, int n) {
	string ans = "";
	for (int i = 1; i <= n; i++) {
		ans = ans + str;
	}
	return ans;
}
string decodeString_re(string& s, int& lo)
{
	string ans = "";  string sN = ""; 
	while (lo<s.size()) {
		if (s[lo] == '[') {
			int n = atoi(sN.data()); lo++;
			string in = decodeString_re(s, lo);
			ans = ans + repeatDS(in, n);
			sN = "";
		}
		else if (s[lo] == ']') {
			lo++;
			return ans;
		}else{
	if (!isNumDS(s[lo])) { ans.push_back(s[lo]); }
	else { sN.push_back(s[lo]); }
	lo++;
}
	}
	return ans;
}

std::string decodeString(std::string s)
{
	int lo = 0;
	return decodeString_re(s,lo);
}
//391. Perfect Rectangle
enum class pointTypeLocal :char {
	ButtomLeft = 0,
	ButtomRight = 1,
	TopLeft = 2,
	TopRight = 3
};
enum class pointTypeGobal :char {
	Corner_ButtomLeft = 0,
	Corner_ButtomRight = 1,
	Corner_TopLeft = 2,
	Corner_TopRight = 3,
	Boundary_Buttom = 4,
	Boundary_Top = 5,
	Boundary_Left = 6,
	Boundary_Right = 7,
	Inside = 8,
	Outside = 9
};
char pointTypeTarget[10] = {
	0b00000001,//Corner_ButtomLeft
	0b00000010,//Corner_ButtomRight
	0b00000100, //Corner_TopLeft
	0b00001000,//Corner_TopRight
	0b00000011,//Boundary_Buttom
	0b00001100,//Boundary_Top       
	0b00000101,//Boundary_Left
	0b00001010,//Boundary_Right       
	0b00001111,//Inside                     
	0b00000000//Outside
};
enum class checkTypeResult :char {
	Finished, Unfinished, Error
};
hash<unsigned int> hull;
unsigned int pointToUI(const pair< short, short>& p) {
	return (((unsigned int)p.first) << 16) + p.second;
}
class Pointhasher {
public:
	size_t operator()(const pair< short, short>& p)const {
		unsigned int ull = pointToUI(p);

		return hull(ull);
	}
};
class dataPS {
private:
	pointTypeGobal type;
public:
	bitset<4> count;
	dataPS(pointTypeGobal _type = pointTypeGobal::Outside) {
		type = _type;
		for (int i = 0; i < 4; i++)count[i] = false;
	}
	checkTypeResult checkType()const {

		return check(type, count);
	}
	bool checkFinished() {
		if (type == pointTypeGobal::Inside) {
			char now = count.to_ulong();
			bool flag = (now == pointTypeTarget[4]) ||
				(now == pointTypeTarget[5]) ||
				(now == pointTypeTarget[6]) ||
				(now == pointTypeTarget[7]) ||
				(now == pointTypeTarget[8]);
			return flag;

		}
		else { return check(type, count) == checkTypeResult::Finished; }
		return false;
	}
private:
	checkTypeResult check(pointTypeGobal t, bitset<4> count)const {
		char target = pointTypeTarget[(char)t];
		char now = count.to_ulong();
		if (target == now)return checkTypeResult::Finished;
		char diff = (target^now);
		if ((target&diff) != diff)return checkTypeResult::Error;
		if (target>now)return checkTypeResult::Unfinished;
		return checkTypeResult::Error;
	}

};
class RectangleCoverChecker {
private:
	std::vector<std::vector<int>>& rects;
	pair< short, short>buttomLeft; pair< short, short>buttomRight;
	pair< short, short>topLeft; pair< short, short>topRight;
	unordered_map<unsigned int, dataPS>table;
public:
	RectangleCoverChecker(std::vector<std::vector<int>>&r) :rects(r) {};
	bool isRectangleCover() {
		if (!findCorner())return false;
		if (!checkArea())return false;
		if (!buildPointSet())return false;
		if (!checkAllPoint())return false;
		return true;
	}
private:
	bool  findCorner() {
		int x_min = rects[0][0]; int x_min_id = 0;
		int x_max = rects[0][2]; int x_max_id = 0;
		for (int i = 1; i < rects.size(); i++) {
			if (rects[i][0] < x_min) {
				if (rects[i][1] <= rects[x_min_id][1]) {
					x_min = rects[i][0];
					x_min_id = i;
				}
			}
			else if (rects[i][0] == x_min) {
				if (rects[i][1] < rects[x_min_id][1]) {
					x_min = rects[i][0];
					x_min_id = i;
				}
				else if (rects[i][1] == rects[x_min_id][1])return false;
			}
			if (rects[i][2] > x_max) {
				if (rects[i][3] >= rects[x_max_id][3]) {
					x_max = rects[i][2];
					x_max_id = i;
				}
			}
			else if (rects[i][2] == x_max) {
				if (rects[i][3] > rects[x_max_id][3]) {
					x_max = rects[i][2];
					x_max_id = i;
				}
				else if (rects[i][3] == rects[x_max_id][3])return false;
			}
		}
		int y_min = rects[x_min_id][1];
		int y_max = rects[x_max_id][3];
		for (int i = 0; i < rects.size(); i++) {
			if (rects[i][1] < y_min)return false;
			if (rects[i][3] > y_max) return false;
		}
		buttomLeft = { x_min,y_min }; buttomRight = { x_max,y_min };
		topLeft = { x_min,y_max }; topRight = { x_max,y_max };

		return true;
	}

	bool buildPointSet() {
		for (auto& r : rects) {
			pair< short, short>buttomLeft = { r[0],r[1] }; //type =0
			pair< short, short>buttomRight = { r[2],r[1] }; //type =1
			pair< short, short>topLeft = { r[0],r[3] }; //type =2
			pair< short, short>topRight = { r[2],r[3] };//type =3
			if (!addPointToSet(buttomLeft, pointTypeLocal::ButtomLeft))return false;
			if (!addPointToSet(buttomRight, pointTypeLocal::ButtomRight))return false;
			if (!addPointToSet(topLeft, pointTypeLocal::TopLeft))return false;
			if (!addPointToSet(topRight, pointTypeLocal::TopRight))return false;
		}

		return true;
	}
	bool checkAllPoint() const {
		for (auto itr : table) {
			if (!itr.second.checkFinished())return false;
		}
		return true;
	}

	bool checkArea()const {
		vector<int>bound({ topLeft.first,topLeft.second,buttomRight.first,buttomRight.second });
		unsigned	long long areaC = area(bound);
		unsigned long long areaA = 0;
		for (auto&r : rects)areaA += area(r);
		return areaC == areaA;
	}
	unsigned long long area(vector<int>& r) const { return abs(((long long)(r[2] - r[0]))*((long long)(r[3] - r[1]))); }
	bool addPointToSet(pair< short, short>&pt, pointTypeLocal type) {
		char tL = (char)type;
		pointTypeGobal typeG = getType(pt);
		auto p = pointToUI(pt);
		if (typeG == pointTypeGobal::Outside)return false;
		auto itr = table.find(p);
		if (itr == table.end()) {
		    dataPS now(typeG); now.count[tL] = true;
			table.insert({ p,now });
			return true;
		}
		else {
			if (itr->second.checkType() == checkTypeResult::Finished || itr->second.count[tL])return false;
			itr->second.count[tL] = true;
			if (itr->second.checkType() == checkTypeResult::Error)return false;
			return true;
		}
	}
	pointTypeGobal getType(pair< short, short>&p)const {
		if (p == buttomLeft)return pointTypeGobal::Corner_ButtomLeft;
		if (p == buttomRight)return pointTypeGobal::Corner_ButtomRight;
		if (p == topLeft)return pointTypeGobal::Corner_TopLeft;
		if (p == topRight)return pointTypeGobal::Corner_TopRight;
		if (p.first > buttomLeft.first&&p.first<topRight.first&&p.second>buttomLeft.second&&p.second < topRight.second)return  pointTypeGobal::Inside;
		if (p.first<buttomLeft.first || p.first>topRight.first || p.second < buttomLeft.second || p.second > topRight.second)return  pointTypeGobal::Outside;
		if (p.first == buttomLeft.first)return pointTypeGobal::Boundary_Left;
		if (p.first == topRight.first)return pointTypeGobal::Boundary_Right;
		if (p.second == buttomLeft.second)return pointTypeGobal::Boundary_Buttom;
		if (p.second == topRight.second)return pointTypeGobal::Boundary_Top;
		return  pointTypeGobal::Outside;
	}

};
bool isRectangleCover(std::vector<std::vector<int>>& rectangles)
{
	RectangleCoverChecker rcc(rectangles);
	
	return rcc.isRectangleCover();
}
class longestSubstringSolver {
private:
	string& s;
	int k;
	vector<bool>isIncluded;
	queue<pair<unsigned short, unsigned short>>intervals;
	int answer;
public:
	longestSubstringSolver( string& _s, int _k) :s(_s), k(_k) {
		answer = 0;
		isIncluded.resize(s.size());
		for (int i = 0; i < isIncluded.size();i++)isIncluded[i] = true;
	};
	int solve() {
		if (s.size() == 0)return 0;
		if (s.size() <k)return 0;
		if (k == 1)return s.size();
		intervals.push({ 0,s.size()-1 });
		while (!intervals.empty()) {
			auto now = intervals.front(); intervals.pop();
			if (checkInterval(now)) {
				answer = max(answer,now.second-now.first+1);
			}else divideInterval(now);
		}
		return answer;
	};
private:
	bool checkInterval(pair<unsigned short, unsigned short>&itv) {
		if (itv.second - itv.first + 1 <= answer)return false;
		if (itv.second - itv.first + 1 <k)return false;
		int localTable[26];
		memset(localTable, 0, 26*sizeof(int));
		//build localTable
		for (int i = itv.first; i <= itv.second; i++) localTable[s[i] - 'a']++;
		//
		bool flag = true;
		for (int i = itv.first; i <= itv.second; i++) {
			if (localTable[s[i] - 'a'] <k) {
				flag = false;
				isIncluded[i] = false;
			}
		}
		return flag;
	}
	void divideInterval(pair<unsigned short, unsigned short>&itv) {\
		if (itv.second - itv.first + 1 <= answer)return ;
	      if (itv.second - itv.first + 1 <k)return ;
		int head = -1;
		for (int i = itv.first; i <= itv.second; i++) {
			if (isIncluded[i] == true && head == -1) {
				head = i;
			}
			if (isIncluded[i] == false && head != -1) {
				if(i - 1 - head + 1>=k)intervals.push({ head,i - 1 });
				head = -1;
			}
		}
		//special case: itv.second==true;
		if (head != -1)	if (itv.second - head + 1>=k) intervals.push({ head,itv.second });
	}
};
int longestSubstring(std::string s, int k)
{
	longestSubstringSolver solver(s, k);
	return solver.solve();
}

int maxRotateFunction(std::vector<int>& A)
{
	int ans = 0; int sum = 0; int innerP = 0;
	for (int i = 0; i < A.size(); i++) {
		ans += i*A[i];
		sum +=A[i];
	}
	innerP = ans;
	for (int i = A.size()-1; i >=1; i--) {
		innerP = innerP + sum - A.size()* A[i];
		ans = max(ans, innerP);
	}
	return ans;
}

int guess(int num)
{
	int ans = 1;
	if (num == ans)return 0;
	if (num >ans)return 1;
	if (num <ans)return -1;
}

int guessNumber(int n)
{
		long long lo = 1; long long hi = n;
		long long now = (lo + hi) / 2;
		while (true) {
			if (guess(now) == 0)return now;
			if (hi - lo == 1) {
				if (guess(hi) == 0)return hi;
				return lo;
			}
			// guess behaviour is reversed with defination
			else if (guess(now) == 1) {
				lo = now;
				now = (lo + hi) / 2;
				
			}
			else {
				hi = now;
				now = (lo + hi) / 2;
			}
		}
}
unordered_map<unsigned int, unsigned short>* tableIntRPM;
int integerReplacement_re(unsigned int n)
{
	auto itr = tableIntRPM->find(n);
	if (itr != tableIntRPM->end())return itr->second;
	if (n % 2 == 0) {
		int ans= integerReplacement_re(n / 2) + 1;
		tableIntRPM->insert({ n,ans });
		return ans;
	}
	int ans = min(integerReplacement_re(n+1), integerReplacement_re(n -1))+1;
	tableIntRPM->insert({ n,ans });
	return ans;
}
int integerReplacement(int n)
{
	unordered_map<unsigned int, unsigned short>tableInt;
	tableIntRPM = &tableInt;
	unsigned short count = 0; unsigned int now = 1;
	while (now <= n) {
		tableInt[now] = count;
		now *= 2;
		count++;
	}
	return integerReplacement_re(n);
}
vector<vector<pair<double, int>>>*tableCalcEquation;
vector<pair<double, int>>*DFSRecord;
void DFScalcEquation(int id, pair<double, int>p) {
	auto&record = *DFSRecord;
	auto& now = record[id];
	if (now.second != -1)return;
	now = p; double& nowp = p.first; int& nowbase = p.second;
	for (auto& next : tableCalcEquation->at(id)) {
		DFScalcEquation(next.second, {next.first*nowp ,nowbase });
	}
}
vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
{
	unordered_map<string, int>map;
	vector<vector<pair<double, int>>>table; tableCalcEquation = &table;
	//build map
	int id = 0;
	for (auto&p : equations) {
		auto itr_a = map.find(p.first);	auto itr_b = map.find(p.second);
		if (itr_a == map.end()) {
			map[p.first] = id; id++;
		}
		if (itr_b == map.end()) {
			map[p.second] = id; id++;
		}
	}
	//build graph table
	table.resize(map.size());
	for (int i = 0; i < equations.size();i++) {
		auto& p = equations[i];
		int aId = map[p.first];	auto bId = map[p.second];
		table[aId].push_back({ 1/values[i],bId });
		table[bId].push_back({ values[i], aId});
	}
	
	//DFS
	vector<pair<double, int>>record; record.resize(map.size());
	for (auto&p : record) { p.first = -1; p.second = -1; }
	DFSRecord = &record;
	for (int i = 0; i < record.size(); i++) {
		if (record[i].second == -1) {
			DFScalcEquation(i, { 1,i });
		}
	}
	//build answer;
	vector<double> ans; 
	for (auto&p : queries) {
		auto itr_a = map.find(p.first);	auto itr_b = map.find(p.second);
		if (itr_a == map.end()|| itr_b == map.end()) {
			ans.push_back(-1); continue;
		}
		auto ra = record[itr_a->second];	auto rb = record[itr_b->second];
		if (ra.second != rb.second){ ans.push_back(-1); }
		else { ans.push_back(ra.first/rb.first); }
	}
	return ans;
}

int findNthDigit(int n)
{
	unsigned long long len = 1; unsigned long long first = 1; unsigned long long last = 9; unsigned long long total = 0;
	//find lenght
	while (true) {
		unsigned long long totalAtLen = (last - first + 1)*len;
		if (total + totalAtLen > n)break;
		total += totalAtLen;
		len++;
		first = first * 10;
		last = last * 10 + 9;
	}
	//find number
	unsigned long long num = first - 1 + (n - total) / len;
	//find  digit
	if ((n - total) % len == 0) {
		return num%10;
	}else{
		num++;
		int digit = len-(n - total) % len+1; int lastD = -1;
		for (int i = 0; i < digit; i++) {
			lastD = num % 10;
			num /= 10;
		}
		return lastD;
	}
}
std::vector<std::string>* readBinaryWatch_ans;
bitset<10>* readBinaryWatch_display;
void readBinaryWatch_re(int nowDig, int nowNum) {
	auto& display = *readBinaryWatch_display;
	if (nowDig == 10) {
		if (nowNum != 0)return;
		unsigned int hour = readBinaryWatch_display->to_ulong();
		unsigned char minute = readBinaryWatch_display->to_ulong();
		hour = hour >> 6;
		if (hour > 11)return;
		minute = minute & 0b00111111;
		if (minute >59)return;
		string str_m;
		if (minute == 0)str_m = "00";
		 else if (minute <10)str_m ="0"+to_string(minute);
		 else str_m =to_string(minute);
		readBinaryWatch_ans->push_back(to_string(hour) + ":" + str_m);
		return;
	}
	
	if (nowNum != 0) {
		display[nowDig] = 1;
		readBinaryWatch_re(nowDig + 1, nowNum - 1);
	}
	display[nowDig] =0;
	readBinaryWatch_re(nowDig + 1, nowNum);
}
std::vector<std::string> readBinaryWatch(int num)
{
	bitset<10>display; readBinaryWatch_display = &display;
	std::vector<std::string>ans; readBinaryWatch_ans = &ans;
	readBinaryWatch_re(0, num);
	return ans;
}

std::string removeKdigits(std::string num, int k)
{
	if (num.size() <= k)return "0";
	int head = 0; int remainInOld = num.size(); int remainInNew = remainInOld - k - 1;
	int tail = remainInOld - remainInNew + head - 1;
	string ans = ""; int target = num.size() - k;
	while (ans.size()<target) {
		if (remainInNew == remainInOld) {
			ans = ans + num.substr(head, num.size() - 1 - head + 1);
			break;
		}
		int id =head;
		for (int i = head; i < tail + 1; i++) {
			if (num[i] < num[id])id = i;
		}
		if (num[id] == '0'&&ans.size() == 0) {
			target--;
		}else ans.push_back(num[id]);
	
		
		head = id + 1; remainInOld = num.size() - 1 - head + 1;
		remainInNew--;
		tail = remainInOld - remainInNew + head - 1;
	}
	if (ans == "")return "0";
	return ans;
}
unordered_map<int, unsigned short>*_posToID_CC;
vector<vector<unsigned short>>*_posCanJumpTo_CC;
bool tryJump_CC(int nowID,int targetDist) {
	if (targetDist <=0)return false;
	auto itr = _posToID_CC->find(targetDist);
	auto&table = *_posCanJumpTo_CC;
	if (itr != _posToID_CC->end()) {
		int nextID = itr->second;
		if (itr->second == table.size() - 1)return true;
		table[nextID].push_back(nowID);
	}
	return false;
}
bool maxTest_CC(long long dist, long long id) {
	 if (dist * 2 > id* (id+1) ){ //max 
		return false;
	}else return true;
}
bool canCrossDP(std::vector<int>& stones)
{
	
	unordered_map<int, unsigned short>posToID;
	_posToID_CC = &posToID;
	vector<vector<unsigned short>>posCanJumpTo;
	_posCanJumpTo_CC = &posCanJumpTo;
	//produce posToID
	for (int i = 0; i < stones.size(); i++)posToID[stones[i]] = i;
	posCanJumpTo.resize(stones.size());
	posCanJumpTo[0].push_back(0);
	//
	unordered_set<int>targetDists;
	for (int i = 0; i < stones.size(); i++) {
		auto& prevID = posCanJumpTo[i];
		
		for (auto p : prevID) {
			int k = stones[i] - stones[p];
			targetDists.insert(stones[i] + k-1);
			targetDists.insert(stones[i] + k);
			targetDists.insert(stones[i] + k+1);
		}
		for (auto t : targetDists) {
			if (tryJump_CC(i, t))return true;
		}
		targetDists.clear();
	}
	return false;
}
//TODO 
vector<int>* _stonesCC;
bool canCrossDFS(int nowID,int k) {
	if(k<1)return false;
	auto&stones = *_stonesCC;
	if (nowID == stones.size() - 1)return true;
	int value_1 = stones[nowID] + k + 1;
	auto itr_1 = lower_bound(stones.begin() + nowID, stones.end(), value_1);
	if (itr_1 != stones.end()&&*itr_1== value_1) {
		if (canCrossDFS(itr_1 - stones.begin(), k + 1))return true;
	}
	int value_2 = stones[nowID] + k ;
	auto itr_2= lower_bound(stones.begin() + nowID, stones.end(), value_2);
	if (itr_2 != stones.end() && *itr_2 == value_2) {
		if (canCrossDFS(itr_2 - stones.begin(), k))return true;
	}
	int value_3 = stones[nowID] + k-1;
	auto itr_3 = lower_bound(stones.begin() + nowID, stones.end(), value_3);
	if (itr_3 != stones.end() && *itr_3 == value_3) {
		if (canCrossDFS(itr_3 - stones.begin(), k-1))return true;
	}
	return false;
}
bool canCrossDFSMain(std::vector<int>& stones) {
	_stonesCC = &stones;
	return canCrossDFS(1,1);
}
bool canCross(std::vector<int>& stones) {
	if(stones.size()<=1)return true;
	if (stones[1]!= 1)return false;
	for (int i = stones.size() - 1; i >= 0; i--) {
		if (!maxTest_CC(stones[i], i))return false;
	}
	return canCrossDFSMain(stones);
}
int ansSumOfLeftLeaves = 0;
void sumOfLeftLeaves_re(TreeNode* root, bool isLeft) {
	if (root == nullptr)return;
	if (root->left == nullptr&&root->right == nullptr&&isLeft) {
		ansSumOfLeftLeaves += root->val;
		return;
	}
	sumOfLeftLeaves_re(root->left, true);
	sumOfLeftLeaves_re(root->right, false);
}
int sumOfLeftLeaves(TreeNode* root) {
	ansSumOfLeftLeaves = 0;
	if (root == nullptr)return 0;
	sumOfLeftLeaves_re(root->left,true);
	sumOfLeftLeaves_re(root->right,false);
	return ansSumOfLeftLeaves;
}

std::string toHex(int _num)
{
	if (_num == 0)return "0";
	string ans;
	unsigned int num = _num;

	while (num != 0) {
		char now = num % 16;
		num /= 16;
		switch (now) {
		case  0: {ans.push_back('0'); break; }
		case  1: {ans.push_back('1'); break; }
		case  2: {ans.push_back('2'); break; }
		case  3: {ans.push_back('3'); break; }
		case  4: {ans.push_back('4'); break; }
		case  5: {ans.push_back('5'); break; }
		case  6: {ans.push_back('6'); break; }
		case  7: {ans.push_back('7'); break; }
		case  8: {ans.push_back('8'); break; }
		case  9: {ans.push_back('9'); break; }
		case  10: {ans.push_back('a'); break; }
		case  11: {ans.push_back('b'); break; }
		case  12: {ans.push_back('c'); break; }
		case  13: {ans.push_back('d'); break; }
		case  14: {ans.push_back('e'); break; }
		case  15: {ans.push_back('f'); break; }

		}
	}
	std::reverse(ans.begin(), ans.end());
	return ans;
}
struct TwoUnsignedInt {
	unsigned int second;
	unsigned int first;
	TwoUnsignedInt(int _a = 0, int _b = 0) :first(_a), second(_b) {};
};
union unsignedLonglongAndTwoInt
{
	unsigned long long ull;
	TwoUnsignedInt ti;
	unsignedLonglongAndTwoInt(int _a = 0, int _b = 0) : ti(_a, _b) {};
}; 
bool operator<(const unsignedLonglongAndTwoInt& a, const unsignedLonglongAndTwoInt&b){
	return a.ull < b.ull;
}
std::vector<std::pair<int, int>> reconstructQueue(std::vector<pair<int, int>>& people)
{
	if (people.size() <= 1)return people;
	vector<unsignedLonglongAndTwoInt>table;
	list<unsignedLonglongAndTwoInt>ansList;
	vector<pair<int, int>> ans;
	int len = people.size(); table.resize(len);
	for (int i = 0; i < len; i++) {
		unsignedLonglongAndTwoInt neo(people[i].first, people[i].second);
		table[i] = neo;
	}
	sort(table.begin(), table.end());
	int numberBegin = len ;
	int numberEnd = len - 1;
	int numberNow = len;
	while (true) {
		if (numberNow == len ||(table[numberNow].ti.first != table[numberEnd].ti.first)) {
			numberEnd = numberBegin - 1;
			numberBegin = lower_bound(table.begin(), table.begin() + numberBegin, table[numberEnd].ti.first) - table.begin();
			numberNow = numberBegin;
		}
		int k = table[numberNow].ti.second; 
		auto itr = ansList.begin();
		for (int nowId = 0; nowId < k; nowId++) {
			    itr++;
		}
		ansList.insert(itr, table[numberNow]);
		numberNow++;
		if (numberBegin == 0 && (numberNow == len||table[numberNow].ti.first != table[numberBegin].ti.first))break;
	}
	for (auto&itr : ansList) {
		ans.push_back({ itr.ti.first,itr.ti.second });
	}
	return ans;
}
vector<vector<int>>*heightMapTRW;
bool inline isBorder(char x, char y) {
	
	if (x == 0)return true;
	if (y == 0)return true;
	auto&heightMap = *heightMapTRW;
	if (x == heightMap.size() - 1)return true;
	if (y == heightMap[0].size() - 1)return true;
	return false;
}
bool inline isBottom(char x, char y) {
	if (isBorder(x, y))return false;
	auto&heightMap = *heightMapTRW;


	//if (heightMap[x][y] > heightMap[x-1][y-1])return false;
	if (heightMap[x][y] > heightMap[x-1][y])return false;
	//if (heightMap[x][y] > heightMap[x-1][y+1])return false;
	if (heightMap[x][y] > heightMap[x][y-1])return false;
	if (heightMap[x][y] > heightMap[x][y+1])return false;
	//if (heightMap[x][y] > heightMap[x+1][y-1])return false;
	if (heightMap[x][y] > heightMap[x+1][y])return false;
	//if (heightMap[x][y] > heightMap[x+1][y+1])return false;
	return true;
}
char  tryHeight(char x, char y, int h, vector<vector<bool>>&isVisited) {
	auto&heightMap = *heightMapTRW;
	if (heightMap[x][y] >= h)return 'H';
	if (isBorder(x, y))return 'B';
	if (isVisited[x][y])return 'V';
	isVisited[x][y] = true;
	//if (tryHeight(x-1, y-1, h, isVisited) == 'B')return 'B';
	if (tryHeight(x - 1, y, h, isVisited) == 'B')return 'B';
	//if (tryHeight(x-1 , y+1, h, isVisited) == 'B')return 'B';
	if (tryHeight(x , y-1, h, isVisited) == 'B')return 'B';
	if (tryHeight(x, y+1, h, isVisited) == 'B')return 'B';
	//if (tryHeight(x + 1, y-1, h, isVisited) == 'B')return 'B';
	if (tryHeight(x+1, y , h, isVisited) == 'B')return 'B';
	//if (tryHeight(x+1, y +1, h, isVisited) == 'B')return 'B';
	return 'F';
}

int findHeight(pair<char, char>&bottom, int lo, int hi) {

	vector<vector<bool>>isVisited;
	auto&heightMap = *heightMapTRW;
	isVisited.resize(heightMap.size());
	for (auto&v : isVisited)v.resize(heightMap[0].size());
	if (lo == hi) {
		if (tryHeight(bottom.first, bottom.second, hi, isVisited) == 'F')return hi;
		else return -1;
	}
	if (hi - lo == 1) {
		if (tryHeight(bottom.first, bottom.second,hi, isVisited) == 'F')return hi;
		for (auto&v : isVisited) { for (int i = 0; i < v.size();i++) { v[i]= false; } }
		if (tryHeight(bottom.first, bottom.second, lo, isVisited) == 'F')return lo;
		else return -1;
	}
	int mid = (lo + hi) / 2; char result = tryHeight(bottom.first, bottom.second, mid, isVisited);
	if (result!='B') {
		return findHeight(bottom, mid, hi);
	}
	else {
		return findHeight(bottom, lo, mid-1);
	}
	
}
void computeVolume_re(char x, char y, int height, unsigned int&ans, vector<vector<bool>>&isComputed) {
	if (isBorder(x, y))return;
	if (isComputed[x][y])return;
	auto&heightMap = *heightMapTRW;
	if(heightMap[x][y]>= height)return;
	ans += height - heightMap[x][y];
	isComputed[x][y] = true;
	//computeVolume_re(x-1, y-1, height, ans);
	computeVolume_re(x - 1, y, height, ans, isComputed);
	//computeVolume_re(x-1 , y+1, height, ans);
	computeVolume_re(x, y-1, height, ans, isComputed);
	computeVolume_re(x, y+1, height, ans, isComputed);
	//computeVolume_re(x +1, y-1, height, ans,);
	computeVolume_re(x+1, y, height, ans, isComputed);
	//computeVolume_re(x+1, y +1, height, ans);
}
int computeVolume(pair<char, char>&bottom, int height, vector<vector<bool>>&isComputed) {
	unsigned int ans = 0;
	computeVolume_re(bottom.first, bottom.second, height, ans, isComputed);
	return ans;
}
int trapRainWater_BinarySearchAndDFS(vector<vector<int>>& heightMap)
{
	
	heightMapTRW = &heightMap;
	vector<pair<char, char>>bottom; int maxHeight = 0;unsigned int ans = 0;
	int m = heightMap.size(); int n = heightMap[0].size();
	//find bottom and  maxHeight
	for (int i = 0; i < m; i++) {
		for (int j= 0;j< n; j++) {
			maxHeight = max(maxHeight, heightMap[i][j]);
			if (isBottom(i, j)) {
				bottom.push_back({ i,j });
			}
		}
	}
	vector<vector<bool>>isComputed;
	isComputed.resize(heightMap.size());
	for (auto&v : isComputed)v.resize(heightMap[0].size());
	for (auto&b : bottom) {
		if (isComputed[b.first][b.second])continue;
		int h = findHeight(b, heightMap[b.first][b.second]+1, maxHeight);
		if (h == -1)continue;
		ans += computeVolume(b, h, isComputed);
	}
	return  ans;
}
vector<vector<int>>* _heightMap;
class compHeightMap {

public:
	bool operator()(const pair<char, char>& a, const pair<char, char>& b)const {
		auto& heightMap = *_heightMap;
		return heightMap[a.first][a.second] > heightMap[b.first][b.second];
	}
};
int trapRainWater_Greedy(vector<vector<int>>& heightMap) {
	_heightMap = &heightMap;
	priority_queue < pair<char, char>, vector<pair<char, char>>, compHeightMap>pq;
	vector<vector<bool>>isVisited;
	isVisited.resize(heightMap.size());
	for (auto&v : isVisited)v.resize(heightMap[0].size());
	for (int i = 0; i < heightMap[0].size(); i++) {
		isVisited[0][i] = true;	isVisited[heightMap.size() - 1][i] = true;
		pq.push({ 0,i }); pq.push({ heightMap.size() - 1,i });
	}
	for (int i = 0; i < heightMap.size(); i++) {
		isVisited[i][0] = true;	isVisited[i][heightMap[0].size() - 1] = true;
		pq.push({ i,0 }); pq.push({ i, heightMap[0].size() - 1 });
	}
	int ans = 0; int currentHeight = 0;
	int m = heightMap.size();
	int n = heightMap[0].size();
	auto pqAdd = [&](int x, int y) {
		if (x < 0 || y < 0)return;
		if (x >=  m|| y>= n)return;
		if (!isVisited[x][y]) {
			pq.push({ x,y });
			isVisited[x][y] = true;
		}
	};

	while (!pq.empty()) {
		auto now = pq.top(); pq.pop(); int nowHeight = heightMap[now.first][now.second];
		if (nowHeight < currentHeight) {
			ans += (currentHeight - nowHeight);
		}else {
			currentHeight = nowHeight;
		}
		pqAdd(now.first + 1, now.second);
		pqAdd(now.first - 1, now.second);
		pqAdd(now.first, now.second + 1);
		pqAdd(now.first, now.second - 1);
	}
	return ans;
}
int trapRainWater(vector<vector<int>>& heightMap) {
	if (heightMap.size() <= 2)return 0;
	if (heightMap[0].size() <= 2)return 0;
	return trapRainWater_Greedy(heightMap);
}

std::vector<std::string> fizzBuzz(int n)
{
	std::vector<std::string> ans; ans.resize(n);
	for (int i = 1; i <= n; i++) {
		ans[i - 1] = to_string(i);
	}
	for (int i = 1; i*3<= n; i++) {
		ans[i * 3-1] = "Fizz";
	}
	for (int i = 1; i * 5 <= n; i++) {
		if (ans[i * 5 - 1] == "Fizz") {
			ans[i * 5 - 1] = "FizzBuzz";
		}else 	ans[i * 5 - 1] = "Buzz";
	
	}
	return ans;
}

int numberOfArithmeticSlices(vector<int>& A)
{
	int totalLen = A.size();
	if (totalLen < 3)return 0;
	int now_len = 2; int now_diff = A[1] - A[0]; int ans = 0;
	for (int i = 1; i < totalLen - 1; i++) {
		if (A[i + 1] - A[i] == now_diff) {
			now_len++;
		}
		else {
			int maxLen = now_len - 2;
			ans += maxLen * (maxLen + 1) / 2;
			now_len = 2; now_diff = A[i + 1] - A[i];
		}
	}
	if (now_len > 2) {
		int maxLen = now_len - 2;
		ans += maxLen * (maxLen + 1) / 2;
	};
	return ans;
}

int thirdMax(std::vector<int>& nums)
{
	if (nums.size() == 1)return nums[0];
	if (nums.size() == 2)return max(nums[0], nums[1]);
	long long m1 = LONG_MIN; long long  m2 = LONG_MIN; long long  m3 = LONG_MIN;
	for (int i = 0; i < nums.size(); i++) {
		int now = nums[i];
		if (now == m1 || now == m2 || now == m3)continue;
		if (now > m1) {
		
			m3 = m2;
			m2 = m1;
			m1 = now;
		}
		else if (now > m2) {
			
			m3 = m2;
			m2 = now;
		}
		else if (now > m3) {
			m3 = now;
		}
	}
	if (m3 == LONG_MIN) {
			return m1;

	}
	return m3;
}

std::string addStrings(std::string num1, std::string num2)
{
	string ans = ""; bool isUp = 0;
	reverse(num1.begin(), num1.end()); reverse(num2.begin(), num2.end());
	int len = max(num1.size(), num2.size()); int a1 = 0; int a2 = 0;
	for (int i = 0; i < len; i++) {
		if (i < num1.size())a1 = num1[i] - '0';
		else a1 = 0;
		if (i < num2.size())a2 = num2[i] - '0';
		else a2 = 0;
		int sum = a1 + a2 + isUp;
		isUp = sum / 10;
		ans.push_back(sum % 10+'0');
	}
	if(isUp)ans.push_back('1');
	reverse(ans.begin(), ans.end());
	return ans;
}
const vector<int>* numsCanPartition;
bool re_func_canPartition(int a, int b, int now) {
	auto& nums = *numsCanPartition;
	if (nums[now] == a || nums[now] == b)return true;
	if (nums[0] == a || nums[0] == b)return true;
	if (nums[0] > a && nums[0]> b)return false;
	if (nums[now] + nums[0] == a || nums[now] + nums[0] == b)return true;
	if (nums[now] + nums[0] > a && nums[now] + nums[0] > b)return false;
	if (nums[now] + nums[0] < a) {
		if (re_func_canPartition(a- nums[now],b,now-1))return true;
	}
	if (nums[now] + nums[0] < b) {
		if (re_func_canPartition(a , b - nums[now], now - 1))return true;
	}
	return false;
}
bool canPartition(std::vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int sum = 0;
	for (auto i : nums)sum += i;
	if (sum % 2 == 1)return false;
	if (nums.back() > sum / 2)return false;
	if (nums.back() == sum / 2)return true;
	numsCanPartition = &nums;
	return re_func_canPartition(sum/2- nums.back(), sum / 2 ,nums.size()-2);
}
std::vector<std::vector<int>>* record_table_pacificAtlantic;
void DFS_pacificAtlantic(int x,int y,char from) {

}
std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& matrix)
{
	std::vector<std::vector<int>>record_table;

	return std::vector<std::vector<int>>();
}
