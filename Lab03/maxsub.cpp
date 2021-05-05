#include <iostream>
#include <algorithm> // used for the max function
#include <limits.h> // used for 'INT_MIN'

using namespace std;

int maxXingSub(int a[], int low, int mid, int high) {
	int lsum = INT_MIN; // set the left hand sum to the lowest value possible
	
	int sum = 0; // set total sum equal to 0
	int maxLeft, maxRight; // index for the left and right hand indices of the max subarray

	for (int i = mid; i >= low; i--) { // check the values from index 0 to the midpoint
		sum = sum + a[i];
		if (sum > lsum) { 
			lsum = sum;
			maxLeft = i; // the index for the max subarray's leftmost index is at position i
		}
	}

	int rsum = INT_MIN; // set the right hand sum to the lowest value possible
	sum = 0; // reset sum to 0 to check the right hand side
	for (int i = mid + 1; i <= high; i++) { // check the values greater than the midpoint until the value high
		sum = sum + a[i];
		if (sum > rsum) {
			rsum = sum;
			maxRight = i; // the index for the max subarray's rightmost index is at position i
		}
	}

	return (lsum + rsum); // return the maximum sum of the left and right's sums
}

int maxsub(int a[], int low, int high) {
	if (low == high) {
		return a[low];
	}

	int mid = (low + high) / 2;

	return max(max(maxsub(a, low, mid), maxsub(a, mid + 1, high)), maxXingSub(a, low, mid, high)); // return the max subarray
}

int main() {
	int n; // size of array
	cin >> n;

	int a[n]; // array to store all the values

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int max = 0; // variable used to store the maximum subarray's value
	max = maxsub(a, 0, n - 1); // find the maximum value

	cout << max; // print out said value
	return max;
}