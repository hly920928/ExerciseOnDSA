//LeetCode 447. Number of Boomerangs 
#include "mainHeader.h"
#include <unordered_map>
using namespace std;
inline  int dist(const vector<int>& a, const vector<int>& b) {
	int x = a[0] - b[0];	int y = a[1] - b[1];
	return x * x + y * y;
}
int numberOfBoomerangs(std::vector<std::vector<int>>& points) {
	if (points.size() < 3) return 0;
	int n = points.size();
	
     int i = 0;
	int ans = 0;
	unordered_map<int, int> record;
	for (auto& p1 : points) {
		record.clear();
		for (auto& p2 : points) {
			int d = dist(p1, p2);
			auto itr = record.find(d);
			if (itr == record.end())record[d] = 1;
			else record[d]++;
		}

		for (auto itr : record) {
			if (itr.second >= 2) {
				ans += itr.second * (itr.second - 1);
			}
		}

		i++;
	}

 
	return ans;
}