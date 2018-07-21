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
	WordDictionary wd;
	wd.addWord("bad");
	wd.addWord("dad");
	wd.addWord("mad");
	wd.search("pad");
	wd.search("bad");
	wd.search(".ad");
	wd.search("b..");
	return 0;

}

