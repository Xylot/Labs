// Lab 1 sample program:  Inventory.cpp
// Calculates the number of items in a shipment based on the number
// of cartons received and the number of items per carton.
//
// Name:        ian scott-fleming
// Course:      ece 1305-004
// assignment:  lab 01
// other students in group: none
//
//..........................................

#include <iostream> // required to perform C++ stream I/O

using namespace std; // for accessing C++ Standard Library members

// function main begins program execution
int main()
{
    // define variables
    int cartons; // stores the number of cartons in a shipment
    int items;   // stores the number of items per carton
    int result;  // stores the product of cartons and items

    // prompt user for number of cartons in shipment
    cout << "\nEnter the number of cartons in shipment: ";
    cin >> cartons; // read user input

    // prompt user for number of items per carton
    cout << "Enter the number of items per carton: ";
    cin >> items; // read user input

    // multiply cartons by items to find the total number of items
    result = cartons * items;
 
    // display result
    cout << "The total number of items is: " << result
         << endl << endl; // note:  last line didn't end w/ semicolon,
                          // so the statement continues to the next line.
 
    return 0; // indicate that program ended successfully
 
} // end function main


