//LeetCode 488. Zuma Game
#include "mainHeader.h"
#include <queue> 
#include <vector>
using namespace std;

class balls {

public:
	char color;//red(R) 0, yellow(Y) 1, blue(B) 2, green(G) 3, white(W) 4
	char counts;
	balls(char cr = 5, char ct = 0) : color(cr), counts(ct) {};
};

class state {
private:
	vector<balls> table;
	int hands[5];//red(R) 0, yellow(Y) 1, blue(B) 2, green(G) 3, white(W) 4
	int depth;
	int remain;
public:
	state(string& board, string& hand) {};
	bool operator<(state& b)const  {
		if (depth > b.depth)return true;
		if (depth < b.depth)return false;
		if (remain > b.remain)return true;
		if (remain < b.remain)return false;
		return false;
	}
	bool produceNextAndTestEmpty(priority_queue<state>& pq) {
		return false;
	}
	int getDepth()const {
		return depth;
	}
private:
	bool removeAtAndTryMerge(int id) {
		return false;
	}
};


int findMinStep(string board, string hand) {
	priority_queue<state> pq;
	state root(board, hand); pq.push(root);
	while (!pq.empty()) {
		auto st = pq.top(); pq.pop();
		if (st.produceNextAndTestEmpty(pq))return st.getDepth() + 1;
	}
	return -1;
}
