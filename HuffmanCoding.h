#pragma once
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
template<typename T>
class Node {
public:
	Node* parent;
	Node* LChild;
	Node* RChild;
	T data;
	int weight;
	Node(T d,int w,Node* L = nullptr, Node* R = nullptr)
		:data(d),weight(w), LChild(L), RChild(R)
	{
		if(L)L->parent = this;
		if(R)R->parent = this;
	}
	~Node() {
		delete LChild; delete RChild;
	}
	bool operator <(const Node& b)const {
		return weight < b.weight;
	}
	bool isLeaf()const {
		if (!LChild && !RChild )return true;
		return false;
	}
};


class HuffmanCode {
private:
	Node<char>* HuffmanRoot;
	unordered_map<char, vector<bool>> hashtable;
public:
	HuffmanCode(unordered_map<char, int>& f);
	~HuffmanCode() {
		delete HuffmanRoot;
	}
	vector<bool> encode(string& s);
	string decode(vector<bool>& s);
private:
	void buildTable(Node<char>*now,vector<bool>& s);

};