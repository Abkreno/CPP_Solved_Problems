#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

int arr[50000 + 5];
int n;
int main() {
	FILE *inputFile = fopen("integer.in", "r");
	FILE *outputFile = fopen("integer.out", "w");
	while (fscanf(inputFile, "%d", &n) != EOF) {
		int curr;
		for (int i = 0; i < n; i++) {
			fscanf(inputFile, "%d", &curr);
			arr[i] = curr;
		}
		int minres = 10000000;
		int number = 0;
		int res = 0;
		for (int i = 0; i < n; i++) {
			res = 0;
			for (int j = 0; j < n; j++) {
				if (arr[j] != arr[i] - i + j) {
					res++;
					if (res > minres)
						break;
				}

			}
			if (minres > res) {
				number = i;
				minres = res;
			}
		}
		fprintf(outputFile, "%d\n", minres);
		for (int i = 0; i < n - 1; i++)
			fprintf(outputFile, "%d ", arr[number] - number + i);
		fprintf(outputFile, "%d\n", arr[number] - number + (n - 1));
	}
	return 0;
}
