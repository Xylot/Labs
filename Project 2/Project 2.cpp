/*

Joseph Meriam
ECE 1305 Project 2
11/30/15
Adds illumination to the contour maps created in project 1

*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

// Global variables
const double PI = 3.141592653589793;
const double SKYBRIGHTNESS = .1;

// Prototypes
string getFileName();
string setFileName(string fileNameDesc, bool addDesc);
string getFileRoot();
double setSunAngle();
double setSunElevation();
int setContourLevel();
int convertEgmToPgmValue(double egmValue, double egmMax, int pgmMax);
bool checkFileExistence(string fileName);
void setPixelScale(string fileName, int& pixelScaleX, int& pixelScaleY);
void getInitialEgmFileProperties(string fileName, string& identifier, int& rows, int& columns, int& commentNumber, double& minElevation, double& maxElevation, bool& isNegative, int& pixelScaleX, int& pixelScaleY);
void doEgmTasks(string fileName, int userChoice, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, int pixelScaleX, int pixelScaleY);
void writePgmArrayToFile(double ** fileArray, int rows, int columns, string fileNameRoot, string fileNameDesc, bool multi);
void createPgmFile(double ** fileArray, int rows, int columns);
void userOptions(string& fileName, int& userChoice);
void createNoContourImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc);
void createContourImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc, int contourLevel);
void createVerticalDerivativeImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc, int contourLevel);
void createHorizontalDerivativeImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc, int contourLevel);
void createThresholdImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc, int contourLevel);
void createAllImages(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, int contourLevel);
double ** getInitialFileArray(string fileName, int rows, int columns, int commentNumber, bool isNegative);
double ** convertEgmToContourArray(double ** fileArray, int rows, int columns, double egmMax, bool multi, int userContourLevel);
double ** convertEgmToPgmArray(double ** fileArray, int rows, int columns, double egmMax);
double ** takeHorizontalDerivative(double ** fileArray, int rows, int columns);
double ** takeVerticalDerivative(double ** fileArray, int rows, int columns);
double ** getFinalArray(double ** fileArray, int rows, int columns);
double ** thresholdImage(double ** hArray, double ** vArray, int rows, int columns);
double ** illuminate(double ** fileArray, int rows, int columns, int pixelScaleX, int pixelScaleY);
double getDotProduct(double a1, double a2, double a3, double b1, double b2, double b3);
void getCrossProduct(double a1, double a2, double a3, double b1, double b2, double b3, double& c1, double& c2, double& c3);
void createIlluminatedImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc);
double getMagnitude(double x, double y, double z);

int main(void) {

	// Initialize variables
	string fileName, identifier;
	bool isNegative = false;
	int rows, columns, commentNumber, userChoice, pixelScaleX, pixelScaleY;
	double minElevation, maxElevation;

	// Presents the user with the available options 
	userOptions(fileName, userChoice);

	// Gets the header properties from the chosen file
	getInitialEgmFileProperties(fileName, identifier, rows, columns, commentNumber, minElevation, maxElevation, isNegative, pixelScaleX, pixelScaleY);

	// Does everything
	doEgmTasks(fileName, userChoice, rows, columns, commentNumber, minElevation, maxElevation, isNegative, pixelScaleX, pixelScaleY);


}

// Does all of the functions based on what the user chose to do
void doEgmTasks(string fileName, int userChoice, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, int pixelScaleX, int pixelScaleY) {

	// Initialize variables
	string root, desc;
	bool multi = false;
	int contourLevel = 0;

	// Sets the file root and description to nothing
	root = "";
	desc = "";

	// If statements based on the user's choice
	if (userChoice == 1) {

		// Creates no contour image
		createNoContourImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, desc);

	}
	else if (userChoice == 2) {

		// Creates contour image
		createContourImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, desc, contourLevel);

	}
	else if (userChoice == 3) {

		// Creates horizontal derivative image
		createHorizontalDerivativeImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, desc, contourLevel);

	}
	else if (userChoice == 4) {

		// Creates vertical derivative image
		createVerticalDerivativeImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, desc, contourLevel);

	}
	else if (userChoice == 5) {

		// Creates threshold image
		createThresholdImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, desc, contourLevel);

	}
	else if (userChoice == 6) {

		// Creates illuminated image
		createIlluminatedImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, desc);
		
	}
	else if (userChoice == 7) {

		// Sets the multiple files boolean to true
		multi = true;

		// Gets the file root from the user
		root = getFileRoot();

		// Gets the contour level from the user
		contourLevel = setContourLevel();

		// Creates all of the images
		createAllImages(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, contourLevel);

	}


	if (userChoice < 7) {

		// Success message
		cout << "\n" << "Your file has been created!" << "\n" << endl;

	}

}

// Prompts the user for a root name for their files if they chose to print all of them
string getFileRoot() {

	// Initialize variables
	string root;

	// Prompts the user for a file root
	cout << "What would you like to name your files? ";
	cin >> root;

	// Formatting
	cout << endl;

	// Returns the root
	return root;

}

// Presents the user with the available options 
void userOptions(string& fileName, int& userChoice) {

	// prints welcome message
	cout << "Welcome to the contour map creator!" << "\n" << endl;

	// Gets filename
	fileName = getFileName();

	// Prints options
	cout << "Here are your options: " << "\n" << endl;

	cout << "	[1] Print a converted egm to pgm file" << endl;
	cout << "	[2] Print a segmented image without derivatives" << endl;
	cout << "	[3] Print a horizontal derivative" << endl;
	cout << "	[4] Print a vertical derivative" << endl;
	cout << "	[5] Print a complete contour image" << endl;
	cout << "	[6] Print an illuminated image" << endl;
	cout << "	[7] Print all of the above" << "\n" << endl;

	// Prompts user for their choice
	cout << "What would you like to do? ";
	cin >> userChoice;

	// If the user did not choose to only print the illuminated image
	if (userChoice != 6) {

		// Formatting
		cout << endl;

	}

}

// Prompts the user for the file name of the file that they wish to open
string getFileName() {

	// Initialize varaibles
	string fileName;

	// Formatting
	//cout << endl;

	// Prompts user for their file name
	cout << "What is the name of your EGM file? ";
	cin >> fileName;

	// Appends .egm to the file
	fileName += ".egm";

	// Formatting
	cout << endl;

	// Runs until the user enters a file name that exists
	while (!checkFileExistence(fileName)) {

		// Prompts the user for a new file name
		cout << "That file does not exist, please re-enter your file name: ";
		cin >> fileName;

		// Appends .egm to the file
		fileName += ".egm";

		// Formatting
		cout << endl;

	}

	// Returns the full file name
	return fileName;
}

// Prompts the user for the file name of the new pgm file
string setFileName(string fileNameRoot, string fileNameDesc, bool multi) {

	// Initialize variables
	string fileName;

	// If the user is printing multiple files
	if (multi) {

		// Creates the file with the specified root and description
		fileName = fileNameRoot + fileNameDesc + ".pgm";

	}

	// If the user is not printing multiple files
	else {

		// Prompts the user for a file name
		cout << "\n" << "What do you want to name your file? (No extension) ";
		cin >> fileName;

		// Appends .pgm to the file
		fileName += ".pgm";
	}

	// Returns the full filename
	return fileName;
}

// Checks if the file exists
bool checkFileExistence(string fileName) {

	// Initialize variables
	bool existence;

	// Opens the file
	ifstream file(fileName);

	// If the file is readable
	if (file) {

		// Closes the file
		file.close();

		// Returns true
		return true;

	}

	// If the file is not readable
	else {
	
		// Closes the file
		file.close();

		// Returns false
		return false;

	}

}

// Prompts the user for their preferred level of contour for the new image
int setContourLevel() {

	// Initialize variables
	int segments;

	// Prompts user for a number of segments
	cout << "How many segments do you want to divide the image into? ";
	cin >> segments;

	// Returns the number of segments
	return segments;
}

// Sets a pixel scale based on the chosen file
void setPixelScale(string fileName, int& pixelScaleX, int& pixelScaleY) {

	// If the file was mount dartmouth or washington
	if (fileName == "mt_dartmouth.egm" || fileName == "mt_washington.egm") {

		pixelScaleX = 30;
		pixelScaleY = 30;

	}

	// If the file was milankovic
	else if (fileName == "milankovic.egm") {

		pixelScaleX = 300;
		pixelScaleY = 600;

	}

	// If the file was volcano
	else if (fileName == "volcano.egm") {

		pixelScaleX = 10;
		pixelScaleY = 10;

	}

	// If the file was not recognized
	else {

		pixelScaleX = 10;
		pixelScaleY = 10;

	}



}

// Prompts the user for their preferred sun angle for the illuminated image
double setSunAngle() {

	// Initialize variables
	double angle;

	// Formatting
	cout << endl;

	// Prompts user for a sun angle
	cout << "What angle do you want the sun to illuminate the surface at? ";
	cin >> angle;

	// Returns the sun angle
	return angle;

}

// Prompts the user for their preferred sun elevation for the illuminated image
double setSunElevation() {

	// Initialize variables
	double elevation;

	// Formatting
	cout << endl;

	// Prompts user for a sun angle
	cout << "What elevation do you want the sun to illuminate the surface from? ";
	cin >> elevation;

	// Returns the sun angle
	return elevation;

}

// Converts degrees to radians
double convertDegreesToRadians(double degrees) {

	// Initialize variables
	double radians;

	// Calculates the radians using the formula: degrees * (PI / 180)
	radians = degrees * (PI / 180);

	// Returns the result
	return radians;

}

// Converts spherical coordinates to cartesian coordinates
void convertSphericalToCartesian(double azimuth, double elevation, double& xCoord, double& yCoord, double& zCoord) {

	// Converts the degree values of azimuth and elevation to radians
	azimuth = convertDegreesToRadians(azimuth);
	elevation = convertDegreesToRadians(elevation);

	// Calculates the x, y, and z coordinates
	xCoord = cos(azimuth) * cos(elevation);
	yCoord = sin(azimuth) * cos(elevation);
	zCoord = sin(elevation);

}

// Calculates the magnitude of a vector
double getMagnitude(double x, double y, double z) {

	// Initialize variables
	double magnitude;

	// Calculates the magnitude using the formula: sqrt(x^2 + y^2 + z^2)
	magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

	return magnitude;

}

// Calculates the dot product of two vectors
double getDotProduct(double a1, double a2, double a3, double b1, double b2, double b3) {

	// Initialize variables
	double result;

	// Calculates the dot product
	result = a1*b1 + a2*b2 + a3*b3;

	// Returns the result
	return result;

}

// Calculates the cross product of two vectors
void getCrossProduct(double a1, double a2, double a3, double b1, double b2, double b3, double& c1, double& c2, double& c3) {

	// Calculates the cross product using the formula
	c1 = a2*b3 - b2*a3;
	c2 = a3*b1 - b3*a1;
	c3 = a1*b2 - b1*a2;

}

// Calculates a normal vector given the magnitude
void getNormalVector(double& x, double& y, double& z, double magnitude, double& xN, double& yN, double& zN) {

	// Calculates the normal vector by dividing the initial vector by it's magnitude
	xN = x / magnitude;
	yN = y / magnitude;
	zN = z / magnitude;

}

// Illuminates the egm file
double ** illuminate(double ** fileArray, int rows, int columns, int pixelScaleX, int pixelScaleY) {

	// Initializing my insane amount of variables
	double a1, a2, a3, aN1, aN2, aN3, aMag, b1, b2, b3, bMag, bN1, bN2, bN3, c1, c2, c3, azimuth, elevation, xCoord, yCoord, zCoord, illuminosity, illuminosityWSB;

	// Prompts user for their preferred sun angle
	azimuth = setSunAngle();

	// Prompts user for their preferred sun elevation
	elevation = setSunElevation();

	// Converts the sun angle and elevation to spherical coordinates
	convertSphericalToCartesian(azimuth, elevation, xCoord, yCoord, zCoord);

	// Calculates the x and y of both vectors
	a1 = 1 * pixelScaleX;
	b2 = 1 * pixelScaleY;
	a2 = 0;
	b1 = 0;

	// Loops through array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			// Checks if the current location is an edge
			if (i == rows - 1 || j == columns - 1) {

				// Sets static values for edge cases
				a3 = 1;
				b3 = 1;

			}

			// If the current location is not an edge
			else {

				// Calculates the unscaled z vectors
				a3 = fileArray[i][j + 1] - fileArray[i][j];
				b3 = fileArray[i + 1][j] - fileArray[i][j];

			}

			// Gets both vector's magnitudes
			aMag = getMagnitude(a1, a2, a3);
			bMag = getMagnitude(b1, b2, b3);

			// Gets both normal vectors
			getNormalVector(a1, a2, a3, aMag, aN1, aN2, aN3);
			getNormalVector(b1, b2, b3, bMag, bN1, bN2, bN3);

			// Gets the cross product of the two vectiors
			getCrossProduct(aN1, aN2, aN3, bN1, bN2, bN3, c1, c2, c3);

			// Calculates the illuminosity without sky brightness
			illuminosity = getDotProduct(c1, c2, c3, xCoord, yCoord, zCoord);
			
			// Calculates the illuminosity with sky brightness
			illuminosityWSB = (1 - SKYBRIGHTNESS) * illuminosity + SKYBRIGHTNESS;

			// Sets the current location to the current value multiplied by the illuminosity
			fileArray[i][j] = fileArray[i][j] * illuminosityWSB;

			// If the current value is negative
			if (fileArray[i][j] < 0) {

				// Sets the value to zero
				fileArray[i][j] = 0;

			}

		}
	}

	// Returns the array
	return fileArray;

}

// Converts the egm value from the original file to a new value based on the max value of the pgm
int convertEgmToPgmValue(double egmValue, double egmMax, int pgmMax) {

	// Initialize variables
	int pgmValue;

	// Calculates the new pgm value based on a proportion
	pgmValue = (pgmMax * egmValue) / egmMax;

	// Returns the calculated value
	return pgmValue;
}

// Reads in the original file into a 2D array 
double ** getInitialFileArray(string fileName, int rows, int columns, int commentNumber, bool isNegative) {

	// Intializes variables
	double fileValue;
	string line;

	// Initializes the 2D array
	double ** fileArray = new double *[rows];
	for (int i = 0; i < rows; ++i) {
		fileArray[i] = new double[columns];
	}

	// Opens the file
	ifstream file(fileName);

	// Skips the appropriate number of lines to get to the first value
	for (int i = 0; i < commentNumber + 2; i++) {
		getline(file, line);
	}

	// Takes in the first array value to prime the loop
	file >> fileValue;

	// Runs until the file runs out of values
	while (file) {

		// Array loop
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {

				if (isNegative) {
					fileValue = -1 * fileValue;
				}

				// Sets the current array location to the value that was read in
				fileArray[i][j] = fileValue;

				// Reads in the next value
				file >> fileValue;
			}
		}
	}

	// Closes the file
	file.close();

	// Returns the array
	return fileArray;
}

// Gets the header properties of the original file
void getInitialEgmFileProperties(string fileName, string& identifier, int& rows, int& columns, int& commentNumber, double& minElevation, double& maxElevation, bool& isNegative, int& pixelScaleX, int& pixelScaleY) {

	// Initializes variables
	string sColumns, sRows, sIdentifier, sCommentNumber, sMinElevation, sMaxElevation, line;
	double tMax, tMin;

	// Opens the file
	ifstream file(fileName);

	// Reads the first line into memory
	getline(file, line);

	// Creates the getProperty function to be able to read in the values
	istringstream getProperty(line);

	// Reads in the first 5 values as strings
	getProperty >> identifier;
	getProperty >> sColumns;
	getProperty >> sRows;
	getProperty >> sMinElevation;
	getProperty >> sMaxElevation;

	// Reads the second line into memory
	getline(file, line);

	// Creates the getProperty2 function to be able to read in the comment value
	istringstream getProperty2(line);

	// Reads the comment number value as a string
	getProperty2 >> sCommentNumber;

	// Converts the string values to their respective data types
	istringstream(sRows) >> rows;
	istringstream(sColumns) >> columns;
	istringstream(sCommentNumber) >> commentNumber;
	istringstream(sMinElevation) >> tMin;
	istringstream(sMaxElevation) >> tMax;

	// If the max or min elevation is less than zero
	if (tMin < 0 || tMax < 0) {

		// Sets a bool value to true indicating that there are negative values in the file
		isNegative = true;

		// Swaps the max and min
		maxElevation = -tMin;
		minElevation = -tMax;

	}

	// If the max or min elevation is less than zero
	else {

		// Leaves the values as they are
		maxElevation = tMax;
		minElevation = tMin;
	}

	setPixelScale(fileName, pixelScaleX, pixelScaleY);

	// Closes the file
	file.close();

}

// Writes the final array to a new file 
void writePgmArrayToFile(double ** fileArray, int rows, int columns, string fileNameRoot, string fileNameDesc, bool multi) {

	// Initialize variables
	string fileName;

	// Prompts the user for a file name
	fileName = setFileName(fileNameRoot, fileNameDesc, multi);

	// Opens the file
	ofstream pgmFile(fileName.c_str());

	// Prints the header of the pgm file
	pgmFile << "P2 " << columns << " " << rows << " 255" << endl;

	// Array loop
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			// Prints the current array value to the file
			pgmFile << fileArray[i][j] << " ";
		}

		// Ends the line when the number of columns printed has been met
		pgmFile << endl;
	}

	// Closes the file
	pgmFile.close();

}

// Converts the egm array to a pgm array
double ** convertEgmToPgmArray(double ** fileArray, int rows, int columns, double egmMax) {

	// Initializes variables
	int pgmValue;
	double currentEgmValue;

	// Array loop
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			// Gets the original egm value from the current array location
			currentEgmValue = fileArray[i][j];

			// Calculates the new pgm value by calling the converter function
			pgmValue = convertEgmToPgmValue(currentEgmValue, egmMax, 255);

			// Sets current array location equal to the calculated pgm value
			fileArray[i][j] = pgmValue;
		}
	}

	// Returns the array
	return fileArray;
}

// Converts the initial array to a contour array based on the user's chosen contour level
double ** convertEgmToContourArray(double ** fileArray, int rows, int columns, double egmMax, bool multi, int userContourLevel) {

	// Initializes variables
	double currentValue, stepAmount, contourPixelValue;
	int contourLevel;

	// If the user is printing multiple files
	if (multi) {

		// Sets the contour level equal to the value passed into the function
		contourLevel = userContourLevel;

	}
	else {

		// Prompts the user for their preferred contour level
		contourLevel = setContourLevel();

	}

	// Calculates the step amount based on the contour level and max value of the egm file
	stepAmount = egmMax / contourLevel;

	// Array loop
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			// Gets the original egm value from the current array location
			currentValue = fileArray[i][j];

			// Iterates through the contour levels
			for (int k = 1; k <= contourLevel; k++) {

				// Calculates the contour value of the current loop iteration
				contourPixelValue = (stepAmount * k + stepAmount * (k - 1)) / 2;

				// If the current array value is less than the product of the step amount and the current loop iteration
				if (currentValue <= stepAmount * k) {

					// Sets the current array location equal to the calculated contour value
					fileArray[i][j] = contourPixelValue;

					// Breaks from the loop
					break;
				}
			}
		}
	}

	// Returns the array
	return fileArray;

}

// Takes horizontal derivative
double ** takeHorizontalDerivative(double ** fileArray, int rows, int columns) {

	// Initialize variables
	double derivativeValue;

	// Array loop
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			// If on the last column, the value won't change because there is no value below it
			if (j == columns - 1) {
				derivativeValue = fileArray[i][j - 1];
			}

			// Takes the derivative using the current value and the one directly to the right of it
			else {
				derivativeValue = fileArray[i][j + 1] - fileArray[i][j];
			}

			// Sets the current array location to the new calculated value
			fileArray[i][j] = derivativeValue;
		}
	}

	// Returns the array
	return fileArray;
}

// Takes vertical derivative of the image
double ** takeVerticalDerivative(double ** fileArray, int rows, int columns) {

	// Initializes variables
	double derivativeValue;

	// Array loop
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			// If on the last row, the value won't change because there is no value below it
			if (i == rows - 1) {

				derivativeValue = fileArray[i - 1][j];

			}

			// Takes the derivative using the current value and the one directly below it
			else {

				derivativeValue = fileArray[i + 1][j] - fileArray[i][j];

			}

			// Sets the current array location to the new calculated value
			fileArray[i][j] = derivativeValue;
		}
	}

	// Returns the array
	return fileArray;
}

// Creates an image without contour lines
void createNoContourImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc) {

	// Initialize variables
	int pixelScaleX, pixelScaleY;

	// Initialize arrays
	double ** fileArray = new double *[rows];
	for (int i = 0; i < rows; ++i) {
		fileArray[i] = new double[columns];
	}

	// Sets the pixel scale based on the chosen file
	setPixelScale(fileName, pixelScaleX, pixelScaleY);

	// Runs the array functions
	fileArray = getInitialFileArray(fileName, rows, columns, commentNumber, isNegative);
	fileArray = convertEgmToPgmArray(fileArray, rows, columns, maxElevation);
	
	// Writes the array to a file
	writePgmArrayToFile(fileArray, rows, columns, root, desc, multi);

	// Deletes the array
	delete[] fileArray;

}

// Creates an image with contour lines
void createContourImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc, int contourLevel) {

	// Initialize arrays
	double ** fileArray = new double *[rows];
	for (int i = 0; i < rows; ++i) {
		fileArray[i] = new double[columns];
	}

	// Runs the array functions
	fileArray = getInitialFileArray(fileName, rows, columns, commentNumber, isNegative);
	fileArray = convertEgmToContourArray(fileArray, rows, columns, maxElevation, multi, contourLevel);
	fileArray = convertEgmToPgmArray(fileArray, rows, columns, maxElevation);

	// Prints the array to a file
	writePgmArrayToFile(fileArray, rows, columns, root, desc, multi);

	// Deletes the array
	delete[] fileArray;

}

// Creates a contour image and takes the vertical derivative of it
void createVerticalDerivativeImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc, int contourLevel) {

	// Initialize arrays
	double ** fileArray = new double *[rows];
	for (int i = 0; i < rows; ++i) {
		fileArray[i] = new double[columns];
	}

	// Runs the array functions
	fileArray = getInitialFileArray(fileName, rows, columns, commentNumber, isNegative);
	fileArray = convertEgmToContourArray(fileArray, rows, columns, maxElevation, multi, contourLevel);
	fileArray = convertEgmToPgmArray(fileArray, rows, columns, maxElevation);
	fileArray = takeVerticalDerivative(fileArray, rows, columns);

	// Prints the array to a file
	writePgmArrayToFile(fileArray, rows, columns, root, desc, multi);

	// Deletes the array
	delete[] fileArray;

}

// Creates a contour image and takes the horizontal derivative of it
void createHorizontalDerivativeImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc, int contourLevel) {

	// Initialize arrays
	double ** fileArray = new double *[rows];
	for (int i = 0; i < rows; ++i) {
		fileArray[i] = new double[columns];
	}

	// Runs the array functions
	fileArray = getInitialFileArray(fileName, rows, columns, commentNumber, isNegative);
	fileArray = convertEgmToContourArray(fileArray, rows, columns, maxElevation, multi, contourLevel);
	fileArray = convertEgmToPgmArray(fileArray, rows, columns, maxElevation);
	fileArray = takeHorizontalDerivative(fileArray, rows, columns);

	// Prints the array to a file
	writePgmArrayToFile(fileArray, rows, columns, root, desc, multi);

	// Deletes the array
	delete[] fileArray;

}

// Creates a contour image and combines the horizontal and vertical derivatives of it
void createThresholdImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc, int contourLevel) {

	// Initialize variables
	double magValue;

	// Initialize arrays
	double ** horizontalArray = new double *[rows];
	for (int i = 0; i < rows; ++i) {
		horizontalArray[i] = new double[columns];
	}

	double ** verticalArray = new double *[rows];
	for (int i = 0; i < rows; ++i) {
		verticalArray[i] = new double[columns];
	}

	double ** thresholdArray = new double *[rows];
	for (int i = 0; i < rows; ++i) {
		thresholdArray[i] = new double[columns];
	}

	// Runs horizontal derivative functions
	horizontalArray = getInitialFileArray(fileName, rows, columns, commentNumber, isNegative);
	horizontalArray = convertEgmToContourArray(horizontalArray, rows, columns, maxElevation, multi, contourLevel);
	horizontalArray = convertEgmToPgmArray(horizontalArray, rows, columns, maxElevation);
	horizontalArray = takeHorizontalDerivative(horizontalArray, rows, columns);

	// Runs vertical derivative functions
	verticalArray = getInitialFileArray(fileName, rows, columns, commentNumber, isNegative);
	verticalArray = convertEgmToContourArray(verticalArray, rows, columns, maxElevation, multi, contourLevel);
	verticalArray = convertEgmToPgmArray(verticalArray, rows, columns, maxElevation);
	verticalArray = takeVerticalDerivative(verticalArray, rows, columns);

	// Threshold array loop
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			// If the value in the horizontal derivative array is less than zero
			if (horizontalArray[i][j] < 0) {

				// Sets the value equal to a positive one
				horizontalArray[i][j] += 255;

			}

			// If the value in the vertical derivative array is less than zero
			if (verticalArray[i][j] < 0) {
				verticalArray[i][j] += 255;
			}

			// Calculates the threshold of the image
			magValue = sqrt(pow(horizontalArray[i][j], 2)) + sqrt(pow(verticalArray[i][j], 2));

			// Sets the calculated threshold value equal to the current array location
			thresholdArray[i][j] = magValue;

		}
	}

	// Threshold array loop
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			// If the current threshold array location is above zero
			if (thresholdArray[i][j] > 0) {

				// Sets all values above 0 to 255
				thresholdArray[i][j] = 255;

			}
		}
	}

	// Writes the array to a file
	writePgmArrayToFile(thresholdArray, rows, columns, root, desc, multi);

	// Deletes all of the arrays
	delete[] horizontalArray;
	delete[] verticalArray;
	delete[] thresholdArray;

}

// Creates the illuminated image
void createIlluminatedImage(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, string desc) {

	// Initialize variables
	int pixelScaleX, pixelScaleY;

	// Initialize arrays
	double ** fileArray = new double *[rows];
	for (int i = 0; i < rows; ++i) {
		fileArray[i] = new double[columns];
	}

	// Sets the pixel scale based on the chosen file
	setPixelScale(fileName, pixelScaleX, pixelScaleY);

	// Runs the array functions
	fileArray = getInitialFileArray(fileName, rows, columns, commentNumber, isNegative);
	fileArray = illuminate(fileArray, rows, columns, pixelScaleX, pixelScaleY);
	fileArray = convertEgmToPgmArray(fileArray, rows, columns, maxElevation);

	// Writes the array to a file
	writePgmArrayToFile(fileArray, rows, columns, root, desc, multi);

	// Deletes the array
	delete[] fileArray;

}

// Creates all the images
void createAllImages(string fileName, int rows, int columns, int commentNumber, double minElevation, double maxElevation, bool isNegative, bool multi, string root, int contourLevel) {

	// Runs all of the creation functions
	createNoContourImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, "_no_contour");
	createContourImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, "_contour", contourLevel);
	createHorizontalDerivativeImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, "_horizontal_derivative", contourLevel);
	createVerticalDerivativeImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, "_vertical_derivative", contourLevel);
	createThresholdImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, "_complete", contourLevel);
	createIlluminatedImage(fileName, rows, columns, commentNumber, minElevation, maxElevation, isNegative, multi, root, "_illuminated");

	// Success message
	cout << "\n" << "Your files have been created!" << "\n" << endl;

}