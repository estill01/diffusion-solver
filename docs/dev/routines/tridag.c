// Tridag.c
// Method for solving tridiagonal linear system of equations
// Source: p. 51 in  "Numerical Recipes"

#include <nrutil.h>

// Solves for a vector u[1..n] the tridiagonal linear set given by equation (2.4.1).
// a[1..n], b[1..n], c[1..n], and r[1..n] are input vectors and are not modified.
void tridag(float a[], float b[], float c[], float r[], float u[], unsigned long n) {
	unsigned long j;
	float bet,*gam;

	gam = vector(1,n);
	// One vector of workspace, gam is needed.
	
	if (b[1] == 0.0) nrerror("Error 1 in tridag"); 
	// If this happens then you should rewrite your equations as a set of order N − 1, with u2 trivially eliminated.
	
	u[1] = r[1]/(bet=b[1]);
	
	for (j = 2; j <= n; j++) {	// Decomposition and forward substitution.
		gam[j] = c[j-1]/bet;
		bet=b[j]-a[j]*gam[j];
		
		if (bet == 0.0)	nrerror("Error 2 in tridag"); // Algorithm fails; see below.
		
		u[j] = (r[j]-a[j]*u[j-1])/bet;
	} 
	
	for (j = (n-1); j >= 1; j--)	// Backsubstitution.
		u[j] -= gam[j+1]*u[j+1];
	
	free_vector(gam,1,n);
}

// Equation 2.4.1
//
//    b1  c1  0   ···                    u1        r1 
//    a2  b2  c2  ...                    u2        r2 
//                ...                 *  ···   =  ···  
//                ··· aN−1 bN−1 cN−1     uN−1     rN−1
//                ··· 0    aN   bN       uN       rN  
