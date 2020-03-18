//482. License Key Formatting
#include "mainHeader.h"
using namespace std;

string licenseKeyFormatting(string S, int K) {
	string ans; int now_count = 0;
	int diff = 'A' - 'a';
	for (int i = S.size() - 1; i >= 0; i--) {
		if (S[i] != '-') {
			if (now_count == K) {
				ans.push_back('-');
				now_count = 0;
			}
			if (S[i] >= 'a' && S[i] <= 'z') {
				ans.push_back(S[i] + diff);
			}
			else ans.push_back(S[i]);
			now_count++;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}