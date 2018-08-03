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
	const int m =3; const int n = 4;
	int t[m][3] =
	{ { 1,2,1 },{ 1,2,2 },{ 1,2,3 } };
	vector<vector<int>>buildings; buildings.resize(m);
	for (int i = 0; i < m; i++) {
		for (int j:t[i]) {
			buildings[i].push_back(j);
		}
	}
	auto ans = getSkyline_V2(buildings);
	return 0;

}

