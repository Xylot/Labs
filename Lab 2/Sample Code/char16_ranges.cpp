/*
 * char16_ranges.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: ian scott-fleming
 *
 *      Program to show the range of values for a char on a computer
 *       
 *      Also shows how to use a do-while and a while loop and a for loop.
 *
 *      This version is for environments with 16-bit chars.
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
		// integer types:
	bool b;
	unsigned char uc;
	char c;

	if (sizeof(c) == 1)
	{
		cout << "Oops.  your computer has 8-bit chars."<<endl;
		cout << "Please use 'char_ranges.cpp' instead."<<endl;
		return 1;
	}
		// show all the values for bool:

	cout << endl << "\tbool Values: "<<endl;
	b = false;
	cout << "b = false:  "<<b<<endl;
	b = true;
	cout << "b = true:   "<<b<<endl;

		// show all the values for chars:
	cout << endl << "\tchar Values  (will increment c & uc 300 times: "<<endl;


			// note:  chars are 'intended' for character data, but are
			// really integer data types.  If I output a char, c++ treats it as
			// a character.  But I can cast it as an integer, and it will output
			// its numerical value.  (You don't need to stat_cast the other
			// integer types to get them to output as values).

			// output uc as character data and as integer data
			// Here, I output uc first as a char, and then as an integer
			// Notice how the same bit pattern can represent either text or numbers.
	uc = 'A';
	c = 'a';
	cout << "Chars and their values  (aka the ASCII code)."<<endl;
	do		// here I'll use a do-while loop.
	{
		cout << uc << setw(3)<< static_cast<int>(uc) << "\t" << c << setw(3) << static_cast<int>(c) << endl;
		uc += 1;
		c += 1;
	} while (uc <= 'Z');

				// OK. Now let's output all possible values of an unsigned char.
				// We'll output a little more than 256, so we can see what happens when
				// the value overflows.  I use a while loop here just to make sure you have
                // an example of a while loop, as well as a do-while loop.
    
                // the setw(n) function , made available by #include <iomanip> , sets the field width
                // of the output, so you can make nice fixed-width columns.
    
	uc = 0;
	int n=1;    // my counter variable
	cout << endl << "unsigned char: all possible values" << endl;
	while (n <= 256*300)					// loop using a while loop
	{
		cout << setw(6) << static_cast<unsigned int>(uc) << " ";
		if (n % 16 == 0)				// output a newline every 16
			cout << endl;
		uc = uc+64;						// 2 different ways to add 64.
		n += 64;                        // I add 64, so you don't have to watch 76800 numbers go by...
	}

                // And now do the same for signed char.
	c = 0;
	cout << endl << "signed char: " << endl;
	for (int m=1; m<=256*300; m+=64)			// now, loop with a for loop.
	{
		cout << setw(6) << static_cast<int>(c) << " ";
		if (m % 16 == 0)				// output a newline every 16
			cout << endl;
		c += 64;;						// does it matter if I use ++c or c++ here?  why not?
	}

	cout << "\ndone!" << endl;

	return 0;
}




