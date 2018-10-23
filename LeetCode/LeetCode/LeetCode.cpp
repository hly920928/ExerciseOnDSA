// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myHeader.h"
#include <vector>
using namespace std;
int main()
{ 
	std::vector<pair<string,string>>tickets({{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}});
	auto ans = findItinerary(tickets);
    return 0;
}

