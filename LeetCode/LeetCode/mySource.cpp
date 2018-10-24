#include "stdafx.h"
#include "myHeader.h"
#include "iostream"
#include<algorithm>
#include<queue>
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