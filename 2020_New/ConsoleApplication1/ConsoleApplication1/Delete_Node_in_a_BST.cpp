//450. Delete Node in a BST
#include "mainHeader.h"
void searchNode(TreeNode* root, int key,TreeNode*& keyNode, TreeNode** parentNodeLink,bool& isMax,bool& isMin) {
	if (root == nullptr)return;
	if (root->val == key) {
		keyNode = root;//special case root
		return;
	}
	if (root->left->val == key) {
		keyNode = root->left ;
		parentNodeLink=&root->left;
		return;
	}
	if (root->right->val == key) {
		keyNode = root->right;
		parentNodeLink = &root->left;
		return;
	}
	if (root->val < key) {
		isMin = false;
		searchNode(root->left, key, keyNode, parentNodeLink, isMax, isMin);
		return;
	}
	if (root->val >key) {
		isMax= false;
		searchNode(root->right, key, keyNode, parentNodeLink, isMax, isMin);
		return;
	}
	return;
}
void findNext(TreeNode* keyNode, TreeNode*& nextNode) {


}
void reconstructAt(TreeNode* keyNode, TreeNode** parentNodeLink, TreeNode*  nextNode) {

}

TreeNode* deleteNode(TreeNode* root, int key) {
	TreeNode* keyNode = nullptr;
	TreeNode**  parentNodeLink=nullptr;

	bool isMax = true; bool isMin = true;

	TreeNode* nextNode;
 
	searchNode(root, key, keyNode, parentNodeLink);
	if (keyNode == nullptr)return nullptr;
	findNext(keyNode, nextNode);
	reconstructAt(keyNode, parentNodeLink, nextNode);
}