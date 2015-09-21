/*

Joseph Meriam
ECE 1305 Lab 2
9/16/15

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Checks with the user if they want to do another conversion
bool convertAgain() {

    // Initialize variables
    char choice;

    // Runs until y or n is entered
    while (true) {

        // Prompts the user with the option of performing another calculation
        // Y for yes, N for no
        cout << "Would you like to do another conversion? [Y]es or [N]o? ";
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

// Decimal to binary logic
string binary(int decimal) {

    // Initialize variables
    string bin;

    // Returns zero if the input is zero
    if (decimal == 0) {
        return "0";
    }

    // Runs until the decimal is zero
    while (decimal != 0) {

        // If the decimal has a remainder of zero
        if ((decimal % 2) == 0) {

            // Adds the character 0 to the binary representation string
            bin = "0" + bin;

        }

        // If the decimal does not have have a remainder of zero
        else {

            // Adds the character 1 to the binary representation string
            bin = "1" + bin;

        }

        // Divides the decimal by 2 in preperation for the next number
        decimal = decimal / 2;

    }


    // Returns the binary representation
    return bin;

}


// Main loop
int main(void) {

    // Initialize variables
    int decimal;
    bool isRunning = true;

    while (isRunning) {

        // Runs until the user enters a positive number
        while (true) {

            // Prompts user for the number they wish to be converted
            cout << "Enter the number that you wish to convert to binary: ";
            cin >> decimal;

            // Breaks if the user enters a postive number
            if (decimal > 0) {
                break;
            }

            // Tells the user to enter a positive number
            else {
                cout << "Please enter a positive number" << endl;
            }

        }

        // Clears Screen
        system("cls");


        // Prints out the formatted result
        cout << "The binary representation of " << decimal << " is: " << binary(decimal) << "\n" << endl;

        if (!convertAgain()) {
            isRunning = false;
        }

    }

}