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
//42. Trapping Rain Water
int trap(std::vector<int>& height);
//43. Multiply Strings
std::string multiply(std::string num1, std::string num2);
//44. Wildcard Matching
bool isMatch(std::string s, std::string p);
//45. Jump Game II
int jump(std::vector<int>& nums);
//46. Permutations
std::vector<std::vector<int>> permute(std::vector<int>& nums);
//47. Permutations II
std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums);
//48. Rotate Image
void rotate(std::vector<std::vector<int>>& matrix);
//49. Group Anagrams
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
//50. Pow(x, n)
double myPow(double x, long long n);
//51. N-Queens
std::vector<std::vector<std::string>> solveNQueens(int n);
//52. N-Queens II
int totalNQueens(int n);
//53. Maximum Subarray
int maxSubArray(std::vector<int>& nums);
//54. Spiral Matrix
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);
//55. Jump Game
bool canJump(std::vector<int>& nums);
//56. Merge Intervals
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
std::vector<Interval> merge(std::vector<Interval>& intervals);
//57. Insert Interval
std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval);
//58. Length of Last Word
int lengthOfLastWord(std::string s);
//59. Spiral Matrix II
std::vector<std::vector<int>> generateMatrix(int n);
//60. Permutation Sequence
std::string getPermutation(int n, int k);
//61. Rotate List
ListNode* rotateRight(ListNode* head, int k);
//62. Unique Paths
int uniquePaths(int m, int n);