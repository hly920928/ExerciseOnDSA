#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>  
#include <string>   
#include <list>   
#include <vector> 
#include <cmath>   
#include <unordered_map>
#include <numeric>
#include <stack> 
#include <iomanip>
#include <bitset>
#include "LeetCode.h"
#include "RouterNode.h"
using namespace std;
int main() {
	_ArcDate ad;
	ArcNode an;
	char v1[9][9] = {{ '.', '.','9','7','4','8','.','.','.'},
	                          {'7','.','.','.','.','.','.', '.', '.' },
							  { '.', '2', '.', '1', '.', '9', '.', '.','.'},
							  { '.', '.', '7', '.', '.', '.', '2', '4', '.' },
							  { '.', '6', '4', '.', '1', '.', '5', '9', '.' },
							  { '.', '9', '8', '.', '.', '.', '3', '.', '.' },
							  { '.', '.', '.', '8', '.', '3', '.', '2', '.' },
							  { '.', '.', '.', '.', '.', '.', '.', '.', '6' },
							  { '.', '.', '.', '2', '7', '5', '9', '.', '.' }};
	vector<vector<char>> t;
	t.resize(9);
	for (int i = 0; i < 9; i++) {
		t[i].resize(9);
		for (int j= 0;j< 9;j++) {
			t[i][j] = v1[i][j];
		}
	};
	solveSudoku(t);
	return 0;
}