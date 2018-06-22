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

	MinStack mstk;
	mstk.push(-2);
	mstk.push(0);
	mstk.push(-3);
	int min = mstk.getMin();
	mstk.pop();
	int top= mstk.top();
	min = mstk.getMin();
	return 0;

}

