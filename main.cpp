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
	int n[] = { 1,2 };
	vector<int> nums;
	for (int i : n)nums.push_back(i);
	auto ans = maxSubArray(nums);
	return 0;
}