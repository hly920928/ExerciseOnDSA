//LeetCode 440. K-th Smallest in Lexicographical Order
#include "mainHeader.h"
#include <iostream>;
using namespace std;
int lowDigit[10] = { 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};

int countStrWithHeader(const string& header, const string& max) {
	int len = header.size();
	if (len == max.size())return 1;
	string subMax = max.substr(0, len);
	if (subMax == header) {
		int sameDigit = atoi(max.substr(len, max.size()).data()) + 1;
		return lowDigit[max.size() - len - 1]+ sameDigit;
	}
	if (subMax> header)return lowDigit[max.size() - len];
	if (subMax < header) {
		return lowDigit[max.size() - len - 1];
	}
	return -1;
};
int findKthNumber_re(string header, int headerIndex, const int targetIndex, const string& max) {
	if (headerIndex == targetIndex)return atoi(header.data());
	int now_index = headerIndex+1;
	int next_index = now_index + countStrWithHeader(header+"0",max) ;
	for (int i =0; i <=8; i++) {
		//cout << header + to_string(i) << " " << now_index << endl;
		if (next_index > targetIndex) {
			return findKthNumber_re(header + to_string(i), now_index, targetIndex, max);
		}
		else {
			now_index = next_index;
			int bw = countStrWithHeader(header + to_string(i + 1), max);
			
			next_index = next_index+bw;
		}
		
	}

   return findKthNumber_re(header + to_string(9), now_index, targetIndex, max);;
}
int findKthNumber(int n, int k) {
	int now_index = 1;
	int next_index = countStrWithHeader("1",to_string(n));
	next_index++;
	for (int i = 2; i <=9; i++) {
		if (next_index == k)return i;
		if (next_index > k) {
			return findKthNumber_re(to_string(i - 1), now_index, k, to_string(n));
		}
		now_index = next_index;
		int bw = countStrWithHeader(to_string(i), to_string(n));
		next_index = next_index + bw;
	}
	 return findKthNumber_re(to_string(9), now_index, k, to_string(n));
}
