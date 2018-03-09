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
	vector<Interval>v;
	v.push_back(Interval(1,2));
	v.push_back(Interval(3,5));
	v.push_back(Interval(6, 7));
	v.push_back(Interval(8, 10));
	v.push_back(Interval(12, 16));
	//v.push_back(Interval(8, 10));
	//v.push_back(Interval(15, 18));
	for (int i = 1; i <= 6; i++) {
		cout << getPermutation(3, i) << endl;
	}
	return 0;
}