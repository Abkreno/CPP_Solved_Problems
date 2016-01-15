#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define UNVISITED -1
int dfsNumberCounter, numSCC;
vi dfs_num, dfs_low, S, visited; // global variables
vi AdjList[100];
map<string, int> names;
string ans[100];
bool done[100];
void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
	S.push_back(u); // stores u in a vector based on order of visitation
	visited[u] = 1;
	for (int j = 0; j < (int) AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if (dfs_num[v] == UNVISITED)
			tarjanSCC(v);
		if (visited[v]) // condition for update
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
		while (1) {
			int v = S.back();
			S.pop_back();
			visited[v] = 0;
			cout << ans[v];
			if (u == v)
				break;
			else
				cout << ", ";
		}
		printf("\n");
	}
}

int main() {
	int i, N, V, x, y, index, cnt = 1;
	bool xx = 0;
	string a, b;
	while (scanf("%d %d", &N, &V)) {
		if (!N && !V)
			break;
		for (i = 0; i < N; i++)
			AdjList[i].clear();
		names.clear();
		memset(done, 0, sizeof done);
		index = 0;
		for (i = 0; i < V; i++) {
			cin >> a >> b;
			if (names.find(a) == names.end()) {
				ans[index] = a;
				names.insert(make_pair(a, index++));
			}
			x = names[a];
			if (names.find(b) == names.end()) {
				ans[index] = b;
				names.insert(make_pair(b, index++));
			}
			y = names[b];
			AdjList[x].push_back(y);
		}
		if (xx)
			printf("\n");
		dfs_num.assign(N, UNVISITED);
		dfs_low.assign(N, 0);
		visited.assign(N, 0);
		dfsNumberCounter = numSCC = 0;
		printf("Calling circles for data set %d:\n", cnt++);
		for (int i = 0; i < index; i++)
			if (dfs_num[i] == UNVISITED)
				tarjanSCC(i);
		xx = 1;
	}

}
