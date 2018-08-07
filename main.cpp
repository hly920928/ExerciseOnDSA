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
	const int m =1; const int n =2;
	char t[m][n] =
	{ {'0','1'} };
	vector<vector<char>>buildings; buildings.resize(m);
	for (int i = 0; i < m; i++) {
		for (int j:t[i]) {
			buildings[i].push_back(j);
		}
	}
	auto ans = maximalSquare(buildings);
	return 0;

}

