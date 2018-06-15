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

	LRUCache cache(2);

	cache.put(2, 1);
	cache.put(2, 2);
	int re=cache.get(2);    
	cache.put(1, 1); 
	cache.put(4, 1);
	 re = cache.get(2);
	return 0;

}

