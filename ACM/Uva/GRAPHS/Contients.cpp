#include <bits/stdc++.h>
using namespace std;
int n, m, w;
char grid[25][25];
char in[60];
int nI[4] = { -1, 1, 0, 0 };
int nJ[4] = { 0, 0, 1, -1 };
char land;
int dfs(int i, int j) {
	grid[i][j] = '!';
	int ni, nj, res = 1;
	for (int k = 0; k < 4; k++) {
		ni = i + nI[k];
		nj = j + nJ[k];
		if (nj < 0)
			nj = m - 1;
		else if (nj >= m)
			nj = 0;
		if (ni >= 0 && ni < n && grid[ni][nj] == land) {
			res += dfs(ni, nj);
		}
	}
	return res;
}
int main() {
	int i, j, ans;
	while (scanf("%d %d", &n, &m) == 2) {
		memset(grid, 0, sizeof(grid));
		for (i = 0; i < n; i++) {
			scanf("%s", grid[i]);
		}
		scanf("%d %d", &i, &j);
		land = grid[i][j];
		dfs(i, j);
		ans = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) {
				if (grid[i][j] == land) {
					ans = max(ans, dfs(i, j));
				}
			}
		printf("%d\n", ans);
	}

}

