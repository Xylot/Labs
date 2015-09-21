/* 
    Sample program to output the ascii table using a loop.
*/


#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

int main(void)
{

	cout << "The ASCII table" <<endl;
    cout << "int ch\tint ch\tint ch\tint ch\tint ch\tint ch\tint ch\tint ch"<<endl;
    cout << "___ _ \t___ _ \t___ _ \t___ _ \t___ _ \t___ _ \t___ _ \t___ _ "<<endl<<endl;
    for (int i=0;i<128; i++)
    {
        // if char is printable, print numeric code and the char.
        // otherwise, just print the numeric code.
        // isprint( ) returns true if the value is a printable ascii character.
        // It is found in the header file <cctype>
        unsigned char c = i;
        if (isprint(i))
            cout << setw(3)<<i<<" "<< c <<"\t";     // output the ascii code & c if printable
        else
            cout << setw(3)<<i<<"  \t";             // just output the code if c is not printable
        
        // and a newline every 8 columns
        if (i % 8 == 7)    // why do I use 7 here?
            // what would happen if I used == 8?
            // what would happen if I used == 0?
            // what would happen if I used == 3?
            cout << endl;
    }
    cout << endl;

            // let's do it again, but print every possible code.
            // depending on the encoding being used by VS, many of the values above 128 will print.
    
    cout << "All unsigned char values" <<endl;
    cout << "note:  some of these, like 10 (newline) and 13 (return) will make the columns come out funny"<<endl;
    cout << "others may produce other unexpected results, such as 7, which may make your computer beep"<<endl;
    cout << "int ch\tint ch\tint ch\tint ch\tint ch\tint ch\tint ch\tint ch"<<endl<<endl;
    cout << "___ _ \t___ _ \t___ _ \t___ _ \t___ _ \t___ _ \t___ _ \t___ _ "<<endl<<endl;
    for (int i=0;i<256; i++)
    {
        // Here I cast the loop counter, i, as an unsigned char to print it,
        // rather than copy it into an unsigned char as I did above.
        // look up static_cast<...>(...) in your textbook.

        cout << setw(3)<<i<<" "<< static_cast<unsigned char>(i) <<"\t";
        
        // and a newline every 8 columns
        if (i % 8 == 7)
            cout << endl;
    }
    cout << endl;
    
    
	return 0;
}