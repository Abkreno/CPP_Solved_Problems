#include <bits/stdc++.h>
using namespace std;
int n;

bool f;
bool visited[301];

vector<char> c;
vector<int> graph[301];

bool valid(int x) {
	for (int i = 0; i < (int) graph[x].size(); i++) {
		if (visited[graph[x][i]])
			return false;
	}
	return true;
}

void dfs(string path) {
	if ((int) path.length() == n) {
		f = true;
		printf("%c", path[0]);
		for (int i = 1; i < n; i++) {
			printf(" %c", path[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[c[i] - 'A'] && valid(c[i] - 'A')) {
			visited[c[i] - 'A'] = true;
			dfs(path + c[i]);
			visited[c[i] - 'A'] = false;
		}
	}
}
stringstream ss;
string line;
int main() {
	int i, t;
	char a, b, x;
	scanf("%d\n\n", &t);
	while (t--) {
		memset(visited, 0, sizeof visited);
		c.clear();
		for (i = 0; i < 301; i++)
			graph[i].clear();
		getline(cin, line);
		ss.clear();
		ss.str(line);
		while (ss >> a)
			c.push_back(a);
		n = c.size();

		sort(c.begin(), c.end());
		getline(cin, line);
		ss.clear();
		ss.str(line);
		while (ss >> a >> x >> b) {
			graph[a - 'A'].push_back(b - 'A');
		}
		f = false;
		dfs("");
		if (!f)
			puts("NO");
		if (t)
			puts("");
		getline(cin, line);
	}

}

