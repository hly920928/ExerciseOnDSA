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
	////
	vector<vector<int>> matrix;
	matrix.resize(4);
	int r0[] = { 5, 1, 9, 11 };
	int r1[] = { 2, 4, 8, 10 };
	int r2[] = { 13, 3, 6, 7 };
	int r3[] = { 15, 14, 12, 16 };
	for (int i : r0)matrix[0].push_back(i);
	for (int i : r1)matrix[1].push_back(i);
	for (int i : r2)matrix[2].push_back(i);
	for (int i : r3)matrix[3].push_back(i);
	rotate(matrix);
	return 0;
}