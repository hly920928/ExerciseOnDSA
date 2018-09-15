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
	vector<int>v({ -8261,2300,-1429,6274,9650,-3267,1414,-8102,6251,-5979,-5291,-4616,-4703 });
	vector<int>case1({ 0,8,4,5,9,11,2,11,0,12,9,12,2,5,0,9,5,9,0,1,12,12,6,7,5,8,1,1,6,7,10,11,11,12,7,8,4,11,8,9,4,11,2,9,2,6,11,12,5,8,11,11,1,9,12,12,10,10,4,7,12,12,8,10,7,9,4,7,0,7,8,9,10,12,0,9,10,12,7,12,9,9,0,12,1,3,8,8,7,10 });
	NumArray as(v);
	for (int i = 0; i < case1.size(); i += 2) {
		if (case1[i]==10&& case1[i+1]==12) {
			int a=666;
		}
			auto s1 = as.sumRange(case1[i], case1[i + 1]);
	}
	return 0;

}

