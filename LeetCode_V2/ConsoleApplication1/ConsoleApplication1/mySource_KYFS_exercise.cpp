#include "stdafx.h"
#include "myHeader.h"
#include "string.h"
int longestPalindrome(char* s) {
	int now = 0;
	int table[100];//ASCII must larger than A~Z a~z
	memset(table, 0, 100 * 4);
	while (s[now] != '\0') {
		table[s[now] - 'A']++;
		now++;
	}
	int ans = 0;
	bool hasOne = false;
	for (int i = 0; i < 100; i++) {
		if (table[i] % 2 == 1)hasOne = true;
		ans += (table[i] / 2) * 2;
	}
	if (hasOne)ans++;
	return ans;
}


