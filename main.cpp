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
	const int m =9; const int n = 4;
	int t[9][3] =
	{ { 2,4,70 },{ 3,8,30 },{ 6,100,41 },{ 7,15,70 },{ 10,30,102 },{ 15,25,76 },{ 60,80,91 },{ 70,90,72 },{ 85,120,59 } };
	vector<vector<int>>buildings; buildings.resize(m);
	for (int i = 0; i < m; i++) {
		for (int j:t[i]) {
			buildings[i].push_back(j);
		}
	}
	auto ans = getSkyline(buildings);
	return 0;

}

