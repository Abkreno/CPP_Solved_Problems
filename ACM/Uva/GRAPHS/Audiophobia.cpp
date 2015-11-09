#include <bits/stdc++.h>

using namespace std;
// Disjoint set forest
struct edge {
	int p, q;
	int d;
	edge(int _p = 0, int _q = 0, int _d = 0) {
		p = _p, q = _q, d = _d;
	}
	const bool operator <(const edge &two) const {
		return d < two.d;
	}
};

vector<edge> edges;
vector<edge> currAns;
vector<pair<int, int> > graph[101];
class DisjSets {
	struct Set {
		int parent;  // index of parent in vector
		int rank;

		// Construct the i'th of an array of disjoint sets
		Set(int i) :
				parent(i), rank(0) {
		}
	};

	vector<Set> forest;

public:
	DisjSets(int n) {
		forest.reserve(n);
		for (int i = 0; i < n; i++)
			forest.push_back(Set(i));
	}

	// Find set that element i belongs to, represented as an index
	int find(int i) {
		if (forest[i].parent == i)
			return i;
		else {
			forest[i].parent = find(forest[i].parent);
			return forest[i].parent;
		}
	}

	// Union (but union is a C++ keyword). Returns true iff i and j were
	// initially in different sets.
	bool merge(int i, int j) {
		int root_i = find(i);
		int root_j = find(j);
		if (root_i != root_j) {
			if (forest[root_i].rank < forest[root_j].rank)
				forest[root_i].parent = root_j;
			else if (forest[root_i].rank > forest[root_j].rank)
				forest[root_j].parent = root_i;
			else {
				forest[root_i].parent = root_j;
				forest[root_j].rank += 1;
			}
			return true;
		}
		return false;
	}
};
int m;
void dfs(int curr, int parent, int goal, int minSoFar) {
	if (curr == goal) {
		m = minSoFar;
		return;
	}
	for (int j = 0; j < (int) graph[curr].size(); j++) {
		if (graph[curr][j].first != parent) {
			dfs(graph[curr][j].first, curr, goal,
					max(minSoFar, graph[curr][j].second));
			if (m != -1)
				return;
		}
	}
}
int main() {
	int i, j, c, s, q, a, b, w, count = 1;
	bool f = false;
	while (scanf("%d%d%d", &c, &s, &q) && (c + s + q)) {
		edges.clear();
		currAns.clear();
		for (i = 0; i < 101; i++)
			graph[i].clear();
		for (i = 0; i < s; i++) {
			scanf("%d%d%d", &a, &b, &w);
			edges.push_back(edge(a, b, w));
		}

		sort(edges.begin(), edges.end());
		DisjSets uf(c + 1);
		for (i = 0; i < (int) edges.size(); i++) {
			if (uf.find(edges[i].p) == uf.find(edges[i].q)) {
				continue;
			}
			uf.merge(edges[i].p, edges[i].q);
			graph[edges[i].p].push_back(make_pair(edges[i].q, edges[i].d));
			//cout << edges[i].p << "->" << edges[i].q << endl;
			graph[edges[i].q].push_back(make_pair(edges[i].p, edges[i].d));
		}
		if (f)
			printf("\n");
		f = true;
		printf("Case #%d\n", count++);
		for (i = 0; i < q; i++) {
			scanf("%d%d", &a, &b);
			m = -1;
			for (j = 0; j < (int) graph[a].size(); j++) {
				dfs(graph[a][j].first, a, b, graph[a][j].second);
				if (m != -1)
					break;
			}
			if (m != -1) {
				printf("%d\n", m);
			} else {
				printf("no path\n");
			}
		}
	}
	return 0;
}
