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
	string n = countAndSay(5);
	vector<int> v; 
	v.push_back(2);
	v.push_back(3);
	v.push_back(6);
	v.push_back(7);
	auto& ans = combinationSum(v, 7);
	return 0;
}