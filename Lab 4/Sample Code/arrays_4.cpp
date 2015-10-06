#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/* sample program to demonstrate two parallel arrays.  
	array X contains x-values from 0 to 2 PI.
	array Y contains the sin(X) for each X element.
*/

const double PI = acos(-1.0);	// get PI using a little trigonometry

const int NPTS = 100;	// define NPTS to be 100, the # of data points we'll use

int main()
{
	int i;
	double x[NPTS], y[NPTS];	// note:  NPTS has to be a constant here.

			// initialize the X array.
	for (i=0;i<NPTS;i++)
		x[i] = 10*i;

			// now fill in the Y values.  Yi = sine(Xi).
	for (i=0;i<NPTS;i++)
		y[i] = x[i] * x[i];

    // now output the results to the screen in 2 columns
    
    for (i=0;i<NPTS;i++)
        cout << i << "\t" << x[i]<<"\t"<<y[i]<<endl;
    

			// now output the results to a CSV file which can be read by excel

	ofstream ofs("squares.csv");
	for (i=0;i<NPTS;i++)
		ofs << i << "," << x[i]<<","<<y[i]<<endl;

	cout << endl<<"results written to \"squares.csv\".  \nYou should be able to open this with Excel, plot it and see a sine wave."<<endl;
    cout << "Or, lab 3 had a Matlab script to plot it (you'll want to change the filename and the axis labels...)"<<endl; 
	return 0;
}
