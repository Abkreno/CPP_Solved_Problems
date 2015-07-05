#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <iostream>     // std::cout
#include <iterator>
#include <vector>       // std::vector
#include <stdio.h>
using namespace std;
int myints[1000001];
int mainda() {

	int Y = 0, P = 0;
	while (scanf("%d", &P) == 1) {
		scanf("%d", &Y);
		for (int i = 0; i < Y; i++) {
			scanf("%d", &myints[i]);
		}
		vector<int> v(myints, myints + Y);
		vector<int>::iterator up;
		int count = 0, s, e;
		for (int i = 0; i < Y; i++) {
			up = std::upper_bound(v.begin() + i, v.begin() + Y,
					myints[i] + P - 1);
			int whatsup = (up - v.begin());
			if (whatsup - i > count) {
				count = whatsup - i;
				s = myints[i];
				e = myints[whatsup - 1];
			}
		}
		printf("%d %d %d\n", count, s, e);
	}
	return 0;
}
