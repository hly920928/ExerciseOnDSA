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

	ListNode ln1(4);
	ListNode ln2(2);
	ListNode ln3(1);
	ListNode ln4(3);
	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	vector<Point>v_p;
	v_p.push_back(Point(0, 0));
	v_p.push_back(Point(0, 0));
	v_p.push_back(Point(1, 1));
	double ld = 000;
	cout << sizeof(ld);
	auto t = sortList(&ln1);
	return 0;

}

