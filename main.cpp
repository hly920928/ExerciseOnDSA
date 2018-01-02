#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>  
#include <string>   
#include <list>   
#include <vector> 
#include <cmath>   
#include <unordered_map>
#include <numeric>
#include "Exce_8_25.h"
#include <stack> 
#include <iomanip>
#include <bitset>
#include "Matrix.h"
#include "myDSA_II.h"
int main() {
	stringstream ss;
	ss << "E 6 8 " << "1 2 a 3 " << "1 3 b 8 ";
	ss << "2 4 c 9 " << "3 2 d 4 " << "2 5 e 6 ";
	ss << "3 5 f 10 " << "4 6 g 6 " << "5 6 h 9 ";
	MyGraphy myG(ss);
	vector<int> topoSort;
	myG.topoSort(topoSort);
	return 0;
}