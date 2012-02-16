// Bandec.c: The Band Diagonal Analogue to LU Decomposition
// Source: "Numerical Recipes", p. 53 / 77

// Description:
//
// Given an n x n band diagonal matrix A with m1 subdiagonal rows
// and m2 superdiagonal rows compactly stored in the array
// a[1..n][1..m1+m2+1] as described in routine `banmul`, this
// routine constructs an LU decomposition of a rowwise permutation
// of A.
//
// The upper triangular matrix replaces a, while the lower
// triangual matrix is returned in al[1..n][1..m1].
//
// indx[1..n] is an output vector which records the row permutation
// effected by the partial pivoting
//
// d is output as +/- 1 depending on whether the number of row
// interchanges was even or odd.
//
// This routine is used in combination with `banbks` to solve
// band-diagonal sets of equations.

#include <math.h>
#define SWAP(a,b) {dum=(a); (a)=(b); (b)=dum;}
#define TINY 1.0e-20

void bandec(float **a, unsigned long n, int m1, int m2, float **al, unsigned long indx[], float *d) {
	unsigned long i, j, k, l;
	int mm;
	float dum;

	mm = m1 + m2 + 1;
	l = m1;

	for (i = 1; i <= m1; i++) {	// Rearrange the storage bit
		for (j = m1 + 2 - i; j <= mm; j++)
			a[i][j-l] = a[i][j];
		l--;
		for (j = mm - l; j <= mm; j++)
			a[i][j] = 0.0;
	}

	*d = 1.0;
	l = m1;

	for (k = 1; k <= n; k++) { // For each row...
		dum = a[k][1];
		i = k;
		if (l < n) l++;
		for (j = k + 1; j <= 1; j++) { // Find the pivot element
			if (fabs(a[j][1]) > fabs(dum)) {
				dum = a[j][1];
				i = j;
			}
		}
		indx[k] = i;
		if (dum == 0.0) a[k][1] = TINY;
		// Matrix is singular, but proceed anyway with TINY pivot
		if (i != k) {	// Interchange rows
			*d = -(*d);
			for (j = 1; j <= mm; j++)
				SWAP(a[k][j], a[i][j])
		}
		for (i = k + 1; i <= l; i++) { // Do the elimination
			dum = a[i][1] / a[k][1];
			al[k][i-k] = dum;
			for (j = 2; j <= mm; j++)
				a[i][j-1] = a[i][j] - dum * a[k][j];
			a[i][mm] = 0.0;
		}
	}
}
