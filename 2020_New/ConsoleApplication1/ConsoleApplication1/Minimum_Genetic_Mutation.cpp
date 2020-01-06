//LeetCode 433. Minimum Genetic Mutation  

#include "mainHeader.h"
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int diff(const string& a, const string& b) {
	int d = 0;
	for (int i = 0; i < 8; i++) {
		if (a[i] != b[i])d++;

	}
	return d;
}
 


int minMutation(std::string start, std::string end, std::vector<std::string>& bank) {
	if (bank.size() == 0)return -1;
	vector< vector<char>>graph;
	vector<char>visited;
	int n =(int) bank.size();
	graph.resize(n);
	visited.resize(n);
	int  end_pos = -1;
	//build graph
	for (int i = 0; i < n; i++) {
		  visited[i] = '0';
		if (bank[i] == end)end_pos = i;
		for (int j = 0; j < n; j++) {
			if (diff(bank[i], bank[j]) == 1)  graph[i].push_back(j);
		}
	}
	if (end_pos == -1)return -1;
	int ans = 0;
	vector<int> now({ end_pos});
	visited[end_pos] = '1';
	vector<int> next;
	//BFS
	while (!now.empty()){
		for (auto& i : now) {
		
			if (diff(bank[i], start) == 1)return ans + 1;
			for (int j : graph[i]) {
				if (visited[j] == '0') {
					next.push_back(j);
					visited[j] = '1';
				}
				
			
			}
		
		}
		now = next;
		next.clear();
		ans++;
	}
	return -1;

	}




 