/*

Joseph Meriam 
9/8/15
ECE 1305 Lab 1
Babylonian square root implementation

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Calculates the square root
void squareRoot(double initialNumber) {

	// Initialize variables
	double result, guess, error;

	// Number of iterations in the while loop
	int i = 0;
	
	// Margin for error
	error = 1e-6;

	// Sets the 'guess' number
	result = initialNumber;

	// Runs until the result is within the margin of error
	while ((result - (initialNumber / result)) > error) {

		// Perfroms the intermediate calculations
		result = (.5)*(result + initialNumber / result);

		// Keeps track of the number of iterations
		i++;
	}

	// Prints the final result along with the number of iterations
	cout << "After " << i << " iterations, the estimated square root of " << initialNumber << " is (+/-): " << result << "\n" << endl;
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
	if(initialNumber < 0){
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