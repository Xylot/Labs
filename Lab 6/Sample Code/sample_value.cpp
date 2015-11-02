#include <iostream>

using namespace std;
/* program to demonstrate function pass-by-value and value-returning function.

    this program asks the user for an integer number, reports the number of digits,
    and outputs each digit separately.
*/

// function prototypes.  Look like functions, but without bodies.

int num_digits(int val);            // returns the # of digits in val
int get_digit(int val, int dig);    // returns the dig'th digit of val

//..............................................................

int main(void)
{
    int number, ndigs;
     
    cout << "enter a number: ";
    cin >> number;
    
    ndigs = num_digits(number);
    
    for (int i=0;i<ndigs; i++) 
        cout << "digit "<<i<<" = " << get_digit(number, i)<<endl;
        
    return 0;
;}

//..............................................................

/* function to calculate # of digits in a number.
    inputs:  int    val     value to get # of digits of
    outputs:                (no reference parameters)
    returns: int            # of digits
*/
int num_digits(int val)
{
    int nd = 0;
    while (val != 0)
    {
        val /= 10;      // because val is passed by value, changing it here doesn't affect
        nd++;           // the original argument
    }
    return nd;
}

//..............................................................

/* function to return a specific digit from a number
    inputs: int     val     value to extract digit from
            int     dig     digit to extract
    output:                 no reference parameters
    returns: int            digit 
*/
int get_digit(int val, int dig)
{
    int ndigs = num_digits(val);
    for (int i=dig; i <ndigs-1; i++)
        val /= 10;
    return val%10;
}

//..............................................................

