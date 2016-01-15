#include <bits/stdc++.h>
using namespace std;
vector<int> graph[205];
int color[205];
int main() {
	int i, n, m, a, b, cnt = 1;
	while (scanf("%d", &n)) {
		if (!n)
			break;
		memset(color, -1, sizeof(color));
		for (i = 0; i < 205; i++)
			graph[i].clear();
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
		}
		queue<int> q;
		q.push(0);
		color[0] = 0;
		bool good = 1;
		while (!q.empty()) {
			a = q.front();
			q.pop();
			for (int i = 0; i < (int) graph[a].size(); i++) {
				if (color[graph[a][i]] == -1) {
					color[graph[a][i]] = 1 - color[a];
					q.push(graph[a][i]);
				} else if (color[graph[a][i]] == color[a]) {
					good = false;
					break;
				}
			}
		}
		if (good)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}

}

