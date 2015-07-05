#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int DP[100000], Path[100];
int nums[100000];
int LIS(int n, int curr) {
	if (curr >= n)
		return 0;
	DP[curr] = 1;
	Path[curr] = -1;
	for (int i = curr - 1; i >= 0; i--) {
		if (nums[i] < nums[curr]) {
			if (DP[curr] < 1 + DP[i]) {
				DP[curr] = 1 + DP[i];
				Path[curr] = i;
			}
		}
	}
	return max(DP[curr], LIS(n, curr + 1));
}
int ll() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	int x = LIS(n, 0);
	cout << x << endl;
	for (int i = 0; i < 10; i++) {
		cout << Path[i] << " ";
	}
	return 0;
}
