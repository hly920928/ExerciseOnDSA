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
	TreeNode n1(-10);
	TreeNode n2(9);
	TreeNode n3(20);
	TreeNode n4(15);
	TreeNode n5(7);
	n1.left = &n2;
	n1.right = &n3;
	n3.left = &n4;
	n3.right = &n5;
	int t = maxPathSum(&n1);
	return 0;
}

