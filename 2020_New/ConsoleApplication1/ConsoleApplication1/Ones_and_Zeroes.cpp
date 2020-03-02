//474. Ones and Zeroes
#include <unordered_map>
#include "mainHeader.h"
using namespace std;
class data_0_1 {
 
public:
	unsigned int _0;
	unsigned int _1;
	data_0_1(const string& str = "") {
		_1 = 0; _0 = 0;
		for (char c : str) {
			if (c == '0')_0++;
			if (c == '1')_1++;
		}
	}
	data_0_1(int a,int b) {
		_1 =b; _0 =a;
	}
	bool canProduce(const data_0_1& target) const{
		if (_0 >= target._0&& _1 >= target._1)return true;
		return false;
	}
	void add(const data_0_1& b) {
		_0 += b._0;
		_1 += b._1;
	}
	void substruct(const data_0_1& b) {
		_0 -= b._0;
		_1 -= b._1;
	}
	
	bool operator<(const data_0_1& b) {
		if ( _0 + _1< b._0 + b._1)return true;
		if (_0 + _1 > b._0 + b._1)return false;
		if (_0 > b._0)return true;
		return false;
	}
	unsigned long long toUll() {
		unsigned long long ans = 0;
		ans += _0;
		ans = ans << 32;
		ans += _1;
		return ans;
	}
};
void DFS(const vector<data_0_1>& v, int begin, data_0_1 remainInHand, data_0_1 remainInSet,int now_count,int& _max) {
	if (begin >= v.size())return;
	if (now_count+v.size() - begin <= _max)return;
	if (remainInHand.canProduce(remainInSet)) {
		now_count += v.size() - begin;
		_max = max(_max, now_count);
		return;
	}
	if (remainInHand._0 == 0 && remainInSet._1 == 0)return;
	if (remainInHand._1 == 0 && remainInSet._0 == 0)return;
	data_0_1 nextInSet = remainInSet;
	nextInSet.substruct(v[begin]);
	if (remainInHand.canProduce(v[begin])) {
		data_0_1 nextInHand = remainInHand;
		
		nextInHand.substruct(v[begin]);
	
		_max = max(_max, now_count+1);
		DFS(v, begin + 1, nextInHand, nextInSet, now_count + 1, _max);
	}
	DFS(v, begin + 1, remainInHand, nextInSet, now_count, _max);
}

const vector<data_0_1>* _v;
vector<unordered_map<unsigned long long, int>>* _t;
int* _m;

int DPS_v2( int begin, data_0_1 remainInHand, data_0_1 remainInSet) {

	const auto& v = *_v;
	if (begin >= v.size())return 0;
	//auto& _max = *_m;
	auto& table = *_t;
	auto itr = table[begin].find(remainInHand.toUll());
	if (itr != table[begin].end()) {
		//_max = max(_max, now_count + itr->second);
		return  itr->second;
	}
	
	if (remainInHand.canProduce(remainInSet)) {
		int remain = v.size() - begin;
		//now_count += remain;
		//_max = max(_max, now_count);
		table[begin][remainInHand.toUll()] = remain;
		return remain;
	}
	if (remainInHand._0 == 0 && remainInHand._1 == 0)return 0;
	if (remainInHand._0 == 0 && remainInSet._1 == 0)return 0;
	if (remainInHand._1 == 0 && remainInSet._0 == 0)return 0;
	data_0_1 nextInSet = remainInSet;
	nextInSet.substruct(v[begin]);
	int ans_1 = 0;	int ans_2 = 0;
	if (remainInHand.canProduce(v[begin])) {
		data_0_1 nextInHand = remainInHand;

		nextInHand.substruct(v[begin]);

		//_max = max(_max, now_count + 1);
		ans_1 =1+DPS_v2(begin + 1, nextInHand, nextInSet);
	}
	ans_2= DPS_v2( begin + 1, remainInHand, nextInSet);
	int ans = max(ans_1, ans_2);
	table[begin][remainInHand.toUll()] = ans;
	return ans;
}
int findMaxForm(vector<string>& strs, int m, int n) {
	vector<data_0_1> v; v.resize(strs.size()); _v = &v;
	int max = 0; _m = &max;

	vector<unordered_map<unsigned long long, int>> table; table.resize(strs.size()); _t = &table;

	data_0_1 total(0, 0);
	for (int i = 0; i < strs.size(); i++) {
		v[i] = data_0_1(strs[i]);
		total.add(v[i]);
	}
	sort(v.begin(), v.end());

	//DFS(v, 0, data_0_1(m, n), total,0, max);
	return DPS_v2(0, data_0_1(m, n), total);
}