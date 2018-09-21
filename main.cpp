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
	vector<pair<int, int>>edges({ {0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4} });
	auto ans = findMinHeightTrees(6, edges);
	return 0;

}

