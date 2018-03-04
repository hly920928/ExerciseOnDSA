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
	vector<Interval>v;
	v.push_back(Interval(1, 4));
	v.push_back(Interval(1, 4));
	//v.push_back(Interval(8, 10));
	//v.push_back(Interval(15, 18));
	auto ans = merge(v);
	return 0;
}