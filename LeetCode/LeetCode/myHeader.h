#pragma once
#include <vector>
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