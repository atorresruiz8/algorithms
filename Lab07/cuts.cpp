#include <iostream>
#include <limits.h> // used for 'INT_MIN' to represent negative infinity

using namespace std;

void print(int s[], int r[], int n) { // print rod cut solution
	cout << r[n] << endl; // print out maximum revenue

	while (n > 0) { 
		cout << s[n] << " "; // print out the slice size and a space to separate each part
		n = n - s[n]; // reduces the length of the rod by each optimal slice until there aren't any more pieces to cut
	} cout << "-1" << endl; // end the line
}

int rodCuts(int p[], int n) {
	int r[n], s[n]; // revenue and slices arrays

	r[0] = 0; // rod length of 0 earns 0 revenue

	for (int j = 1; j <= n; j++) {
		int q = INT_MIN; // used for comparisons
		for (int i = 1; i <= j; i++) {
			if (q < (p[i] + r[j - i])) {
				q = p[i] + r[j - i];
				s[j] = i; // holds the optimal size (i) of the first piece to cut off
			}
		} r[j] = q; // holds the solution to subproblem j
	}

	print(s, r, n);

	return r[n], s[n]; // return the maximum revenue and slices
}

int main() {
	int n; // rod length
	cin >> n;

	int p[n]; // array for the market prices of rods

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	rodCuts(p, n); // initial call to rod cutting algorithm

	return 0;
}