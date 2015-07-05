#include <iostream>
#include <string>
#include <sstream>
#include <ostream>
#include <vector>
#include <stdio.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef vector<int> vi;
vi pset;
void initSet(int N) {
	pset.assign(N + 1, 0);
	for (int i = 1; i <= N; i++)
		pset[i] = i;
}
int findSet(int i) {
	return pset[i] = (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
	pset[findSet(i)] = findSet(j);
}
int main223() {
	int N;
	while (scanf("%d", &N) != 0) {
		initSet(N);
		char c;
		int i, j;
		int cA = 0, wA = 0;
		while (scanf("%c %d %d", &c, &i, &j)) {
			if (c == 'c') {
				unionSet(i, j);
			} else if (c == 'q') {
				if (isSameSet(i, j))
					cA++;
				else
					wA++;
			}
		}
		printf("%d,%d", cA, wA);
	}
	return 0;
}
