//470. Implement Rand10() Using Rand7()
#include "mainHeader.h"
using namespace std;
int rand7() {
	return rand()%7+1;
};

int rand10() {
	int isHigherThenFive = 4;
	while (isHigherThenFive == 4)isHigherThenFive = rand7();
	int base = 6;
	while(base>5)base = rand7();
	if (isHigherThenFive < 4)return base;
	else return base + 5;
}