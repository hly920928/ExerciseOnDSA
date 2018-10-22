// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myHeader.h"
#include <vector>
using namespace std;
int main()
{ 
	std::vector<int>nums({1,2,2,6,34,38,41,44,47,47,56,59,62,73,77,83,87,89,94});
	auto head = buildList(nums);
	auto ans= minPatches(nums,20);
    return 0;
}

