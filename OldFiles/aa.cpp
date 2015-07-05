// http://uva.onlinejudge.org/external/7/727.html

// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
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
#include <math.h>
#define pi acos(-1.0)
#define N 1000000
using namespace std;

stack<char> s;
vector<char> output;

bool checkOperator(char p) {
	if (p == '+' || p == '-' || p == '*' || p == '/')
		return true;
	return false;
}

int hasPrecedence(char p, char q) {
	if ((p == '*' || p == '/') && (q == '+' || q == '-'))
		return 1;
	if ((p == '+' || p == '-') && (q == '*' || q == '/'))
		return -1;

	return 0;
}

void setOperator(char op) {
	queue<char> temp;

	if (!s.empty() && s.top() != '(' && hasPrecedence(op, s.top()) <= 0) {
		output.push_back(s.top());
		s.pop();
	}

	while (!s.empty() && s.top() != '(' && hasPrecedence(op, s.top()) <= 0) {
		temp.push(s.top());
		s.pop();
	}

	s.push(op);

	while (!temp.empty()) {
		output.push_back(temp.front());
		temp.pop();
	}
}

int main223() {
	//freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);

	int testCase;
	scanf("%d", &testCase);
	bool blank = false;
	getchar();
	getchar();

	while (testCase--) {
		char ch[5];
		string input;
		output.clear();

		while (gets(ch) && strlen(ch)) {
			if (ch[0] == '(') {
				if (input.length() && isdigit(input[input.length() - 1]))
					input += 'x';
			} else if (isdigit(ch[0])) {
				if (input.length() && input[input.length() - 1] == ')')
					input += 'x';
			}

			input += ch[0];
		}

		for (size_t i = 0; i < input.length(); i++) {
			if (isdigit(input[i]))
				output.push_back(input[i]);
			else if (checkOperator(input[i])) {
				setOperator(input[i]);
				/*
				 if ( !s.empty() && checkOperator (s.top ()) ) {
				 if ( hasPrecedence (s.top (), input [i])) {
				 output.push_back (s.top ());
				 s.pop ();
				 }
				 }

				 s.push (input [i]);
				 */
			} else if (input[i] == '(')
				s.push('(');
			else if (input[i] == ')') {
				while (s.top() != '(') {
					output.push_back(s.top());
					s.pop();
				}
				s.pop();
			}
		}

		while (!s.empty()) {
			output.push_back(s.top());
			s.pop();
		}

		if (blank)
			printf("\n");
		blank = true;

		for (size_t i = 0; i < output.size(); i++) {
			if (output[i] != 'x')
				printf("%c", output[i]);
		}
		printf("\n");
	}

	return 0;
}

// @END_OF_SOURCE_CODE
