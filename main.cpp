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
	vector<int>v({0,0 });
	MedianFinder mf;
	for (auto i : v) {
		mf.addNum(i);
		
		auto ans = mf.findMedian();
		int a = 0;
	}
	
	return 0;

}

