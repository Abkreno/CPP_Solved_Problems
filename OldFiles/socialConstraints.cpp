#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int a;
	int b;
	int c;
} arr[21];
void reset() {
	for (int i = 0; i < 21; i++) {
		arr[i].a = 0;
		arr[i].b = 0;
		arr[i].c = 0;
	}
}
int main() {
	int nums[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	int n, m, a, b, c;
	while (true) {
		scanf("%d %d", &n, &m);
		if (!n && !m)
			break;
		reset();
		int r = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			arr[i].a = a;
			arr[i].b = b;
			arr[i].c = c;
		}
		do {
			bool good = true;
			for (int i = 0; i < m; i++) {
				int aPos = 0;
				int bPos = 0;
				for (int j = 0; j < n; j++) {
					if (nums[j] == arr[i].a)
						aPos = j;
					if (nums[j] == arr[i].b)
						bPos = j;
				}
				if (arr[i].c < 0) {
					if (abs(aPos - bPos) < abs(arr[i].c)) {
						good = false;
						break;
					}
				} else {
					if (abs(aPos - bPos) > arr[i].c) {
						good = false;
						break;
					}
				}
			}
			if (good)
				r++;
		} while (std::next_permutation(nums, nums + n));
		cout << r << endl;
	}

	return 0;
}
