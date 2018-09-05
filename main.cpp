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
	vector<int>v({ 1,2,3 });
	PeekingIterator pi(v);
	auto a1 = pi.next();
	auto a2 = pi.peek();
	auto a3 = pi.next();
	auto a4 = pi.next();
	auto a5 = pi.hasNext();
	return 0;

}

