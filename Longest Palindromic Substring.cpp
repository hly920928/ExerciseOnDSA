#include "stdafx.h"
#include <queue>  
using namespace std;
class solver_old {
private:
	const string* s;
	queue<int>q;
public:
	solver_old(const string& _s) :s(&_s) {};
	string ans() {
		addInit();
		int id = 0;
		while (!q.empty()) {
			id = q.front(); q.pop();
			tryAdd(id);
		}
		int lo = 0; int hi = 0;
		toPOS(id, lo, hi);
		return s->substr(lo, hi - lo + 1);
	}
private:
	void addInit() {
		for (int i = 0; i < s->size(); i++) {
			q.push(toID(i, i));
		}
		for (int i = 0; i < s->size(); i++) {
			if (isPalindrome(i, i + 1))q.push(toID(i, i + 1));
		}
	}
	inline void tryAdd(int id) {
		int lo = 0; int hi = 0; toPOS(id, lo, hi);
		if (isPalindrome(lo - 1, hi + 1))q.push(toID(lo - 1, hi + 1));
	}
	bool isPalindrome(int i, int j) {
		/*cout << "Now at " << s->substr(i, j-i+1) << endl;
		if (s->substr(i, j - i + 1) == "ranynar") {
		cout << "catch";
		}*/
		//cout << "len is " << j - i + 1 << endl;
		if (i < 0 || i >= s->size())return false;
		auto& ts = *s;
		return (ts[i] == ts[j]) ? true : false;
	}
	inline int toID(int lo, int hi) {
		return  lo * 1000 + hi;
	}
	inline void toPOS(int id, int& lo, int& hi) {
		lo = id / 1000;
		hi = id % 1000;
	}

};