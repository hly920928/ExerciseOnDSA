// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myHeader.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{ 
	vector<int> v1({1,1,2 });	vector<int> v2({ 1,2,3 });
	auto ans= kSmallestPairs(v1,v2,2);
	
    return 0;
}

