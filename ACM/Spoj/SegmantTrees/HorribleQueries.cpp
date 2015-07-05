#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct node {
	long long value, update;
	void reset() {
		value = 0;
		update = 0;
	}
} st[4 * MAXN];

void setUpdate(int v, long long val) {
	st[v].update += val;
}

void doUpdate(int v, int l, int r) {
	st[v].value += (r - l + 1) * st[v].update;
	if (l != r) {
		setUpdate(v * 2 + 1, st[v].update);
		setUpdate(v * 2 + 2, st[v].update);
	}
	st[v].update = 0;
}

void Update(int v, int l, int r, int i, int j, long long val) {
	if (l >= i && r <= j)
		setUpdate(v, val);
	doUpdate(v, l, r);
	if (r < i || l > j)
		return;
	if (!(l >= i && r <= j)) {
		int mid = (l + r) >> 1;
		Update(v * 2 + 1, l, mid, i, j, val);
		Update(v * 2 + 2, mid + 1, r, i, j, val);
		st[v].value = st[v * 2 + 1].value + st[v * 2 + 2].value;
	}
}

long long query(int v, int l, int r, int i, int j) {
	doUpdate(v, l, r);
	if (l >= i && r <= j)
		return st[v].value;
	if (r < i || l > j)
		return 0;
	int mid = (l + r) >> 1;
	long long ret = query(v * 2 + 2, mid + 1, r, i, j)
			+ query(v * 2 + 1, l, mid, i, j);
	st[v].value = st[v * 2 + 1].value + st[v * 2 + 2].value;
	return ret;
}

int main() {
	int T, N, Q;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < 4 * MAXN; i++)
			st[i].reset();
		scanf("%d", &Q);
		long long val;
		for (int i = 0, x, l, r; i < Q; ++i) {
			scanf("%d %d %d", &x, &l, &r);
			if (!x) {
				scanf("%lld", &val);
				Update(0, 0, N - 1, l - 1, r - 1, val);
			} else {
				printf("%lld\n", query(0, 0, N - 1, l - 1, r - 1));
			}
		}
	}
	return 0;
}
