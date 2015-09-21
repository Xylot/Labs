/*
 * binary_value.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: ian scott-fleming
 *
 *      program to output the binary value for a number
 */

#include <iostream>
using namespace std;

int main(void)
{

	int n,b;			// binary 0000 1101, 1*8 + 1*4 + 0*2 +1*1

	cout << "enter a positive integer: ";
	cin >> n;
	cout << n << ": ";

	b=1;
	while (b < n) b *=2;
	while (b > 0)
	{
		cout << ( (n%(2*b)) / b);
		b /=2;
	}
	cout << endl;

	return 0;

}




