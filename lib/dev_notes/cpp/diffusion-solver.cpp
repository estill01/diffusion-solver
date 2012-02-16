// Diffusion-Solver
// Ethan Stillman
// C++

#include <iostream>
using namespace std;

/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *																																																	 *
 *																																																	 *
 *																																																	 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 */

// Size of the simulation space
struct CartesianDomain {
	int x = 100;				
	int y = 100;
	int z = 100;
// 	int is_periodic = 0;		// does the space wrap around itself?
}

// Granularity of simulation along each spatial dimension
struct DimensionalResolution {
	int dx = 1;
	int dy = 1;
	int dz = 1;
}

CartesianDomain init_domain(int x = 100, int y = 100, int z = 100 /*, int is_periodic = 0 */ ) {
	try {
		catch ((x||y||z) < 0 ) {
			cout << "ERROR: Non-Positive Domain Dimension(s)" << endl;
			cout << "All spatial dimension must be >= 0 for simulation to be meaningful." << endl;
		}
	}

	CartesianDomain domain;
	domain.x = x;
	domain.y = y;
	domain.z = z;
	
	return domain;
}

DimensionalResolution init_resolution(int dx = 1, int dy = 1, int dz = 1) {
	try {
		catch ((dx||dy||dz) < 0) {
			cout << "ERROR: Negative Dimensional Resolution" << endl;
			cout << "All dimensional resolution values must be >= 0 for simulation to work." << endl;
		}
	}

	DimensionalResolution resolution;
	resolution.dx = dx;
	resolution.dy = dy;
	resolution.dz = dz;

	return resolution;
}


diffusivity
timestep


/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *																																																	 *
 *																																																	 *
 *																																																	 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 */

// Forward-Time Central-Space
int ftcs(){
	
}

// Crank-Nicholson Method
int crank-nicholson {

}


int main() {

}
