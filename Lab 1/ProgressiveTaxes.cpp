/*

Joseph Meriam
ECE 1305
Lab 1
Progressive Tax calculator

*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// Calculates the income tax based on what the user entered
void calculateIncomeTax(double income) {

	// Initialize variables
	double taxAmount, incomeAfterTax, taxPercentage;

	// The tax amount calculations below are done that way so I can easily print out the percentage paid in the final output

	// Income is less than or equal to 5000
	if (income <= 5000) {

		// Tax Percentage
		taxPercentage = 0;

		// Calculates the amount of tax that will be paid
		taxAmount = (income / 100) * taxPercentage;

		// Calculates what you will take home in the end
		incomeAfterTax = income - taxAmount;

	}

	// Income is greater than 5000 and less than or equal to 10000
	else if (income > 5000 && income <= 10000) {

		// Tax Percentage
		taxPercentage = 10;

		// Calculates the amount of tax that will be paid
		taxAmount = ((income - 5000) / 100) * taxPercentage;

		// Calculates what you will take home in the end
		incomeAfterTax = income - taxAmount;

	}

	// Income is greater than 10000 and less than or equal to 20000
	else if (income > 10000 && income <= 20000) {

		// Tax Percentage
		taxPercentage = 15;

		// Calculates the amount of tax that will be paid
		taxAmount = ((income - 10000) / 100) * taxPercentage + 500;

		// Calculates what you will take home in the end
		incomeAfterTax = income - taxAmount;

	}

	// Income is greater than 10000 and less than or equal to 20000
	else if (income > 20000 && income <= 30000) {

		// Tax Percentage
		taxPercentage = 20;

		// Calculates the amount of tax that will be paid
		taxAmount = ((income - 10000) / 100) * taxPercentage + 2000;

		// Calculates what you will take home in the end
		incomeAfterTax = income - taxAmount;

	}

	// Income is greater than 30000
	else {

		// Tax Percentage
		taxPercentage = 30;

		// Calculates the amount of tax that will be paid
		taxAmount = ((income - 30000) / 100) * taxPercentage + 4000;


		// Calculates what you will take home in the end
		incomeAfterTax = income - taxAmount;

	}

	// Prints out results
	cout << "\nYou Belong in the %" << taxPercentage << " tax bracket" << endl;
	cout << "You are paying $" << taxAmount << " in taxes" << endl;
	cout << "You are taking home $" << incomeAfterTax << "\n" << endl;

}

// Sets the console to only display 2 decimal points
void twoDecimals() {
	cout << fixed << setprecision(2);
}

// Checks with the user if they want to do another calculation
bool calculateAgain() {

	// Initialize variables
	char choice;

	// Runs until y or n is entered
	while (true) {

		// Prompts the user with the option of performing another calculation
		// Y for yes, N for no
		cout << "Would you like to calculate the tax on another income? [Y]es or [N]o? ";
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
	double initIncome;

	// If this is the user's first calculation, a welcome message will appear
	if (count == 0)
		cout << "Welcome to the income tax calculator!\n" << endl;

	// Asks user for their income
	cout << "What is your income? ";
	cin >> initIncome;

	// Returns the value the user entered
	return initIncome;

}

// Main Function
int main(void) {

	// How many calculations have been done
	int count = 0;

	// Sets the console to only display 2 decimal points
	twoDecimals();

	// Main loop
	while (true) {

		// Performs the income tax calculation with the number the user entered
		calculateIncomeTax(promptUser(count));

		// Exits Application if the user did not want to calculate again
		if (!calculateAgain()) {
			break;
		}

		// Iterates the number of calculations
		count++;
	}

}