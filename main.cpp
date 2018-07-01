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
	vector<vector<int>>m;
	m.resize(1); 
/*
m[0].push_back(1); m[0].push_back(-3); m[0].push_back(3);
m[1].push_back(0); m[1].push_back(-2); m[1].push_back(0);
m[2].push_back(-3); m[2].push_back(-3); m[2].push_back(-3);
*/
	m[0].push_back(0); m[0].push_back(0);
	auto ans = calculateMinimumHP(m);
	return 0;

}

