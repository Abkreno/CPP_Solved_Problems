#include <bits/stdc++.h>
using namespace std;

int n, bestS, m;
vector<int> graph[10];
void dfs(int curr, int dad, int l) {
	if (l > m) {
		m = l;
		bestS = curr;
	}
	for (int i = 0; i < (int) graph[curr].size(); i++) {
		if (graph[curr][i] != dad)
			dfs(graph[curr][i], curr, l + 1);
	}
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	m = -1;
	dfs(1, 0, 0);
	m = -1;
	dfs(bestS, 0, 0);
	printf("%d\n", m);
	return 0;
}
