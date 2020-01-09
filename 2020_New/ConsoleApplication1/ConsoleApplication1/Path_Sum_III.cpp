#include "mainHeader.h"
#include <map>
 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 

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
    return pathSum_re(root, sum, false);
}