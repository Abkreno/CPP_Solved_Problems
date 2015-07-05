#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int main752() {
	int n;
	while (scanf("%d", &n) != EOF) {
		priority_queue<int> pq;
		queue<int> q;
		stack<int> st;
		int t, num;
		bool isStack = true, isQ = true, isPq = true;
		int s, qq, q2;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &t, &num);
			if (t == 1) {
				if (isStack)
					st.push(num);
				if (isQ)
					q.push(num);
				if (isPq)
					pq.push(num);
			} else {
				if (isStack) {
					if (st.empty())
						isStack = false;
					else {
						s = st.top();
						st.pop();
						if (s != num)
							isStack = false;
					}
				}
				if (isQ) {
					if (q.empty()) {
						isQ = false;
					} else {
						qq = q.front();
						q.pop();
						if (qq != num)
							isQ = false;
					}
				}
				if (isPq) {
					if (pq.empty()) {
						isPq = false;
					} else {
						q2 = pq.top();
						pq.pop();
						if (q2 != num)
							isPq = false;
					}
				}
			}
		}
		if (isStack && isQ && isPq) {
			cout << "not sure" << endl;
		} else if ((isStack && isQ) || (isQ && isPq) || (isStack && isPq)) {
			cout << "not sure" << endl;
		} else if (isStack) {
			cout << "stack" << endl;
		} else if (isQ) {
			cout << "queue" << endl;
		} else if (isPq) {
			cout << "priority queue" << endl;
		} else {
			cout << "impossible" << endl;
		}
	}
	return 0;
}
