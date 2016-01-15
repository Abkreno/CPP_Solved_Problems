#include <bits/stdc++.h>
using namespace std;
vector<int> divsors;
int numOfDivsors;
long long memo[1000000];
long long mod = 1000000007;
void findDivisors(int n) {
	for (int i = 2; i <= n / i; i++) {
		while (n % i == 0) {
			divsors.push_back(i);
			n /= i;
		}
	}
	if (n > 1) {
		divsors.push_back(n);
	}
}
long long dp(int curr) {
	if (curr >= numOfDivsors)
		return 1;
	if (memo[curr] != -1)
		return memo[curr];
	int next = 0;
	while (curr + next < numOfDivsors && divsors[curr + next] == divsors[curr])
		next++;
	int c = 0;
	long long ans = 0, d = 1;
	while (c++ < next) {
		d *= divsors[curr];
		d %= mod;
		ans += ((d * dp(curr + next)) % mod);
		ans %= mod;
	}
	memo[curr] = ans + dp(curr + next);
	memo[curr] %= mod;
	return memo[curr];
}
int main() {
	int n, a, t, c = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		divsors.clear();
		memset(memo, -1, sizeof(memo));
		while (n--) {
			scanf("%d", &a);
			findDivisors(a);
		}
		numOfDivsors = (int) divsors.size();
		sort(divsors.begin(), divsors.end());
		printf("Case %d: %lld\n", c++, dp(0));
	}
}
