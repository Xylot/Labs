/*

Joseph Meriam
ECE 1305 Lab 4
10/2/15
Outputs a table with the months, their number of days, and the total number of preceeding days
Prompts the user for a year and day number and then outputs the month and day it falls on

*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	// Initialize Variables
	int amount, sum, daysPreceding, day, year;
	double average;
	
	// Creates monthArray array
	string monthArray[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	// Creates dayArray array
	int dayArray[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	// Sets dayArray preceding to zero
	daysPreceding = 0;
	
	// Prints the table
	for(int i = 0; i < 12; i++) {
		
		// Prints the table header
		if(i == 0) {
			cout << endl;
			cout << "    Month         dayArray        dayArray Preceding  " << endl;
			cout << " ___________    ________    __________________" << endl;
		}
		
		// Prints the month
		cout << "  " << monthArray[i];
		
		
		// Prints the remaining spaces after the month to fromat the table correctly
		for(int j = monthArray[i].length(); j < 9; j++) {
			
			cout << " ";
			
		}
		
		// Prints the number of days in the month
		cout << "        " << dayArray[i];
		
		// Prints the days preceding
		cout << "               " << daysPreceding << endl;
		
		// Increments preceding days by the number of days in the current month
		daysPreceding += dayArray[i];	
		
	}	
	
	// Prompts the user for the year that they would like to look up
	cout << "\n" << "What year would you like to look up? ";
	cin >> year;
	
	// If the year is a leap year
	if(year % 4 == 0){
	
		// Prompts the user for the day
		cout << "\n" << "What day number? (1-366) ";
		cin >> day;
		
		// Sets the number of days in February to 29
		dayArray[1] = 29;
	
	} 
	
	// If the year is not a leap year
	else {
	
		// Prompts the user for the day
		cout << "\n" << "What day number? (1-365) ";
		cin >> day;
	
	}
	
	// Resets the days preceding to zero
	daysPreceding = 0;
	
	// Prints the month and day that corresponds to the day entered
	for(int i = 0;i < 12;i++) {
	
		// If the day entered is within the current month iteration
		if(day > daysPreceding && day <= daysPreceding + dayArray[i]) {
		
			cout << monthArray[i] << " " << day - daysPreceding << endl;
		
		}
	
		// Increments preceding days by the number of days in the current month
		daysPreceding += dayArray[i];
	
	}
	
}