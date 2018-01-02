#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
float eval(char* s,string* RPN=nullptr);
class board_small {
public:
	char* b;
	int n;
public:
	board_small(istream& in);
	inline char& get(int x, int y);
	void printOut(ostream& out);
};
struct point {
	int x; int y;
	point(int _x = -1, int _y = -1) :x(_x), y(_y) {};
};
class findLongestPath {
private:
	board_small* bd;
	vector<point>Lon;
	vector<point>Now;
public:
	findLongestPath(board_small* _bd):bd(_bd){}
	void SolverAndPrint(ostream& os);
	void tryAfter(int x,int y);
	void tryAt(int x, int y);
};