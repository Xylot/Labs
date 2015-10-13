/*

Joseph Meriam
ECE 1305 Lab 5
10/7/15
Prompts the user for a number of seconds and then converts the number to hours, minutes and seconds

*/
#include <iostream>

using namespace std;

int main()
{

	// Initialize variables
	int initSecs, seconds, minutes, hours, i;

	// Prompts user for the number of seconds that they wish to convert
	cout << "Enter your number of seconds: ";
	cin >> initSecs;

	// Sets variables to zero
	i = 0;
	seconds = 0;
	minutes = 0;
	hours = 0;

	// Conversion loop
	while (i < initSecs) {
		
		// If the number of seconds reaches 60, a minute is added to the counter
		if (seconds == 60) {

			// Increments minutes and sets seconds back to zero
			minutes++;
			seconds = 0;

			// If the number of minutes reaches 60, an hour is added to the counter
			if (minutes == 60) {

				// Increments hours and sets minutes back to zero
				hours++;
				minutes = 0;
			}

		}

		// Increments seconds
		seconds++;

		// Increments the loop counter
		i++;

	}

	// Prints Results
	cout << "Hours: " << hours << endl;
	cout << "Minutes: " << minutes << endl;
	cout << "Seconds: " << seconds << endl;

}