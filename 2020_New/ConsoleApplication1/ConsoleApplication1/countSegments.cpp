//Leetcode 434. Number of Segments in a String
#include "mainHeader.h"
#include <string>
#include <algorithm>
using namespace std;

int countSegments(std::string s) {
	int count = 0; bool flag = false;
	for (int i = 0; i < s.size(); i++) {
		if (flag) {
			if (s[i]==' ') {
				flag = false;
				count++;
			}	
		}
		else {
			if (s[i] != ' ')	flag = true;
		}
	}
	if (flag)count++;
	return count;


}