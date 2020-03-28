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


inline char colorToId(char c) {
	if (c == 'R')return 0;
	if (c == 'Y')return 1;
	if (c == 'B')return 2;
	if (c == 'G')return 3;
	if (c == 'W')return 4;
	return -1;
}
class state {
private:
	vector<balls> table;
	int hands[5];//red(R) 0, yellow(Y) 1, blue(B) 2, green(G) 3, white(W) 4
	int depth;
	int remain;
public:
	state() :depth(0), remain(0) {
		for (int& i : hands) i = 0;
	}
	state(string& board, string& hand) {
		depth = 0; remain = board.size();
		for (int& i : hands) i = 0;
		table.push_back(balls(colorToId(board[0]),1));
		for (int i = 1; i < board.size(); i++) {
			if (board[i] == board[i - 1]) {
				table[table.size() - 1].counts++;
			}
			else {
				table.push_back(balls(colorToId(board[i]), 1));
			}
		}
		
		for (char c : hand)hands[colorToId(c)]++;
	
	};
	bool operator<(const state& b)const  {
		if (depth > b.depth)return true;
		if (depth < b.depth)return false;
		if (remain > b.remain)return true;
		if (remain < b.remain)return false;
		return false;
	}
	bool produceNextAndTestEmpty(priority_queue<state>& pq) {
		vector<int>pos_1; vector<int>pos_2;
		for (int i = 0; i < table.size(); i++) {
			char cr = table[i].color;
			char ct = table[i].counts;
			if (ct == 1 && hands[cr] >= 2)pos_1.push_back(i);
			if (ct ==2 && hands[cr] >= 1)pos_2.push_back(i);
		}
		for (int i : pos_2) {
			state neo;
			if (removeAndMergeAndTestEmpty(neo, i, 2))return true;
			pq.push(neo);
		}

		for (int i : pos_1) {
			state neo;
			if (removeAndMergeAndTestEmpty(neo, i, 1))return true;
			pq.push(neo);
		}
		return false;
	}
	int getDepth()const {
		return depth;
	}
private:
	bool removeAndMergeAndTestEmpty(state& out,int id,char type) {

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
