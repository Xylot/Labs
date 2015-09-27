/*

Joseph Meriam
ECE 1305 Lab 3 Extra Credit
9/26/15
Creates a circle PGM file complete with shading the ability to draw a box

*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void) {

	// Initialize Varibales
	int rows, cols, maxval, shadeInterval, backgroundColorValue, radius, hypotenuse, xValue
		, yValue, yCoord, xCoord, boxHeight, boxWidth, boxColor;
	string pgmName, fNameIn;
	char settingsChoice, boxChoice;
	bool isBoxDrawn;
	ofstream pgm;
	
	while (true) {
		
		// Prompts user to choose their own header values or use the default ones
		cout << "Would you like to use the [d]efault header settings or [c]hoose your own? ";
		cin >> settingsChoice;
		
		if (settingsChoice == 'd') {
		
			// Sets default file attributes
			rows = 120;
			cols = 128;
			maxval = 255;
			backgroundColorValue = 0;
			radius = 56;
			break;
			
		} else if (settingsChoice == 'c') {
			
			// Prompts user for number of rows
			cout << "How many rows would you like to see? ";
			cin >> rows;
			
			// Prompts user for number of columns
			cout << "How many columns would you like to see? ";
			cin >> cols;
			
			// Prompts user for the circle radius
			cout << "What do you want the circle radius to be? ";
			cin >> radius;
			
			// Prompts user for max value
			cout << "What would you like the max value to be? (Higher = smoother transition): ";
			cin >> maxval;
			
			// Prompts user for the background color
			cout << "What would you like the background color value to be? (Higher = lighter): ";
			cin >> backgroundColorValue;
			
			while (true) {
			
				// Prompts user for the choice to draw a box
				cout << "Would you like to draw a box?! [Y]es or [N]o? ";
				cin >> boxChoice;
				
				// The user wants to draw a box
				if (boxChoice == 'y') {
				
					// Prompts user for box height
					cout << "Box height? ";
					cin >> boxHeight;
					
					// Prompts user for box width
					cout << "Box width? ";
					cin >> boxWidth;
					
					// Allows the box to be drawn
					isBoxDrawn = true;
					
					// Breaks from box loop
					break;
				
				// The user does not want to draw a box
				} else if (boxChoice == 'n') {
			
					// Disallows the box to be drawn
					isBoxDrawn = false;
					
					// Breaks from box loop
					break;
			
				} else {
				
					// Input error handling
					cout << "I didn't catch that, try again \n" << endl;
				
				}
			}
			
			// Breaks from settings loop
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
	cout << "Circle Radius: " << radius << endl;
	cout << "Max Color Value: " << maxval << endl;
	cout << "Background Color Value: " << backgroundColorValue << endl;
	
	if (isBoxDrawn) {
	
		cout << "Box Height: " << boxHeight << endl;
		cout << "Box Width: " << boxWidth << endl;
	
	}
	
	// Creates file
	pgm.open(pgmName.c_str());
	
	// Calculates the color transition for each row
	shadeInterval = maxval/radius;
	
	// Prints header
	pgm << "P2 " << cols << " " << rows << " " << maxval << endl;
	
	// Iterates through the rows
	for (int i = 0;i < rows;i++) {
	
		// If the coordinate is positive
		if (rows/2 - i > 0) {
			
			// Rows/2 is bigger than i which makes the coordinate positive
			yCoord = (rows/2 - i);
			
		// If the coordinate is negative
		} else if (rows/2 - i < 0){
			
			// Rows/2 is bigger than i which makes the coordinate negative
			yCoord = (rows/2 - i);
		
		} else {
			
			// Coordinate is zero
			yCoord = 0;
			
		}
		
		// Iterates through the columns
		for (int j = 0;j < cols;j++) {
			
			// If the coordinate is positive
			if (cols/2 - j > 0) {
			
				// Cols/2 is bigger than i which makes the coordinate positive
				xCoord = (cols/2 - j);
			
			// If the coordinate is negative
			} else if (cols/2 - j < 0) {
			
				// Cols/2 is bigger than i which makes the coordinate negative
				xCoord = (cols/2 - j);
			
			} else {
			
				// Coordinate is zero
				xCoord = 0;
			
			}
			
			// The value of x^2
			xValue = pow((double)xCoord,2);
			
			// The value of y^2
			yValue = pow((double)yCoord,2);
			
			// The value of the hypotenuse
			hypotenuse = sqrt(xValue + yValue);
		
			// If the radius is larger than the hypotenuse
			if ( hypotenuse < radius) {
			
				// If the user chose to draw a box
				if (isBoxDrawn) {
					
					// Draws the box if the x and y coordinates are within its limits
					if (xCoord < boxWidth && xCoord > -(boxWidth) && yCoord < boxHeight && yCoord > -(boxHeight)) {
						
						// Draws the box based on the user defined box color value
						pgm << boxColor << " ";
						
					// Draws the rest of the circle
					} else {
						
						// Draws the inner shading by multiplying the hypotenuse by the previously calculated shadeInterval
						pgm << hypotenuse * shadeInterval << " ";
					}
				
				// Draws the circle without the box
				} else {
					
					// Draws the inner shading by multiplying the hypotenuse by the previously calculated shadeInterval
					pgm << hypotenuse * shadeInterval << " ";
					
				}
				
			
			} else {
			
				// Draws the background based on the user defined background color value
				pgm << backgroundColorValue << " ";	
			
			}
		}
		
		
	
	}
	
	// Lets the user know that the file has been created
	cout << "\n" << "Your PGM file has been created" << endl;
	
	// Closes the file
	pgm.close();
}