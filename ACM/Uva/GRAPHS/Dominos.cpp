#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define UNVISITED -1
vi S; // global variables
vi AdjList[100005];
bool visited[100005];
int ans;
void dfs(int u) {
	visited[u] = 1;
	for (int j = 0; j < (int) AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if (!visited[v])
			dfs(v);
	}
	S.push_back(u); // stores u in a vector based on order of visitation
}

int main() {
	int i, N, V, a, b, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &N, &V);
		for (i = 0; i < N; i++)
			AdjList[i].clear();
		memset(visited, 0, sizeof visited);
		for (i = 0; i < V; i++) {
			scanf("%d %d", &a, &b);
			a--;
			b--;
			AdjList[a].push_back(b);
		}
		S.clear();
		ans = 0;
		for (i = 0; i < N; i++)
			if (!visited[i])
				dfs(i);
		memset(visited, 0, sizeof visited);
		for (i = N - 1; i >= 0; i--)
			if (!visited[S[i]])
				ans++, dfs(S[i]);
		printf("%d\n", ans);
	}

}
