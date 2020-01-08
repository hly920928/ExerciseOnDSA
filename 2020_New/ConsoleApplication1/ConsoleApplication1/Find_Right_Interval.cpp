//LeetCode 436. Find Right Interval

#include "mainHeader.h"
#include <algorithm>
#include <vector>
using namespace std;
class interval {
public:
	int start;
	int end;
	int index;
	interval(int a = INT_MIN, int b = INT_MAX, int c = -1) :
		start(a), end(b), index(c) {};
	bool operator<(const interval& b)const { return  start < b.start; }

};

std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) {
	int i = 0; int n = intervals.size();
	vector<interval> table;
	for (auto& v : intervals) {
		table.push_back(interval(v[0], v[1], i));
		i++;
	}
	sort(table.begin(), table.end());

	vector<int> ans;
	ans.resize(n);
	for (int i = 0; i < n;i++) {
		auto itr = lower_bound(
			table.begin() + i + 1,
			table.end(),
			interval(table[i].end, INT_MAX, -1)
			);
		if (itr == table.end()) {
			ans[table[i].index] = -1;
		
		}
		else {
			ans[table[i].index] =itr->index;

		}
	
	
	}

	return ans;

}