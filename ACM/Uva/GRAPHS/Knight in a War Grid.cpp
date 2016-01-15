#include <bits/stdc++.h>
using namespace std;
int N, M, n, m;
bool inBounds(int i, int j) {
	return i < N && j < M && i >= 0 && j >= 0;
}
bool grid[101][101];
bool visited[101][101];
int counts[101][101];
void dfs(int i, int j);
void dfs2(int i, int j, int nI, int nJ) {
	if (inBounds(nI, nJ) && grid[nI][nJ]) {
		counts[nI][nJ]++;
		if (!visited[nI][nJ])
			dfs(nI, nJ);
	}
}
void go(int i, int j, int n, int m) {
	int limit1 = n == 0 ? 1 : 2;
	int limit2 = m == 0 ? 1 : 2;
	for (int x = -1; x < limit1; x += 2)
		for (int y = -1; y < limit2; y += 2)
			dfs2(i, j, i + (x * n), j + (y * m));

}
void dfs(int i, int j) {
	visited[i][j] = 1;
	go(i, j, n, m);
	if (m != n)
		go(i, j, m, n);
}
int main() {
	int T, i, j, e, o, a, b, c, cnt = 1;
	scanf("%d", &T);
	while (T--) {
		m = 0;
		memset(grid, 1, sizeof(grid));
		memset(visited, 0, sizeof(visited));
		memset(counts, 0, sizeof(counts));
		scanf("%d%d%d%d\n%d", &N, &M, &n, &m, &c);
		for (i = 0; i < c; i++) {
			scanf("%d%d", &a, &b);
			grid[a][b] = 0;
		}
		dfs(0, 0);
		e = o = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (counts[i][j] != 0 || (!i && !j)) {
					if (counts[i][j] % 2)
						o++;
					else
						e++;
				}
			}
		}
		printf("Case %d: %d %d\n", cnt++, e, o);
	}

}

