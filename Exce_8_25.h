#pragma once
#include <vector>
class TSP {
private:
	int table[12][12];
	bool isTraveled[12];
	int dp[1 << 11][11];
	int n;
	int min;
	int now;
	std::vector<char> v_now;
	std::vector<char> v_min;
public:
	TSP(int);
	void DFS();
	void DFS_v2();
	void DP();
private:
	void tryAfter(int i,int f);
	void tryAfter_v2(int n);
	void floyd();
};