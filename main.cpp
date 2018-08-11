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
	TreeNode tn1(1);	TreeNode tn2(2); TreeNode tn3(3); TreeNode tn4(4);
	tn1.left = &tn2; tn1.right = &tn3; tn2.left = &tn4;
	auto ans = countNodes(&tn1);
	return 0;

}

