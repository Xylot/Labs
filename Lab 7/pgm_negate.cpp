/*

Joseph Meriam
ECE 1305 Lab 7
11 / 15 / 15

Other group members:
	Syed Ahmed
	Trevor Calvert
	aAdolfo Carrillo
	Bin Lee

*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Prototypes
string get_filename();
void readPGM(string fname, int &nc, int &nr, int &mv, int * &pix);
void negatePGM(int nc, int nr, int mv, int *pix);
void writePGM(string fname, int nc, int nr, int mv, int *pix);

int main()
{
	// Initialize variables
	int ncols = 0, nrows = 0, maxval = 255;
	int *pix = NULL;

	// Gets the file name from the user
	string filename = get_filename();

	// Calls the functions
	readPGM(filename, ncols, nrows, maxval, pix);
	negatePGM(ncols, nrows, maxval, pix);
	writePGM("neg_" + filename, ncols, nrows, maxval, pix);

	// Deletes the array
	delete[] pix;

}


string get_filename()
{
	bool ok = false;
	string fn = "";
	do
	{
		if (fn.size() == 0) cout << "filename? ";
		else cout << "can't open " << fn << ". re-enter filename: ";
		cin >> fn;
		ifstream ifs(fn);
		if (ifs) ok = true;
	} while (!ok);
	return fn;
}


void readPGM(string fname, int &nc, int &nr, int &mv, int * &pix)
{
	// Initialize variables
	string sColumns, sRows, sIdentifier, sMaxValue, line;
	int fileValue;

	// Opens the file
	ifstream file(fname);

	// Loads first line
	getline(file, line);
	
	// Gets identifiers
	istringstream getProperty(line);
	getProperty >> sIdentifier;
	getProperty >> sColumns;
	getProperty >> sRows;
	getProperty >> sMaxValue;

	// Converts the values to ints
	nr = stoi(sRows);
	nc = stoi(sColumns);
	mv = stod(sMaxValue);

	// Allocates the array to the specified size
	pix = new int[nr * nc];

	// Gets primer value from file
	file >> fileValue;

	for (int i = 0; i < nr * nc; i++) {

		// Sets current index of the array to the current value
		pix[i] = fileValue;

		// Gets new value
		file >> fileValue;
	}

	// Closes the file
	file.close();
}


void writePGM(string fname, int nc, int nr, int mv, int *pix)
{
	// Initialize variables
	ofstream pgmFile;
	string fileName;

	// Opens the file
	pgmFile.open(fname.c_str());

	// Writes header to file
	pgmFile << "P2 " << nc << " " << nr << " " << mv << endl;
	
	//Sets index to zero
	int index = 0;

	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			// Writes the current element of pix to the file
			pgmFile << pix[index] << " ";

			// Increments index
			index++;
		}

		pgmFile << endl;
	}

	// Closes the file
	pgmFile.close();

}


void negatePGM(int nc, int nr, int maxval, int *pix)
{
	for (int r = 0; r < nr; r++) {
		for (int c = 0; c < nc; c++)
		{
			pix[r*nc + c] = maxval - pix[r*nc + c];
		}
	}
}