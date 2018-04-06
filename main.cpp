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
	int m[] = {
		1,1,1,1
	};
	vector<int>mat;
	for (int i : m)mat.push_back(i);
	string str = "ABCB";
	int ans = removeDuplicates_V2(mat);
	return 0;
}