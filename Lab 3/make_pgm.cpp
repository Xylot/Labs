/*

Joseph Meriam
ECE 1305 Lab 3
9/26/15
Creates a right triangle PGM file that gets brighter towards the bottom

*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(void) {

	// Initialize Varibales
	int rows, cols, maxval, shadeInterval, backgroundColorValue;
	string pgmName, fNameIn;
	char choice;
	ofstream pgm;
	
	while (true) {
		
		// Prompts user to choose their own header values or use the default ones
		cout << "Would you like to use the [d]efault header settings or [c]hoose your own? ";
		cin >> choice;
		
		// If the user chose to use the default settings
		if (choice = 'd') {
		
			// Sets default file attributes
			rows = 20;
			cols = 30;
			maxval = 255;
			backgroundColorValue = 80;
			break;
			
		} else if (choice = 'c') {
			
			// Prompts user for number of rows
			cout << "How many rows would you like to see? ";
			cin >> rows;
			
			// Prompts user for number of columns
			cout << "How many columns would you like to see? ";
			cin >> cols;
			
			// Prompts user for max value
			cout << "What would you like the max value to be? (Higher = smoother transition): ";
			cin >> maxval;
			
			// Prompts user for the background color
			cout << "What would you like the background color value to be? (Higher = lighter): ";
			cin >> backgroundColorValue;
			
			break;
			
		} else {
			
			// Input error handling
			cout << "I didn't catch that, try again \n" << endl;
			
		}
		
	}
	
	// Prompts user for the PGM filename
	cout << "What would you like to name your PGM File? ";
	cin >> fNameIn;
	
	// Formats the filename
	pgmName = fNameIn + ".pgm";
	
	// Clears screen
	system("cls");
	
	// Prints file attributes
	cout << "Filename: " << pgmName << endl;
	cout << "Rows: " << rows << endl;
	cout << "Columns: " << cols << endl;
	cout << "Max Value: " << maxval << endl;
	cout << "Background Color Value: " << backgroundColorValue << endl;
	
	// Creates file
	pgm.open(pgmName.c_str());
	
	// Calculates the color transition for each row
	shadeInterval = maxval/rows;
	
	// Prints header
	pgm << "P2" << cols << " " << rows << " " << maxval << endl;
	
	// Iterates through the rows
	for (int i = 0;i < rows;i++) {
	
		// Iterates through the columns
		for (int j = 0;j < cols;j++) {
		
			// Prints the first column
			if ( j == 0) {
			
				// Prints the column based on the user defined background color value
				pgm << backgroundColorValue << " ";

				// Reiterates the loop
				continue;
			
			}
			
			// If j is less than or equal to i and this is not the last row
			if (j < i + 1 && i != rows - 1) {
			
				pgm << i * shadeInterval << " ";
			
			} else {
				
				// Prints the last row a solid color
				pgm << backgroundColorValue << " ";
			
			}
		
		}
		
		// Continues on to the next line
		pgm << endl;
	
	}
	
	// Lets the user know that their file has been created
	cout << "\n" << "Your PGM file has been created" << endl;
	
	// Closes the file
	pgm.close();
}