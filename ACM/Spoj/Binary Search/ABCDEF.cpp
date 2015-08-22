#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int NN = N * N;
int n;
int nums[N + 1];
int mult[NN + 1];
int addedPairs[NN + 1];  // nums[i] + nums[j]
int addMult[NN * N + 1]; // addedPairs[i] * nums[j]
int multAdd[NN * N + 1]; // mult[i] + nums[j]
int lowerBound(int key, int n) {
	int lo = 0;
	int hi = n;
	int mid;
	while (lo + 1 < hi) {
		mid = (lo + hi) >> 1;
		if (multAdd[mid] <= key) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	if (multAdd[lo] != key)
		return n;
	return lo + 1;
}

int upperBound(int key, int n) {
	int lo = -1;
	int hi = n - 1;
	int mid;
	while (lo + 1 < hi) {
		mid = (lo + hi) >> 1;
		if (multAdd[mid] >= key) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	if (multAdd[hi] != key)
		return n;
	return hi;
}
int main() {
	int i, j, nn, nnn, ind;
	scanf("%d", &n);
	nn = n * n;
	nnn = nn * n;
	for (i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	ind = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			mult[ind++] = nums[i] * nums[j];

	ind = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			addedPairs[ind++] = nums[i] + nums[j];

	ind = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < nn; j++)
			if (nums[i])
				addMult[ind++] = nums[i] * addedPairs[j];
	int addMSize = ind;
	ind = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < nn; j++)
			multAdd[ind++] = nums[i] + mult[j];

	sort(multAdd, multAdd + nnn);
	long long res = 0, curr;
	int a, b;
	for (i = 0; i < addMSize; i++) {
		a = lowerBound(addMult[i], nnn);
		b = upperBound(addMult[i], nnn);
		curr = a - b;
		res += curr;
	}
	printf("%lld\n", res);
	return 0;
}
