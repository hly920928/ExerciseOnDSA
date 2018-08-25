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
	const int w = 5; const int h = 5;
	int mt[h][w] = { { 1,2,3,4,5 },{ 6,7,8,9,10 },{ 11,12,13,14,15 },{ 16,17,18,19,20 },{ 21,22,23,24,25 } };
	vector<vector<int>>vmt; vmt.resize(h);
	for (int i = 0; i < h; i++) {
		vmt[i].resize( w);
		for (int j = 0; j < w; j++)vmt[i][j] = mt[i][j];
	}
	auto ans = searchMatrix_V2(vmt,5);
	return 0;

}

