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
	vector<int>v({ 155,66,114,0,60,73,109,26,154,0,107,75,9,57,53,6,85,151,12,110,64,103,42,103,126,3,88,142,79,88,147,47,134,27,82,95,26,124,71,79,130,91,131,67,64,16,60,156,9,65,21,66,49,108,80,17,159,24,90,79,31,79,113,39,54,156,139,8,90,19,10,50,89,77,83,13,3,71,52,21,50,120,159,45,22,69,144,158,19,109,52,50,51,62,20,22,71,95,47,12,21,32,17,130,109,8,61,13,48,107,14,122,62,54,70,96,11,141,129,157,136,41,40,78,141,16,137,127,19,70,15,16,65,96,157,111,87,95,52,42,12,60,17,20,63,56,37,129,67,129,106,107,133,80,8,56,72,81,143,90,0 });
	MedianFinder mf;
	for (auto i : v) {
		mf.addNum(i);
		auto ans = mf.findMedian();
	}
	
	return 0;

}

