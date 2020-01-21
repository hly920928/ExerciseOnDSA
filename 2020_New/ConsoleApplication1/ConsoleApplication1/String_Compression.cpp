//LeetCode 443. String Compression

#include "mainHeader.h"
using namespace std;
int compress(vector<char>& chars) {
	if (chars.size() == 1)return 1;

	 
	int len = 1;
	int pos = 0;
	char pre = chars[0];
	int flag_1 = false;
	for (int i = 1; i < chars.size(); i++) {
		if (chars[i] != pre || i == chars.size() - 1) {
			if (i == chars.size() - 1&& chars[i] == pre)len++;
			if (i == chars.size() - 1 && chars[i] != pre)flag_1 = true;
			chars[pos] = pre; pos++;
			pre = chars[i];
			if (len > 1) {
				string l = to_string(len);

				for (char c : l) {
					chars[pos] = c;
					pos++;
				}
			}
			len = 1;
			if (flag_1) {
				chars[pos] = pre; pos++;
			}
		}
		else {
			len++;
		}
	}
	//chars.resize(pos);
	return pos;
}