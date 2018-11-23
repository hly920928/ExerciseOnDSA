// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myHeader.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{ 
	vector<pair<int, int>>ens({ {5,4 }, { 6,4 }, { 6,7 }, { 2,3 } });
	auto ans = maxEnvelopes_V2(ens);
    return 0;
}

