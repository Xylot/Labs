/*
 * floating_pt_precision.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: ian scott-fleming
 *
 *      Value for PI below is from http://3.141592653589793238462643383279502884197169399375105820974944592.com/
 *
 *		Starting program for demonstrating the precision of floating point data types.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
	float f = 1.234;
    double d = 1.2345; 
	long double ld = 1.23456;

//	cout << "\n\there is PI to many decimal places:  "<<endl;
//	cout << "PI:              3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"<<endl;
    cout << "f set to 1.234, d to 1.2345, and ld to 1.23456"<<endl;
	cout << "float:           "<<setprecision(10)  << f  << endl;
	cout << "double:          "<<setprecision(20)  << d  << endl;
	cout << "long double:     "<<setprecision(30)  << ld << endl;

	cout << "\n\n\tHere's an interesting way to get PI to double-precision:" << endl;
	cout << "PI:              3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"<<endl;
	cout <<"arc-cosine(-1):  "<<setprecision(20)  << acos(-1.0) << endl;

	return 0;
}



