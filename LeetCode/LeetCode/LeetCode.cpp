// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myHeader.h"
#include <vector>
using namespace std;
int main()
{ 
	vector<string>v({ "a","b","c","ab","ac","aa" });
	auto ans = palindromePairs(v);
    return 0;
}

