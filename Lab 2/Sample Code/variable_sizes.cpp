/*
 * variable_sizes.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: ian scott-fleming
 *
 *      Program to report the size of different C++ variable types on a computer
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
		// integer types:
	bool b;
	unsigned char uc;
	char c;
	unsigned short ush;
	short sh;
	unsigned int ui;
	int i;
	unsigned long ul;
	long l;
    long long ll;

		// floating point types
	float f;
	double d;
	long double ld;

			// C++ gives us a function sizeof(  ) which reports the size,
			// in bytes, of a variable (or a data type).

	cout << "C++ Data Type Sizes on your system (all sizes in bytes)"<<endl;
	cout << "\tInteger data types:"<<endl;
	cout << "bool:            "<<sizeof(b)  <<endl;
	cout << "unsigned char:   "<<sizeof(uc) <<endl;
	cout << "char:            "<<sizeof(c)  <<endl;
	cout << "unsigned short:  "<<sizeof(ush)<<endl;
	cout << "short:           "<<sizeof(sh) <<endl;
	cout << "unsigned int:    "<<sizeof(ui) <<endl;
	cout << "int:             "<<sizeof(i)  <<endl;
	cout << "unsigned long:   "<<sizeof(ul) <<endl;
	cout << "long:            "<<sizeof(l)  <<endl;
    cout << "long long:       "<<sizeof(ll) <<endl;

	cout << endl << "\tFloating point types:"<<endl;
	cout << "float:           "<<sizeof(f)  <<endl;
	cout << "double:          "<<sizeof(d)  <<endl;
	cout << "long double:     "<<sizeof(ld) <<endl;


		// show all the values for bool:

	cout << endl << "\tbool Values: "<<endl;
	b = false;
	cout << "b = false:  "<<b<<endl;
	b = true;
	cout << "b = true:   "<<b<<endl;

	cout << "\ndone!" << endl;

	return 0;
}





