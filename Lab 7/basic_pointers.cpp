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
using namespace std;

int main()
{

	// Initialize variables
	int i = 5, j = 51, k = 62;
	int data[5] = { 10, 20, 30, 40, 50 };
	char my_cstring[8] = "the fox";

	// Assings p to the address of i
	int * p = &i;
	cout << "The address of i is: " << &p << endl;

	// Points p to j
	*p = j;
	cout << "The value of p while pointing to j : " << *p << endl;

	// Points p to k
	*p = k;
	cout << "The value of p while pointing to k : " << *p << endl;

	// Points p to the first element of the array data
	*p = data[0];
	cout << "The value of p while pointing to the first element of the data array: " << *p << endl;

	// Points p to the third element of the array data
	*p = data[2];
	cout << "The value of p while pointing to the third element of the data array: " << *p << endl;

	// Resets p to the first elment of the array data
	p = data;

	// Changes the first value of the data array
	p[0] = 1;

	// Changes the second value of the data array
	p[2] = 2;
	
	// Prints the changed values
	cout << data[0] << " " << data[2] << endl;

	// Creates character pointer pc
	char *pc;

	// Points pc to my_cstring
	pc = my_cstring;

	// Changes the first element of the my_cstring array to uppercase
	pc[0] = toupper(my_cstring[0]);

	// Changes the fifth element of the my_cstring array to uppercase
	pc[4] = toupper(my_cstring[4]);

	// Prints the changed values
	cout << my_cstring[0] << " " << my_cstring[4] << endl;

	// Prints the integer values of the array elements
	for (int i = 0; i < 8; i++) {
		cout << static_cast<int>(pc[i]) << endl;
	}
}
