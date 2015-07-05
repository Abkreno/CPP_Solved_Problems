#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long a[70][12];
int mainmm() {
	int t, k, i, j, n, m, b, c, d, e, f, g;
	scanf("%d", &t);
	for (i = 0; i <= 9; i++)
		a[1][i] = 1;
	a[1][10] = 10;
	for (i = 2; i <= 64; i++) {
		for (j = 0; j <= 9; j++) {
			for (k = j; k <= 9; k++)
				a[i][j] = a[i][j] + a[i - 1][k];
		}
		for (j = 0; j <= 9; j++)
			a[i][10] = a[i][10] + a[i][j];
	}
	for (k = 1; k <= t; k++) {
		scanf("%d%d", &b, &c);
		printf("%d %lld\n", b, a[c][10]);
	}
	return 0;
}

