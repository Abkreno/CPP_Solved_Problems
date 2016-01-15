#include <bits/stdc++.h>
using namespace std;
vector<int> graph[105];
map<string, int> ind;
string s[105];
vector<int> ans;
bool visited[105];
int inDeg[105];
class Prioritize {
public:
	int operator()(const int &p1, const int &p2) {
		return p1 > p2;
	}
};
string curr1, curr2;
string sol[105];
int main() {
	int i, n, m, a, b, cnt = 1;
	while (cin >> n) {
		memset(visited, 0, sizeof(visited));
		memset(inDeg, 0, sizeof(inDeg));
		ans.clear();
		ind.clear();
		for (i = 0; i < 105; i++)
			graph[i].clear();
		for (i = 0; i < n; i++) {
			cin >> sol[i];
			ind.insert(make_pair(sol[i], i));
		}
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> curr1 >> curr2;
			a = ind[curr1];
			b = ind[curr2];
			inDeg[b]++;
			graph[a].push_back(b);
		}
		priority_queue<int, vector<int>, Prioritize> pq;
		for (i = 0; i < n; i++) {
			if (inDeg[i] == 0) {
				pq.push(i);
			}
		}
		while (!pq.empty()) {
			a = pq.top();
			pq.pop();
			ans.push_back(a);
			for (int i = 0; i < (int) graph[a].size(); i++) {
				inDeg[graph[a][i]]--;
				if (inDeg[graph[a][i]] == 0)
					pq.push(graph[a][i]);
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order:",
				cnt++);
		for (int x = 0; x < (int) ans.size(); x++) {
			cout << " " << sol[ans[x]];
		}
		printf(".\n\n");
	}

}

