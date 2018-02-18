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
	int a[] = {10, 1, 2, 7, 6, 1, 5};
	vector<int> v(a,a+7); 
	auto& ans = combinationSum2(v,8);
	return 0;
}