//450. Delete Node in a BST
#include "mainHeader.h"
void searchNode(TreeNode* root, int key,TreeNode*& keyNode, TreeNode**& parentNodeLink,bool& isMax,bool& isMin) {
	if (root == nullptr) {
		keyNode = nullptr;
		return;
	}
	if (root->val == key) {
		keyNode = root;//special case root
		return;
	}
	if (root->right != nullptr && root->right == nullptr) {
		keyNode = nullptr;
		return;
	}
	if (root->left !=nullptr&&root->left->val == key) {
		isMax = false;
		keyNode = root->left ;
		parentNodeLink=&root->left;
		return;
	}
	if (root->right != nullptr && root->right->val == key) {
		isMin = false;
		keyNode = root->right;
		parentNodeLink = &root->right;
		return;
	}
	if (root->val < key) {
		isMin = false;
		searchNode(root->right, key, keyNode, parentNodeLink, isMax, isMin);
		return;
	}
	if (root->val >key) {
		isMax= false;
		searchNode(root->left, key, keyNode, parentNodeLink, isMax, isMin);
		return;
	}
	keyNode = nullptr;
	return ;
}
void findNextAndRemove(TreeNode* keyNode, TreeNode*& nextNode) {
	if (keyNode->right == nullptr) {
		nextNode = nullptr;
		return;
	}
	TreeNode* now = keyNode->right;
	TreeNode* parent = keyNode;
	if (now->left == nullptr) {
		nextNode = now;
		parent->right = now->right;
		return;
	}
	while(now->left != nullptr) {
		parent = now;
		now = now->left;

	}
	nextNode= now;
	parent->left = now->right;
 }
 

TreeNode* deleteNode(TreeNode* root, int key) {
	if (root == nullptr)return nullptr;
	TreeNode* keyNode = nullptr;
	TreeNode** parentNodeLink = nullptr;

	bool isMax = true; bool isMin = true;

	TreeNode* nextNode;
	if (root->val == key) {
		if (root->left == nullptr && root->right == nullptr)return nullptr;
		if (root->left == nullptr)return root->right;
		if (root->right == nullptr)return root->left;
		findNextAndRemove(root, nextNode);
		root->val = nextNode->val;
		return root;
	}

 
	searchNode(root, key, keyNode, parentNodeLink, isMax, isMin);
	if (keyNode == nullptr)return root;
	if (isMax) {
		*parentNodeLink = keyNode->left;
		return root;
	}
	if (keyNode->right == nullptr) {
		*parentNodeLink = keyNode->left;
		return root;
	}
	findNextAndRemove(keyNode, nextNode);
	if (nextNode != nullptr)keyNode->val = nextNode->val;
	else *parentNodeLink = nullptr;
	return root;
}