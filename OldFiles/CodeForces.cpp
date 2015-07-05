#include <cstdio>

int A[1000010], B[1000010];

typedef long long ll;

ll mergesort(ll begin, ll end) {
	if (begin == end)
		return 0;
	int middle = (begin + end) / 2;

	ll inv_index = mergesort(begin, middle);
	inv_index += mergesort(middle + 1, end);

	ll left = begin;
	ll right = middle + 1;

	for (int k = begin; k <= end; ++k) {
		if (right > end || (left <= middle && A[left] <= A[right])) {
			B[k] = A[left++];
		} else {
			B[k] = A[right++];
			inv_index += (middle - left + 1);
		}
	}

	for (int k = begin; k <= end; ++k)
		A[k] = B[k];
	return inv_index;
}

int main1() {
	/*freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);*/
	int N;
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; ++i)
			scanf("%d", &A[i]);

		printf("%lld\n", mergesort(0, N - 1));
	}
	return 0;
}
