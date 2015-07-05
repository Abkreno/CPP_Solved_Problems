#include <cstdio>
#include <algorithm>
#include <stdio.h>
#include <iterator>
#include <vector>
using namespace std;
int nums1[1000000];
int main222321() {
	int m, n, c = 1;
	while (scanf("%d %d", &n, &m) == 2 && m && n) {
		for (int i = 0; i < n; i++)
			scanf("%d", &nums1[i]);
		sort(nums1, nums1 + n);
		vector<int> v(nums1, nums1 + n);
		vector<int>::iterator low;
		int curr;
		printf("CASE# %d:\n", c++);
		for (int i = 0; i < m; i++) {
			scanf("%d", &curr);
			low = lower_bound(v.begin(), v.begin() + n, curr);
			int index = low - v.begin();
			if (nums1[index] == curr)
				printf("%d found at %d\n", curr, index + 1);
			else
				printf("%d not found\n", curr);
		}
	}
	return 0;
}
