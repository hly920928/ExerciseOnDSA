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
using namespace std;
int main() {
	vector<int>nums;
	nums.push_back(1); 
	nums.push_back(3);
	/*nums.push_back(6);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);*/
	int i = search(nums,3);
	return 0;
}