#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <hash_set>
using namespace std;
pair<int, int> dominos[15];
int m, nn, r;
void resetDominos() {
	for (int i = 0; i < 15; i++) {
		dominos[i] = make_pair(0, 0);
	}
}
bool f(int left, int spaces, int mask) {
	if (spaces == nn) {
		return left == r;
	}
	if (mask == (1 << m) - 1) {
		return false;
	}
	bool call = false;
	for (int i = 0; i < m; i++) {
		if (((1 << i) & mask) == 0) {
			if (dominos[i].first == left || dominos[i].second == left) {
				call = f(
						dominos[i].first == left ?
								dominos[i].second : dominos[i].first,
						spaces + 1, mask ^ (1 << i));
				if (call)
					break;
			}
		}
	}
	return call;
}

int main222() {
	int l, x;
	while (scanf("%d", &nn) && nn) {
		scanf("%d", &m);
		resetDominos();
		scanf("%d %d", &x, &l);
		scanf("%d %d", &r, &x);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &dominos[i].first, &dominos[i].second);
		}
		if (f(l, 0, 0))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
