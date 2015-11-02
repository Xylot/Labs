/*

Joseph Meriam
ECE 1305 Lab 6
10/29/15
Calculates the factorial of a number recursively

*/

#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes
int get_factorial(int initNum);

// Main function
int main(void)
{

	// Initialize variables
	int initNum, result;

	// Prompts user for their number
	cout << "Enter an integer number: ";
	cin >> initNum;

	// Get the factorial
	result = get_factorial(initNum);

	// Prints the factorial
	cout << initNum << " factorial is: " << result << endl;

}

// Recursive factorial function
int get_factorial(int initNum) {

	// Sets inital result to 1
	int result = 1;

	// If the factorial is less than 1 the result will be 1
	if (initNum < 1) {
		return 1;
	}

	// Gets factorial recursively
	result = initNum * get_factorial(initNum - 1);

	// Returns the result
	return result;
}