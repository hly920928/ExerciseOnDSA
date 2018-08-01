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
	const int m = 4; const int n = 4;
	int t[] =
	{
		3,2,1,5,6,4
	};
	TreeNode tn1(1);
	TreeNode tn2(2);
	TreeNode tn3(3);
	tn1.right = &tn2;
	tn2.left = &tn3;
	auto ans = inorderTraversal_iterative(&tn1);
	return 0;

}

