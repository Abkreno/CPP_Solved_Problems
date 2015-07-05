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
char inputt[10];
char end[3] = { 'e', 'n', 'd' };
int grid2[10];
int size = 10;
bool arrayComparer() {
	for (int i = 0; i < 3; i++) {
		if (inputt[i] != end[i])
			return false;
	}
	return true;
}
bool checkBack(int row) {
	for (int i = 0; i < row - 1; i++) {
		if (grid2[i] != 0)
			return true;
	}
	return false;
}
static int check2() {
	for (int i = 0; i < size; i++) {
		if (grid2[i] > 0)
			return 100;
	}
	return 0;
}
void changeState(int row, int i) {
	if (row != 0) {
		if ((grid2[row - 1] & (1 << i)) > 0) {
			grid2[row - 1] &= ~(1 << i);
		} else {
			grid2[row - 1] ^= (1 << i);
		}
	}
	if (row + 1 < size) {
		if ((grid2[row + 1] & (1 << i)) > 0) {
			grid2[row + 1] &= ~(1 << i);
		} else {
			grid2[row + 1] ^= (1 << i);
		}

	}
	if (i != 0) {
		if ((grid2[row] & (1 << (i - 1))) > 0) {
			grid2[row] &= ~(1 << (i - 1));
		} else {
			grid2[row] ^= (1 << (i - 1));
		}
	}
	if (i + 1 < size) {
		if ((grid2[row] & (1 << (i + 1))) > 0) {
			grid2[row] &= ~(1 << (i + 1));
		} else {
			grid2[row] ^= (1 << (i + 1));
		}
	}
	return;
}
int minMoves(int row, int i, int movesSoFar) {
	if (movesSoFar >= 100)
		return 100;
	if (row == size) {
		return check2();
	}
	if (checkBack(row))
		return 100;
	bool f = (i == size - 1);
	int m = minMoves(f ? row + 1 : row, f ? 0 : i + 1, movesSoFar);
	if (row == 0 || (grid2[row - 1] & (1 << i)) > 0) {
		if ((grid2[row] & (1 << i)) > 0) {
			grid2[row] &= ~(1 << i);
			changeState(row, i);
			m = min(
					1
							+ minMoves(f ? row + 1 : row, f ? 0 : i + 1,
									movesSoFar + 1), m);
			grid2[row] ^= (1 << i);
			changeState(row, i);
		} else {
			grid2[row] ^= (1 << i);
			changeState(row, i);
			m = min(
					1
							+ minMoves(f ? row + 1 : row, f ? 0 : i + 1,
									movesSoFar + 1), m);
			grid2[row] &= ~(1 << i);
			changeState(row, i);
		}
	}
	return m;
}
int mainD() {
	while (scanf("%s", &inputt)) {
		if (arrayComparer())
			break;
		printf("%s ", inputt);
		memset(grid2, 0, sizeof(grid2));
		for (int i = 0; i < size; i++) {
			scanf("%s", &inputt);
			int c = size - 1;
			for (int j = 0; j < size; j++) {
				if (inputt[j] == 'O')
					grid2[i] = ((grid2[i]) ^ (1 << c));
				c--;
			}
		}
		int res = minMoves(0, 0, 0);
		if (res > 100)
			res = -1;
		printf("%d\n", res);
	}

	return 0;
}
