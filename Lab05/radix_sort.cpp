#include <iostream>
#include <vector> // used for vectors, iterators, begin and end

using namespace std;

void print(vector<int> a[], int n) { // function to print the sorted vectors
	for (int i = 0; i < n; i++) { // use iterator (set to the initial element in the vector) to access and print the elements
		vector<int>::iterator v = a[i].begin();

		while (v != a[i].end()) { // while the iterator is not in the final position of the vector, continue incrementing to see the remaining elements
			cout << *v << ";"; // dereference the iterator and print out what it is pointing to
			v++;
		} cout << endl;
	}
}

void countingSort(vector<int> a[], int d, int k) { // stable sort to use with radix sort
	vector<int> *b = new vector<int>[d]; // output vector
	int c[4] = {0, 0, 0, 0};  // counts array

	for (int i = 0; i < d; i++) {
		c[a[i][k] % 4]++; // incrementing by 4 because vectors store ints in byte sizes of 4
	} // c[i] now contains the number of elements equal to i

	for (int i = 1; i < 4; i++) {
		c[i] = c[i] + c[i - 1];
	} // c[i] now contains the number of elements less than or equal to i

	for (int j = d - 1; j >= 0; j--) { // build output array
		b[c[a[j][k] % 4] - 1] = a[j];
		c[a[j][k] % 4]--;
	}

	for (int i = 0; i < d; i++) { // copy (now sorted) output array to our initial array
		a[i] = b[i];
	}
}

void radixSort(vector<int> a[], int d) { // d = digits
	int size = 10; // size of each vector to sort
	for (int k = size - 1; k >= 0; k--) {
		countingSort(a, d, k); // counting sort is used as a stable sorting method for every digit
	}
}

int main() {
	int n; // number of vectors to sort
	cin >> n;

	vector<int> *a = new vector<int>[n]; // declare pointer to int vector of size n

	int val; // elements in vector

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) { // fill each vector with up to 10 elements
			cin >> val; // input the element
			a[i].push_back(val); // push back the element into the vector
		}
	}

	radixSort(a, n); // call radix sort for n many vectors

	print(a, n); // print the sorted vectors

	delete[] a; // free up memory taken up by vector

	return 0;
}