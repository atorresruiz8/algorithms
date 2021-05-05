#include <iostream>
#include <climits>
using namespace std;

void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ";";
	}
}

void merge(int a[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;

	int left[n1 + 1];
	int right[n2 + 1];

	int i, j;

	for (i = 0; i < n1; i++) {
		left[i] = a[p + i - 1];
	}

	for (j = 0; j < n2; j++) {
		right[j] = a[q + j];
	}

	left[n1] = INT_MAX;
	right[n2] = INT_MAX;

	i = 0;
	j = 0;

	for (int k = p - 1; k < r; k++) {
		if (left[i] <= right[j]) {
			a[k] = left[i];
			i++;
		}
		else {
			a[k] = right[j];
			j++;
		}
	}
}

void merge_sort(int a[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;

		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);

		merge(a, p, q, r);
	}
}

int main() {
	int n; // number of integers to sort
	cin >> n; // input num of integers

	int a[n]; // array to store the integers

	for (int i = 0; i < n; i++) {
		cin >> a[i]; // input each integer
	}

	merge_sort(a, 0, n); // call merge sort algorithm with p = 0, r = 1 less than size of array

	print(a, n); // print array

	return 0;
}