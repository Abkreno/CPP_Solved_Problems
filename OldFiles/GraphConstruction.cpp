#include <iostream>
#include <map>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;
int nums[10001];
int sums[10001];
int main1122() {
	int n;
	while (scanf("%d", &n) && n) {
		int sum = 0;
		bool p = true;
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
			sum += nums[i];
			if (nums[i] < 0)
				p = false;
		}
		sort(nums, nums + n, greater<int>());
		if (n == 1 && nums[0] != 0) {
			p = false;
		} else if (!(sum % 2) && p) {
			sums[0] = nums[0];
			for (int i = 1; i < n; i++) {
				sums[i] = nums[i] + sums[i - 1];
			}
			int d = 0;
			int r = 0;
			p = true;
			for (int i = 0; i < n - 1; i++) {
				d = sums[i];
				r = 0;
				for (int k = i + 1; k < n; k++) {
					r += min(nums[k], i + 1);
				}
				r += (i * (i + 1));
				if (d > r) {
					p = false;
					break;
				}
			}
		} else {
			p = false;
		}
		if (p)
			printf("Possible\n");
		else
			printf("Not possible\n");
	}
	return 0;
}
