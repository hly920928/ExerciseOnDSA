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
	////
	string strs[] = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<string>vstrs;
	for (string& s : strs)vstrs.push_back(s);
	auto ans = groupAnagrams(vstrs);
	return 0;
}