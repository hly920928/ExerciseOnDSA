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
	int t[1][1] = {
			{'a'}
	};
	vector<vector<char>>board; board.resize(1);
	for (int i = 0; i <1; i++) {
		board[i].resize(1);
		for (int j= 0;j< 1;j++) 
			board[i][j]= t[i][j];
	}
	string strs[] = {
		"a","a" 
	};
	vector<string> words(strs, strs + 2);
	auto ans = findWords(board, words);
	return 0;

}

