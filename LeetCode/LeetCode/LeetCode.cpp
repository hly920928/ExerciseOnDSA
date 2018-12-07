// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myHeader.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{ 
	vector<int> v({ 2,3,4,9,8 });
	auto ans= largestDivisibleSubset(v);
	
    return 0;
}

