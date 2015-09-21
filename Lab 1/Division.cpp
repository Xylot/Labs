/*

Joseph Meriam
9/8/15
ECE 1305 Lab 1
Little siblings' dividing program

*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// If the user is the brother
void brother() {

	// Initialize variables
	int b1, b2;

	// Runs until user does not attempt to divide by zero
	while (true) {

		//Prompts user for the numbers that they wish to divide
		cout << "Enter your first number: ";
		cin >> b1;
		cout << "Enter your second number: ";
		cin >> b2;

		// If the user attempts to divide by zero, they will be asked to re-enter valid numbers
		if (b2 == 0) {
			cout << "You can't divide by zero! Try again" << endl;
		}
		else {
			break;
		}
	}

	// Sets bResult equal to the quotient of s1 and s2
	int bResult = b1 / b2;

	// Sets bRemainder equal to the remainder of s1 and s2
	int bRemainder = b1 % b2;

	// Prints the result
	cout << "\n" << "Result: " << bResult << endl;

	// Prints the remainder
	cout << "Remainder: " << bRemainder << "\n" << endl;
}

// If the user is the sister
void sister() {

	// Initialize variables
	double s1, s2, sResult;

	// Runs until user does not attempt to divide by zero
	while (true) {

		//Prompts user for the numbers that they wish to divide
		cout << "Enter your first number: ";
		cin >> s1;
		cout << "Enter your second number: ";
		cin >> s2;

		// If the user attempts to divide by zero, they will be asked to re-enter valid numbers
		if (s2 == 0) {
			cout << "You can't divide by zero! Try again" << endl;
		}
		else {
			break;
		}

	}

	// Sets sResult equal to the quotient of s1 and s2
	sResult = s1 / s2;

	// Prints the answer
	cout << "\n" << "Result: " << sResult << "\n" << endl;

}

// Checks with the user if they want to do another calculation
int calculateAgain() {

	// Initialize variables
	char choice;

	// Runs until y, n or c is entered
	while (true) {

		// Prompts the user with the option of performing another calculation
		// Y for yes, N for no, and C for change user
		cout << "Would you like to do another? [Y]es, [N]o, or [C]hange user? ";
		cin >> choice;

		// Clears screen
		system("cls");

		// Compares what the user entered with the predefined choices
		// Makes sure the input is forced to lowercase to avoid case errors
		switch (tolower(choice)) {

		case 'y':

			// The user does want to perform another calculation
			return 1;

		case 'n':

			// The user does want to perform another calculation
			cout << "\nBye!\n" << endl;
			return 2;

		case 'c':

			// The user has decided to change the current user setting
			return 3;

		default:

			// Handles input that was not predefined
			// Reprompts the user with the choice to do another recalculation
			cout << "I didn't catch that, try again\n" << endl;
		}
	}

}

// Checks which sibling the user is based on what they entered in
bool checkSibling(char currentSibling) {

	// Runs until b or s is entered
	while (true) {

		// Compares what the user entered with the predefined choices
		// Makes sure the input is forced to lowercase to avoid case errors
		switch (tolower(currentSibling)) {

		case 'b':

			// Clears screen
			system("cls");

			// Greets brother
			cout << "Hello brother! \n" << " " << endl;

			// Returns true for brother
			return true;

		case 's':

			// Clears screen
			system("cls");

			// Greets sister
			cout << "Hello sister! \n" << " " << endl;

			// Returns false for brother
			return false;

		default:

			// Clears screen
			system("cls");

			// Handles input that was not predefined
			// Reprompts the user with the choice to do another recalculation
			cout << "I didn't catch that, are you my [B]rother or [S]ister?\n" << endl;
		}

	}
}

// Asks the user which sibling they are
char promptSibling() {
	
	// Initialize variables
	char response;

	// Prompts the user to enter which sibling they are
	// B = Brother, S = Sister
	cout << "Are you my [B]rother or [S]ister? ";
	cin >> response;

	// Returns sibling value
	return response;
}

// Main Function
int main(void) {

	// The current 'sibling' using the program
	// True = brother, false = sister
	bool currentSibling = checkSibling(promptSibling());

	// Variable to determine if the loop should be running
	bool isRunning = true;

	// Main loop
	while (isRunning) {

		// Check if the current sibling is the brother or sister
		if (currentSibling) {
			brother(); // True
		}
		else {
			sister(); // False
		}

		// Exits Application if the user did not want to calculate again
		switch (calculateAgain()) {
		case 2:
			isRunning = false;
		case 3:
			currentSibling = !currentSibling;
		}

	}
}
