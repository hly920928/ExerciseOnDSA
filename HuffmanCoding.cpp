#include "stdafx.h"
#include "HuffmanCoding.h"
#include <queue>
class ptrComper {
public:
	bool operator()(const Node<char>* a, const Node<char>* b) {
		return !(*a < *b);
	}
};
HuffmanCode::HuffmanCode(unordered_map<char, int>& f)
{
	priority_queue<Node<char>*,vector<Node<char>*>, ptrComper> pq;
	for (auto& itr:f)
		pq.push(new Node<char>(itr.first, itr.second));
	while (pq.size()>1) {
		auto a = pq.top(); pq.pop();
		auto b = pq.top(); pq.pop();
		pq.push(new Node<char>(' ', a->weight+b->weight, a, b));
	}
	HuffmanRoot = pq.top(); pq.pop();
	vector<bool> s;
	buildTable(HuffmanRoot, s);
}
vector<bool> HuffmanCode::encode(string & s)
{
	vector<bool> ans;
	for(char c:s){
		if (hashtable.find(c) == hashtable.end())continue;
		auto& code = hashtable[c];
		ans.insert(ans.end(), code.begin(), code.end());
	}
	return ans;
}
string HuffmanCode::decode(vector<bool>& s)
{
	string ans;
	auto now = HuffmanRoot;
	for (bool i : s) {
		now = (i) ? now->RChild : now->LChild;
		if (now->isLeaf()) {
			ans.push_back(now->data);
			now = HuffmanRoot;
		}
	}
	return ans;
}
void HuffmanCode::buildTable(Node<char>* now, vector<bool>& s)
{
	if (now->isLeaf()) {
		hashtable[now->data] = s; return;
	}
	s.push_back(false);
	buildTable(now->LChild, s);
	s.pop_back();
	s.push_back(true);
	buildTable(now->RChild, s);
	s.pop_back();
}


