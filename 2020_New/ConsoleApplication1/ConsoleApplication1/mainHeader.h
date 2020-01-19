#pragma once
#include <string>
#include <vector>
#include <algorithm>

class TreeNode;
int threeTupleMinDistance(int a[], int  b[], int  c[], int m, int n, int l);
int minMutation(std::string start, std::string end, std::vector<std::string>& bank);
int countSegments(std::string s);
int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals);
int pathSum(TreeNode* root, int sum);
std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals);
std::vector<int> findAnagrams(std::string s, std::string p);

int findKthNumber(int n, int k);

int arrangeCoins(int n);