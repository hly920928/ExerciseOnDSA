#pragma once
#include <string>
#include <vector>
//17. Letter Combinations of a Phone Numberclass Solution {
std::vector<std::string> letterCombinations(std::string digits);
//18. 4Sum
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);
//19. Remove Nth Node From End of List
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n);
//20. Valid Parentheses
bool isValid(std::string s);
//23. Merge k Sorted Lists
ListNode* mergeKLists(std::vector<ListNode*>& lists);
//21. Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
//22. Generate Parentheses
std::vector<std::string> generateParenthesis(int n);
//24. Swap Nodes in Pairs
ListNode* swapPairs(ListNode* head);
//25. Reverse Nodes in k - Group
ListNode* reverseKGroup(ListNode* head, int k);
//26. Remove Duplicates from Sorted Array
int removeDuplicates(std::vector<int>& nums);
//27. Remove Element
int removeElement(std::vector<int>& nums, int val);
//28. Implement strStr()
int strStr(std::string haystack, std::string needle);
//29. Divide Two Integers
int divide(long long dividend, int divisor);
//30.Substring with Concatenation of All Words
std::vector<int> findSubstring(std::string s, std::vector<std::string>& words);
//31.Next Permutation
void nextPermutation(std::vector<int>& nums);
//32.Longest Valid Parentheses
int longestValidParentheses(std::string s);
//33.Search in Rotated Sorted Array
int search(std::vector<int>& nums, int target);
//34.Search for a Range
std::vector<int> searchRange(std::vector<int>& nums, int target);
//35.Search Insert Position
int searchInsert(std::vector<int>& nums, int target);
//36.Valid Sudoku
bool isValidSudoku(std::vector<std::vector<char>>& board);
//37. Sudoku Solver
void solveSudoku(std::vector<std::vector<char>>& board);
//38.Count and Say
std::string countAndSay(int n);
//39.Combination Sum
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);
//40. Combination Sum II
std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);
//41. First Missing Positive
int firstMissingPositive(std::vector<int>& nums);