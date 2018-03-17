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
	vector<vector<int>>v;
	v.resize(3);
	v[0].push_back(1); v[0].push_back(3); v[0].push_back(1);
	v[1].push_back(1); v[1].push_back(5); v[1].push_back(1);
	v[2].push_back(4); v[2].push_back(2); v[2].push_back(1);
	int t = minPathSum(v);
	return 0;
}