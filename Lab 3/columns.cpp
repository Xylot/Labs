/*

Joseph Meriam
ECE 1305 Lab 3
9/26/15
Prints a set of user defined numbers based on a user defined amount of rows

*/

#include <iostream>

using namespace std;

int main(void)
{
    
    // Initialize variables
    int nums, rows;
    
    // Prompts user for the amount of numbers to display
    cout << "How many numbers do you want to output? ";
    cin >> nums;
    
    // Prompts the user for the amount of rows to display
    cout << "How many rows do you want to output? ";
    cin >> rows;
    
    // Formatting
    cout << endl;
    
    // Increments i until the amount of rows
    for (int i = 0; i < rows; i++) {
        
        // Formatting for the numbers 1-9
        if (i < 9) {
            cout << " ";
        }
        
        // Increments j by the number of rows  until the numbers to be displayed has been reached
        for (int j = 1; j < nums; j += rows) {
            
            
            // Only prints the next integer if the sum of i and j are less than the number amount
            if (i + j < nums + 1) {
                cout << i + j << "  ";
            }
            
        }
        
        // Formatting
        cout << endl;
        
    }
}
