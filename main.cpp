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
	ListNode ln2(2);
	ListNode ln3(3);
	ListNode ln4(4);
	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	reorderList(&ln1);
	auto t = &ln1;
	while (t != nullptr) {
		cout << t->val << endl;
		t = t->next;
	}
	return 0;
}

