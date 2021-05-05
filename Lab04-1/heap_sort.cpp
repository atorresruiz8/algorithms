#include <iostream>
using namespace std;

void print(int a[], int n) { // function to print the sorted array
	for (int i = 0; i < n; i++) {
		cout << a[i] << ";";
	}
}

void max_heapify(int a[], int n, int i) {
	int left = (2 * i); 
	int right = (2 * i) + 1;
	int largest;

	// if left child > root
	if (left < n && a[left] > a[i]) { // if the values in the left side of the array are greater than largest, set them equal to largest
		largest = left;
	}
	else {
		largest = i; // if left !> largest, then the largest value is the root of the array
	}

	// if right child > largest so far
	if (right < n && a[right] > a[largest]) { // if the values in the right side of the array are greater than largest, set them equal to largest
		largest = right;
	}

	// if largest is not root
	if (largest != i) {
		swap(a[i], a[largest]); // exchange a[i] with a[largest]

		max_heapify(a, n, largest); // now find the max heap again 
	}
}

void build_max_heap(int a[], int n) { // builds the max heap to sort the array with
	for (int i = ((n / 2) - 1); i >= 0; i--) {
		max_heapify(a, n, i);
	}
}

void heap_sort(int a[], int n) {
	build_max_heap(a, n); // build the max heap before sorting

	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]); // move current root to end
		
		max_heapify(a, i, 0); // reduced heap
	}
}

int main() {
	int n; // value of how many integers to sort
	cin >> n;

	int a[n]; // array to hold integers
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	heap_sort(a, n); // call to sort the array using heap sort

	print(a, n); // print the sorted array

	return 0;
}