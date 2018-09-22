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
	vector<pair<int, int>>edges({ {1,0} ,{ 1, 2 } ,{ 1, 3} });
	auto ans = findMinHeightTrees(4, edges);
	return 0;

}

