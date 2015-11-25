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
#include <iomanip>
#include <cmath>
using namespace std;


void print_array(int *  p, int npts);
void create_array(int * &p, int size, int initval);


int main()
{
	// Initialize variables
	int *x = NULL;
	x = NULL;

	// Set x to size 5
	x = new int[5];

	// Allocates x to intervals of 5
	for (int i = 0; i < 5; i++) {
		x[i] = 5 * (i + 1);
	}

	// Outputs x
	cout << "X: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << x[i] << " ";
	}
	cout << endl;

	// Prints the array using a function
	print_array(x, 5);

	// Deletes x array
	delete[] x;
	x = NULL;

	// Initializes y array
	int *y = NULL;
	y = NULL;
	y = new int[10];

	// Calls function to create the array and prints it
	create_array(y, 10, 0);
	cout << "0 Array:" << endl;
	print_array(y, 10);

	// Delete y array
	delete[] y;
	y = NULL;

	// Initializes z array
	int *z = NULL;
	z = NULL;
	z = new int[20];

	// Calls function to create the array and prints it
	create_array(z, 20, 999);
	cout << "999 Array:" << endl;
	print_array(z, 20);
	
	// Delete z array
	delete[] z;
	z = NULL;

}

void print_array(int *p, int npts)
{
	// Prints the array
	for (int i = 0; i < npts; i++) {
		cout << *p++ << ' ';
	}

	cout << endl;
}

void create_array(int * &p, int size, int initval) {

	// Intializes the array
	p = new int[size];

	// Sets each element to initval
	for (int i = 0; i < size; i++) {
		p[i] = initval;
	}

	cout << endl;
}