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
	char t1[] = { 1,0,1,0,0,1,0,1,1,1 ,1,1,1,1,1,1,0,0,1,0};
	vector<vector<char>>m; m.resize(4);
	for (int i = 0; i < 4; i++) {
		m[i].resize(5);
		for (int j= 0;j< 5; j++) {
			m[i][j] = t1[i * 5 + j]+'0';
		}
	}
	int sum = maximalRectangle(m);
	return 0;
}