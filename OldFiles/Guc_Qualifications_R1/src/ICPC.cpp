#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<limits.h>
#define  maxn  500005
using namespace std;

long long len, heapsize, a[maxn];
long long LEFT(long long i) {
	return i * 2;
}
long long RIGHT(long long i) {
	return i * 2 + 1;
}
long long PARENT(long long i) {
	return i / 2;
}
void MIN_HEAPIFY(long long A[], long long i) {
	long long l = LEFT(i);
	long long r = RIGHT(i);
	long long fewest;
	if (l <= heapsize && A[l] < A[i])
		fewest = l;
	else
		fewest = i;
	if (r <= heapsize && A[r] < A[fewest])
		fewest = r;  //找出本节点以及其儿子节点最小的值的编号
	if (i != fewest) {
		long long temp = A[i];
		A[i] = A[fewest];
		A[fewest] = temp;
		MIN_HEAPIFY(A, fewest);  //子树可能交换后不保持性质，使起保持性质
	}

}
void BUILD_MIN_HEAP(long long A[]) {
	heapsize = len;
	//for(long long i = len/2 ;i >= 1;i --)
	// MIN_HEAPIFY(A,i);
}
long long HEAP_EXTRACT_MIN(long long A[]) {
	long long MIN = A[1];
	A[1] = A[heapsize];
	heapsize = heapsize - 1;
	MIN_HEAPIFY(A, 1);
	return MIN;
}
void HEAP_INCREASE_KEY(long long A[], long long i, long long key) {
	A[i] = key;
	while (i > 1 && A[PARENT(i)] > A[i]) {
		long long temp = A[PARENT(i)];
		A[PARENT(i)] = A[i];
		A[i] = temp;
		i = PARENT(i);
	}     //向上更新

}
void MIN_HEAP_INSERT(long long A[], long long key) {
	heapsize = heapsize + 1;
	A[heapsize] = INT_MAX;
	HEAP_INCREASE_KEY(A, heapsize, key);
}
int main2() {
	FILE *inputFile = fopen("huffman.in", "r");
	FILE *outputFile = fopen("huffman.out", "w");
	while (fscanf(inputFile, "%d", &len) != EOF) {
		memset(a, 0, sizeof(a));
		for (long long i = 1; i <= len; i++)
			fscanf(inputFile, "%lld", &a[i]);
		BUILD_MIN_HEAP(a);
		long long sum = 0;
		for (long long i = 1; i <= len - 1; i++) {
			long long tsum = HEAP_EXTRACT_MIN(a) + HEAP_EXTRACT_MIN(a);
			sum += tsum;
			MIN_HEAP_INSERT(a, tsum);
		}
		fprintf(outputFile, "%lld\n", sum);
	}
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}
