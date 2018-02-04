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
using namespace std;
int main() {
	vector<string>words;
	words.push_back("word");	words.push_back("good");
	words.push_back("best");	words.push_back("good");
	auto ans = findSubstring("wordgoodgoodgoodbestword",words);
	return 0;
}