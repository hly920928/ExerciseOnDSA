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
void MyGraphy::topoSort(std::vector<int>& sorted)const
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
			for (auto i:vertex_table[now].inVertex)OutDeg[i]--;
		}
		else {
			for (auto i : vertex_table[now].outVertex)
				if (!isVisited[i]) {
					stk.push(i); isVisited[i] = true; goto Out;
				}
		}
	Out:;
	}
	reverse(sorted.begin(), sorted.end());
}

void MyGraphy::CriticalPath(std::vector<std::vector<int>>& path)const
{
	vector<int> topoOrder; topoSort(topoOrder);
	vector<int> ve; ve.resize(numOfVertex + 1);
	vector<int> vl; vl.resize(numOfVertex + 1);
	//ve
	{
		auto& itr_f = topoOrder.begin();
		ve[*itr_f] = 0; vl[*itr_f] = 0; itr_f++;
		while (itr_f != topoOrder.end()) {
			int now = *itr_f;
			ve[now] = INT_MIN;
			if (vertex_table[now].inDeg == 0) {
				ve[now] = 0; break;
			}
			for (int i : vertex_table[now].inVertex) {
				int et = ve[i] + adjMatrix[i][now].weight;
				ve[now] = (ve[now] > et) ? ve[now] : et;
			}
			itr_f++;
		}
	}
	//vl
	{
	auto& itr_b = topoOrder.end() - 1;
		vl[*itr_b] = ve[*itr_b]; itr_b--;
		while (itr_b != topoOrder.begin()) {
			int now = *itr_b;
			vl[now] = INT_MAX;
			if (vertex_table[now].outDeg == 0) {
				vl[now] = 0; break;
			}
			for (int i : vertex_table[now].outVertex) {
				int lt = vl[i] - adjMatrix[now][i].weight;
				vl[now] = (vl[now] <lt) ? vl[now] : lt;
			}
			itr_b--;
		}
	}
	//buildCriticalPath
	{
		stack< vector<int>> stk; vector<int>p;
		p.push_back(*topoOrder.begin());
		stk.push(p);
		int total_time = ve[topoOrder.back()];
		while (!stk.empty()) {
			auto now = stk.top(); stk.pop();
			int end = now.back();
			if (vertex_table[end].outDeg == 0 ) {
				if (pathWeight (now)== total_time)
					path.push_back(now); 
				continue;
			}
			for (int i : vertex_table[end].outVertex) {
				if (ve[i] == vl[i]) {
					now.push_back(i);
					stk.push(now);
					now.pop_back();}
			}
		}
		int end=10;
	}
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
		vertex_table[s].outVertex.push_back(e);
		vertex_table[e].inDeg++;
		vertex_table[e].inVertex.push_back(s);
	}
}

bool MyGraphy::hasEdge(int i, int j)
{
	if (adjMatrix[i][j].id == ' ')return false;
	return true;
}

int MyGraphy::pathWeight(std::vector<int>& p)const
{
	 int sum = 0;
	 for (int i = 0; i < p.size() - 1; i++) 
		 sum += adjMatrix[p[i]][p[i + 1]].weight;
	 return sum;
}


