/*

Joseph Meriam
ECE 1305 Lab 5
10/7/15
Prompts the user for a number and then uses the babylonian algorithm to calculate its square root

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Calculates the square root
void squareRoot(double initialNumber) {

	// Initialize variables
	double result, guess, error, pastResult, ratio;

	// Number of iterations in the while loop
	int i = 0;

	// Margin for error
	error = 1e-6;

	// Sets the 'guess' number
	result = initialNumber / 2;

	// Runs until the result is within the margin of error
	while (true) {

		// Keeps track of the number of iterations
		i++;

		// Saves the previous result so we can compare it to the new one
		pastResult = result;

		// Perfroms the intermediate calculations
		result = (.5)*(result + initialNumber / result);

		// Calculates the ratio of the past and new results
		ratio = pastResult / result;

		// Breaks if the ratio is within 1%
		if (ratio >= 100 / 101 && ratio <= 101 / 100) {
			break;
		}

	}

	// Prints the final result along with the number of iterations
	cout << "After " << i << " iterations, the estimated square root of " << initialNumber << " is (+/-): " << result << "\n" << endl;
	cout << "The answer using the square root function is: " << sqrt(initialNumber) << endl;
	cout << "The absoulte error is: " << sqrt(initialNumber) - result << endl;
	cout << "The relative error is: " << result / sqrt(initialNumber) << "\n" << endl;
}

// Checks with the user if they want to do another calculation
bool calculateAgain() {

	// Initialize variables
	char choice;

	// Runs until y or n is entered
	while (true) {

		// Prompts the user with the option of performing another calculation
		// Y for yes, N for no
		cout << "Would you like to calculate another square root? [Y]es or [N]o? ";
		cin >> choice;

		// Clears screen
		system("cls");

		// Compares what the user entered with the predefined choices
		// Makes sure the input is forced to lowercase to avoid case errors
		switch (tolower(choice)) {

		case 'y':

			// The user does want to perform another calculation
			return true;

		case 'n':

			// The user does want to perform another calculation
			cout << "\nBye!\n" << endl;
			return false;

		default:
			// Handles input that was not predefined
			// Reprompts the user with the choice to do another recalculation
			cout << "I didn't catch that, try again\n" << endl;
		}
	}

}

// Prompts the user for the intial number
// Takes in count to check whether or not this is their first calculation 
double promptUser(int count) {

	// Initialize variable
	double initialNumber;

	// If this is the user's first calculation, a welcome message will appear
	if (count == 0)
		cout << "Welcome to the Babylonian square root calculator!\n" << endl;

	// Asks user for the initial number
	cout << "What is the number that you want to take the square root of? ";
	cin >> initialNumber;

	// If the user enters a neagative number, it will be converted to a positive number to avoid errors
	if (initialNumber < 0) {
		initialNumber = 0 - initialNumber;
	}

	// Clears screen
	system("cls");

	// Returns the value the user entered
	return initialNumber;

}

// Main Function
int main(void) {

	// How many calculations have been done
	int count = 0;

	// Sets decimal precision to 4
	cout << fixed << setprecision(4);

	// Main loop
	while (true) {

		// Performs the square root calculation with the number the user entered
		squareRoot(promptUser(count));

		// Exits Application if the user did not want to calculate again
		if (!calculateAgain()) {
			break;
		}

		// Iterates the number of calculations
		count++;
	}

}