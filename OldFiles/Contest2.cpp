#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
#define F(i,n) for(int i = 0; i < n ;i++)
struct teams {
	int penalty[12], index, solved[12];
	bool submit;
} a[105];

void restart() {
	F(i,105)
	{
		memset(a[i].penalty, 0, sizeof(a[i].penalty));
		memset(a[i].solved, 0, sizeof(a[i].solved));
		a[i].index = i;
		a[i].submit = false;
	}
}

void calculateAll2() {
	F(i,105)
	{
		F(j,10)
		{
			if (a[i].solved[j]) {
				a[i].solved[10]++;
				a[i].penalty[10] += a[i].penalty[j];
			}
		}
	}
}

bool comp(teams x, teams y) {
	if (x.solved[10] > y.solved[10])
		return true;
	if (x.solved[10] == y.solved[10] && x.penalty[10] < y.penalty[10])
		return true;
	if (x.solved[10] == y.solved[10] && x.penalty[10] == y.penalty[10]
			&& x.index < y.index)
		return true;
	return false;

}

int main() {
	int N;
	scanf("%d", &N);
	getchar();
	bool blank = false;
	char inp[1000];
	gets(inp);
	while (N--) {
		restart();
		int t, p, l;
		char c;
		while (gets(inp) && strlen(inp)) {
			sscanf(inp, "%d %d %d %c", &t, &l, &p, &c);
			if (c != 'I' && c != 'C')
				continue;
			a[t].submit = true;
			if (c == 'I') {
				if (!a[t].solved[l]) {
					a[t].penalty[l] += 20;
				}
			} else {
				if (!a[t].solved[l]) {
					a[t].solved[l]++;
					a[t].penalty[l] += p;
				}
			}
		}
		calculateAll2();
		sort(a, a + 105, comp);
		if (blank)
			printf("\n");
		blank = true;

		F(i,105)
		{
			if (a[i].submit) {
				printf("%d %d %d \n", a[i].index, a[i].solved[10],
						a[i].penalty[10]);
			}
		}
		cout << "0 0 1" << endl;
	}
	return 0;
}
