/*

Joseph Meriam
ECE 1305 Lab 3
9/26/15
Outputs triangle side lengths to a text file

*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
	
	// Initialize variables
	double length, height, hypotenuse;
	ofstream triangle;
	string fileName;

	// Prompts user for height
	cout << "What is the triangle height? ";
	cin >> height;

	// Prompts user for length
	cout << "What is the triangle length? ";
	cin >> length;

	// Calculates the length of the hypotenuse
	hypotenuse = sqrt(pow(height, 2) + pow(length, 2));
	
	// Prompts user for the file name that they wish to use
	cout << "What do you want to name your file? (No extension) ";
	cin >> fileName;
	
	// Adds the .txt extension to the file
	fileName += ".txt";
	
	// Creates/Edits the triangle.txt file
	triangle.open(fileName.c_str());

	// Prints height
	triangle << "Height: " << height << endl;

	// Prints length
	triangle << "Length: " << length << endl;

	// Prints hypotenuse
	triangle << "Hypotenuse: " << hypotenuse << endl;
	
	// Lets the user know that their file has been created
	cout << "\nYour file has been created" << endl;

	// Closes the file
	triangle.close();

}