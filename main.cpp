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
	const int m = 1; const int n = 2;
	int matrix[m][n] ={
		{1,-7} };
	vector<vector<int>>_m; _m.resize(m);
	for (int i = 0; i < m; i++) {
		_m[i].resize(n);
		for (int j = 0;j < n; j++) {
			_m[i][j] = matrix[i][j];
		}
	}
	NumMatrix nm(_m);
	auto a1 = nm.sumRegion(0,0,0,0);
	auto a2= nm.sumRegion(1, 0, 1, 0);
	auto a3 = nm.sumRegion(0, 0, 1, 0);
	return 0;

}

