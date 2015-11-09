#include <bits/stdc++.h>
using namespace std;
bool visited[50001];
int dp[50001];
int graph[50001];
int N;
int dfs(int curr) {
	visited[curr] = 1;
	int ans = 0;
	if (graph[curr] != -1 && !visited[graph[curr]]) {
		ans = max(ans, 1 + dfs(graph[curr]));
	}
	visited[curr] = 0;
	return dp[curr] = ans;
}
int main() {
	int T, i, ans, a, b, c, cnt = 1, start;
	scanf("%d", &T);
	while (T--) {
		memset(dp, -1, sizeof(dp));
		memset(graph, -1, sizeof(graph));
		memset(visited, 0, sizeof(visited));
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%d%d", &a, &b);
			graph[a - 1] = b - 1;
		}
		ans = 0;
		start = 1;
		for (i = 0; i < N; i++)
			if (dp[i] == -1) {
				c = dfs(i);
				if (c > ans) {
					ans = c;
					start = i + 1;
				}
			}
		printf("Case %d: %d\n", cnt++, start);
	}

}

