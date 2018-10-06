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
	vector<int>n1({ 3, 4, 6, 5 }); vector<int>n2({ 9, 1, 2, 5, 8, 3 });
	auto ans = maxNumber(n1,n2,5);
	return 0;

}

