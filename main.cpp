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
	int t[] = { 1,1,1,1,1,1,1 };
	ListNode head(t[0]);
	ListNode* cur = &head;
	for (int i = 1; i < sizeof(t)/sizeof(int); i++) {
		cur->next = new ListNode(t[i]);
		cur = cur->next;
	}
	cur = &head;
	while (cur != nullptr) {
		cout << cur->val << endl;
		cur = cur->next;
	}
	auto ans = deleteDuplicates(&head);
	cur = &head;
	while (cur != nullptr) {
		cout << cur->val << endl;
		cur = cur->next;
	}
	return 0;
}