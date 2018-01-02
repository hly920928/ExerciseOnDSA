#pragma once
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
void geneAllPermutation(int n);
struct stage{
	int n;
	int p;
	stage(int _n=0, int _p=-1) :n(_n), p(_p) {};
};
class StoneMerger_simplified {
private:
	vector<vector<stage>>point;
	vector<vector<int>>sum_table;
	vector<int>data;
	int n;
public:
	StoneMerger_simplified(istream& is);
	void printOut(ostream& is);
private:
	int solve(char c, stack<string>& sque) ;
	void pushDown(int l, int p, int h, stack<string>& sque);
	void solvepoint(int l, int h, char c);
	int sum(int l, int h);
};