//============================================================================
// Name        : find_pi.cpp
// Author      : Ian Scott-Fleming
// Version     :
// Copyright   : 
// Description : Finds zero-crossing for cos(theta), for theta between 3 & 4
//				 Demonstrates a do-while loop to iterate until the answer
//				 sought is close enough.
//============================================================================

#include <iostream>
#include <cmath>		// for cosine function
#include <iomanip>		// so we can set # of digits on output
using namespace std;

int main()
{
	int nsteps = 0;
	double thresh, theta1 = 3.0, theta2 = 4.0, delta, my_pi;

	//Pi is somewhere between 3 and 4, and we know that
	// sin(theta) changes from positive to negative at
	// theta = pi. So, lets use sin(theta) repeatedly to find PI,
	// adjusting my endpoints each time to zero in on the actual value.

	cout << "threshold (accuracy for pi)? ";
	cin >> thresh;

	cout << fixed << setprecision(10);

	delta = theta2 - theta1;
	my_pi = (theta2+theta1)/2.0;
	do
	{
				// Am I too high or too low?
		if (sin(my_pi) > 0)
			theta1 = my_pi;	// too high.  move theta1 in closer
		else
			theta2 = my_pi;	// too low.  move  theta2 in closer

				// calculate the PI estimate and the delta
		delta = theta2 - theta1;
		my_pi = (theta2+theta1)/2.0;

			// count the # of steps, and output intermediate results
		nsteps = nsteps + 1;
		cout << nsteps << "\t" << theta1 << "\t" << my_pi << "\t" << theta2 << "\t" << delta << endl;
	} while (delta > thresh);

	cout << "PI estimate:   " << my_pi << endl;
	cout << "PI is really:  " << acos(-1.0) <<endl;
	cout << "difference:    " << abs(my_pi - acos(-1.0)) << endl;		// abs( ) gives us the absolute value
	cout << "threshold:     " << thresh << endl;
 	return 0;
}
