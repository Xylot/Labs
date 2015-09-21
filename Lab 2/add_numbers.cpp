#include <iostream>
#include <string>

using namespace std;

// Checks with the user if they want to do another calculation
bool calculateAgain() {

	// Initialize variables
	char choice;

	// Runs until y or n is entered
	while (true) {

		// Prompts the user with the option of performing another calculation
		// Y for yes, N for no
		cout << "Would you like to do another calculation? [Y]es or [N]o? ";
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

// Main loop
int main(void)
{

	// Initialize Variables
	int numberOfIntegers, num, sum;
	int * numberArray;
	float average;
	bool isRunning = true;

	while (isRunning) {

		// Prompts the user asking for how many numbers they want to sum up
		cout << "How many numbers would you like to sum up? ";
		cin >> numberOfIntegers;

		// Sets up the array of numbers
		numberArray = new int[numberOfIntegers];
		
		// Sets the sum to zero 
		sum = 0;

		// Prompts the user for a number until the predetermined amount has been met and calculates the sum of the set
		for (num = 0; num < numberOfIntegers; num++)
		{

			// Prompts user for their numbers
			cout << "Enter your number: ";
			cin >> numberArray[num];

			// Calculates sum
			sum = sum + numberArray[num];

		}

		// Calculates average
		average = float(sum) / float(numberOfIntegers);

		// Clears Screen
		system("cls");

		// Prints out result
		for (num = 0; num < numberOfIntegers; num++) {

			// Prints out text before the numbers if this is the first iteration of the loop
			if (num == 0) {
				cout << "You entered the numbers: ";
			}

			// Prints out numbers
			if (num < numberOfIntegers - 1) {
				cout << numberArray[num] << ", ";
			}
			
			// Prints out the last number without the comma, the sum, and the average
			else {

				// Last number without the comma
				cout << numberArray[num] << endl;

				// Prints sum
				cout << "\n" << "Their resulting sum is: " << sum << endl;

				// Prints average
				cout << "Their resulting average is: " << average << "\n" << endl;

				// Deletes the number array
				delete[] numberArray;
			}
		}

		// If the user does not want to do another calculation, the program will exit
		if (!calculateAgain()) {
			break;
		}
	}
}