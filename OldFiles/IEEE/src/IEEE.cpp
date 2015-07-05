#include<iostream>
#include<string.h>

using namespace std;

int main() {

	int n;
	int nums[100000];
	int arr_odd[100000];
	int arr_even[100000];
	int counter_E, counter_O;

	for (int i = 0; i < 100000; i++) {
		arr_even[i] = 100001;
		arr_odd[i] = 100001;
	}

	cin >> n;
	int curr;
	for (int i = 0; i < n; i++) {
		cin >> curr;
		nums[i] = curr;
		if (nums[i] % 2 != 0) {
			arr_odd[i] = curr;
			counter_E++;
		} else if (nums[i] % 2 == 0) {
			arr_even[i] = curr;
			counter_O++;
		}

	}

	for (int i = 100000 - 1; i >= 0; i--) {
		if (arr_odd[i] != 100001) {
			cout << arr_odd[i];
			cout << ",";
		}
	}

	for (int i = 0; i < 100000; i++) {
		if (arr_even[i] != 100001) {
			cout << arr_even[i];
			cout << ",";
		}
	}

	return 0;
}
