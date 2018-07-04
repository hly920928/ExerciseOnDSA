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
	int a[] = { 1,2,4,2,5,7,2,4,9,0 };
	vector<int>v(a, a +10);
	auto ans = maxProfit(2,v);
	return 0;

}

