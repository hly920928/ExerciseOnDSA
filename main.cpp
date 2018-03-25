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
	int t1[] = { 0,0, 0, 5,4, 3, 1, 4,0, 1, 1, 4,1, 2, 1, 3,0, 0, 1, 1 };
	vector<vector<int>> matrix;
	matrix.resize(5);
	for (int i = 0; i < 5; i++) {
		matrix[i].resize(4);
		for (int j= 0;j < 4; j++) {
			matrix[i][j] = t1[i * 4 + j];
		}
	}
	 setZeroes(matrix);
	return 0;
}