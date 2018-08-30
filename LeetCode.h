#pragma once
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
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
//63. Unique Paths II
int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);
//64. Minimum Path Sum
int minPathSum(std::vector<std::vector<int>>& grid);
//65. Valid Number
bool isNumber(std::string s);
//66. Plus One
std::vector<int> plusOne(std::vector<int>& digits);
//67. Add Binary
std::string addBinary(std::string a, std::string b);
//68. Text Justification
std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth);
//68. Text Justification
int mySqrt(int x);
//70. Climbing Stairs
int climbStairs(int n);
//71. Simplify Path
std::string simplifyPath(std::string path);
//72. Edit Distance
int minDistance(std::string word1, std::string word2);
//73. Set Matrix Zeroes
void setZeroes(std::vector<std::vector<int>>& matrix);
//74. Search a 2D Matrix
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);
//75. Sort Colors
void sortColors(std::vector<int>& nums);
//76. Minimum Window Substring
std::string minWindow(std::string s, std::string t);
//77. Combinations
std::vector<std::vector<int>> combine(int n, int k);
//78. Subsets
std::vector<std::vector<int>>subsets(std::vector<int>& nums);
//79. Word Search
bool exist(std::vector<std::vector<char>>& board, std::string word);
//Remove Duplicates from Sorted Array II
int removeDuplicates_V2(std::vector<int>& nums);
//81. Search in Rotated Sorted Array II
bool searchRotated_Sorted_Array(std::vector<int>& nums, int target);
//82. Remove Duplicates from Sorted List II
ListNode* deleteDuplicates(ListNode* head);
//83. Remove Duplicates from Sorted List
ListNode* deleteDuplicates_v0(ListNode* head);
//84. Largest Rectangle in Histogram
int largestRectangleArea(std::vector<int>& heights);
//85. Maximal Rectangle
int maximalRectangle(std::vector<std::vector<char>>& matrix);
//86. Partition List
ListNode* partition(ListNode* head, int x);
//87. Scramble String
bool isScramble(std::string s1, std::string s2);
//88. Merge Sorted Array
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
//89. Gray Code
std::vector<int> grayCode(int n);
//90. Subsets II
std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums);
//91. Decode Ways
int numDecodings(std::string s);
//92. Reverse Linked List II
ListNode* reverseBetween(ListNode* head, int m, int n);
//93. Restore IP Addresses
std::vector<std::string> restoreIpAddresses(std::string s);
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//94. Binary Tree Inorder Traversal
std::vector<int> inorderTraversal(TreeNode* root);
std::vector<int> inorderTraversal_iterative(TreeNode* root);
//95. Unique Binary Search Trees II

std::vector<TreeNode*> generateTrees(int n);
//96. Unique Binary Search Trees
int numTrees(int n);
//97. Interleaving String
bool isInterleave(std::string s1, std::string s2, std::string s3);
//98. Validate Binary Search Tree
bool isValidBST(TreeNode* root);
//99. Recover Binary Search Tree
void recoverTree(TreeNode* root);
//100. Same Tree
bool isSameTree(TreeNode* p, TreeNode* q);
//101. Symmetric Tree
bool isSymmetric(TreeNode* root);
//102. Binary Tree Level Order Traversal
std::vector<std::vector<int>> levelOrder(TreeNode* root);
//103. Binary Tree Zigzag Level Order Traversal
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root);
//104. Maximum Depth of Binary Tree
int maxDepth(TreeNode* root);
//105. Construct Binary Tree from Preorder and Inorder Traversal
TreeNode* buildTree_inAndpre(std::vector<int>& preorder, std::vector<int>& inorder);
//106. Construct Binary Tree from Inorder and Postorder Traversal
TreeNode* buildTree_inAndpost(std::vector<int>& inorder, std::vector<int>& postorder);
//107. Binary Tree Level Order Traversal II
std::vector<std::vector<int>> levelOrderBottom(TreeNode* root);
//108. Convert Sorted Array to Binary Search Tree
TreeNode* sortedArrayToBST(std::vector<int>& nums);
//109. Convert Sorted List to Binary Search Tree
TreeNode* sortedListToBST(ListNode* head);
//110. Balanced Binary Tree
bool isBalanced(TreeNode* root);
//111. Minimum Depth of Binary Tree
int minDepth(TreeNode* root);
//112. Path Sum
bool hasPathSum(TreeNode* root, int sum);
//113. Path Sum II
std::vector<std::vector<int>> pathSum(TreeNode* root, int sum);
//114. Flatten Binary Tree to Linked List
void flatten(TreeNode* root);
//115. Distinct Subsequences
int numDistinct(std::string s, std::string t);
//116. Populating Next Right Pointers in Each Node
struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int v) :val(v) {};
};
void connect(TreeLinkNode *root);
std::vector<std::vector<int>> generate(int numRows);
std::vector<int> getRow(int rowIndex);
//120. Triangle
int minimumTotal(std::vector<std::vector<int>>& triangle);
//121. Best Time to Buy and Sell Stock
int maxProfit(std::vector<int>& prices);
//122. Best Time to Buy and Sell Stock II
int maxProfit_V2(std::vector<int>& prices);
//123. Best Time to Buy and Sell Stock III
int maxProfit_V3(std::vector<int>& prices);
//124. Binary Tree Maximum Path Sum
int maxPathSum(TreeNode* root); 
//125. Valid Palindrome
bool isPalindrome(std::string s);
//127. Word Ladder
int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList);
//126. Word Ladder II
std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string>& wordList);
//128. Longest Consecutive Sequence
int longestConsecutive(std::vector<int>& nums);
//129. Sum Root to Leaf Numbers
int sumNumbers(TreeNode* root);
//130. Surrounded Regions
void solve_SR(std::vector<std::vector<char>>& board);
//131. Palindrome Partitioning
std::vector<std::vector<std::string>> partition(std::string s);
//132. Palindrome Partitioning II new!!
int minCut(std::string s);
struct UndirectedGraphNode {
	int label;
	std::vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
	
};
//133 Clone Graph
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
//134 Gas Station
int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost);
//135. Candy
int candy(std::vector<int>& ratings);
//136-137 singleNumber
int singleNumber(std::vector<int>& nums);
//138. Copy List with Random Pointer
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
RandomListNode *copyRandomList(RandomListNode *head);
//139. Word Break
bool wordBreak(std::string s, std::vector<std::string>& wordDict);
//140. Word Break II
std::vector<std::string>  wordBreak_II(std::string s, std::vector<std::string>& wordDict);
//141. Linked List Cycle
bool hasCycle(ListNode *head);
//142. Linked List Cycle II
ListNode *detectCycle(ListNode *head);
//143. Reorder List
void reorderList(ListNode* head);
//144. Binary Tree Preorder Traversal
std::vector<int> preorderTraversal(TreeNode* root);
//145.Binary Tree Postorder Traversal
std::vector<int> postorderTraversal(TreeNode* root);
//146. LRU Cache
struct keyAndVal {
	int key;
	int val;
	keyAndVal(int _k=-1, int _v=-1) :key(_k), val(_v) {};
};
class LRUCache {
private:
	int clock;
	int _capacity;
	int now_size;
	std::map<int, keyAndVal>clock_to_keyAndVal;
	std::unordered_map<int, int>key_to_clock;
public:
	LRUCache(int capacity);
	int get(int key);
	void put(int key, int value);
};
//147. Insertion Sort List
ListNode* insertionSortList(ListNode* head);
//148. Sort List
ListNode* sortList(ListNode* head);
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
//149. Max Points on a Line
int maxPoints(std::vector<Point>& points);
//150. Evaluate Reverse Polish Notation
int evalRPN(std::vector<std::string>& tokens);
//151. Reverse Words in a String
void reverseWords(std::string &s);
//152. Maximum Product Subarray
int maxProduct(std::vector<int>& nums);
//153. Find Minimum in Rotated Sorted Array
int findMin(std::vector<int>& nums);
//154. Find Minimum in Rotated Sorted Array II
int findMin_V2(std::vector<int>& nums);
class MinStack {
private:
	std::stack<int>stk;
	int min;
public:
	MinStack();
	void push(int x);
	void pop();
    int top();
    int getMin();
};
//160. Intersection of Two Linked Lists
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
//164. Maximum Gap
int maximumGap(std::vector<int>& nums);
//165. Compare Version Numbers
int compareVersion(std::string version1, std::string version2);
//166. Fraction to Recurring Decimal
std::string fractionToDecimal(int numerator, int denominator);
std::string fractionToDecimal(long long  numerator, long long denominator);
//167. Two Sum II - Input array is sorted
std::vector<int> twoSum(std::vector<int>& numbers, int target);
//168. Excel Sheet Column Title
std::string convertToTitle(int n);
//169. Majority Element
int majorityElement(std::vector<int>& nums);
//171. Excel Sheet Column Number
int titleToNumber(std::string s);
//172. Factorial Trailing Zeroes
int trailingZeroes(int n);
class BSTIterator {
private:
	std::stack<TreeNode*>stk;
public:
	BSTIterator(TreeNode *root);
	bool hasNext();
	int next();
};
//174. Dungeon Game
int calculateMinimumHP(std::vector<std::vector<int>>& dungeon);
//179. Largest Number
std::string largestNumber(std::vector<int>& nums);
//187. Repeated DNA Sequences
std::vector<std::string> findRepeatedDnaSequences(std::string s);
//188. Best Time to Buy and Sell Stock IV
int maxProfit(int k, std::vector<int>& prices);
//189. Rotate Array
void rotate(std::vector<int>& nums, int k);
//190. Reverse Bits
uint32_t reverseBits(uint32_t n);
//191. Number of 1 Bits
int hammingWeight(uint32_t n);
//198. House Robber
int rob(std::vector<int>& nums);
//199. Binary Tree Right Side View
std::vector<int> rightSideView(TreeNode* root);
//200. Number of Islands
int numIslands(std::vector<std::vector<char>>& grid);
//201. Bitwise AND of Numbers Range
int rangeBitwiseAnd(int m, int n);
//202. Happy Number
bool isHappy(int n);
//203. Remove Linked List Elements
ListNode* removeElements(ListNode* head, int val);
//204. Count Primes
int countPrimes(int n);
//205. Isomorphic Strings
bool isIsomorphic(std::string s, std::string t);
//206. Reverse Linked List
ListNode* reverseList(ListNode* head);
//207. Course Schedule
bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites);
//208. Implement Trie (Prefix Tree)
struct TriesNode {
	bool isExist;
	unsigned int indexNext[26];
	TriesNode() {
		isExist = false;
		for (unsigned int& i : indexNext) i = 0;
	}
	bool haveNext() {
		int t = 0;
		for (int i : indexNext)t += i;
		return t!= 0;
	}
};
class Tries {
private:
	std::vector<TriesNode>table;
public:
	/** Initialize your data structure here. */
	Tries();

	/** Inserts a word into the trie. */
	void insert(std::string word);

	/** Returns if the word is in the trie. */
	bool search(std::string word);

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(std::string prefix);
	bool searchWithWildCard(std::string& word, int id, int nodeId);
};
//209. Minimum Size Subarray Sum
int minSubArrayLen(int s, std::vector<int>& nums);
//210. Course Schedule II
std::vector<int> findOrder(int numCourses, std::vector< std::pair<int, int>>& prerequisites);
//211. Add and Search Word - Data structure design
class WDNode {
public:
	bool isExist;
	WDNode* Next[26];
	WDNode():isExist(false) {
		for (auto& p : Next)p=nullptr;
	};
	~WDNode() {
		for (auto p : Next)delete p;
	}
};
class WordDictionary {
public:
	WDNode root;
	WordDictionary() {};
	void addWord(std::string word);;
	bool search(std::string word) { return searchRe(word, 0, &root); };
private:
	bool searchRe(std::string& word, int i, WDNode* now);
};
//212. Word Search II
std::vector<std::string> findWords_V1(std::vector<std::vector<char>>& board, std::vector<std::string>& words);
std::vector<std::string> findWords_V2(std::vector<std::vector<char>>& board, std::vector<std::string>& words);
//213. House Robber II
int rob_sub(std::vector<int>& nums, int h, int t);
int rob_II(std::vector<int>& nums);
//214. Shortest Palindrome
std::string shortestPalindromeV1(std::string s);
std::string shortestPalindromeV2(std::string s);
//215. Kth Largest Element in an Array
//trivial sort method
int findKthLargest_V1(std::vector<int>& nums, int k);
//quickSelect
int findKthLargest_V2(std::vector<int>& nums, int k);
//216. Combination Sum III
std::vector<std::vector<int>> combinationSum3(int k, int n);
//217. Contains Duplicate
bool containsDuplicate(std::vector<int>& nums);
//218. The Skyline Problem
std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& buildings);
std::vector<std::pair<int, int>> getSkyline_V2(std::vector<std::vector<int>>& buildings);
//219. Contains Duplicate II
bool containsNearbyDuplicate(std::vector<int>& nums, int k);
bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t);
//221. Maximal Square
int maximalSquare(std::vector<std::vector<char>>& matrix);
//222. Count Complete Tree Nodes
int countNodes(TreeNode* root);
//223. Rectangle Area
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);
//224. Basic Calculator
int calculate_my(std::string s);
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {

	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {

	}

	/** Get the top element. */
	int top() {

	}

	/** Returns whether the stack is empty. */
	bool empty() {

	}
}; 
//225. Implement Stack using Queues
class MyStack_q {
private:
	std::queue<int>q;
public:
	/** Initialize your data structure here. */
	MyStack_q() {};

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int n = q.size();
		for (int i = 0; i < n - 1; i++) {
			q.push(q.front()); q.pop();
		}
		int ans = q.front(); q.pop();
		return ans;
	}

	/** Get the top element. */
	int top() {
		int n = q.size();
		for (int i = 0; i < n - 1; i++) {
			q.push(q.front()); q.pop();
		}
		int ans = q.front(); q.pop();
		q.push(ans);
		return ans;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};
//226. Invert Binary Tree
TreeNode* invertTree(TreeNode* root);
//227. Basic Calculator II
int calculate_II(std::string s);
//228. Summary Ranges
std::vector<std::string> summaryRanges(std::vector<int>& nums);
//229. Majority Element II
std::vector<int> majorityElement_II(std::vector<int>& nums);
//230. Kth Smallest Element in a BST
int kthSmallest(TreeNode* root, int k);
//231. Power of Two
bool isPowerOfTwo(int n);
class MyQueue {
private:
	std::stack<int>a;
	std::stack<int>b;
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		a.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int ans = 0;
		while (a.size() != 1) {
			b.push(a.top()); a.pop();
		}
		ans = a.top(); a.pop();
		while (!b.empty()) {
			a.push(b.top()); b.pop();
		}
		return ans;
	}

	/** Get the front element. */
	int peek() {
		int ans = 0;
		while (a.size() != 1) {
			b.push(a.top()); a.pop();
		}
		ans = a.top();
		while (!b.empty()) {
			a.push(b.top()); b.pop();
		}
		return ans;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return a.empty();
	}
};
//233. Number of Digit One
int countDigitOne(int n);
int countDigitOneBF(int n);
//234. Palindrome Linked List
bool isPalindrome(ListNode* head);
//235. Lowest Common Ancestor of a Binary Search Tree
TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q);
//236. Lowest Common Ancestor of a Binary Tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
//237. Delete Node in a Linked List
void deleteNode(ListNode* node);
std::vector<int> productExceptSelf(std::vector<int>& nums);
//239. Sliding Window Maximum
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k);
//240. Search a 2D Matrix II
bool searchMatrix_V2(std::vector<std::vector<int>>& matrix, int target);
bool searchMatrix_V2_2(std::vector<std::vector<int>>& matrix, int target);
//241. Different Ways to Add Parentheses
std::vector<int> diffWaysToCompute(std::string input);
//242. Valid Anagram
bool isAnagram(std::string s, std::string t);
//257. Binary Tree Paths
std::vector<std::string> binaryTreePaths(TreeNode* root);
//258. Add Digits
int addDigits(int num);
//260. Single Number III
std::vector<int> singleNumberIII(std::vector<int>& nums);