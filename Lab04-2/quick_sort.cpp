#include <iostream>
#include <stdlib.h> // used for rand() function
using namespace std;

void print(int a[], int n) { // print sorted array
	for (int i = 0; i < n; i++) { 
		cout << a[i] << ";";
	}
}

int partition(int a[], int p, int r) { // partition the array
	int x = a[r];
	int i = p - 1;

	for (int j = p; j <= r - 1; j++) {
		if (a[j] <= x) {
			i = i + 1;
			swap(a[i], a[j]); // exchange a[i] with a[j]
		}
	} swap(a[i + 1], a[r]); // exhcange a[i+1] with a[r]
	return i + 1; 
}

int randomized_partition(int a[], int p, int r) { // select a random pivot to partition the array around 
	int i = p + rand() % (r - p + 1); // select random pivot
	swap(a[r], a[i]); // exchange a[r] with a[i], the randomized pivot
	return partition(a, p, r); // return the subarray
}

void quick_sort(int a[], int p, int r) { // p = permutations, r = randomly chosen element from array
	int q; // index to act as a 'midway point' between index p and r

	if (p < r) {
		q = randomized_partition(a, p, r); // randomly choose an index q to use as a pivot
		quick_sort(a, p, q - 1); // sort the subarray a[p...q - 1]
		quick_sort(a, q + 1, r); // sort the subarray a[q + 1...r]
	} // the array is now sorted
}

int main() {
	int n; // number of elements to sort
	
	cin >> n;

	int a[n]; // array used to store the elements

	for (int i = 0; i < n; i++) { 
		cin >> a[i];
	}

	quick_sort(a, 0, n - 1); // call the quick sort function

	print(a, n); // print the sorted array

	return 0;
}