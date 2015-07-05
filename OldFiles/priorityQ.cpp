#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct comparator {
	bool operator()(int i, int j) {
		return i > j;
	}
};

int mains() {
	priority_queue<int, std::vector<int>, comparator> q;
	q.push(1);
	q.push(44);
	q.push(2);
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	return 0;
}
