#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include<algorithm>
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
/*class NestedInteger;
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
      std::vector<NestedInteger> &getList()  { return list; };
	  const std::vector<NestedInteger> &getList()const { return list; };
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
	void flat( NestedInteger& ni) {
		if (ni.isInteger()) {
			list.push_back(ni.getInteger());
		}
		else {
			auto& l = ni.getList();
			for (auto& i : l)flat(i);
		}
	}
};*/
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
//355. Design Twitter
struct Tweet {
	int uID;
	int tID;
	Tweet(int u = INT_MIN, int t = INT_MIN): uID(u),tID(t){};
};
class UserData{
private:
	std::stack<Tweet>ts;
public:
	UserData() {
	}
	void addTweet(Tweet t) {
		ts.push(t);
	}
	void getTweet(std::vector<int>& v,std::unordered_set<int>&f) {
		std::vector<Tweet>vt;
		while (vt.size() < 10&&!ts.empty()) {
			auto t = ts.top(); ts.pop();
			if (f.find(t.uID) != f.end())vt.push_back(t);
		}
		for (int i = vt.size() - 1; i >= 0; i--) ts.push(vt[i]);
		for (int i =0; i < vt.size(); i++) v.push_back(vt[i].tID);
	}
};
class UserDataV2 {
private:
	int tweets[11]; int head; int tail;
public:
	int size;
	UserDataV2():head(0), tail(-1) {
		for (int& i : tweets)i = -1;
		size = 0;
	
	};
	void addTweets(int t) {
		 tail = (tail + 1) % 11;
		 tweets[tail] = t;
		 size = std::min(10, size + 1);
		 if ((tail + 1) % 11 == head) {
			 tweets[head] = -1;
			 head = (head + 1) % 11;

		 }
	}
	int getTweets(int id) {
		if (id > 9|| id<0)return INT_MIN;
		int t = tweets[(head + id) % 11];
		if(t==-1)return INT_MIN;
		return t;
	}
	void getAll(std::vector<int>&v) {
		for (int i = 0; i <=9; i++) {
			int t = getTweets(i);
			if (t == INT_MIN)break;
			v.push_back(t);
		}
	}
};
class Twitter {
private:
	std::unordered_map<int, std::unordered_set<int>>fellowee;
	std::unordered_map<int, UserDataV2>userData;
	std::unordered_map<int, int>tweetData;
	int timeStamp;
public:
	Twitter() {
		timeStamp = 0;
	}
	void postTweet(int userId, int tweetId) {
		fellowee[userId].insert(userId);
		userData[userId].addTweets(tweetId);
		tweetData[tweetId] = timeStamp;
		timeStamp++;
	}
	std::vector<int> getNewsFeed(int userId) {
		std::vector<std::pair<int,std::pair<int, int>>>felloweeData;
		std::vector<int> ans;
		auto& fes = fellowee[userId];
		for (int fe : fes)felloweeData.push_back({ fe,{ userData[fe].size-1,userData[fe].getTweets(userData[fe].size - 1)} });
		for (int i = 0; i < 10; i++) {
			int maxT = INT_MIN; int max_V=-1;
			for (int n = 0; n < felloweeData.size(); n++) {
				int tID = felloweeData[n].second.second;
				if (tID!= INT_MIN&&tweetData[tID]> maxT) {
					maxT = tweetData[tID];
					max_V = n;
				}
			}
				if (maxT == INT_MIN)break;
				ans.push_back(felloweeData[max_V].second.second);
				felloweeData[max_V].second.first--;
				felloweeData[max_V].second.second = userData[felloweeData[max_V].first].getTweets(felloweeData[max_V].second.first);
		}
		return ans;
	}
	void follow(int followerId, int followeeId) {

		fellowee[followerId].insert(followerId);
		fellowee[followerId].insert(followeeId);
	}
	void unfollow(int followerId, int followeeId) {
		if (followerId == followeeId)return;
		fellowee[followerId].erase(followeeId);
	}
};
//354. Russian Doll Envelopes
int maxEnvelopes(std::vector<std::pair<int, int>>& envelopes);
int maxEnvelopes_V2(std::vector<std::pair<int, int>>& envelopes);
////357. Count Numbers with Unique Digits
int countNumbersWithUniqueDigits(int n);
//365. Water and Jug Problem
bool canMeasureWater(int x, int y, int z);
//363. Max Sum of Rectangle No Larger Than K
int maxSumSubmatrix(std::vector<std::vector<int>>& matrix, int k);
//367. Valid Perfect Square
bool isPerfectSquare(int num);
//368. Largest Divisible Subset
std::vector<int> largestDivisibleSubset(std::vector<int>& nums);
//373. Find K Pairs with Smallest Sums
std::vector<std::pair<int, int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k);
//376. Wiggle Subsequence
int wiggleMaxLength(std::vector<int>& nums);
//377. Combination Sum IV
int combinationSum4(std::vector<int>& nums, int target);
//378. Kth Smallest Element in a Sorted Matrix
int kthSmallest(std::vector<std::vector<int>>& matrix, int k);
//386. Lexicographical Numbers
std::vector<int> lexicalOrder(int n);
//383. Ransom Note
bool canConstruct(std::string ransomNote, std::string magazine);
//387. First Unique Character in a String
int firstUniqChar(std::string s);
//388. Longest Absolute File Path
int lengthLongestPath(std::string input);
//389. Find the Difference
char findTheDifference(std::string s, std::string t);
//390. Elimination Game
int lastRemaining(int n);
//392. Is Subsequence
bool isSubsequence(std::string s, std::string t);
//393. UTF-8 Validation
bool validUtf8(std::vector<int>& data);
//394. Decode String
std::string decodeString(std::string s);
//391. Perfect Rectangle
bool isRectangleCover(std::vector<std::vector<int>>& rectangles);
//395. Longest Substring with At Least K Repeating Characters
int longestSubstring(std::string s, int k);