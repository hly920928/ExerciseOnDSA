#include "mainHeader.h"
#include <unordered_map>
using namespace std;
 
 
void pathSum_re_II(TreeNode* root, int sum,int pre_sum,int&  ans, unordered_map<int, int>&table) {
    if (root == nullptr)return;
    int now_sum = pre_sum + root->val;
    auto itr = table.find(now_sum - sum);
    if (itr != table.end())ans= ans+ itr->second;
      itr = table.find(now_sum);
    if (itr == table.end())table[now_sum] = 1;
    else table[now_sum]++;
    pathSum_re_II(root->left, sum, now_sum, ans, table);
    pathSum_re_II(root->right, sum, now_sum,ans, table);
    if (table[now_sum] == 1)table.erase(now_sum);
    else table[now_sum]--;
}

int pathSum_re(TreeNode* root, int sum, bool isInvolved) {
    if (root == nullptr)return 0;
    int isThis = (root->val == sum) ? 1 : 0;
    if (isInvolved) {
        int l = pathSum_re(root->left, sum - root->val, true);
        int r= pathSum_re(root->right, sum - root->val, true);
        return l + r + isThis;
    }
    else {
        int l1 = pathSum_re(root->left, sum - root->val, true);
        int r1 = pathSum_re(root->right, sum - root->val, true);
        int l2 = pathSum_re(root->left, sum, false);
        int r2 = pathSum_re(root->right, sum, false);
        return l1 + r1 + l2 + r2 + isThis;
    }

}
int pathSum(TreeNode* root, int sum) {
    int  ans = 0;
    unordered_map<int, int> table;
    //return pathSum_re(root, sum, false);
      table[0] = 1;
      pathSum_re_II(root, sum, 0, ans, table);
      return ans;
}