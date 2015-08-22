#include <bits/stdc++.h>
using namespace std;
int N, K, MASK;
int DP[(1 << 12) +10][100];
int f(int mask, int k) {
	if (k > K)
		return 0;
	if (mask == MASK)
		return k == K ? 1 : 0;
	if (DP[mask][k] != -1)
		return DP[mask][k];
	int ans = 0;
	int prevOnes = 0;
	for (int i = 0; i < N; i++) {
		if ((1 << i) & mask) {
			prevOnes++;
		} else {
			ans += f(mask | (1 << i), k + prevOnes);
		}
	}
	return DP[mask][k] = ans;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(DP, -1, sizeof(DP));
		scanf("%d%d", &N, &K);
		MASK = (1 << N) - 1;
		printf("%d\n", f(0, 0));
	}
	return 0;

}
