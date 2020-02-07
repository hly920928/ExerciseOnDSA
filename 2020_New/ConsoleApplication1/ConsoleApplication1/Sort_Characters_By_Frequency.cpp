#include "mainHeader.h"
using namespace std;
class dataChar {
public:
	int count;
	char c;
	dataChar(int _c = 0, char cr = ' '):count(_c), c(cr) {}
	bool operator < (const dataChar & b) {
		return count> b.count;
	}
};
void countChar(const string& s, dataChar table[]) {
	for (char c : s) {
		table[c].count++;
	}
}
void constructStr(dataChar table[],string& ans) {
	for (int i = 0; i < 255; i++) {
		dataChar& now = table[i];
		for (int i = 0; i < now.count; i++) {
			ans.push_back(now.c);
		}
	}

}
std::string frequencySort(std::string s) {
	dataChar table[255];
	for (int i = 0; i < 255; i++) {
		table[i] = dataChar(0,i);
	}
	countChar(s, table);
	sort(table, table + 255);
	string ans;
	constructStr(table, ans);
	return ans;
}