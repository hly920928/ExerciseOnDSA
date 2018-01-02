#include "stdafx.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <stack>
#include <bitset>
#include "Exce_8_25.h"
using namespace std;
struct table {
	int n;
	int* m;
	table(istream& in) {
		in >> n;
		m = new int[n*n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int t;
				in >> t;
				m[j + i*n] = t;
			}
		}
	}
	void printOut(ostream& os) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				os << m[j + i*n] << " ";
			}
			os << endl;
		}
	}
	inline int get(int x, int y) { return  m[y + x*n]; }
};
struct pathNode {
	virtual  void setTable(table*) = 0;
	virtual  void setCost(int) = 0;
	virtual  void findNext(vector<void*>& v) = 0;
	virtual  int getCost() = 0;
	virtual  bool isFinished() = 0;
	virtual  void printOut(ostream& os) = 0;
};
struct travelPath : public pathNode {
	vector<int> p;
	int cost;
	table* tb;
	travelPath() : cost(0) {
		p.push_back(0);
	}
	void setCost(int x) { cost = x; }
	void setTable(table* t)override { tb = t; }
	int getCost() override { return cost; }
	bool isFinished() {
		return p.size() == tb->n + 1;
	}
	bool tryAdd(int i) {
		int cost_t = tb->get(p.back(), i);
		bool unDup = find(p.begin(), p.end(), i) == p.end();
		if (unDup && (cost_t != -1)) {
			cost += cost_t;
			p.push_back(i);
			return true;
		}
		else { return false; }
	}
	void findNext(vector<void*>& v)override {
		if (p.size() != tb->n) {
			for (int i = 0; i < tb->n; i++) {
				travelPath neo = travelPath(*this);
				if (neo.tryAdd(i))v.push_back(new travelPath(neo));
			}
		}
		else {
			int cost = tb->get(p.back(), p[0]);
			if (cost != -1) {
				travelPath* neo = new travelPath(*this);
				neo->p.push_back(neo->p[0]);
				neo->cost += cost;
				v.push_back(neo);
			}
		}
	}
	void printOut(ostream& os) override {
		for (int i : p) {
			os << (char)(i + 'A') + " ";
		}
		os << endl;
		os << "TOTAL = " << cost << endl;
	}

};
struct workflow :public pathNode {
	vector<int> p;
	int cost;
	table* tb;
	workflow() : cost(0) {
	}
	void setTable(table* t)override { tb = t; }
	void setCost(int x) { cost = x; }
	int getCost() override { return cost; }
	bool isFinished() {
		return p.size() == tb->n;
	}

	bool tryAdd(int i) {
		int unDup = find(p.begin(), p.end(), i) == p.end();
		if (unDup) {
			cost += tb->get(i, p.size());
			p.push_back(i);
			return true;
		}
		else { return false; }
	}
	void findNext(vector<void*>& v)override {
		for (int i = 0; i < tb->n; i++) {
			workflow neo = workflow(*this);
			if (neo.tryAdd(i))v.push_back(new workflow(neo));
		}
	}
	void printOut(ostream& os) override {
		vector<int>t(p.size());
		for (int i = 0; i < p.size(); i++) {
			t[p[i]] = i;
		}
		string s;
		for (int i = 0; i < t.size(); i++) {
			s.append(to_string(i + 1));
			s.append("-");
			s.append(to_string(t[i] + 1));
			s.append(",");
		}
		s.erase(s.size() - 1, 1);
		os << s << endl;
		os << "TOTAL = " << cost << endl;
	}
};
template<class T>
void DFS_leastPath(istream& in) {
	table tb(in);
	stack<T*>stk;
	T* first = new T();
	first->setTable(&tb);
	stk.push(first);
	first = new T(); first->setCost(MAX);
	vector<void*> v;
	while (!stk.empty()) {
		T* now = stk.top(); stk.pop();
		now->findNext(v);
		for (auto pn : v) {
			T* temp = (T*)pn;
			int cost_a = temp->getCost();
			int cost_b = first->getCost();
			if (cost_a<cost_b) {
				if (temp->isFinished()) {
					first = temp;
				}
				else { stk.push(temp); }
			}
			else { delete pn; }
		}
		v.clear();
		delete now;
	}
	first->printOut(cout);
	/*
	stringstream ss;
	ss << "4" << endl;
	ss << "-1 2 5 7" << endl;
	ss << "2 -1 8 3" << endl;
	ss << "5 8 -1 1" << endl;
	ss << "7 3 1 -1" << endl;
	DFS_leastPath<travelPath>(ss);
	*/
	/*
	stringstream ss;
	ss << 4 << endl;
	ss <<"2 15 13 4" << endl;
	ss << "10 4 14 15" << endl;
	ss << "9 14 16 13" << endl;
	ss << "7 8 11 9" << endl;
	DFS_leastPath<workflow>(ss);
	return 0;
	*/
}


////binTree test Data
/* tree_input
Node<char> root('i');
Node<char> d('d');
Node<char> l('l');
Node<char> c('c');
Node<char> h('h');
Node<char> a('a');
Node<char> b('b');
Node<char> f('f');
Node<char> e('e');
Node<char> g('g');
Node<char> k('k');
Node<char> j('j');
Node<char> n('n');
Node<char> m('m');
Node<char> p('p');
Node<char> o('o');
root.insertAsLChild(&d);
root.insertAsRChild(&l);
d.insertAsLChild(&c);
d.insertAsRChild(&h);
c.insertAsLChild(&a);
a.insertAsRChild(&b);
h.insertAsLChild(&f);
f.insertAsLChild(&e);
f.insertAsRChild(&g);
l.insertAsLChild(&k);
l.insertAsRChild(&n);
k.insertAsLChild(&j);
n.insertAsLChild(&m);
n.insertAsRChild(&p);
p.insertAsLChild(&o);
*/
template <class T>
struct Node {
	T data;
	bool isLChild;
	Node* LChild;
	Node* RChild;
	Node* parent;
	Node(T d) :data(d), isLChild(false), LChild(nullptr)
		, RChild(nullptr), parent(nullptr) {}
	void insertAsLChild(Node* _LChild) {
		LChild = _LChild;
		_LChild->parent = this;
		_LChild->isLChild = true;
	}
	void insertAsRChild(Node* _RChild) {
		RChild = _RChild;
		_RChild->parent = this;
		_RChild->isLChild = false;
	}
	bool isLeaf() {
		if (!LChild && !RChild) return true;
		return false;
	}
	Node* succ() {
		Node* succ;
		if (RChild) {
			succ = RChild;
			while (succ->LChild) {
				succ = succ->LChild;
			}
		}
		else {
			succ = this;
			while (!succ->isLChild) {
				succ = succ->parent;
				while (!succ)return succ;
			}
			succ = succ->parent;
			return succ;
		}
	}
};
template <class T>
void inorder_travel_vI(Node<T>* root) {
	if (!root)return;
	inorder_travel_vI(root->LChild);
	cout << root->data << " ";
	inorder_travel_vI(root->RChild);
};

template <class T>
void printOutNode(Node<T>* v) {
	cout << v->data << " ";
};

template <class T>
void inorder_travel_vII(Node<T>* root, void(*visit)(Node<T>*)) {
	if (!root)return;
	Node<T>* now = root;
	while (now->LChild) {
		now = now->LChild;
	}
	visit(now);
	while (now->succ()) {
		now = now->succ();
		visit(now);
	}
};

template <class T>
void  gotoHLVFL(stack<Node<T>*>& S) {
	while (Node<T>* x = S.top())
	{
		if (x->LChild) {
			if (x->RChild)S.push(x->RChild);
			S.push(x->LChild);
		}
		else S.push(x->RChild);
	}
	S.pop();
};
template <class T>
void post_travel_I(Node<T>* root, void(*visit)(Node<T>*)) {
	stack<Node<T>* > S;
	if (root)S.push(root);
	while (!S.empty()) {
		gotoHLVFL(S);
		while (true) {
			Node<T>* x = S.top(); S.pop();
			visit(x);
			if (S.empty()||x->parent != S.top())break;
		}
	}
};

TSP::TSP(int _n)
{
	n = _n;
	min = INT_MAX;
	now = 0;
	for (int i = 0; i <= n; i++) {
		isTraveled[i] = false;
		for (int j = 0; j <= n; j++)
			scanf("%d",&table[i][j]);
	}
}

void TSP::DFS()
{
	floyd();
	isTraveled[0] = true;
	tryAfter(0, 0);
	printf("%d\n", min);
}
void TSP::tryAfter_v2(int _n) {
	if (min < now)return;
	if (_n == n+1) {
		if (min > now) {
			min = now;
			v_min = v_now;
		}
		return;
	}
	for (int i = 0; i < n+1; i++) {
		if (isTraveled[i]) continue;
		isTraveled[i] = true;
		now += table[_n][i];
		v_now.push_back(i);
		tryAfter_v2(_n + 1);
		v_now.pop_back();
		now -= table[_n][i];
		isTraveled[i] = false;
	}
}
void TSP::DFS_v2()
{
	tryAfter_v2(0);
	int n = 1;
	for (int i : v_min) {
		printf("%d-%d,", n, i+1); n++;
	}
	printf("\n");
	printf("Total %d\n", min);
}

void TSP::tryAfter(int pre, int f)
{
	if (now > min)return;
	if (f == n) {
		int t = now + table[pre][0];
		if (t < min)min = t;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!isTraveled[i]) {
			isTraveled[i] = true;
			now += table[pre][i];
			tryAfter(i, f + 1);
			isTraveled[i] = false;
			now -= table[pre][i];
		}
	}
}
void TSP::DP()
{
	floyd();
	int n_stage =(1 << (n + 1))-1;
	for (int i = 1; i <=n_stage; i++)
		for (int j = 0; j < n+1; j++)
			dp[i][j] =-1;
	dp[1][0] = 0;
	bitset<16> bs;
	for (int i = 1; i <= n_stage; i++) {
		bs = i;
		if (!bs[0])continue;
		bitset<16> bs1;
		for (int j = 1; j < n + 1; j++) {
			if (!bs[j])continue;
			int stage_reduced = i - (1 << j);
			bs1 = stage_reduced;
			for (int k = 0; k < n + 1; k++)
				if (bs1[k]) {
					if (dp[stage_reduced][k] == -1)continue;
					int t = dp[stage_reduced][k] + table[k][j];
					dp[i][j] =(dp[i][j]!=-1&&(dp[i][j] < t)) ? dp[i][j] : t;
				}
		}
	}
		
	int ans = INT_MAX;
	for (int i = 1; i < n + 1; i++) {
		int t =(dp[n_stage][i]!=-1)? dp[n_stage][i] + table[i][0]: INT_MAX;
		ans = (ans < t) ? ans : t;
	}
	printf("%d\n", ans);
}
void TSP::floyd() {
	for (int k = 0; k <= n; k++) 
		for (int i = 0; i<= n; i++)
			for (int j = 0; j <= n; j++) {
				int t = table[i][k] + table[k][j];
				if (table[i][j] > t)table[i][j] = t;
			}
}

