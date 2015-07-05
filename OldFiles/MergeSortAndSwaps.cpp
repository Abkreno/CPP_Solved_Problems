#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <bitset>
#include <utility>
#include <set>
#define pi acos(-1.0)
#define N 1000000
typedef long long ll;
using namespace std;
int arr[N + 1];
ll swaps = 0;
void merg(int iBegin, int iMiddle, int iEnd) {
	int i0 = iBegin, i1 = iMiddle;
	int n = iEnd - iBegin;
	int B[n];
	// While there are elements in the left or right runs
	for (int j = 0; j < n; j++) {
		// If left run head exists and is <= existing right run head.
		if (i0 < iMiddle && (i1 >= iEnd || arr[i0] <= arr[i1])) {
			B[j] = arr[i0];
			i0 = i0 + 1;
		} else {
			B[j] = arr[i1];
			swaps += (iMiddle - i0);
			i1 = i1 + 1;
		}
	}
	int c = 0;
	for (int i = iBegin; i < iEnd; i++) {
		arr[i] = B[c++];
	}

}

void mSort(int lo, int hi) {
	if (hi - lo < 2)
		return;
	int mid = (hi + lo) / 2;
	mSort(lo, mid);
	mSort(mid, hi);
	merg(lo, mid, hi);
}

int mai2n() {
	int s;
	while (scanf("%d", &s) != EOF) {
		swaps = 0;
		for (int i = 0; i < s; i++) {
			scanf("%d", &arr[i]);
		}
		mSort(0, s);
		printf("%lld\n", swaps);
	}
	return 0;
}

