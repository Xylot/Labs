#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

/* sample program to demonstrate using an array for histogramming a data set.
	reads an arbitrary-sized set of data and count how many times 
	each value occurs.
	assumes data will be in range [0..29] (inclusive).

  To help with debugging, user can specify to histogram only 1st 9 points.
*/

int main()
{
	int counts[30] = {0};	// array of counters, initialized to zeros.
							// this assumes all values will be between 0 & 29.
							// Note how this is enforced in the code below.

			// open the data file
	ifstream ifs("data.txt");
	if (!ifs) {cout << "error opening file 'data.txt'.  exiting..."; return 0;}

	cout << "reading data from file 'data.txt'"<<endl;

			// for testing, give option of counting only first 9 values.
			// this is few enough that we can check the results by hand.
	char resp;
	cout << "use all data or first 9 points only? (enter a or 9) ";
	cin >> resp;

				// now count how many occurrences of each value (0...29) there are in the data.

	if (resp == '9')		// for debugging, do first 9 points only
	{
		int i=0;
		int val;
		ifs >> val;
		while (ifs && i < 9)	
		{
			i++;						// keep track of how many data values read so far.
			if (val < 0 || val >= 30)
				cout << "data out of range: "<<val<<" .  Must be between 0 and 29"<<endl;
			else
				counts[val]++;			// increment the counter for data's value.

			ifs >> val;			// read next data value
		}
	}

	else				// regular run.  do all data points.
	{
		int val;
		ifs >> val;     // prime the loop by reading the first data point.
		while (ifs)     // while we've got data, count the last value read and read the next value.
		{
			if (val < 0 || val >= 30)
				cout << "data out of range: "<<val<<" .  Must be between 0 and 29"<<endl;
			else
				counts[val]++;			// increment the counter for data's value.

			ifs >> val;			// read next data value
		}
	}

			// now output the histogram, or table of counts:
	cout << "val  counts"<<endl;
	for (int i=0;i<30;i++)
		cout << setw(2)<<i<<setw(6)<<counts[i]<<endl;

	return 0;
}