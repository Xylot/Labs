#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	// Initialize variables
	double pi, signedI, y, z, w;
	
	// Calculates the value for PI
	pi = acos(-1);
	
	// Opens/creates the file
	ofstream file("sines.txt");
	
	// Prints the header to the file
	file << " Steps(x) = 0.1 | y = cos(x) | z = sin(x) | w = .37cos(x) + .92sin(x)" << "\n" << endl;   
	
	// Iterates i 0.1 from -pi to pi
	for(double i = pi; i < 2 * pi;i += 0.1) {
	
		// Calculates the signed value of I
		signedI = -pi + i;
		
		// Calculates the cos of signed I
		y = cos(signedI);
		
		// Calculates the sin of signed I 
		z = sin(signedI);
		
		// Calculates .37cos of signed I + .92sin of signed I
		w = .37 * cos(signedI) + .92 * sin(signedI);
		
		// Prints the results to the file
		file << endl;
		file << "X: " << signedI << endl;
		file << "Y = " << y << endl;
		file << "Z = " << z << endl;
		file << "W = " << w << endl;
		file << "______________" << endl;
	
	}

	// Lets the user know that the file has been created
	cout << "Your file has been successfully created" << endl;
	
}