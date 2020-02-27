//472. Concatenated Words
#include "mainHeader.h"
using namespace std;
vector<string>* _w;
class TriesNode {
public:
	TriesNode* next[26];
	TriesNode() {
		for (auto& p : next)p = nullptr;
	}
};
void addToTries(const string& str, TriesNode* root) {

}
bool isConcat(const string& str, TriesNode* root) {
	return false;
}
bool isLonger(  int a,int b) {
	const auto& words = *_w;
	return words[a].size() < words[b].size();
}
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
	vector<string> ans;
	_w = &words;
	vector<int>index; index.resize(words.size());
	for (int i = 0; i < words.size(); i++) {
		index[i] = i;
	}
	sort(index.begin(), index.end(), isLonger);
	TriesNode root;
	for (int i = 0; i < words.size(); i++) {
		string& now = words[index[i]];
		if (isConcat(now, &root))ans.push_back(now);
		addToTries(now, &root);
	}
	return ans;
}