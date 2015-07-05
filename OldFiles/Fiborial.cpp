#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <bitset>
#include <utility>
#include <set>
#define pi acos(-1.0)
#define N 1000000
typedef long long ll;
using namespace std;
int main() {
	stack<int> st;
	int n;
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		int arr[n];
		for (int i = 1; i <= n; i++) {
			arr[i - 1] = i;
		}
		bool done = false;
		while (true) {
			int train[n];
			for (int i = 0; i < n; i++) {
				cin >> train[i];
				if (train[i] == 0) {
					done = true;
					break;
				}
			}
			if (done)
				break;
			int index = 0;
			st.push(arr[index++]);
			int curr = 0;
			while (!st.empty() && index < n) {
				if (st.top() == train[curr]) {
					st.pop();
					curr++;
				}
				st.push(arr[index++]);
			}
			while (!st.empty()) {
				if (st.top() == train[curr]) {
					st.pop();
					curr++;
				} else {
					break;
				}
			}
			if (curr != n)
				cout << "No\n";
			else
				cout << "Yes\n";
		}
		cout << endl;
	}
	return 0;
}
