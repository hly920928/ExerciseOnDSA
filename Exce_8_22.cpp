#include "stdafx.h"
#include <iostream> 
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
#include "Exce_8_22.h"
using namespace  std;
class board {
public:
	bool* b;
	int n;
public:
	board(istream& in) {
		in >> n;
		b = new bool[(n + 2)*(n + 2)];
		for (int i = 0; i <(n + 2)*(n + 2); i++) {
			b[i] = false;
		}
		int head = 0 + n + 1 + 1;
		for (int i = 0; i < n; i++) {
			string s;
			in >> s;
			for (int j = 0; j < n; j++) {
				b[head + j] = (s[j] == '1') ? true : false;
			}
			head += n + 1;
		}
	}
	inline bool get(int x, int y)const {
		return b[y + x*(n + 1)];
	}
	void printOut(ostream& out) {
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < n + 2; j++) {
				out << get(i, j) << " ";
			}
			out << endl;
		}
	}
};
class path {
public:
	string p;
	const board* b;
	int len;
	int x;
	int y;
public:
	path(board* bd) :p(""), b(bd), len(0), x(-1), y(-1) {}
	bool tryAdd(int _x, int _y, stack<path*>& stk) {
		if (b->get(_x, _y) == 0) { return false; }
		string neo_s = "(" + to_string(_x) + "," + to_string(_y) + ")";
		if (p.find(neo_s)<p.size()) { return false; }
		else {
			path* neo = new path(*this);
			neo->len++; neo->x = _x; neo->y = _y;
			neo->p.append(neo_s.append(" "));
			stk.push(neo);
			return true;
		}
	}
	bool tryNext(stack<path*>& stk) {
		bool ans = false;
		ans = ans || tryAdd(x + 1, y, stk);
		ans = ans || tryAdd(x - 1, y, stk);
		ans = ans || tryAdd(x, y + 1, stk);
		ans = ans || tryAdd(x, y - 1, stk);
		return ans;
	}
};
void findLongest(board* board) {
	stack<path*> stk;
	path empty(board);
	int n = board->n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			empty.tryAdd(i, j, stk);
		}
	}
	path* longest = &empty;
	while (!stk.empty()) {
		path* now = stk.top();
		stk.pop();
		if (!now->tryNext(stk) && now->len>longest->len) {
			longest = now;
		}
		else { delete now; };
	}
	cout << "lenght of longest is " << longest->len << endl;
	cout << "path is :" << endl;
	stringstream ss;
	ss << longest->p;
	while (!ss.eof()) {
		string t;
		ss >> t;
		cout << t << endl;
	}
	cout << endl;
	/*
	IO case
	string s = "6 111001 110111 000101 110111 010000 111100";
	stringstream ss;
	ss << s;
	board bd(ss);
	findLongest(&bd);
	*/
}
inline int oprToId(char c) {
	switch (c) {
	case '+':return 0;
	case '-':return 1;
	case '*':return 2;
	case '/':return 3;
	case '(':return 4;
	case')':return 5;
	}
	return -1;
}
char priority(char a, char b) {
	if (a == -1 || b == -1)return '@';
	const static char table[6][6] = {
		  //'+'  '-'  '*'  '/'  '('  ')'
			'>','>','<','<','<','>',// '+'
			'>','>','<','<','<','>',// '-'
			'>','>','>','>','<','>',// '*'
			'>','>','>','>','<','>',// '/'
			'<','<','<','<','<','=',// '('
			'.', '.' ,'.' ,'.' ,'.' ,'.' // ')'
	};
	if (a == '\0'&&b == '\0') { return '='; }
	if (a == '\0') { return '<'; }
	if (b == '\0') { return '>'; }
	return table[oprToId(a)][oprToId(b)];
}
inline bool isDigit(char* c,const char* first) {
	//tackle negitive
	if (c == first&&(*c >= '0'&&*c <= '9' ||*c=='-'))return true;
	if (*c == '-') {
		char pre = *(c - 1);
		if (pre == '+' || pre == '-' || pre == '*' || pre == '/')return true;
		else return false;
	}
	//
	return *c >= '0'&&*c <= '9' || *c == '.';
}
float readNum(char*&s,const char* f) {
	stringstream ss;
	char* head = s;
	while (isDigit(s,f)) s++;
	string t(head, s);ss << t;
	float temp;ss >> temp;
	return temp;
}
float compute(float a, float b, char c) {
	switch (c) {
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a*b;
	case '/':return a / b;
	}
}

float eval(char* s,string* RPN) {
	char* p = s;
	stack<float> num;
	stack<char> opr;
	float b = 0; float a = 0;
	opr.push('\0');
	stringstream ss;
	while (!opr.empty()) {
		if (isDigit(p,s)) {
			float  t= readNum(p,s);
			num.push(t);
			if (RPN) ss << t <<' ';
		}else {
			if (*p == ' ') {p++; continue;}
			switch (priority(opr.top(), *p)) {
			case '<':
				opr.push(*p);p++;break;
			case '>':
				b = num.top(); num.pop();
				a = num.top(); num.pop();
				num.push(compute(a, b, opr.top()));
				if (RPN) ss << opr.top() << ' ';
				opr.pop();break;
			case'=':
				opr.pop(); p++; break;
			default:exit(-1);
			}
		}
	}
	if(RPN)*RPN = ss.str();
	return num.top();
}



board_small::board_small(istream & in)
{
		in >> n;
		b = new char[(n + 2)*(n + 2)];
		for (int i = 0; i <(n + 2)*(n + 2); i++) {
			b[i] = '.';
		}
		int head = 0 + n + 1 + 1;
		for (int i = 0; i < n; i++) {
			string s;
			in >> s;
			for (int j = 0; j < n; j++) {
				b[head + j] = (s[j] == '1') ? 'U' : '.';
			}
			head += n + 1;
		}
	}
inline char & board_small::get(int x, int y)
{ return b[y + x*(n + 1)];}
void board_small::printOut(ostream & out)
{
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			out << get(i, j) << " ";
		}
		out << endl;
	}
}
void findLongestPath::SolverAndPrint(ostream & os)
{
	int n = bd->n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			tryAt(i, j); 
	///output
	for (int i = 0; i < Lon.size()-1; i++)
		os << '(' << Lon[i].x << ',' << Lon[i].y << ')' << "->" << endl;
	os << '(' << Lon[Lon.size() - 1].x << ',' << Lon[Lon.size() - 1].y << ')' << endl;
}
void findLongestPath::tryAt(int x, int y)
{
	char& c = bd->get(x, y);
	if (c != 'U')return;
	c = 'F'; Now.push_back(point(x, y));
	tryAfter(x, y);
	Now.pop_back(); c = 'U';
}
void findLongestPath::tryAfter(int x,int y)
{ 
		tryAt(x + 1, y);
		tryAt(x -1, y);
		tryAt(x , y+1);
		tryAt(x , y- 1);
		if (Now.size() > Lon.size())
			Lon = Now;
}

