//464. Can I Win
#include "mainHeader.h"
 
#include<vector>
#include <bitset>
using namespace std;
int m = -1;
int d = -1;
vector<char>* state_table;
bool canIwin_re(unsigned int state) {
	vector<char>& table = *state_table;
	if (table[state]!=2)return table[state];
	bitset<32>st (state);
	//get now sum
	unsigned int now_sum = 0;
	for (int i = 0; i <m; i++) {
		if (st[i])now_sum +=(i+1);
	}
	//check can win right now
	for (int i = m-1; i >= 0; i--) {
		if (!st[i]) {
			if (now_sum +(i+1) >= d) {
 
				table[state] = 1;
				return true;
			}
		}
	}
	//check if all next state is true
	for (int i = 0; i <m; i++) {
		if (!st[i]) {
			bitset<32>next = st;
			next[i] = true;
			if (!canIwin_re((unsigned int)next.to_ulong())) {
		 
				table[state] = 1;
				return true;
			}
		}
	}
 
	table[state] = 0;
	return false;
}
bool canIWin(int maxChoosableInteger, int desiredTotal) {
	m = maxChoosableInteger;
	d = desiredTotal;
	if (m * (m + 1) / 2 < d)return false;
	vector<char> st(pow(2,m)+1,2);
	state_table = &st;
	return canIwin_re(0);
}