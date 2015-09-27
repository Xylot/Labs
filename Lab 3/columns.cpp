#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main() {

	// Initialize variables
	string line, rheight, rlength, rhypotenuse, x, fileName;
	double area, height, length, hypotenuse;
	
	// Prompts user for their filename
	cout << "What is the name of the file that you wish to use? (No extension) ";
	cin >> fileName;
	
	// Adds the .txt extension to the file
	fileName += ".txt";

	// Loads the file
	ifstream triangle(fileName.c_str());

	// Loads line 1
	getline(triangle, line);
	istringstream getHeight(line);

	// Gets the characters before the space
	getHeight >> x;

	// Gets the height
	getHeight >> rheight;

	// Turns the height into a double for calculations
	height = stod(rheight);

	// Load line 2
	getline(triangle, line);
	istringstream getLength(line);

	// Gets the characters before the space
	getLength >> x;

	// Gets the length
	getLength >> rlength;

	// Turns length into a double for calculation
	length = stod(rlength);

	// Loads line 3
	getline(triangle, line);
	istringstream getHypotenuse(line);

	// Gets the characters before the space
	getHypotenuse >> x;

	// Gets the hypotenuse
	getHypotenuse >> rhypotenuse;

	// Turns the hypotenuse into a double
	hypotenuse = stod(rhypotenuse);
	
	// Calculates area
	area = (length*height) / 2;

	// Prints triangle dimensions
	cout << "Triangle dimensions \n" << endl;
	cout << "Height: " << height << endl;
	cout << "Length: " << length << endl;	
	cout << "Hypotenuse: " << hypotenuse << "\n" << endl;

	// Prints area
	cout << "The area of the triangle is: " << area << "\n" << endl;

	// Closes file
	triangle.close();
}