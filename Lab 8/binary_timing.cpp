/* 

Joseph Meriam
ECE 1305 Lab 8
12/2/15
Reads and writes to a file in both ascii and binary

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Calculates the size of the dat array
const int SIZE = 64 * 1048576;

// Prototypes
void randomizeDat(char dat[], int size);
void write_ascii_data(const char dat[], int size);
void write_binary_data(const char dat[], int size);
void read_ascii_data(char dat[], int size);
void read_binary_data(char dat[], int size);


int main()
{

	// Intializes char array of the size calculated by the global SIZE variable
	char *dat = new char[SIZE];

	// If the dat array was not allocated into memory
	if (!dat) { 

		// Lets the user know that the dat array could not be allocated into memory
		cerr << "cannot alloc dat array" << endl; 

		// Ends the program
		return 1; 

	}

	// Calls the function to fill the dat array with random numbers
	randomizeDat(dat, SIZE);

	// Lets the user know that the program is writing to the file in ascii
	cout << "writing 64 MB of 8-bit integer data in ascii" << endl;

	// Writes to the file in ascii
	write_ascii_data(dat, SIZE);

	// Lets the user know that the program is reading from the file in ascii
	cout << "reading 64 MB of 8-bit integer data in ascii" << endl;

	// Reads from the file in ascii
	read_ascii_data(dat, SIZE);

	// Lets the user know that the program is writing to the file in binary
	cout << "writing 64 MB of 8-bit integer data in binary"<<endl;
	
	// Writes to the file in binary
	write_binary_data(dat, SIZE);
	
	// Lets the user know that the program is reading from the file in binary
	cout << "reading 64 MB of 8-bit integer data in binary"<<endl;
	
	// Reads from the file in binary
	read_binary_data(dat, SIZE);
	
}

// Fills the dat array with random numbers between -127 and 128
void randomizeDat(char dat[], int size)
{

	// Loops through the array
	for (int i = 0; i < size; i++) {

		// Gets a random number between 0 and 256 then subtracts 128 from it to achieve our desired range and finally puts it into the dat array
		dat[i] = rand() % 256 - 128;

	}

}

// Writes to the file in ascii
void write_ascii_data(const char *dat, int size)
{
	// Opens the file
	ofstream os("ascii.txt");

	// Loops through the array
	for (int i = 0; i < size; i++)	{

		// Prints the current value to the file
		os << setw(4) << static_cast<int>(dat[i]);

		// If 16 values have been written on the current line
		if (i % 16 == 15) {

			// Ends the line
			os << endl;

		}

		// If 16 values have not been written on the current line
		else {

			// Prints a space
			os << ' ';

		}

		// If a megabyte of data has been written
		if (i % (1024 * 1024) == 0) {

			// Prints out the progress
			cout << "\r" << i / 1024 / 1024 << " MB text written"; cout.flush();
		}
	}

	// Lets the user know that the program is done writing the data to the file
	cout << "The ascii data has successfully been written to the file" << endl;
}

// Reads data from the file in ascii
void read_ascii_data(char *dat, int size)
{
	// Opens the file
	ifstream ifs("ascii.txt");

	// Loops through the array
	for (int i = 0; i < size; i++)	{
		// Initialize val variable to hold the current file data
		int val;

		// Reads the value from the file into val
		ifs >> val;

		// Converts the value that was read in into a char and stores it in the dat array
		dat[i] = static_cast<char>(val);

		// If a megabyte of data has been written
		if (i % (1024 * 1024) == 0) {

			// Prints out the progress
			cout << "\r" << i / 1024 / 1024 << " MB text read in"; cout.flush(); 

		} 
	}

	// Lets the user know that they program is done reading from the file
	cout << "The ascii data has successfully been read into memory from the file" << endl;
}

// Writes data to a file in binary
void write_binary_data(const char *dat, int size)
{

	// Opens the file
	ofstream os("binary.dat", ios::binary);

	// Outputs the dat values
	for (int i = 0; i < size; i++)	{

		// Prints the current value to the file
		os << setw(4) << static_cast<int>(dat[i]);

		// If 16 values have been written on the current line
		if (i % 16 == 15) {

			// Ends the line
			os << endl;

		}

		// If 16 values have not been written on the current line
		else {

			// Prints a space
			os << ' ';

		}

		// If a megabyte of data has been written
		if (i % (1024 * 1024) == 0) {

			// Prints out the progress
			cout << "\r" << i / 1024 / 1024 << " MB text written"; cout.flush();
		}
	}

	// Lets the user know that the data is done writing
	cout << "The binary data has successfully been written to the file" << endl;
}

// Reads data from a file in binary
void read_binary_data(char *dat, int size)
{

	// Opens the binary.dat file
	ifstream is("binary.dat", ios::binary);

	// Loops through the array
	for (int i = 0; i < size; i++)	{
		// Initialize val variable to hold the current file data
		int val;

		// Reads the value from the file into val
		is >> val;

		// Converts the value that was read in into a char and stores it in the dat array
		dat[i] = static_cast<char>(val);

		// If a megabyte of data has been written
		if (i % (1024 * 1024) == 0) {

			// Prints out the progress
			cout << "\r" << i / 1024 / 1024 << " MB text read in"; cout.flush();

		}
	}

	// Lets the user know that they program is done reading from the file
	cout << "The binary data has successfully been read into memory from the file";
}

