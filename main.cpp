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
	int t[m][n] =
	{
		{'o', 'a', 'a', 'n'},
		{'e', 't', 'a', 'e'},
		{'i', 'h', 'k', 'r'},
		{'i', 'f', 'l', 'v'}
	};


	vector<vector<char>>board; board.resize(m);
	for (int i = 0; i <m; i++) {
		board[i].resize(n);
		for (int j= 0;j< n;j++) 
			board[i][j]= t[i][j];
	}
	string strs[] = {
		"oath","pea","eat","rain"
	};
	vector<string> words(strs, strs + 4);
	auto ans = findWords_V2(board, words);
	return 0;

}

