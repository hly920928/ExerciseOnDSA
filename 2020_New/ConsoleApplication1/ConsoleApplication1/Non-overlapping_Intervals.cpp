#include "mainHeader.h"
#include <algorithm>
#include <list>
using namespace std;

bool comp(const vector<int>& a, const vector<int>& b) {
	if (a[0] < b[0])return true;
	if (a[0] > b[0])return false;
	if (a[1] < b[1])return true;
	if (a[1] > b[1])return false;
	return false;
}

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), comp);


	list<vector<int>> _list;
	for (auto& v : intervals)_list.insert(_list.end(), v);
	int ans =0;
	auto itr_1 = _list.begin();
	while (itr_1 != _list.end()) {
		auto itr_2 = itr_1;
		itr_2++;
		if (itr_2 == _list.end())break;
		vector<int>v1 = *itr_1;	vector<int>v2 = *itr_2;
		if (v1[1] >v2[0]) {
			if (v1[1] >v2[1]) {
				_list.erase(itr_1);
				itr_1 = itr_2;
			}
			else {
				_list.erase(itr_2);
			}
			ans++;
		}
		else {
			itr_1 = itr_2;
		}
	}
	return ans;


}