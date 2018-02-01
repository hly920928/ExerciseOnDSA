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
	vector<int>v;
	v.push_back(3); v.push_back(2);
	v.push_back(2); v.push_back(3);
	int n = removeElement(v,3);
	return 0;
}