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
	vector<pair<int, int>>v; v.push_back({ 1,0 }); 
	//v.push_back({0,1});
	Tries trie;
	trie.insert("apple");
	trie.search("apple");   // returns true
	trie.search("app");     // returns false
	trie.startsWith("app"); // returns true
	trie.insert("app");
	trie.search("app");     // returns true
	return 0;

}

