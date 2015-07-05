#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

#define all(v)          ((v).begin()), ((v).end())
int arr[50000 + 5];
int DP[12000 + 5][12000 + 5];
int n, bestStart, minSoFar = 1000000000;
int minMoves(int curr, int start, int mm) {
	if (mm >= minSoFar)
		return 1000000000;
	if (start == n || curr == n)
		return 0;
	bool ff = curr < 12005 && start < 12005 ? true : false;
	if (ff && DP[curr][start] != -1)
		return DP[curr][start];
	int f = arr[start] != arr[curr] - curr + start ? 1 : 0;
	int call1 = f + minMoves(curr, start + 1, mm + f);
	if (ff)
		DP[curr][start] = call1;
	return call1;
}

int main() {
	FILE *inputFile = fopen("integer.in", "r");
	FILE *outputFile = fopen("integer.out", "w");
	while (fscanf(inputFile, "%d", &n) != EOF) {
		int curr;
		minSoFar = 1000000000;
		bestStart = 0;
		memset(DP, -1, sizeof(DP));
		for (int i = 0; i < n; i++) {
			fscanf(inputFile, "%d", &curr);
			arr[i] = curr;
		}
		for (int i = 0; i < n; i++) {
			int call = minMoves(i, 0, 0);
			if (minSoFar > call) {
				minSoFar = call;
				bestStart = i;
			}
		}
		fprintf(outputFile, "%d\n", minSoFar);
		for (int i = 0; i < n - 1; i++)
			fprintf(outputFile, "%d ", arr[bestStart] - bestStart + i);
		fprintf(outputFile, "%d\n", arr[bestStart] - bestStart + (n - 1));
	}
	return 0;
}
