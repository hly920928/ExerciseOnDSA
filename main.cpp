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
	ListNode ln1(1);
	ListNode ln2(1);
	ListNode ln3(3);
	ListNode ln4(2);
	ListNode ln5(5);
	ListNode ln6(2);
	ln1.next = &ln2;
	auto cur = &ln1;
	while (cur != nullptr) {
		cout << cur->val << endl;
		cur = cur->next;
	}
	cur = &ln1;
	cur = partition(cur,3);
	cout<<"Second" << endl;
	while (cur != nullptr) {
		cout << cur->val << endl;
		cur = cur->next;
	}
	return 0;
}