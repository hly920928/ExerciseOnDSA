#pragma once
#include "stdafx.h"
#include <iostream> 
#include <fstream>
#include <sstream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include "Exce_8_19.h"
using namespace  std;
 namespace {
	bool isPrime(int n) {
		if (n % 2 == 0) { return false; }
		if (n == 3) { return true; }
		for (int i = 3; i < n; i += 2) {
			if (n%i == 0) { return false; }
		}
		return true;
	};
	void print_vector(vector<int>& v) {
		for (int t : v) {
			cout << t << " ";
		}
		cout << endl;
	}
	void printOut(int num) {
		queue<vector<int>*> q;
		vector<int>* now = new vector<int>();
		q.push(now);
		while (!q.empty()) {
			vector<int>* top = q.front();
			q.pop();
			for (int i = 1; i <= num; i++) {
				if (top->size() != 0) {
					auto itr = find(top->begin(), top->end(), i);
					if (itr != top->end()) { continue; }
					if (!isPrime(i + top->back())) { continue; }
				}
				vector<int>* neo = new vector<int>(*top);
				neo->push_back(i);
				if (neo->size() == num) {
					if (isPrime(neo->front() + neo->back())) {
						print_vector(*neo);
					}
					else { delete neo; }
				}
				else { q.push(neo); }
			}
			//cout << "Looping"<<q.size()<< endl;
			delete top;
		}
	}
	bool larger(int a, int b) {
		return a > b;
	}
	bool smaller(int a, int b) {
		return a < b;
	}
	void generateTable(vector<bool>& table, int n) {
		table.resize(n+1);
		for (int i = 0; i <=n; i++)table[i] = 1;
		table[0] = 0; table[1] = 0; table[2] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= n; j++) {
				if (i*j > n)break;
				table[i*j] = 0;
			}
		}
	}
	bool isPlausible(vector<bool>& table,vector <int>& v, int next) {
		if (v.size() == 0)return true;
		for (int n : v) if (n == next)return false;
		if (!table[*(v.end() - 1) + next])return false;
     	return true;
	}
	void printOutAllCircle(vector <int>& v) {
		//static int num = 1;
		int n = v.size();
		for (int start = 0; start < n; start++) {
			//cout << num << endl; num++;
			for (int shift = 0; shift < n; shift++)
				cout << v[(start + shift) % n] << " ";
			cout << endl;}
	}
	void allPermutation(vector<bool>& table, vector <int>& v,int n) {
		if (v.size() == n) {
			if (!table[*v.begin() + *(v.end() - 1)])return;
			printOutAllCircle(v);}
		for (int i = 1; i <= n; i++) {
			if (isPlausible(table, v, i)) {
				v.push_back(i);
				allPermutation(table, v, n);
				v.pop_back();
			}
		}
	}
}
 void geneAllPermutation(int n) {
	 vector<bool> table;
	 generateTable(table, n+n-1);
	 vector<int> v; v.push_back(1);
	 allPermutation(table, v, n);
 }

 
class StoneMerger_GD{
private:
	vector<int> input;
public:
	StoneMerger_GD(istream& in) {
		int n;
		in >> n;
		for (int i = 0; i < n; i++) {
			int size;
			in >> size;
			input.push_back(size);
		}
	}
	void output() {
		ofstream fs("OUTPUT.TXT");
		merger(0, fs);
		fs << "OK" << endl;
		merger(1, fs);
		fs.close();
	}
	void merger(bool max, ostream& os) {
		vector<int> temp(input);

		int point = 0;
		while (temp.size() != 1) {
			int pos = findPos(temp, max);
			int next = (pos + 1) % temp.size();
			int top = temp[pos] + temp[next];
			if (temp[pos] < temp[next]) {
				os << temp[pos] << " " << temp[next] << endl;
			}
			else {
				os << temp[next] << " " << temp[pos] << endl;
			};
			point += top;
			temp[pos] = top;
			copy(temp.begin() + next + 1, temp.end(), temp.begin() + next);
			temp.resize(temp.size() - 1);
		}
		os << point << endl;
	}
private:
	
	int findPos(const vector<int>& v, bool max) {
		bool(*comparer)(int, int) = max ? larger : smaller;
		int pos = 0;
		int next = (pos + 1) % v.size();
		int top = v[pos] + v[next];
		for (int i = 0; i < v.size(); i++) {
			next = (i + 1) % v.size();
			int cur = v[i] + v[next];
			if (comparer(cur, top)) {
				top = cur;
				pos = i;
			}
		}
		return pos;
	}
};
struct TrieNode {
	bool isExist;
	TrieNode* next;
	TrieNode() :isExist(false), next(nullptr) {};
	~TrieNode() {
		if (next) {
			delete[] next;
		}
	}
};
class Trie {
private:
	TrieNode* root;
public:
	Trie() {
		root = new TrieNode();
		root->next = new TrieNode[26]();
	}
	~Trie() { delete root; }
	void insert(string s) {
		if (s.size() == 0) { return; }
		TrieNode* now = root->next + s[0] - 'a';
		for (int i = 1; i < s.size(); i++) {
			if (!now->next) { now->next = new TrieNode[26](); }
			now = now->next + s[i] - 'a';
		}
		now->isExist = true;
	}
	bool find(string s) {
		TrieNode* now = root->next + s[0] - 'a';
		for (int i = 1; i < s.size(); i++) {
			if (!now->next) { return false; }
			now = now->next + s[i] - 'a';
		}
		return now->isExist;
	}
};
class stoneState;
template<class T>
class _pComp {
public:
	bool operator()(const T* a, const T* b) const {
		return  *a>*b;
	}
};
struct stoneState {
	vector<int> list;
	string path;
	int cost;
	stoneState(const vector<int>& v) :list(v), path(""), cost(0) {};
	bool operator>(const stoneState& b)const {
		if (list.size() != b.list.size()) {
			return list.size()> b.list.size();
		}
		for (int i = 0; i < list.size(); i++) {
			if (list[i] != b.list[i]) {
				return list[i]>b.list[i];
			}
		};
		return false;
	}
	int mergeAt(int i, int cost_above) {
		return mergeStone(*this, i, cost_above);
	}
	int size() { return list.size(); }
	int mergeStone(stoneState& ss, int i, int cost_above) {

		auto& v = ss.list;
		auto& p = ss.path;
		int cost = 0;
		int a = 0;
		int b = 0;
		if (i != v.size() - 1) {
			a = v[i];
			b = v[i + 1];
			if (a> b) { swap(a, b); }
			p.append(to_string(a));
			p.append(" ");
			p.append(to_string(b));
			p.append(" ");
			v[i] = v[i] + v[i + 1];
			cost = v[i];
			v.erase(v.begin() + i + 1);
		}
		else {
			a = v[0];
			b = *(v.end() - 1);
			if (a> b)swap(a, b);
			p.append(to_string(a));
			p.append(" ");
			p.append(to_string(b));
			p.append(" ");
			v[0] = v[0] + v[i];
			cost = v[0];
			v.erase(v.end() - 1);
		}
		//cout << "Do merge ";
		//ss.printOut();
		ss.cost = cost + cost_above;
		return ss.cost;
	}
	void printPath(ostream& os) {
		path.erase(path.end() - 1);
		stringstream ss;
		ss << path;
		int a = 0;
		int b = 0;
		while (!ss.eof()) {
			ss >> a >> b;
			os << a << " " << b << endl;
		}
	}

};

class StoneMerger_DP {
private:
	int n;
	vector<int> input;
public:
	StoneMerger_DP() {};
	StoneMerger_DP(istream& in) {
		int n;
		in >> n;
		for (int i = 0; i < n; i++) {
			int size;
			in >> size;
			input.push_back(size);
		}
	}
	int solve(ostream& os, bool max) {

		queue<stoneState*>q;
		set<stoneState*, _pComp<stoneState>> set;
		auto first = new stoneState(input);
		q.push(first);
		set.insert(first);
		while (true) {
			auto now = q.front(); q.pop();
			if (now->size() == 1 && q.empty()) {
				now->printPath(os);
				os << "Cost is " << now->cost << endl;
				return now->cost;
			}
			for (int i = 0; i < now->size(); i++) {
				auto temp(*now);
				int cost = temp.mergeAt(i, now->cost);
				auto itr = set.find(&temp);
				if (itr != set.end()) {
					if (!max) { if ((*itr)->cost > cost)(*itr)->cost = cost; }
					else { if ((*itr)->cost <cost)(*itr)->cost = cost; }
				}
				else {
					auto t = new auto(temp);
					set.insert(t);
					q.push(t);
				}
			}
			set.erase(now);
			delete now;
		}
	}
};

StoneMerger_simplified::StoneMerger_simplified(istream & is)
{
	is >> n;
	for (int i = 0; i < n; i++) {
		int t = 0; is >> t;
		data.push_back(t);
	}
	point.resize(n);
	sum_table.resize(n);
	for (int i = 0; i < n; i++) {
		point[i].resize(n);
		sum_table[i].resize(n);
		for (int j = 0; j < n; j++) 
			sum_table[i][j] = INT_MIN;
	}
}
void StoneMerger_simplified::printOut(ostream & os)
{
	stack<string> sque;
	int min = solve('L', sque);
	os << min << endl;
	while (!sque.empty()) { os << sque.top() << endl, sque.pop(); }
	os << endl;
	int max = solve('M', sque);
	os << max << endl;
	while (!sque.empty()) { os << sque.top() << endl, sque.pop(); }
}
int StoneMerger_simplified::solve(char c, stack<string>& sque)
{
	for (int l=2;l<=n; l++) 
			for (int i = 0; i < n; i++)
			solvepoint(i, (i + l) % n, c);
	int m = (c == 'L') ? INT_MAX : INT_MIN;
	int p = 0;
	for (int i = 0; i < n; i++) {
		if ((c == 'L'&&m > point[i][i].n)
			|| (c != 'L'&&m < point[i][i].n))
		{m = point[i][i].n; p = i;}
	}
	pushDown(p, point[p][p].p, p, sque);
	return m;
}
void StoneMerger_simplified::solvepoint(int l, int h, char c)
{
	int m = (c == 'L') ? INT_MAX : INT_MIN;
	int now = (l + 1) % n;
	int p = now;
	while (now != h) {
		int t = point[l][now].n + point[now][h].n;
		if ((c == 'L'&&m > t)
			||(c != 'L'&&m < t))
		{ m = t; p = now; }
		now = (now + 1) % n;
	}
	int current = m + sum(l, h);
	point[l][h].n = current;
	point[l][h].p = p;
}
void StoneMerger_simplified::pushDown(int l, int p, int h,stack<string>& sque) {
	stringstream now;
	int a = sum(l, p);int b = sum(p, h);
	if(a<b)now << a<< ' ' << b;
	else now <<b << ' ' << a;
	sque.push(now.str());
	if (point[l][p].p!=-1)pushDown(l, point[l][p].p, p, sque);
	if (point[p][h].p != -1)pushDown(p, point[p][h].p, h, sque);
}

int StoneMerger_simplified::sum(int l, int h)
{
	if (sum_table[l][h] != INT_MIN)return sum_table[l][h];
	int sum = data[l];
	int now =(l + 1)%n;
	while (now != h) {
		sum += data[now];
		now = (now + 1) % n;
	}
	sum_table[l][h] = sum;
		return sum;
}
