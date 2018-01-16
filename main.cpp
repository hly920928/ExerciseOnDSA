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
	int a[] = { 1, 0, -1, 0, -2, 2 };
	vector<int> v;
	for (int t : a)v.push_back(t);
	auto vv = fourSum(v, 0);
	return 0;
}