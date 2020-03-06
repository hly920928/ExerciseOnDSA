//476. Number Complement
#include "mainHeader.h"
int findComplement(int num) {
	int mask = 0; int now = 1;

	unsigned int n = num;
	while (mask < num) {
		mask += now;
		now = now << 1;
	}
	return (~n)-(~mask);
}