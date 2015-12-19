/*

Joseph Meriam
ECE 1305 Lab 8
12/2/15
Demonstrates the use of binary input and output

*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(void)
{

	// Initializes arrays
    int a[11] = {543516756,  1667855729, 1919033451,   544110447,  544763750, 1886221674, 1986994291, 1948283493, 1814062440,  544832097,  778530660 };
    int b[11] = {0};
    char buf[100] = {0};

	// Opens the file
	ofstream os("binary.dat", ios::binary);

    // Writes out the data in array a to the file in binary format
    os.write(reinterpret_cast<char*>(a), 11 * sizeof(int));

	// Closes the file
    os.close();

    // Opens the binary.dat file
    ifstream is("binary.dat", ios::binary);

	// Reads the data into array b
    is.read(reinterpret_cast<char*>(b), 11 * sizeof(int));

	// Closes the file
    is.close();

    // Prints the table header
    cout << " i     a[i]       b[i]" << endl;

	// Table formatting
	cout << "___________________________" << endl;

	// Outputs the arrays to the console
	for (int i = 0; i < 11; i++) {

		// Prints the index
		cout << setw(2) << i << "  ";

		// Prints array a
		cout << setw(10) << a[i] << " ";

		// Prints array b
		cout << setw(10) << b[i] << endl;
	}

	// Re-opens the file
    is.open("binary.dat", ios::binary);

	// Reads the data into a char array
    is.read(buf, 11 * sizeof(int));

	// Formatting
	cout << endl;

	// Prints the table header
    cout << " i  " << "  buf[i]  " << "\t" << "int" <<"\t" << "hex"<< endl;

	// Table formatting
	cout << "___________________________" << endl;

	// Outputs the array values to the console as characters, integers, and hexadecimals
	for (int i = 0; i < 11 * sizeof(int) + 1; i++) {

		// If the current character in the array is printable
		if (isprint(buf[i])) {

			// Prints the index value
			cout << setw(2) << i << "\t";
			
			// Prints the character
			cout << buf[i] << "\t";
			
			// Converts the character to an int and prints it out
			cout << static_cast<int>(buf[i]) << "\t";

			// Sets the basefield to hexadecimal
			cout << hex;

			// Converts the character to an int which will now be displayed as a hex value
			cout << static_cast<int>(buf[i]);

			// Resets the basefield back to decimal
			cout << dec;
			
			// Ends the line
			cout << endl;
		}

		// If the current character in the array is not printable
		else {

			// Prints the index value
			cout << setw(2) << i << "\t";

			// Prints nothing since the character is not printable
			cout << " " << "\t";

			// Converts the character to an int and prints it out
			cout << static_cast<int>(buf[i]) << "\t";

			// Sets the basefield to hex
			cout << hex;

			// Converts the character to an int which will now be displayed as a hex value
			cout << static_cast<int>(buf[i]);

			// Resets the basefield back to int
			cout << dec;

			// Ends the line
			cout << endl;

		}
	}
}
