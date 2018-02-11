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
using namespace std;
int main() {
	vector<int>nums;
	nums.push_back(5); 
	nums.push_back(7);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(10);
	auto i = searchRange(nums, 8);
	return 0;
}