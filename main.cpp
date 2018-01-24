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
	ListNode n1(1);
	ListNode n2(0);
	vector<ListNode*> v;
	//v.push_back(&n1);
	//v.push_back(&n2);
	ListNode* head = mergeKLists(v);
	while (head != nullptr) {
		printf_s("%d\n", head->val);
		head = head->next;
	}
	return 0;
}