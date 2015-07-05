#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	char s1[111], s2[111];
	while (gets(s1)) {
		gets(s2);
		int dp[111][111] = { };
		for (int j = 0; s1[j]; j++) {
			for (int i = j; i >= 0; i--) {
				dp[i][j] = dp[i + 1][j] + 1;
				for (int k = i + 1; k <= j; k++) {
					if (s2[i] == s2[k]) {
						dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
					}
				}
			}
		}
		int need[111];
		for (int i = 0; s1[i]; i++) {
			if (s1[i] == s2[i]) {
				need[i] = i ? need[i - 1] : 0;
				continue;
			}
			need[i] = dp[0][i];
			for (int j = 0; j < i; j++) {
				need[i] = min(need[i], need[j] + dp[j + 1][i]);
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < 4; k++) {
				printf("%d ", dp[i][k]);
			}
			printf("\n");
		}
		printf("\n%d\n", need[strlen(s1) - 1]);
	}
	return 0;
}
