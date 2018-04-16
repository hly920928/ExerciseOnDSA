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
	int t[] = { 2,1,5,6,2,3 };
	vector<int >v;
	for (int i : t) {
		v.push_back(i);
	}
	int sum = largestRectangleArea(v);
	return 0;
}