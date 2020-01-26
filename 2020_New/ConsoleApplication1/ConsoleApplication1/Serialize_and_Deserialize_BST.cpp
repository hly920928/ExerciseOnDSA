//449. Serialize and Deserialize BST
#include "mainHeader.h"
using namespace std;

union dataBST {
	int v;
	char s[4] ;
};
void inorder_tra(TreeNode* root, vector<dataBST>& v) {


}

void preorder_tra(TreeNode * root, vector<dataBST>& v) {

}
void vector_to_str(string& ans, vector<dataBST>& in, vector<dataBST>& pre) {


}
void str_to_vector(string& input, vector<dataBST>& in, vector<dataBST>& pre) {


}
TreeNode* buildBST(
	vector<dataBST>& in, int in_head,int in_tail,
	vector<dataBST>& pre, int pre_head, int pre_tail
	) {

}
std::string serialize(TreeNode* root) {
	vector<dataBST>  in;
	vector<dataBST>  pre;
	inorder_tra(root, in);
	preorder_tra(root, pre);
	string ans;
	vector_to_str(ans, in, pre);
	return ans;
}

TreeNode* deserialize(std::string data) {
	vector<dataBST>  in;
	vector<dataBST>  pre;
	str_to_vector(data, in, pre);
	int len = in.size();
	return buildBST(in, 0, len - 1, pre, 0, len - 1);
}