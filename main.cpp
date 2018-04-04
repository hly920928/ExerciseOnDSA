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
	int m[] = {
		'A','B','C','E',
			'S','F','C','S',
			'A','D','E','E'
	};
	vector<vector<char>>mat;
	mat.resize(3);
	for (int i = 0; i < 3; i++) {
		mat[i].resize(4);
		for (int j = 0;j <4; j++) {
			mat[i][j] = m[i * 4 + j];
		}
	}
	string str = "ABCB";
	bool ans = exist(mat, str);
	return 0;
}