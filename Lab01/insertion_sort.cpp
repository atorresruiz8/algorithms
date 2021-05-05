#include <iostream>
using namespace std;

void insert(int a[], int n) {
	int it = 0; // number of iterations the algorithm has gone through
	for (int j = 1; j <= n; j++) {
		int key = a[j];

		int i = j - 1;

		it++;

		while (i >= 0 && a[i] > key) { // insert a[j] into sorted sequence a[1..j-1]
			a[i + 1] = a[i];
			i--;
		} 	a[i + 1] = key;

		if (it >= 1 && it < n) { // print out each pass of the algorithm
			for (int k = 0; k < n; k++) {
				if (k <= it) {
					cout << a[k] << ';';
				}
			} cout << endl;
		} 
	}
}

int main() {
	int n; // num. of integers to sort

	cin >> n;

	int a[n]; // array of numbers to sort

	for (int i = 0; i < n; i++) { // input numbers to sort
		cin >> a[i];
	}

	insert(a, n);

	return 0;
}