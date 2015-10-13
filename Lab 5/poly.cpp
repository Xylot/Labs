/*

Joseph Meriam
ECE 1305 Lab 5
10/12/15
Prompts the user for a set of values and uses them to calculate the x, y, and slope 

*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{

	// Initialize variables
	double a0, a1, a2, x1, x2, n, deltaX, xArray[1002], yArray[1002], dArray[1002];

	// Prompts user to input their numbers
	cout << "Please enter your values: " << endl;
	cout << "a0: ";
	cin >> a0;
	cout << "a1: ";
	cin >> a1;
	cout << "a2: ";
	cin >> a2;
	cout << "x1: ";
	cin >> x1;
	cout << "x2: ";
	cin >> x2;

	// Prompts the user for n
	while (true) {

		cout << "n: ";
		cin >> n;

		// If the number is greater than 1001, they are reprompted
		if (n > 1001) {
			cout << "Please enter a number less than or equal to 1001 for n" << endl;
		}

		// Breaks from the loop
		else {
			break;
		}
	}

	// Calculates delta x
	deltaX = (x2 - x1) / n;

	// Calculates the values in the x array
	for (int i = 0; i <= n + 1; i++)
	{
		xArray[i] = i * deltaX + x1;
	}

	// Calculates the values in the y array
	for (int i = 0; i <= n + 1; i++)
	{	
		yArray[i] = a0 + a1 * xArray[i] + a2 * xArray[i] * xArray[i];
	}

	/*
		Calculates the slope
		I calculated n + 1 points to find the slope for the last point
	*/
	for (int i = 0; i <= n; i++)
	{
		dArray[i] = (yArray[i+1] - yArray[i]) / deltaX;
	}

	// Prints the table header
	cout << "     " << "X" << "     |     " << "Y" << "     |     " << "Slope" << endl;

	// Prints the table
	for (int i = 0; i <= n; i++) {

		// Adds extra spaces if x is a whole number for better formatting
		if (int(xArray[i]) == xArray[i]) {
			cout << xArray[i] << "             " << yArray[i] << "           " << dArray[i] << endl;
		}
		// If x is not a whole number
		else {
			cout << xArray[i] << "           " << yArray[i] << "          " << dArray[i] << endl;
		}
	}
}
