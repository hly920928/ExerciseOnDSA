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
struct table_item {
	int n;
	char id;
	table_item(int _n = 0, char _id = 0) : n(_n), id(_id) {};
	void set(int _n, char _id) {
		n = _n;
		id = _id;
	}
};
int ClockSimu(vector<table_item>& init_table, vector<char>& sequ, int limit) {
	int table_len = init_table.size(); int n_page_fail = 0;
	int ptr = 0;
	for (char c : sequ) {
		//search all
		bool found = false;
		for (auto& it : init_table) {
			if (it.id == c) {
				found = true;
				it.n =1;
			}
			else {
				if (it.n != 0)it.n = (it.n + 1) % limit;
			}
			
		}
		// no found,page_fail
		if (!found) {
			n_page_fail++;
			while (init_table[ptr].n != 0) {
				init_table[ptr].n = (init_table[ptr].n + 1) % limit;
				ptr = (ptr + 1) % table_len;
			}
			init_table[ptr].n = 1;
			init_table[ptr].id = c;
			ptr = (ptr + 1) % table_len;
		}
	    found:;
	}
	return n_page_fail;
}
int main() { 

	auto ans = restoreIpAddresses("010010");

	return 0;
}

