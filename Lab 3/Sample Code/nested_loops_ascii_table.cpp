/*
 * nested_loops.cpp
 *
 *  Created on: Feb 12, 2013
 *      Author: iscottfl
 */


#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int main(void)
{
	int r, c;
	
	cout << "this program outputs the ASCII code for the standard 128 ASCII chars"<<endl;
	cout << "It uses nested loops to print out the table, though you could easily"<<endl;
	cout << "do it with a single loop and the modulus operator"<<endl;
	cout << "It uses the library function isprint( ), which tells whether"<<endl;
	cout << "the particular ascii code is a printable char or not"<<endl;
	cout << "It also shows how to use setw( ) to set the width of an output field"<<endl;
	cout << "so you get nice columns."<<endl<<endl;
	
	// output some column headers
	for (c=0;c<8;c++)
		cout <<"c val\t";
	cout << endl;
	
	// output the ASCII table
	for (r=0;r<128; r=r+8)	// 16 rows  
							// I'm incrementing by 8 because there will be 8 columns.
							// r is the value of the code to be output in the first column.
	{
		for (c=0;c<8;c++)	// and 8 columns
		{					// output each number, and print the char if it is a printable character
			int code=r+c;				// ASCII code
			unsigned char ch=static_cast<unsigned char>(code);		// and as a char
			if (isprint(ch))
				cout << ch  << " " << setw(3) << code<<"\t";		// char is printable.  
			else
				cout << " " << " " << setw(3) << code<<"\t";		// not printable.  print a space instead.
			
		}
		cout << endl;		// output a newline at the end of each row
	}
}



