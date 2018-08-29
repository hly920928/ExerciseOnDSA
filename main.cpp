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
	const int w = 1; const int h = 1;
	int mt[h][w] = { { -5} };
	vector<vector<int>>vmt; vmt.resize(h);
	for (int i = 0; i < h; i++) {
		vmt[i].resize( w);
		for (int j = 0; j < w; j++)vmt[i][j] = mt[i][j];
	}
	auto ans = isAnagram("anagram","nagaram");
	return 0;

}

