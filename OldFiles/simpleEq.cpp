#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <hash_set>
using namespace std;
bool check2(int x, int y, int z, int a, int b, int c) {
	if (pow(x, 2) + pow(y, 2) + pow(z, 2) == c) {
		if ((x + y + z) == a && (x * y * z) == b) {
			return true;
		}
	}
	return false;
}
int main22() {

	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int boundry = 10000;
		bool found = false;
		int xres = 0;
		int yres = 0;
		int zres = 0;
		for (int x = -1 * boundry; x <= boundry; x++) {
			if (x != 0 && b % x == 0) {
				int boundry2 = b / x;
				if (boundry2 < 0)
					boundry2 *= -1;

				for (int y = -1 * boundry2; y <= boundry2; y++) {
					if (y != 0 && y != x && b % y == 0) {
						if (b % (x * y) == 0) {
							for (int i = -1; i <= 1; i++) {
								if (i == 0)
									continue;
								int z = b / (x * y);
								z *= i;
								if (!(z == x && y == z)
										&& check2(x, y, z, a, b, c)) {
									if (!found) {
										xres = x;
										yres = y;
										zres = z;
										found = true;

									}
								}

							}
						}
					}
				}
			}
		}

		if (!found)
			printf("No solution.");
		else
			printf("%d %d %d", xres, yres, zres);
		if (n > 0)
			printf("\n");

	}

}
