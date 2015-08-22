#include <bits/stdc++.h>

using namespace std;
#define N 26
int INF = 1000000000;
int Y[N + 1][N + 1], M[N + 1][N + 1];
int main() {
	char ym, ub, a, b, young, old;
	int i, j, k, n, c, minDist;
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++)
				Y[i][j] = M[i][j] = INF;
		}
		for (i = 0; i < n; i++) {
			cin >> ym >> ub >> a >> b >> c;
			if (ym == 'Y') {
				Y[a - 'A'][b - 'A'] = c;
				if (ub == 'B')
					Y[b - 'A'][a - 'A'] = c;
			} else {
				M[a - 'A'][b - 'A'] = c;
				if (ub == 'B')
					M[b - 'A'][a - 'A'] = c;
			}
		}
		for (i = 0; i < N; i++)
			Y[i][i] = M[i][i] = 0;
		cin >> young >> old;
		for (k = 0; k < N; k++)
			for (i = 0; i < N; i++)
				for (j = 0; j < N; j++)
					Y[i][j] = min(Y[i][j], Y[i][k] + Y[k][j]), M[i][j] = min(
							M[i][j], M[i][k] + M[k][j]);
		minDist = INF;
		for (i = 0; i < N; i++) {
			if (Y[young - 'A'][i] == INF || M[old - 'A'][i] == INF)
				continue;
			if (Y[young - 'A'][i] + M[old - 'A'][i] < minDist) {
				minDist = Y[young - 'A'][i] + M[old - 'A'][i];
			}
		}
		if (minDist != INF) {
			cout << minDist;
			for (i = 0; i < N; i++) {
				if (Y[young - 'A'][i] == INF || M[old - 'A'][i] == INF)
					continue;
				if (Y[young - 'A'][i] + M[old - 'A'][i] == minDist) {
					cout << " " << char(i + 'A');
				}
			}
			cout << endl;
		} else
			cout << "You will never meet." << endl;
	}
	return 0;
}
