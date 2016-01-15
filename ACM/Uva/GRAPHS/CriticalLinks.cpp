#include <bits/stdc++.h>
using namespace std;
int dfsNumberCounter;
vector<int> dfs_num, dfs_parent, dfs_low;
vector<int> AdjList[200];
vector<pair<int, int> > ans;
int UNVISITED = -10;
void Bridge(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
	for (int j = 0; j < (int) AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if (dfs_num[v] == UNVISITED) { // a tree edge
			dfs_parent[v] = u;
			Bridge(v);
			if (dfs_low[v] > dfs_num[u]) { // for bridge
				ans.push_back(make_pair(min(u, v), max(u, v)));
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
		} else if (v != dfs_parent[u]) // a back edge and not direct cycle
			dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
	}
}
int main() {
	int i, j, n, a, b, v;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			AdjList[i].clear();
		ans.clear();
		dfsNumberCounter = 0;
		dfs_num.assign(n, UNVISITED);
		dfs_low.assign(n, 0);
		dfs_parent.assign(n, 0);
		for (i = 0; i < n; i++) {
			scanf("%d (%d)", &v, &a);
			for (j = 0; j < a; j++) {
				scanf("%d", &b);
				AdjList[v].push_back(b);
			}
		}
		for (i = 0; i < n; i++)
			if (dfs_num[i] == UNVISITED) {
				Bridge(i);
			}
		sort(ans.begin(), ans.end());
		printf("%d critical links\n", (int) ans.size());
		for (i = 0; i < (int) ans.size(); i++) {
			printf("%d - %d\n", ans[i].first, ans[i].second);
		}
		printf("\n");
	}

}
