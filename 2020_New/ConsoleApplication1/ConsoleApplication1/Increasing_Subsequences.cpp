//491. Increasing Subsequences

#include "mainHeader.h"
#include <set>
#include <bitset>

using namespace std;
vector<vector<int>> findSubsequences(vector<int>& nums) {
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
		delete[]next;
	}
	void tryInsert(int next) {};
};
void buildAnswer(treeNode* root,vector<vector<int>>& ans, vector<int>&path) {

}

vector<vector<int>> findSubsequences_II(vector<int>& nums) {
	treeNode root;

	for (int i = 0; i < nums.size(); i++)root.tryInsert(nums[i]);

	vector<vector<int>> ans; vector<int>path;
	for (auto& ptr : root.next)buildAnswer(ptr, ans, path);
	return ans;
}