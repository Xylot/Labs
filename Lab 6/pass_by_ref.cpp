/*

Joseph Meriam
ECE 1305 Lab 6
10/29/15
Gets the magnitudes and polar forms of vectors

*/

#include<iostream>
#include<cmath>

using namespace std;

// Prototypes
double mag(double x, double y);
void r2p(double x, double y, double& r, double& theta);

// Main function
int main(void)
{

	// Initialize variables
	double x = 0;
	double y = 0;
	double r, theta, mg;

	// Prompts user for their numbers
	cout << "Please enter the X coordinate: ";
	cin >> x;
	cout << "Please enter the Y coordinate: ";
	cin >> y;

	// Gets magnitude
	mg = mag(x, y);

	// Prints magnitude
	cout << "The magnitude of ( " << x << " , " << y << " ) is: " << mg << endl;

	// Gets polar from
	r2p(x, y, r, theta);

	// Prints polar form
	cout << "the polar form of ( " << x << " , " << y << " ) is: ( " << r << " , " << theta << " )" << endl;

}


// Calculates the magnitude
double mag(double x, double y) {

	// Calculates magnitude
	double mag = sqrt(pow(x, 2) + pow(y, 2));

	// Returns the magnitude
	return mag;
}

// Converts from rectangular to polar
void r2p(double x, double y, double& r, double& theta) {

	// Gets radius
	r = mag(x, y);

	// Gets theta
	theta = atan(y / x);

}