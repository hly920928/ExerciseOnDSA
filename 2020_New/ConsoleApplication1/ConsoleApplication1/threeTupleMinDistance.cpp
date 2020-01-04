
#include "mainHeader.h"
#include "limits.h"

int findUp(int a, int b, int c,bool f1, bool f2, bool f3) {

	if(f1&&f2&&f3)return 0;
	if (!f1 && f2 && f3)return 1;
	if (f1 && !f2 && f3)return 2;
	if (f1 && f2 && !f3)return 3;
	if (f1)return  (b <= c) ? 2 : 3;
	if (f2)return  (a <= c) ? 1 : 3;
	if (f3)return  (a <= b) ? 1 : 2;
	if (a <= b && a <= c)return 1;
	if (b <= a && b <= c)return 2;
	if (c <= a && c <= b)return 3;
	return 0;
}
int max(int a, int b) {return (a > b) ? a : b;}
int min(int a, int b) {return (a< b) ? a : b;}

int threeTupleMinDistance(int a[], int  b[], int  c[], int m, int n, int l) {

	int p1 = 0; int p2 = 0; int p3 = 0; int ans = INT_MAX; int now = INT_MAX; int now_up = INT_MAX;
	while(true) {
		now = min(a[p1], min(b[p2], c[p3]));
		while (a[p1] < now&& p1 != m - 1)p1++;
		while (b[p2] < now && p2 !=n - 1)p2++;
		while (c[p3] < now&& p3 !=l - 1)p3++;
		ans = min(ans, max(a[p1], max(b[p2], c[p3])) - now);
		now_up = findUp(a[p1], b[p2], c[p3], p1 == m - 1, p2 == n - 1, p3 == l - 1);
		if (!now_up)break;
		if (now_up == 1) p1++;
		if (now_up == 2)p2++;
	    if (now_up == 3) p3++;
	}
	return ans;  
}