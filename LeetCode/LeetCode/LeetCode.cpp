// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myHeader.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{ 
	vector<vector<int>> matrix({ {2,2,-1} });
	auto ans=maxSumSubmatrix(matrix, 0);
	
    return 0;
}

