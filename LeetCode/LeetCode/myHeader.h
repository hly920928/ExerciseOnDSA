#pragma once
#include <vector>
#include <map>
//327. Count of Range Sum
int countRangeSum(std::vector<int>& nums, int lower, int upper);
//328. Odd Even Linked List
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* buildList(std::vector<int>&v);
ListNode* oddEvenList(ListNode* head);
//329. Longest Increasing Path in a Matrix
int longestIncreasingPath(std::vector<std::vector<int>>& matrix);
//331. Verify Preorder Serialization of a Binary Tree
bool isValidSerialization(std::string preorder);
//330. Patching Array
int minPatches(std::vector<int>& nums, int n);
//332. Reconstruct Itinerary
std::vector<std::string> findItinerary(std::vector<std::pair<std::string, std::string>> tickets);
//334. Increasing Triplet Subsequence
bool increasingTriplet(std::vector<int>& nums);
//335. Self Crossing
bool isSelfCrossing(std::vector<int>& x);
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int robIII(TreeNode* root);
std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words);
std::vector<int> countBits(int num);
class NestedInteger;
class NestedInteger {
private:
	std::vector<NestedInteger>list;
	int ing;
	public:
		NestedInteger(int i = INT_MIN) {
			ing = i;
		}
		NestedInteger(std::vector<NestedInteger>*p = nullptr) {
			if (p != nullptr)list = *p;
		}
		     // Return true if this NestedInteger holds a single integer, rather than a nested list.
		bool isInteger() const { return list.size()==0; };
		
		     // Return the single integer that this NestedInteger holds, if it holds a single integer
			     // The result is undefined if this NestedInteger holds a nested list
		int getInteger() const { return ing; };
		
			   // Return the nested list that this NestedInteger holds, if it holds a nested list
		     // The result is undefined if this NestedInteger holds a single integer
		const std::vector<NestedInteger> &getList() const { return list; };
};
class NestedIterator {
private:
	std::vector<int>list;
	int now;
public:
	NestedIterator(std::vector<NestedInteger> &nestedList) {
		now = 0;
		for (auto& i : nestedList)flat(i);
		
	}

	int next() {
		int ans = list[now]; now++;
		return ans;
	}

	bool hasNext() {
		return now < list.size();
	}
private:
	void flat(const NestedInteger& ni) {
		if (ni.isInteger()) {
			list.push_back(ni.getInteger());
		}
		else {
			auto& l = ni.getList();
			for (auto& i : l)flat(i);
		}
	}
};
//342. Power of Four
bool isPowerOfFour(int num);
//343. Integer Break
int integerBreak(int n);
//344. Reverse String
std::string reverseString(std::string s);
//345. Reverse Vowels of a String
std::string reverseVowels(std::string s);
//347. Top K Frequent Elements
std::vector<int> topKFrequent(std::vector<int>& nums, int k);
//349. Intersection of Two Arrays
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2);
//350. Intersection of Two Arrays II
std::vector<int> intersectionII(std::vector<int>& nums1, std::vector<int>& nums2);
//
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class SummaryRanges {
private:
	std::map<int, int>map;
public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		auto itr_b = map.upper_bound(val);
		auto itr_s = itr_b; 
		if (itr_b != map.end()) { itr_s--; }
		else if (map.size() > 0) { itr_s = map.end(); itr_s--; }
		char type = 'I';
		if (itr_s !=map.end()) {
			if (itr_s->first <= val&&itr_s->second >= val)type = 'U';
			if (itr_s->second == val - 1)type = 'F';
		}
		if (itr_b != map.end()) {
			if (itr_b->first <= val)type = 'U';
			if (itr_b->first == val+1)type = 'A';
		}
		if (itr_b != map.end()&& itr_s != map.end()) {
			if (itr_b->first == val + 1&& itr_s->second == val - 1)type = 'M';
		}
		switch (type)
		{
		case'U':break;
		case 'I': {map[val] = val; break; }
		case 'F': {map[itr_s->first] = val; break; }
		case 'A': {map[val] = itr_b->second; map.erase(itr_b->first); break; }
		case 'M': {map[itr_s->first] = itr_b->second; map.erase(itr_b->first); break; }
		}
	}

	std::vector<Interval> getIntervals() {
		std::vector<Interval>ans;
		for (auto itr : map) {
			ans.push_back(Interval(itr.first, itr.second));
		}
		return ans;
	}
};