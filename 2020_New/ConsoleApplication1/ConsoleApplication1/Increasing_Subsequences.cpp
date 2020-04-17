//491. Increasing Subsequences

#include "mainHeader.h"
#include <set>
#include <bitset>

using namespace std;
class treeNode {
public:
	int val;
	int nextLen;
	treeNode* next[20];
	treeNode(int v = INT_MAX) :val(v) {
		nextLen = 0;
		for (auto& ptr : next)ptr = nullptr;
	};
	~treeNode() {
		for (auto& ptr : next)delete ptr;
	}
	void tryInsert(int next_val) {
		bool flag = true;
		for (int i = 0; i < nextLen; i++) {
			if (next[i]->val == next_val) {
				flag = false;
				break;
			}
		}
		int old_len = nextLen;
		if (flag) {
			next[nextLen] = new treeNode(next_val);
			nextLen++;
		}
		for (int i = 0; i < old_len; i++) {
			if (next[i]->val <= next_val) {
				next[i]->tryInsert(next_val);
			}
		}

	};
};
void buildAnswer(treeNode* root, vector<vector<int>>& ans, vector<int>& path) {
	if (root == nullptr)return;
	path.push_back(root->val);
	if (path.size() >= 2)ans.push_back(path);
	for (int i = 0; i < root->nextLen; i++) {
		buildAnswer(root->next[i], ans, path);
	}
	path.pop_back();

}

vector<vector<int>> findSubsequences(vector<int>& nums) {
	treeNode root;

	for (int i = 0; i < nums.size(); i++) {
		root.tryInsert(nums[i]);
	}

	vector<vector<int>> ans; vector<int>path;
	for (auto& ptr : root.next)buildAnswer(ptr, ans, path);
	return ans;
}

vector<vector<int>> findSubsequences_t(vector<int>& nums) {
	set<vector<int>>table[20];
	set<vector<int>> temp;
	for (int i = 0; i < nums.size(); i++) {
 
		for (int j = 1; j <=15; j++) {
			auto& now_set = table[j];
			auto& next_set = table[j+1];
			for (auto& v : now_set) {
		 
				if (v[v.size() - 1] <= nums[i]) {
					vector<int> neo = v;
					neo.push_back(nums[i]);
					auto itr = next_set.find(neo);
					if(itr==next_set.end())temp.insert(neo);
				}
			}
		
	   }
		table[1].insert(vector<int>({ nums[i] }));
		for (auto& v : temp) {
			int len = v.size();
			table[len].insert(v);
		}


		temp.clear();
	}
	 
	vector<vector<int>> ans;
	for (int i =2; i <=15; i++) {
		for (auto& v : table[i])ans.push_back(v);
	}
	return ans;
}

