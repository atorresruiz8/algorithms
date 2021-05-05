#include <iostream>
#include <limits.h> // used for 'INT_MAX' to represent positive infinity

using namespace std;

void printOptParen(int *s, int i, int j, int n, int &matNum) {
	if (i == j) {
		cout << "A" << matNum++; // mat_num is the matrix number in the sequence, starting at matrix 0
		return;
	}

	cout << "(";
	printOptParen(s, i, *((s + i * n) + j), n, matNum); // print optimal paranthesis placement for the values less than the midpoint
	
	printOptParen(s, *((s + i * n) + j) + 1, j, n, matNum); // print optimal paranthesis placement for the values greater than the midpoint
	cout << ")";
}

void matrixChainOrder(int p[], int n) {
	int m[n][n]; // minimum costs for chains 
	int s[n][n]; // create two new tables of size n x n

	for (int i = 1; i < n; i++) {
		m[i][i] = 0; 
	}

	for (int l = 2; l < n; l++) { // int l is the chain length
		for (int i = 1; i < n - l + 1; i++) {
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	int matNum = 0;

	cout << m[1][n - 1] << endl; // print the minimum number of scalar mulitplications needed to multiply the given matrices
	printOptParen((int *)s, 1, n - 1, n, matNum);
}

int main() {
	int n; // n >= 1

	cin >> n;

	n = n + 1; // size of the dimensions of the matrices

	int p[n];

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	matrixChainOrder(p, n);

	cout << endl;

	return 0;
}