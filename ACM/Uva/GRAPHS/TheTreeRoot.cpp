#include <bits/stdc++.h>
using namespace std;
int dp[5001];
vector<int> graph[5001];
vector<int> diameter;
vector<int> best, worst;
int n;
int maxDst, maxInd;
bool w;
void dfs(int curr, int dad, int dst) {
	if (!w && dst > maxDst)
		maxDst = dst, maxInd = curr;
	if (w && dst == maxDst)
		worst.push_back(curr);
	for (int i = 0; i < (int) graph[curr].size(); i++) {
		if (graph[curr][i] != dad) {
			dfs(graph[curr][i], curr, 1 + dst);
		}
	}
}

int dfs_diameter(int curr, int dad) {
	int h = 0;
	for (int i = 0; i < (int) graph[curr].size(); i++) {
		if (graph[curr][i] != dad) {
			h = max(h, 1 + dfs_diameter(graph[curr][i], curr));
		}
	}
	return dp[curr] = h;
}

void set_diameter(int curr, int dad) {
	if (dp[curr] == 0) {
		diameter.push_back(curr);
		return;
	}
	for (int i = 0; i < (int) graph[curr].size(); i++) {
		if (graph[curr][i] != dad) {
			if (1 + dp[graph[curr][i]] == dp[curr]) {
				diameter.push_back(curr);
				set_diameter(graph[curr][i], curr);
				return;
			}
		}
	}
}
int main() {
	int i, j, k, a, siz;
	while (scanf("%d", &n) != EOF) {
		diameter.clear();
		best.clear();
		worst.clear();
		w = false;
		for (i = 1; i <= n; i++) {
			graph[i].clear();
			dp[i] = -1;
			scanf("%d", &k);
			for (j = 0; j < k; j++) {
				scanf("%d", &a);
				graph[i].push_back(a);
			}
		}
		maxDst = maxInd = 1;
		dfs(1, 0, 0);
		dfs_diameter(maxInd, 0);
		set_diameter(maxInd, 0);
		siz = (int) diameter.size();
		best.push_back(diameter[siz / 2]);
		if (siz % 2 == 0)
			best.push_back(diameter[siz / 2 - 1]);
		for (i = 0; i < (int) best.size(); i++) {
			maxDst = 1;
			w = false;
			dfs(best[i], 0, 0);
			w = true;
			dfs(best[i], 0, 0);
		}
		sort(best.begin(), best.end());
		sort(worst.begin(), worst.end());
		printf("Best Roots  :");
		for (i = 0; i < (int) best.size(); i++)
			printf(" %d", best[i]);
		printf("\nWorst Roots :");
		for (i = 0; i < (int) worst.size(); i++)
			printf(" %d", worst[i]);
		printf("\n");

	}
	return 0;
}
