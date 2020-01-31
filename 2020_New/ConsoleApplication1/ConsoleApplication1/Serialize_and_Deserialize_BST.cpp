//449. Serialize and Deserialize BST
#include "mainHeader.h"
#include <stack>
using namespace std;

union _data {
	int v;
	char s[4] ;
};
class dataBST {
public:
	_data _d;
	dataBST(int _v = INT_MIN) {
		_d.v = _v;
	}
	bool operator<(const dataBST& b)const {
		return _d.v < b._d.v;
	}
};
vector<dataBST>* _in;
vector<dataBST>* _pre;
void inorder_tra(TreeNode* root ) {
	auto& v = *_in;
	if (root == nullptr)return;
	inorder_tra(root->left);
	v.push_back(dataBST(root->val));
	inorder_tra(root->right);
}

void preorder_tra(TreeNode * root ) {
	auto& v = *_pre;
	if (root == nullptr)return;
    v.push_back(dataBST(root->val));
	preorder_tra(root->left);
	preorder_tra(root->right);
}
void vector_to_str(string& ans) {
	auto& in = *_in;
	auto& pre = *_pre;
	for (auto& d : in)
		for (int i = 0; i < 4; i++) {
			ans.push_back(d._d.s[i]);
		}
	for (auto& d : pre)
		for (int i = 0; i < 4; i++) {
			ans.push_back(d._d.s[i]);
		}
}


void str_to_vector(string& input) {
	auto& in = *_in;
	auto& pre = *_pre;
	int len = input.size(); int n = 0;
	dataBST  d;
	for (int i = 0; i < len / 2; i++) {
		if (n == 4) {
			in.push_back(d);
			n = 0;
		}
		d._d.s[n] = input[i];
		n++;
	}
	in.push_back(d);
	n = 0;
	for (int i = len / 2; i < len; i++) {
		if (n == 4) {
			pre.push_back(d);
			n = 0;
		}
		d._d.s[n] = input[i];
		n++;
	}
	pre.push_back(d);
	n = 0;
}
TreeNode* buildBST(
unsigned short in_head, unsigned short in_tail,
unsigned short pre_head, unsigned short pre_tail
	) {
	auto& in = *_in;
	auto& pre = *_pre;
	if (in_head > in_tail) {
		return nullptr;
	}
	if (pre_head > pre_tail) {
		return nullptr;
	}
	if (in_head == in_tail) {
	 return new TreeNode(in[in_head]._d.v);
	}
	auto itr = lower_bound(in.begin() + in_head, in.begin() + in_tail, pre[pre_head]);
	unsigned short root_index = itr - (in.begin() + in_head);
	unsigned short left_len = root_index - in_head;
	auto left = buildBST(
		in_head, root_index - 1,
		pre_head+1, pre_head + left_len
	);
	auto right = buildBST(
		root_index + 1, in_tail,
		pre_head + left_len+1,  pre_tail
	);
	auto ans = new TreeNode(pre[pre_head]._d.v);
	ans->left = left;
	ans->right = right;
	return ans;
}

std::string serialize_I(TreeNode* root) {
	if (root == nullptr)return "";
	vector<dataBST>  in;
	vector<dataBST>  pre;
	_in = &in;
	_pre = &pre;
	inorder_tra(root);
	preorder_tra(root);

 
	string ans;
	vector_to_str(ans);
	return ans;
}
 
TreeNode* deserialize_I(std::string data) {
	if (data == "")return nullptr;
	vector<dataBST>  in;
	vector<dataBST>  pre;
	_in = &in;
	_pre = &pre;
	str_to_vector(data);
	int len = in.size();
	return buildBST(0, len - 1,0, len - 1);
}
stack<int>* _stk;
vector<dataBST>* _post;
void vector_to_str_post(string& ans) {
	auto& in = *_post;
 
	for (auto& d : in)
		for (int i = 0; i < 4; i++) {
			ans.push_back(d._d.s[i]);
		}
	 
}

void postorder_tra(TreeNode* root) {
	auto& v = *_post;
	if (root == nullptr)return;
	postorder_tra(root->left);
	postorder_tra(root->right);
	v.push_back(dataBST(root->val));
}

void strInStack(string& input) {
	auto& in = *_stk;
 
	int len = input.size(); int n = 0;
	dataBST  d;
	for (int i = 0; i < len; i++) {
		if (n == 4) {
			in.push(d._d.v);
			n = 0;
		}
		d._d.s[n] = input[i];
		n++;
	}
	in.push(d._d.v);
	n = 0;
 

}

TreeNode* deserialize_re(int min, int max) {
	auto& stk = *_stk;
	if (stk.empty())return nullptr;
	int v = stk.top();
	if (v > max || v < min)return nullptr;
	stk.pop();
	TreeNode* root = new TreeNode(v);
	TreeNode* right = deserialize_re(v, max);
	TreeNode* left = deserialize_re(min, v);
	
	root->left = left;
	root->right = right;
	return root;
}
std::string serialize_II(TreeNode* root) {
	if (root == nullptr)return "";
	vector<dataBST>post;
	_post = &post;
	postorder_tra(root);
	string ans;
	vector_to_str_post(ans);
	return ans;
}

TreeNode* deserialize_II(std::string data) {
		if (data == "")return nullptr;
		stack<int>stk;
		_stk=&stk;
		strInStack(data);
		return deserialize_re(INT_MIN, INT_MAX);
}

std::string serialize(TreeNode* root) {
 
	return serialize_II(root);
}

TreeNode* deserialize(std::string data) {
	return deserialize_II(data);
}