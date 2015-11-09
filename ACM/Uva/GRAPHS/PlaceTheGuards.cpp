#include <bits/stdc++.h>
using namespace std;
vector<int> graph[205];
int color[205];
int colorCount[2] = { 0, 0 };
int main() {
	int i, j, n, m, a, b, t, res;
	bool g;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		memset(color, -1, sizeof(color));
		for (i = 0; i < 205; i++)
			graph[i].clear();
		for (i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		queue<int> q;
		res = 0;
		g = true;
		for (j = 0; j < n; j++) {
			if (color[j] != -1)
				continue;
			q.push(j);
			color[j] = 0;
			colorCount[0]++;
			while (!q.empty()) {
				a = q.front();
				q.pop();
				for (int i = 0; i < (int) graph[a].size(); i++) {
					b = graph[a][i];
					if (color[b] == -1) {
						color[b] = 1 - color[a];
						colorCount[color[b]]++;
						q.push(b);
					} else if (color[b] == color[a]) {
						g = false;
						break;
					}
				}
			}
			if (!g) {
				res = -1;
				break;
			} else {
				res += (colorCount[0] > 0 && colorCount[1] > 0) ?
						min(colorCount[0], colorCount[1]) :
						max(colorCount[0], colorCount[1]);
			}
		}
		printf("%d\n", res);
	}

}

