//LeetCode Unique Substrings in Wraparound String
#include "mainHeader.h" 
using namespace std;
inline char next(char c) {
	if (c == 'z')return 'a';
	return c + 1;
}
inline void  setArray(int* a, int len, int v) {
	for (int i = 0; i < len; i++)a[i] = v;
}
int findSubstringInWraproundString(string p) {
	if (p.size() == 0)return 0;
	int subStringlen[26]; setArray(subStringlen, 26, 0);
	 int firstCharPos[26]; setArray(firstCharPos, 26, -1);
	 int head = 0; int tail = 0;
	 while (true) {
		 if (tail + 1 >= p.size()) {
			 if (tail == p.size() - 1) {
				 if (subStringlen[p[tail] - 'a'] == 0)subStringlen[p[tail] - 'a'] = 1;
				 for (int i = 0; i < 26; i++) {
					 if (firstCharPos[i] != -1) subStringlen[i] = max(subStringlen[i], tail - firstCharPos[i] + 1);
				 }
			 }	
			 break;
		 }
		 if (firstCharPos[p[tail] - 'a'] == -1)firstCharPos[p[tail] - 'a'] = tail;
		 if (p[tail + 1] == next(p[tail])) {
			 tail++;
		 }
		 else {
			 for (int i = 0; i < 26; i++) {
				if(firstCharPos[i]!=-1) subStringlen[i] = max(subStringlen[i], tail-firstCharPos[i]+1);
			 }
			 setArray(firstCharPos, 26, -1);
			 head = tail + 1; tail = head;
		 }
	 }
	 int ans = 0;
	 for (int i = 0; i < 26; i++) ans += subStringlen[i];
	 return ans;
}