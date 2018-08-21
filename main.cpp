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
	TreeNode tn6(6);	TreeNode tn2(2); 
	TreeNode tn8(8); TreeNode tn4(4);
	TreeNode tn0(0);
	TreeNode tn7(7); TreeNode tn9(9);
	TreeNode tn3(7); TreeNode tn5(5);
	tn6.left = &tn2; tn6.right = &tn8;
	tn2.left = &tn0; tn2.right = &tn4;
	tn4.left = &tn3; tn4.right = &tn5;
	tn8.left = &tn7; tn8.right = &tn9;
	auto ans = lowestCommonAncestor(&tn6, &tn2, &tn4);
	return 0;

}

