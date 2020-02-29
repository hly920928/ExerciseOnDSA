//472. Concatenated Words
#include "mainHeader.h"
using namespace std;
vector<string>* _w;
class TriesNode {
public:
	TriesNode* next[26];
	bool hasWords;
	TriesNode() :hasWords(false) {
		for (auto& p : next)p = nullptr;
	}
};
void addToTries(const string& str, TriesNode* root) {
	auto now = root;
	for (int i = 0; i < str.size(); i++) {
		if (now->next[str[i] - 'a'] == nullptr) {
			now->next[str[i] - 'a'] = new TriesNode();

		}
		if (i == str.size() - 1) {
			now->next[str[i] - 'a']->hasWords = true;
		}
		now = now->next[str[i] - 'a'];
	}
}
 
bool isConcat_DFS(const string& str,  TriesNode* root,TriesNode* now,int i) {
 
	if (i >= str.size())return false;
	if (i == str.size() - 1) {
		char last = str[i];
		if (now->next[last - 'a'] == nullptr)return false;
		else return now->next[last - 'a']->hasWords;
	}
	auto next = now->next[str[i] - 'a'];
	if (next == nullptr)return false;
	if (next->hasWords) {
		if (isConcat_DFS(str, root, root, i + 1))return true;
	}
	return isConcat_DFS(str, root, next, i + 1);
}
bool isLonger(  int a,int b) {
	const auto& words = *_w;
	return words[a].size() < words[b].size();
}
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
	vector<string> ans;
	if (words.size() == 0)return ans;
	_w = &words;
	vector<int>index; index.resize(words.size());
	for (int i = 0; i < words.size(); i++) index[i] = i;
	sort(index.begin(), index.end(), isLonger);
	TriesNode root;
	for (int i = 0; i < words.size(); i++) {
		string& now = words[index[i]];
		if (now.size() == 0)continue;
		if (isConcat_DFS(now, &root, &root,0))ans.push_back(now);
		addToTries(now, &root);
	}
	return ans;
}