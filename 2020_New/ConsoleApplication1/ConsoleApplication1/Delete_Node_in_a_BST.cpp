//450. Delete Node in a BST
#include "mainHeader.h"
void searchNode(TreeNode* root, int key,TreeNode*& keyNode, TreeNode*& parentNode, bool& isRightChild) {

}
void reconstructAt(TreeNode* keyNode, TreeNode* parentNode,bool isRightChild) {

}
TreeNode* deleteNode(TreeNode* root, int key) {
	TreeNode* keyNode;
	TreeNode* parentNode;
	bool isRightChild;
	searchNode(root, key, keyNode, parentNode, isRightChild);
	reconstructAt(keyNode, parentNode, isRightChild);
}