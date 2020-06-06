//502. IPO
using namespace std;
#include "mainHeader.h"
#include <queue>
class project {
public:
	int p;
	int c;
	project(int _p = -1, int _c = -1) :p(_p), c(_c) {};
	bool operator<(const project& b)const  {
		return c < b.c;
	}
};
int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
	vector<project>projects;
	int len = Profits.size();
	if (len != Capital.size())return W;
	for (int i = 0; i < len; i++)projects.push_back(project(Profits[i], Capital[i]));
	sort(projects.begin(), projects.end());
	priority_queue<int>projects_can_done;
	int now_project_pos = 0;
	int ans = W;
	for (int i = 0; i < k; i++) {
		while (now_project_pos < len && projects[now_project_pos].c <= ans) {
			projects_can_done.push(projects[now_project_pos].p);
			now_project_pos++;
		}
		if (projects_can_done.empty())break;
		ans += projects_can_done.top(); projects_can_done.pop();
	}
	return ans;
}