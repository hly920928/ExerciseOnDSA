//483. Smallest Good Base
#include "mainHeader.h"
using namespace std;
bool isGoodBase(unsigned long long n, int base) {
	return false;
}
int binarySearch_re(unsigned long long n, unsigned long long lo, unsigned long long hi) {
	return 0;
}
string smallestGoodBase(string n) {
	unsigned long long _n = strtoull(n.data(),NULL,10);
	return to_string(binarySearch_re(_n, 2, _n));
}