#pragma once
#include <string>
#include <vector>
#include <list>
#include <iostream>
int KMP(const std::string& m, const std::string& p);
struct MyGraphy_Vertex {
	int n;
	char id;
	int inDeg;
	int outDeg;
	std::vector<int> inVertex;
	std::vector<int> outVertex;
	MyGraphy_Vertex(int _n = -1, int _id = -1, int i_D = -1, int o_D = -1) :
		n(_n), id(_id), inDeg(i_D), outDeg(o_D) {};

};
struct MyGraphy_Edge {
	int weight;
	char id;
	MyGraphy_Edge(char i =' ', int w = -1): weight(w), id(i){};
};
class MyGraphy {
private:
	int numOfVertex;
	int numOfEdge;
	std::vector<std::vector<MyGraphy_Edge>>adjMatrix;
	std::vector<MyGraphy_Vertex> vertex_table;
public:
	MyGraphy(std::istream& in);
	void topoSort(std::vector<int>& sorted)const;
	void CriticalPath(std::vector<std::vector<int>>& path) const;
private:
	void buildWithEdgeList(std::istream& in);
	bool hasEdge(int i, int j);
	int pathWeight(std::vector<int>& p)const;
};