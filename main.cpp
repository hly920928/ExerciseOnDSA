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
	TreeNode tn1(2);
	TreeNode tn2(1);
	tn1.left = &tn2;
	BSTIterator i(&tn1);
	while (i.hasNext()) cout << i.next()<<endl;
	return 0;

}

