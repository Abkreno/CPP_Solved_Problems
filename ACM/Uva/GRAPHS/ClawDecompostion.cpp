#include <bits/stdc++.h>
using namespace std;
vector<int> graph[305];
int color[305];
int main() {
	int i, j, n, m, a, b;
	while (scanf("%d", &n)) {
		if (!n)
			break;
		memset(color, -1, sizeof(color));
		for (i = 0; i < 305; i++)
			graph[i].clear();
		m = 0;
		while (1) {
			scanf("%d %d", &a, &b);
			if (!a && !b)
				break;
			m++;
			graph[a - 1].push_back(b - 1);
			graph[b - 1].push_back(a - 1);
		}
		queue<int> q;
		q.push(0);
		color[0] = 0;
		bool good = 1;
		for (j = 0; j < n; j++) {
			if (color[j] != -1)
				continue;
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
			if (!good)
				break;
		}
		if (good)
			printf("YES\n");
		else
			printf("NO\n");
	}

}
