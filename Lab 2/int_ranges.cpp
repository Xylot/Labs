/*

Joseph Meriam
ECE 1305 Lab 2
9/18/15
Calculates int ranges

*/
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

    cout << "\n------------UNSIGNED INT FOR LOOP IMPLEMENTATION------------" << endl;

    int xf, yf;

    //Going to 32 demonstrates the looping back to a large negative number when the limit of the value is reached
    for (xf = 0; xf < 33; xf++) {
        yf = pow(2, xf);
        cout << "2^" << xf << ": " << yf << endl;
    }

    cout << "\n------------UNSIGNED INT WHILE LOOP IMPLEMENTATION------------" << endl;

    int xw, yw;

    xw = 0;

    while (xw < 33) {
        yw = pow(2, xw);
        cout << "2^" << xw << ": " << yw << endl;
        xw++;
    }

    cout << "\n------------UNSIGNED SHORT INT FOR LOOP IMPLEMENTATION------------" << endl;

    unsigned short int zf, af;

    // Going to 17 demonstrates the loopng back to zero when the limit of the value is reached
    for (zf = 0; zf < 18; zf++) {
        if (zf == 16) {
            af = pow(2, zf) - 1;
        }
        else {
            af = pow(2, zf);
        }
        cout << "2^" << zf << ": " << af << endl;
    }

    cout << "\n------------UNSIGNED SHORT INT DO WHILE LOOP IMPLEMENTATION------------" << endl;

    unsigned short int zd, ad;

    zd = 0;

    do {

        if (zd == 16) {
            ad = pow(2, zd) - 1;
        }
        else {
            ad = pow(2, zd);
        }
        cout << "2^" << zd << ": " << ad << endl;
        zd++;

    } while (zd < 18);
}