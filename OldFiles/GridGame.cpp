#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <math.h>
#define Max_Val 1000000;
#define Min_Val -1000000;
using namespace std;

int grid[8][8];
int DP[1 << 8][1 << 8][8];
int n;
int f(int row, int col, int last, bool aliceTurn) {
	if (col == (1 << n) - 1 && row == (1 << n) - 1)
		return 0;
	if (DP[row][col][last] != -1)
		return DP[row][col][last];
	if (aliceTurn) {
		int Max = Min_Val
		;
		for (int i = 0; i < n; i++) {
			int mask = 1 << i;
			if ((mask & row) == 0)
				Max = max(Max, f(row ^ mask, col, i, false));
		}
		return DP[row][col][last] = Max;
	} else {
		int Min = Max_Val
		;
		for (int i = 0; i < n; i++) {
			int mask = 1 << i;
			if ((mask & col) == 0)
				Min = min(Min, grid[last][i] + f(row, col ^ mask, i, true));
		}
		return DP[row][col][last] = Min;
	}
}

int mai2() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(DP, -1, sizeof(DP));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		cout << f(0, 0, 0, true) << endl;
	}
}
