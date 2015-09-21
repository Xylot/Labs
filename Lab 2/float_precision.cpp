/*

Joseph Meriam
ECE 1305 Lab 2
9/18/15
Calculates the decimal point precision of different variable type

*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void) {

    // Variables
    float piF = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;//acos(-1.0)
    double piD = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;//acos(-1.0)
    long double piLD = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;//acos(-1.0)

    // Initial precision
    int x = 1;

    // This loop is used to determine how many decimals each type can hold
    while (x <= 50) {
        cout << setprecision(x) << "Float : " << piF << " x: " << x << endl; // Allows for 22 decimal point precision
        cout << setprecision(x) << "Double: " << piD << " x: " << x << endl; // Allows for 49 decimal point precision
        cout << setprecision(x) << "Louble: " << piLD << " x: " << x << endl; // Allows for 49 decimal point precision
        x++;
    }
}
