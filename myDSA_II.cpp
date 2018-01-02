#include "stdafx.h"
#include "myDSA_II.h"
#include <stack>
#include <algorithm>
using  namespace std;
void buildNext(vector<int>& next, const string& p,int j) {
	if (j == 0) {next[j] =-1; return;}
	int tryPos = next[j-1];
	while (true) {	
		if (tryPos == -1) {
			next[j] = 0; break;}
		if (p[tryPos] == p[j-1]) {
			next[j] = tryPos+1; break;}
		tryPos = next[tryPos];
	}
}
int KMP(const string& m, const string& p) {
	vector<int>next; next.resize(p.size());
	int size_n = p.size(); int size_m = m.size();
	for (int i = 0; i < size_n; i++)buildNext(next, p, i);
	int i = 0; int j = 0;
	while (true) {
		if (i == size_n) {
			if (j <=size_m)return j - i;
			else return j;}
		if (j == size_m)return j;
		if (m[j] == p[i]) { i++; j++; }
		else {
			i = next[i];
			if (i == -1) { i++; j++; };
		}
	};
}
MyGraphy::MyGraphy(istream& in) {
	char c; in >> c;
	if (c == 'E') {
		buildWithEdgeList(in);
	}
}
void MyGraphy::topoSort(std::vector<int>& sorted)
{
	stack<int>stk;
	vector<int> OutDeg; OutDeg.resize(numOfVertex + 1);
	vector<bool> isVisited; isVisited.resize(numOfVertex + 1);
	for (int i = 1; i < numOfVertex + 1; i++) {
		OutDeg[i] = vertex_table[i].outDeg;
		if (vertex_table[i].inDeg == 0) {
			stk.push(i); isVisited[i] = true;
		}
	}
	while (!stk.empty()) {
		int now = stk.top();
		if (OutDeg[now] == 0) {
			stk.pop(); sorted.push_back(now);
			for (int i = 1; i < numOfVertex + 1; i++)
				if (hasEdge(i, now))OutDeg[i]--;
		}
		else {
			for (int i = 1; i < numOfVertex + 1; i++)
				if (hasEdge(now, i) && !isVisited[i]) {
					stk.push(i); isVisited[i] = true; goto Out;
				}
		}
	Out:;
	}
	reverse(sorted.begin(), sorted.end());
}

void MyGraphy::CriticalPath(std::vector<std::string>& paths)
{
}
void MyGraphy::buildWithEdgeList(istream& in) {
	in >> numOfVertex;
	in >> numOfEdge;
	adjMatrix.resize(numOfVertex + 1);
	vertex_table.resize(numOfVertex + 1);
	for (auto& vector : adjMatrix)vector.resize(numOfVertex + 1);
	for (int i = 1; i < numOfVertex + 1;i++)vertex_table[i] = MyGraphy_Vertex(i, i, 0, 0);
	int s; int e; char num; int w;
	for (int i = 0; i < numOfEdge; i++) {
		in >> s >> e >> num >> w;
		adjMatrix[s][e] = MyGraphy_Edge(num, w);
		vertex_table[s].outDeg++;
		vertex_table[e].inDeg++;
	}
}

bool MyGraphy::hasEdge(int i, int j)
{
	if (adjMatrix[i][j].id == ' ')return false;
	return true;
}
