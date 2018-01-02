#include "stdafx.h"
#include <iostream>  <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include "Exce_8_21.h"
using namespace  std;
int all_Diamond(std::ostream& os);
bool isfeasible(vector<int>& v, int now, int i);
/// nQueen 
struct chessBoard {
	int numOfQueen;
	bool* board;
	int num;
	chessBoard(int n) {

		numOfQueen = 0;
		num = n;
		board = new bool[num*num];
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				board[j + num*i] = false;
			}
		}
	}
	~chessBoard() {
		delete[] board;
	}
	chessBoard(const chessBoard& b) {
		numOfQueen = b.numOfQueen;
		num = b.num;
		board = new bool[num*num];
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				board[j + num*i] = b.board[j + num*i];
			}
		}
	}
	void  placeQueenAt(int x, int y) {
		board[y + x*num] = true;
		numOfQueen++;
	}
	bool isFeasible(const int x, const int y)const {
		for (int i = 0; i < num; i++) {
			if (board[y + i*num]) { return false; }
		}
		for (int j = 0; j < num; j++) {
			if (board[j + x*num]) { return false; }
		}
		//1
		int _x = x;
		int _y = y;
		while ((_x < num) && (_y < num)) {
			if (board[_y + _x*num]) { return false; }
			_x++; _y++;
		}
		//2
		_x = x;
		_y = y;
		while ((_x >= 0) && (_y >= 0)) {
			if (board[_y + _x*num]) { return false; }
			_x--; _y--;
		}
		//3
		_x = x;
		_y = y;
		while ((_x <num) && (_y >= 0)) {
			if (board[_y + _x*num]) { return false; }
			_x++; _y--;
		}
		//4
		_x = x;
		_y = y;
		while ((_x >= 0) && (_y <num)) {
			if (board[_y + _x*num]) { return false; }
			_x--; _y++;
		}
		return true;
	}
	void printBoard(ostream& os)const {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				os << board[j + num*i] << " ";
			}
			os << endl;
		}
	}
};
int nQueen(int n) {
	int ans = 0;
	stack<chessBoard*> stk;
	chessBoard * first = new chessBoard(n);
	stk.push(first);
	while (!stk.empty()) {
		chessBoard * now = stk.top();
		stk.pop();
		for (int j = 0; j < n; j++) {
			if (now->isFeasible(now->numOfQueen, j)) {
				chessBoard * next = new chessBoard(*now);
				next->placeQueenAt(now->numOfQueen, j);
				if (next->numOfQueen == n) {
					ans++;
					delete next;
				}
				else { stk.push(next); }
			}
		}
		delete now;
	}
	return ans;
}
///Diamond BFS
class DiamondBoard {
public:
	string bd;
	int size;
	DiamondBoard() :bd("........"), size(0) {};
	DiamondBoard(const DiamondBoard& b) {
		bd = b.bd;
		size = b.size;
	}
	void push(int i) {
		bd[size] = i + '0';
		size++;
	}
	void printOut(ostream& os) {
		os << " " << bd[0] << " " << endl;
		os << bd[1] << bd[2] << bd[3] << endl;
		os << bd[4] << bd[5] << bd[6] << endl;
		os << " " << bd[7] << " " << endl;
	}
	inline bool isFeasible(int i) {
		return isFeasible(size, i);
	}
	bool isFeasible(int n, int i) {
		int pos = bd.find(i + '0');
		if (pos < bd.size()) { return false; }
		switch (n)
		{
		case 0:
			return isOK(i, "123");
		case 1:
			return isOK(i, "0245");
		case 2:
			return isOK(i, "013456");
		case 3:
			return isOK(i, "0256");
		case 4:
			return isOK(i, "1257");
		case 5:
			return isOK(i, "123467");
		case 6:
			return isOK(i, "2357");
		case 7:
			return isOK(i, "456");
		}
	}
	inline bool isOK(int i, int j) {
		return abs(i - j) > 1;
	}
	bool isOK(int i, string s) {
		for (char c : s) {
			if (!isOK(i, bd[c - '0'] - '0')) {
				return false;
			}
		}
		return true;
	};
};
int allDiamond() {
	int ans = 0;
	queue<DiamondBoard*>q;
	DiamondBoard* first = new DiamondBoard();
	q.push(first);
	while (!q.empty()) {
		DiamondBoard* now = q.front();
		q.pop();
		for (int i = 1; i < 9; i++) {
			if (now->isFeasible(i)) {
				DiamondBoard* neo = new DiamondBoard(*now);
				neo->push(i);
				if (neo->size == 8) {
					ans++;
					cout << "case " << ans << endl;
					neo->printOut(cout);
				}
				else { q.push(neo); }
			}
		};
		delete now;
	}
	return ans;
}
bool isfeasible(vector<int>& v, int now, int i) {
	for (int t : v)if (t == i)return false;
	string checklist;
	switch (now)
	{
	case 0:checklist = "123"; break;
	case 1:checklist = "0245"; break;
	case 2:checklist = "013456"; break;
	case 3:checklist = "0256"; break;
	case 4:checklist = "1257"; break;
	case 5:checklist = "123467"; break;
	case 6:checklist = "2357"; break;
	case 7:checklist = "456"; break;
	}
	for (char c : checklist)
		if (abs(v[c - '0'] - i) <= 1)return false;
	return true;
}
void inline printDia(vector<int>& v, ostream& os,int& n) {
	n++;
	os << n << endl;
	os << ' ' << v[0] << ' ' << endl;
	os << v[1] << v[2] << v[3] << endl;
	os << v[4] << v[5] << v[6] << endl;
	os << ' ' << v[7] << ' ' << endl;
}
void allDia(vector<int>& v, int now, ostream& os,int& n) {
	if (now ==8) { printDia(v, os,n); return; }
	for (int i = 1; i <= 8; i++) {
		if (isfeasible(v, now, i)) {
			v[now] = i;
			allDia(v, now + 1, os,n);
			v[now] = -1;}
	}
}
int all_Diamond(std::ostream& os)
{
	int n=0;
	vector<int>v; v.resize(8);
	for (int& i : v)i = -1;
	allDia(v, 0, os,n);
	return n;
};


///OctBoard BFS
void printOutBoard(const string& board, ostream& os) {
	os << board[0] << board[1] << board[2] << endl;
	os << board[3] << board[4] << board[5] << endl;
	os << board[6] << board[7] << board[8] << endl;
}
struct octBoard {
	string board;
	string path;
	octBoard() :board("........"), path("") {};
	octBoard(string _b) :path("") {
		board = "........";
		string temp = _b;
		sort(temp.begin(), temp.end());
		if (temp != "012345678") {
			cout << "Error Input" << endl;
		}
		else { board = _b; };
	};
	octBoard(const octBoard&_b) :board(_b.board), path(_b.path) {};
	void printOut(ostream& os)const {
		printOutBoard(board, os);
	}
	void toNext(int zero_id, int replace_id) {
		swap(board[zero_id], board[replace_id]);
		path.push_back(replace_id + '0');
	}
	void productNext(vector<octBoard*>& nexts) {
		int p = board.find("0");
		switch (p) {
		case 0:
			productNext(nexts, "13", p);
			return;
		case 1:
			productNext(nexts, "024", p);
			return;
		case 2:
			productNext(nexts, "15", p);
			return;
		case 3:
			productNext(nexts, "046", p);
			return;
		case 4:
			productNext(nexts, "1357", p);
			return;
		case 5:
			productNext(nexts, "248", p);
			return;
		case 6:
			productNext(nexts, "37", p);
			return;
		case 7:
			productNext(nexts, "468", p);
			return;
		case 8:
			productNext(nexts, "57", p);
			return;
		}
	}
	void productNext(vector<octBoard*>& nexts, string s, int zeroPos) {
		for (char t : s) {
			octBoard* neo = new octBoard(*this);
			neo->toNext(zeroPos, t - '0');
			nexts.push_back(neo);
		}
	}
};
void printOutPath(string firstBoard, string path) {
	int i = 0;
	cout << "State " << i << endl;
	printOutBoard(firstBoard, cout);
	int zeroPos = firstBoard.find("0");
	for (char t : path) {
		i++;
		int replacePos = t - '0';
		swap(firstBoard[zeroPos], firstBoard[replacePos]);
		zeroPos = replacePos;
		cout << "State " << i << endl;
		printOutBoard(firstBoard, cout);
	}
}
void trySolveOctBoard(const string& sou, const string& des) {
	octBoard* first = new octBoard(sou);
	queue<octBoard*> q;
	unordered_map<string, bool>map;
	map.insert({ sou,true });
	q.push(first);
	vector<octBoard*> nexts;
	bool hasAnswer = false;
	while (!q.empty()) {
		octBoard* now = q.front();
		q.pop();
		now->productNext(nexts);
		for (auto t : nexts) {
			if (t->board == des) {
				cout << "Has answer" << endl;
				printOutPath(sou, t->path);
				hasAnswer = true;
				break;
			}
			else {
				auto itr = map.find(t->board);
				if (itr == map.end()) {
					map.insert({ t->board ,true });
					q.push(t);
				}
			}
		}
		delete now;
		if (hasAnswer) { break; }
		nexts.clear();
	}
	if (!hasAnswer) { cout << "answer unfound" << endl; }
	while (!q.empty()) {
		octBoard* now = q.front();
		q.pop();
		delete now;
	}
	for (auto t : nexts) {
		delete t;
	}

}

///OctBoard simpfilied
void myItoA(int t, char* table) {
	if (t < 100000000) {
		table[0] = '0';
		_itoa(t, table+1, 10);
	}else _itoa(t, table, 10);
}
int heurt(const char* a, const char*target) {
	int n=0;
	for (int i = 0; i < 9; i++) 
		if (a[i] != target[i])n++;
	return n-1;
}
struct board_min {
	int now;
	int d; int h;
	board_min(int t=-1):now(t),d(0),h(INT_MAX){
	}
	
	void addNext(board_min* con,const char* t)const {
		char table[10];myItoA(now, table);
		int posZero = -1;
		for (int i = 0; i < 9; i++) 
			if (table[i] == '0')posZero = i;
		tryNext(con,posZero, posZero + 1, table,  t);
		tryNext(con+1, posZero, posZero - 1, table,  t);
		tryNext(con+2, posZero, posZero +3, table,  t);
		tryNext(con+3, posZero, posZero-3, table,  t);
	}

	void tryNext(board_min* con, int posZero, int now_posZero,
		const char* pre, const char* t) const{
		if (now_posZero >= 0 && now_posZero < 9) {
			char now[10]; copy(pre, pre + 10, now);
			swap(now[posZero], now[now_posZero]);
			con->now = atoi(now);
			con->d = this->d+1;
			con->h = heurt(now, t);
		}else con->now = -1;
	}
};
void printBoard(int now) {
	int t = now;
	char table[10];
	myItoA(t, table);
	cout << table[0] << table[1] << table[2] << endl;
	cout << table[3] << table[4] << table[5] << endl;
	cout << table[6] << table[7] << table[8] << endl;
}
bool operator <(const board_min& a,const board_min& b) {
	return (a.d + a.h) > (b.d + b.h);
}
void solveBoard(int init, int target) {
	priority_queue<board_min> q;
	q.push(board_min(init));
	unordered_map<int, int> map;
	char table_target[10]; myItoA(target, table_target);
	map[init] = -1;
	int last = -1;
	board_min con[4];
	while (!q.empty()) {
		auto cur = q.top(); q.pop();
		cur.addNext(con, table_target);
		for (const auto& t : con) {
			if (t.now == target) { last = cur.now; break; };
			if (t.now == -1)continue;
			if (map.find(t.now) != map.end())continue;
			map[t.now] = cur.now;
			q.push(t);
		}
		if (last != -1)break;
	}
	if (last == -1) {
		cout << "Answer Unfound" << endl;return;}
	stack<int> stk; stk.push(target);
	while (last!=-1) {
		stk.push(last); last = map[last];
	}
	int n = 0;
	while (!stk.empty()) {
		cout << n << endl; n++;
		printBoard(stk.top());stk.pop();
	}
}