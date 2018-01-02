#include "stdafx.h"
#include <iostream> 
#include <string>
#include <algorithm>
#include <vector>
////http://acm.nefu.edu.cn/JudgeOnline/problemShow.php?problem_id=488
using namespace std;
struct accountEntry {
	int need;
	int remainClean;
	int remainDirty;
	int out_S;
	int out_F;
	int buy_P;
	int total_cost;
	accountEntry() :need(0),
		remainClean(0),
		remainDirty(0),
		out_S(0),
		out_F(0),
		buy_P(0),
		total_cost(0) {}
};
class ledger {
private:
	int total_day;
	int cost_P;
	int clean_F;
	int clean_S;
	int dayf_M;
	int days_N;
	int total_cost;
	accountEntry* book;
public:
	ledger(istream& is) {
		is >> total_day >> cost_P >>
			dayf_M >> clean_F >> days_N >> clean_S;
		book = new accountEntry[total_day + days_N];
		for (int i = days_N; i < total_day + days_N; i++) {
			int t;
			is >> t;
			book[i].need = t;
		}
		total_cost = 0;
		solveTotal();
	}
	void solveOneDay(int i) {
		int remain_need = book[i].need;
		book[i].remainClean = book[i - 1].remainClean;
		if (remain_need > book[i].remainClean) {
			book[i].remainClean = 0;
			remain_need -= book[i].remainClean;
		}
		else {
			book[i].remainClean -= remain_need;
			return;
		}
		if (remain_need > book[i - days_N].remainDirty) {
			book[i - days_N].out_S = book[i - days_N].remainDirty;
			book[i - days_N].remainDirty = 0;
			remain_need -= book[i - days_N].out_S;
		}
		else {
			book[i - days_N].remainDirty -= remain_need;
			book[i - days_N].out_S = remain_need;
			return;
		}
		if (remain_need > book[i - dayf_M].remainDirty) {
			book[i - dayf_M].out_F = book[i - dayf_M].remainDirty;
			book[i - dayf_M].remainDirty = 0;
			remain_need -= book[i - dayf_M].out_F;
		}
		else {
			book[i - dayf_M].remainDirty -= remain_need;
			book[i - dayf_M].out_F = remain_need;
			return;
		}
		book[i].buy_P = remain_need;
		book[i].remainDirty += book[i].need;
	}
	int computeCost_one(int i) {
		book[i].total_cost = book[i].buy_P*cost_P
			+ book[i].out_F*clean_F
			+ book[i].out_S*clean_S;
		return book[i].total_cost;
	}
	int solveTotal() {
		for (int i = days_N; i < total_day + days_N; i++) {
			solveOneDay(i);
		}
		for (int i = days_N; i < total_day + days_N; i++) {
			total_cost += computeCost_one(i);
		}
		return total_cost;
	}
	void printOut(ostream& os) {
		os << total_cost << endl;
		/*
		os << "Lowest Cost " << total_cost << endl;
		for (int i = days_N; i < total_day + days_N; i++) {
		os<<"Day "<<i- days_N+1 << endl;
		os << " New napkin " << book[i].buy_P<<endl;
		os << " Send to fast laundry " << book[i].out_F << endl;
		os << " Send to slow laundry " << book[i].out_S << endl;
		os << " Delay to laundry " << book[i].remainDirty << endl;
		os << endl;
		}
		*/
	}
};