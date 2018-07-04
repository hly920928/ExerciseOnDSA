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
	int a[] = { 1,3,5,4,3,7,6,9,2,4};
	vector<int>v(a, a +10);
	int m = maxProfit_IV(2,v);
	return 0;
}

