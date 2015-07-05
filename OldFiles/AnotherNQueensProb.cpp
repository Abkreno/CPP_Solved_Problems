#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int Mask, ans, tmp[18];
char s[18];
void count(int level, int x, int lD, int rD) {
	if (x == Mask) {
		ans++;
		return;
	}
	int pos = Mask & ~(x | lD | rD) & tmp[level];
	while (pos != 0) {
		int p = (pos & -pos);
		pos -= p;
		count(level + 1, x | p, (lD | p) << 1, (rD | p) >> 1);
	}
}

int main2224() {
	int N, cnt = 1;
	while (scanf("%d", &N) == 1 && N) {
		Mask = (1 << N) - 1;
		for (int i = 0; i < N; i++) {
			scanf("%s", &s);
			tmp[i] = Mask;
			for (int j = 0; j < N; j++)
				if (s[j] == '*')
					tmp[i] ^= 1 << j;
		}
		ans = 0;
		count(0, 0, 0, 0);
		printf("Case %d: %d\n", cnt++, ans);
	}
	return 0;
}
