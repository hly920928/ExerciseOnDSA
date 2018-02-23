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
	int n[] = { 5,9,3,2,1,0,2,3,3,1,0,0 };
	vector<int >v(n, n + 12);
	int i = jump(v);
	return 0;
}