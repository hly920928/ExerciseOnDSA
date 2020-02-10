//LeetCode 453. Minimum Moves to Equal Array Elements
#include "mainHeader.h"
#include <algorithm>
using namespace std;
int minMoves(vector<int>& nums) {
	if (nums.size() < 2)return 0;
	long long sum = 0;
	for (int i : nums)sum += i;
	int min = *min_element(nums.begin(), nums.end());
	return sum - min * nums.size();
}