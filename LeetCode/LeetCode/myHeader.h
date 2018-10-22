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