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
vector<int> currAns;
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

int main() {
	int i, a, b, c, n, m;
	while (scanf("%d%d", &n, &m) && (n + m)) {
		edges.clear();
		currAns.clear();
		for (i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			edges.push_back(edge(a, b, c));
		}

		sort(edges.begin(), edges.end());
		DisjSets uf(n);
		for (i = 0; i < (int) edges.size(); i++) {
			if (uf.find(edges[i].p) == uf.find(edges[i].q)) {
				currAns.push_back(-edges[i].d);
				continue;
			}
			uf.merge(edges[i].p, edges[i].q);
		}
		if (currAns.size()) {
			sort(currAns.begin(), currAns.end());
			while (currAns.size() > 1)
				printf("%d ", -currAns.back()), currAns.pop_back();
			printf("%d\n", -currAns.back());
			currAns.pop_back();
		} else {
			printf("forest\n");
		}
	}
	return 0;

}
