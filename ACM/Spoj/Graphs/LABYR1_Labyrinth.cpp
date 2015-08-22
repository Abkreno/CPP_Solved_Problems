#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define Fill(a,b) memset(&a,b,sizeof(a))

const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int cols, rows, maxd, maxr, maxc;
char s[1005][1005], v[1005][1005];
bool inBounds(int i, int j) {
	return i >= 0 && j >= 0 && i < rows && j < cols;
}
void dfs(int i, int j, int l) {
	if (l > maxd) {
		maxd = l;
		maxr = i;
		maxc = j;
	}
	v[i][j] = 1;
	int ni, nj;
	for (int k = 0; k < 4; k++) {
		ni = i + dc[k];
		nj = j + dr[k];
		if (inBounds(ni, nj) && s[ni][nj] == '.' && !v[ni][nj]) {
			dfs(ni, nj, l + 1);
		}
	}
}

int main() {
	int t, i, j;
	scanf("%d", &t);

	while (t--) {
		scanf("%d%d\n", &cols, &rows);
		for (j = 1; j <= rows; ++j)
			gets(s[j - 1]);

		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++) {
				if (s[i][j] == '.' && !v[i][j]) {
					maxd = -1;
					memset(v, 0, sizeof(v));
					dfs(i, j, 0);
					maxd = -1;
					memset(v, 0, sizeof(v));
					dfs(maxr, maxc, 0);
					printf("Maximum rope length is %d.\n", maxd);
					i = 10000;
					break;
				}
			}
		}

	}

	return 0;
}
