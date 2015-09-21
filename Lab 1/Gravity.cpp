/*

Joseph Meriam
9/8/15
ECE 1305 Lab 1
Calculates the time needed to reach maximum height and the maximum height reached

*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// Calculates the time it takes to reach the maximum height
double timeToMaxHeightCalc(double vInit, double acceleration) {

	// Initialize Variables
	double timeToMaxHeight;

	// V Final will be zero when the object reaches its maximum height
	double vFinal = 0;

	// Performs the calculation
	timeToMaxHeight = (vFinal - vInit) / (acceleration);

	// Returns the result
	return timeToMaxHeight;
}

// Calculates the maximum height the object reaches
double maxHeightCalc(double yInit, double vInit, double timeToMaxHeight) {

	// Initialize Variables
	double maxHeight;

	// vFinal will be zero when the object reaches its maximum height
	double vFinal = 0;

	// Performs the calculation
	maxHeight = yInit + (.5) * (vInit + vFinal) * (timeToMaxHeight);

	// Returns the result
	return maxHeight;

}

// Checks with the user if they want to do another calculation
bool calculateAgain() {

	// Initialize variables
	char choice;

	// Runs until y or n is entered
	while (true) {

		// Prompts the user with the option of performing another calculation
		// Y for yes, N for no
		cout << "Do you want to do another calculation? [Y]es or [N]o? ";
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
	double vInit;

	// If this is the user's first calculation, a welcome message will appear
	if (count == 0)
		cout << "Welcome to the trajectory calculator!\n" << endl;

	// Runs until user does not attempt to use a negative initial velocity
	while (true) {

		// Asks user for the initial velocity
		cout << "What is your initial velocity? ";
		cin >> vInit;

		// If the user attempts to enter a negative initial velocity, they will be asked to enter a valid positive number
		if (vInit < 0) {

			// Clears screen
			system("cls");

			// Prompts user to enter a positive intial velocity
			cout << "You can't throw a ball through the ground! Please enter a positive value\n" << endl;
		}
		else {
			break;
		}


	}

	// Returns the initial velocity
	return vInit;

}

// Performs all of the calculations and outputs the results to the console
void calculateEverything(double vInit) {
	
	// Initialize variables
	double acceleration, yInit;

	// Acceleration will always be -9.8
	acceleration = -(9.8);

	// Assuming the throw is started on ground level, the Y Initial will always be zero
	yInit = 0;

	// Clears screen
	system("cls");

	// Performs all of the calculations and outputs the results to the console
	cout << "Initial Velocity: " << vInit << " m/s\n" << endl;
	cout << "Time to maximum height: " << timeToMaxHeightCalc(vInit, acceleration) << " seconds" << endl;
	cout << "Maximum height reached: " << maxHeightCalc(yInit, vInit, timeToMaxHeightCalc(vInit, acceleration)) << " meters\n" << endl;

}

// Main Function
int main(void) {

	// How many calculations have been done
	int count = 0;

	// Main loop
	while (true) {

		// Performs the square root calculation with the number the user entered
		calculateEverything(promptUser(count));

		// Exits Application if the user did not want to calculate again
		if (!calculateAgain()) {
			break;
		}

		// Iterates the number of calculations
		count++;
	}

}