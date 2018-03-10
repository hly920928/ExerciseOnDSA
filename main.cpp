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
	vector<Interval>v;
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(4);
	ListNode l5(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	auto ans = rotateRight(&l1,5);
	//v.push_back(Interval(8, 10));
	//v.push_back(Interval(15, 18));
	for (int i = 1; i <= 6; i++) {
		cout << getPermutation(3, i) << endl;
	}
	return 0;
}