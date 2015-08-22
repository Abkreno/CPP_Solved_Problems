#include <bits/stdc++.h>
using namespace std;
map<int, long long> DP;
int n;
long long f(int curr) {
	if (curr == 0)
		return 0;
	if (curr < 3)
		return curr;
	if (DP.find(curr) != DP.end())
		return DP[curr];
	long long ans = f(curr / 2) + f(curr / 3) + f(curr / 4);
	ans = max(ans, ((long long) curr));
	DP.insert(make_pair(curr, ans));
	return ans;
}
int main() {
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", f(n));
	}
	return 0;

}
