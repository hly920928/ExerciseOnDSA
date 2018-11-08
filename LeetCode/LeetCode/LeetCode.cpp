// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myHeader.h"
#include <vector>
using namespace std;
int main()
{ 
	vector<string>v({ "bat","tab","cat" });
	auto ans = palindromePairs(v);
    return 0;
}

