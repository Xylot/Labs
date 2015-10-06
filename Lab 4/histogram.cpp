/*

Joseph Meriam
ECE 1305 Lab 4
10/5/15
Outputs a histogram of a pgm file complete with results for its min, max, mean, and median values

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <sstream>
using namespace std;

int main()
{

	// Initialize variables
	string line;
	int medianArray[1000] = { 0 };
	int pgmArray[255] = { 0 };
	int min, max, sum, total, k, h, medianCount, pgmValue, setSum;
	double mean, median;

	// Sets variables to zero so they can be used
	total = 0, sum = 0, k = 0, h = 0, setSum = 0;

	// Opens the file
	ifstream pgm("initials.pgm");

	// Ignores the first line
	getline(pgm, line);
	
	// Takes in the first value so the loop can start
	pgm >> pgmValue;

	// Runs until there is nothing left in the file to use
	while (pgm)
	{

		// Increments the value by one if they number is found
		pgmArray[pgmValue]++;

		// Takes in the next value
		pgm >> pgmValue;
	}

	// Calculates the minimum value in the array
	for (int i = 0; i < 255; i++) {
		if (pgmArray[i] > 0) {
			min = i;
			break;
		}
	}

	// Calculates the maximum value in the array
	for (int i = 255; i > 0; i--) {
		if (pgmArray[i] > 0) {
			max = i;
			break;
		}
	}

	// Calculates the sum and total number of all the values in order to find the mean later on
	for (int i = 0; i < 255; i++) {

		// Calculates the total number of values
		total = total + pgmArray[i];

		if (pgmArray[i] > 0) {

			// Sums up the values
			sum = sum + i * pgmArray[i];

			// Puts each value in the array in order to calculate the median later on
			for (int j = 0; j < pgmArray[i]; j++) {
				medianArray[j] = i;
			}
		}
	}

	// Calculates how many variables we need for the median
	while (medianArray[k] != 0) {
		k++;
	}

	// If the amount of values is even, it calculates the average of the two most middle values
	if (k % 2 == 0) {
		median = (medianArray[(k + 1) / 2]) / (medianArray[(k - 1) / 2]);
	}

	// If the amount of values is odd, it finds the middle value
	else {
		median = medianArray[k / 2];
	}

	// Calculates the mean
	mean = (double)sum / (double)total;

	// Prints out the formatted histogram
	for (int j = 0; j < 255; j += 9) {

		// Sets setSum to zero so it can be reused
		setSum = 0;

		// If this is the first iteration
		if (true) {

			// Calculates how many numbers are in the range
			for (int g = j; g < j + 10; g++) {

				setSum = setSum + pgmArray[g];

				// Breaks if the maximum value has been hit
				if (g == 255) {
					break;
				}

			}

			// Prints out the results
			cout << j << " - " << j + 9 << ": " << setSum << endl;

			// Increments j by 1
			j += 1;

		}
		else {

			// Calculates how many numbers are in the range
			for (int g = j; g < j + 9; g++) {

				setSum = setSum + pgmArray[g];


			}

			// Prints out the results
			cout << j << " - " << j + 9 << ": " << setSum << endl;

			j += 1;
		}

	}

	// Prints out the results
	cout << endl;
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	cout << "Mean: " << mean << endl;
	cout << "Median: " << median << endl;

}
