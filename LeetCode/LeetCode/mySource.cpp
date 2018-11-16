#include "stdafx.h"
#include "myHeader.h"
#include "iostream"
#include<algorithm>
#include<queue>
#define US_MAX 65500
#include<unordered_set>
#include<unordered_map>
#include<map>
#include <math.h>
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
