
#include "mainHeader.h"
inline char toLow(char c) {
	if (c >= 'a' && c <= 'z')return c;
	return c + 'a' - 'A';
}
std::vector<std::string> findWords(std::vector<std::string>& words) {
	char table_1[10] ={'q','w','e','r','t','y','u','i','o','p'};
	char table_2[9] = { 'a','s','d','f','g','h','j','k','l' };
	char table_3[7] = { 'z','x','c','v','b','n','m' };
	char table_main[26];
	for (char c : table_1)table_main[c - 'a'] = 1;
	for (char c : table_2)table_main[c - 'a'] =2;
	for (char c : table_3)table_main[c - 'a'] = 3;
	std::vector<std::string>ans;
	for (auto str : words) {
		if (str == "")continue;
		char row = table_main[toLow(str[0]) - 'a'];
		bool flag = true;
		for (int i = 1; i < str.size(); i++) {
			char c = toLow(str[i]);
			if (table_main[c - 'a'] != row) {
				flag = false;
				break;
			}
			
		}
		if (flag)ans.push_back(str);
	}
	return ans;
}