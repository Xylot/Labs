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
	int i = 5;
	int data[5] = { 10, 20, 30, 40, 50 };
	char my_cstring[8] = "the fox";

	// Sets pointers to null
	int *p = NULL;
	char *pc = NULL;

	// Initialize p to the beginning of the data array
	p = &data[0];

	// Indexing the array data
	cout << "Indexing the array data: ";
	for (int j = 0; j < 5; j++) {
		cout << data[j] << ' ';
	}

	// Indexing the pointer
	cout << endl << "Indexing pointer:    ";
	for (int j = 0; j < 5; j++) {
		cout << p[j] << ' ';
	}

	// Initialize p to the beginning of the data array
	p = data;

	// Incrementing the pointer
	cout << endl << "Incrementing the pointer (*p)++: ";
	for (int i = 0; i < 5; i++) {
		cout << (*p)++ << ' ';
	}
	
	cout << endl;
	
	// Initialize p to the beginning of the data array
	p = data;

	// Output by adding i
	cout << "Output by adding i, *(p+i): ";
	for (int i = 0; i < 5; i++) {
		cout << *(p + i) << ' ';
	}

}
