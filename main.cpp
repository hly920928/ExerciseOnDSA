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
	vector<int>v({ 1,2,3,0,2 });
	NumArray a1(v);
	a1.update(4, 5);
	a1.update(1,7);
	a1.update(0, 8);
	int a2 = maxProfit_WCD(v);
	a1.update(1, 2);
	a2 = a1.sumRange(0, 2);
	return 0;

}

