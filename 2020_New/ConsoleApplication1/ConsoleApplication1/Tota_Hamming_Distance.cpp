//477. Total Hamming Distance
#include "mainHeader.h"
#include <bitset>
using namespace std;
inline void add(int* v, int bits) {
	unsigned b = bits;
	for (int i = 0; i < 32; i++) {
		if (b % 2 == 1) {
			v[i]++;
		}
		b = b >> 1;
	}
}
int totalHammingDistance(vector<int>& nums) {
	if (nums.size() <= 1)return 0;
	int v[32]; for (int& i : v)i = 0;
	//bitset<32>bits(nums[0]);
	add(v, nums[0]); int ans = 0;
	for (int i = 1; i < nums.size(); i++) {
		//bits = nums[i];
		unsigned b = nums[i];
		for (int j= 0; j< 32; j++) {
			if (b%2==1) {
				ans += i - v[j];
			}
			else {
				ans +=   v[j];
			}
			b = b >> 1;
		}
		add(v, nums[i]);
	}
	return ans;
}