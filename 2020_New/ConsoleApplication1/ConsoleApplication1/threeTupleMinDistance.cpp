
#include "mainHeader.h"
#include "limits.h"

int findMinInThree(int a, int b, int c) {
	if (a <= b && a <= c)return 1;
	if (b <= a&& b <= c)return 2;
	if (c <= a && c<= b)return 3;
}
int max(int a, int b) {
	return (a > b) ? a : b;
}
int min(int a, int b) {
	return (a< b) ? a : b;
}
int threeTupleMinDistance(int* a, int* b, int* c, int m, int n, int l) {

	int p1 = 0; int p2 = 0; int p3 = 0; int ans = INT_MAX; int now = INT_MAX; int now_a = INT_MAX;
	while(p1 < m - 1 && p2 < n - 1 && p3 < l - 1) {
		now = min(a[p1], min(b[p2], c[p3]));
		now_a = findMinInThree(a[p1], b[p2], c[p3]);
		while (a[p1] < now)p1 = min(p1+1, m - 1);
		while (b[p2] < now)p2= min(p2+1, n - 1);
		while (c[p3] < now)p3 = min(p3+1, l - 1);
		ans = min(ans, max(a[p1], max(b[p2], c[p3])) - now);
		if(now_a==1)p1 = min(p1 + 1, m - 1);
		if (now_a == 2)p2 = min(p2 + 1, n - 1);
		if (now_a == 3) p3 = min(p3 + 1, l - 1);
	}
	return ans;
}