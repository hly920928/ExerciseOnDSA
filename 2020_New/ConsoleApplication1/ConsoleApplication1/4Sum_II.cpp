//454. 4Sum II
#include "mainHeader.h"
#include <iostream>
#include<unordered_map>
using namespace std;

void produceCombinationTable(
	const std::vector<int>& A, 
	const std::vector<int>& B,
	unordered_map<int ,int>& table) {
	for (auto& a : A) {
		for (auto& b : B) {
			auto itr = table.find(a + b);
			if (itr == table.end()) {
				table[a + b] = 1;
			}
			else {
				table[a + b]++;
			}
		}
	}

}
int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D) {
	unordered_map<int, int>  table_AB; 
	unordered_map<int, int>  table_CD;
	produceCombinationTable(A, B, table_AB);
	produceCombinationTable(C, D, table_CD);
	int ans = 0;
	for (auto itr_1 : table_AB) {
		auto itr_2 = table_CD.find(-1 * itr_1.first);
		if (itr_2 != table_CD.end()) {
			ans += itr_1.second * itr_2->second;
		}
	}
	return ans;
}