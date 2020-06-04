//LeetCode 501. Find Mode in Binary Search Tree
#include "mainHeader.h"

using namespace std;

void findMode_re(TreeNode* root, vector<int>& ans, int& count, int& maxCount, int& pre) {
	if (root == nullptr)return;
	if (root->left == nullptr && root->right == nullptr) {
		if (count == 0 || root->val != pre) {
			pre = root->val;
			count = 1;
		}
		else if (root->val == pre) {
			count++;
		}
		if (count == maxCount) {
			ans.push_back(root->val);
		}
		else if (count > maxCount) {
			ans.clear();
			ans.push_back(root->val);
		}
		maxCount = max(maxCount, count);
		return;
	}
	findMode_re(root->left, ans, count, maxCount, pre);
	//
	if (count == 0 || root->val != pre) {
		pre = root->val;
		count = 1;
	}
	else if (root->val == pre) {
		count++;
	}
	if (count == maxCount) {
		ans.push_back(root->val);
	}
	else if (count > maxCount) {
		ans.clear();
		ans.push_back(root->val);
	}
	maxCount = max(maxCount, count);
	//
	findMode_re(root->right, ans, count, maxCount, pre);
}

vector<int> findMode(TreeNode* root) {
	vector<int> ans;
	int count=0;
	int maxCount = 0;
	int pre = -1;

	findMode_re(root, ans, count, maxCount, pre);
	return ans;
}