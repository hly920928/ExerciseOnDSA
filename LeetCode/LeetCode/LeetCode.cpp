// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myHeader.h"
#include <vector>
using namespace std;
int main()
{ 
	NestedInteger n1(1); NestedInteger n2(2);
	vector<NestedInteger>v1({ n1,n1 });
	NestedInteger t1(&v1);
	vector<NestedInteger>v2({ t1,NestedInteger(2),t1 });
	NestedIterator itr(v2);
	vector<int>ans;
	while (itr.hasNext())ans.push_back(itr.next());
    return 0;
}

