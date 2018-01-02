#include "stdafx.h"
#include "Real_Exam.h"
void BlackWhiteShuffle(int * a, int stop, int item, int n)
{
	if (item == 2 * n - 1) { return; }
	int i = item;
	while (i>stop + 1) {
		int t = a[i - 1];a[i] = a[i - 1];a[i - 1] = t;
		i--;
	}
	BlackWhiteShuffle(a, stop + 2, item + 1, n);
};