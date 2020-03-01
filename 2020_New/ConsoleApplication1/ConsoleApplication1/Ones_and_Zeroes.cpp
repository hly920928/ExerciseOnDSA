//474. Ones and Zeroes
#include "mainHeader.h"
using namespace std;
class data_0_1 {
private:
	unsigned int _0;
	unsigned int _1;
public:
	data_0_1(const string& str = "") {
		_1 = 0; _0 = 0;
	}
	data_0_1(int a,int b) {
		_1 = 0; _0 = 0;
	}
	bool canProduce(const data_0_1& remain) {
		return false;
	}
	void add(const data_0_1& b) {

	}
	void substruct(const data_0_1& b) {

	}
	bool operator<(const data_0_1& b) {
		return false;
	}
};
void DFS(const vector<data_0_1>& v, int begin, data_0_1 remainInHand, data_0_1 remainInSet,int& max) {
	if (begin >= v.size())return;

}
int findMaxForm(vector<string>& strs, int m, int n) {
	vector<data_0_1> v; v.resize(strs.size());
	data_0_1 total(0, 0);
	for (int i = 0; i < strs.size(); i++) {
		v[i] = data_0_1(strs[i]);
		total.add(v[i]);
	}
	sort(v.begin(), v.end());
	int max = 0;
	DFS(v, 0, data_0_1(m, n), total, max);
	return max;
}