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
	vector<int>v({1,4,-6 });
	NumArray as(v);
	auto s1 = as.sumRange(0, 2);
	auto s2 = as.sumRange(1,2);
	auto s3 = as.sumRange(0, 1);
	return 0;

}

