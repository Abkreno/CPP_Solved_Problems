#include <bits/stdc++.h>
using namespace std;
vector<int> graph[101];
vector<int> ans;
bool visited[101];
void dfs(int x) {
	visited[x] = 1;
	for (int i = 0; i < (int) graph[x].size(); i++) {
		if (!visited[graph[x][i]])
			dfs(graph[x][i]);
	}
	ans.push_back(x);
}
int main() {
	int i, n, m, a, b;
	while (scanf("%d %d", &n, &m)) {
		if (!n && !m)
			break;
		memset(visited, 0, sizeof(visited));
		ans.clear();
		for (i = 0; i < 101; i++)
			graph[i].clear();
		for (i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			graph[a - 1].push_back(b - 1);
		}
		for (i = 0; i < n; i++) {
			if (!visited[i])
				dfs(i);
		}
		reverse(ans.begin(), ans.end());
		for (int x = 0; x < (int) ans.size(); x++) {
			if (x < ((int) ans.size()) - 1)
				printf("%d ", ans[x] + 1);
			else
				printf("%d\n", ans[x] + 1);
		}
	}

}

