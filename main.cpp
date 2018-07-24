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
	const int m = 4; const int n = 4;
	int t[] =
	{
		1,3,1
	};


	vector<int>v(t,t+3);
	auto ans = rob_sub(v, 0,2);
	return 0;

}

