#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
void BlackWhiteShuffle(int * a, int stop, int item, int n);
template <class T>
void uniqueAndKeepOrder(vector<T>& a){
	unordered_map<T, int> map1;
	vector<T> t(a);
	for (int i = 0; i < a.size(); i++) {
		map1.insert({a[i], i });
	}
	sort(t.begin(), t.end());
	auto itr=unique(t.begin(), t.end());
	t.resize(itr - t.begin());
	int size = t.size();
	vector<int> temp;
	temp.resize(size);
	for (int i = 0; i <size; i++) {
		temp[i] = map1.find(t[i])->second;
	}
	sort(temp.begin(), temp.end());
	for (int i = 0; i <size; i++) {
		a[i]=a[temp[i]];
	}
	a.resize(size);
};