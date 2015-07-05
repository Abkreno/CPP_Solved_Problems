#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <vector>

using namespace std;
int main2() {
	int t, C = 1;
	scanf("%d", &t);
	while (t--) {
		int n, p, q;
		scanf("%d%d%d", &n, &p, &q);
		int prince[p + 1];
		int queen[q + 1];
		for (int i = 0; i < p + 1; i++) {
			scanf("%d", &prince[i]);
		}
		for (int i = 0; i < q + 1; i++) {
			scanf("%d", &queen[i]);
		}
		int M = p + 1;
		int N = q + 1;
		int opt[M + 1][N + 1];
		int maxl = 0;
		for (int i = M - 1; i >= 0; i--) {
			for (int j = N - 1; j >= 0; j--) {
				if (prince[i] == queen[j]) {
					opt[i][j] = opt[i + 1][j + 1] + 1;
					maxl = max(maxl, opt[i][j]);
				} else {
					opt[i][j] = max(opt[i + 1][j], opt[i][j + 1]);
					maxl = max(maxl, opt[i][j]);
				}
			}
		}

		printf("Case %d: %d\n", C++, maxl);
	}
	return 0;
}
