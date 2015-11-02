/*

Joseph Meriam
ECE 1305 Lab 6
10/29/15

*/
#include <iostream>
#include <ctime>

using namespace std;

// Prototypes
double getMaxVal(const double array[], int length);
double getMinVal(const double array[], int length);
double get_array_average(double array[], int length);
double * query_for_array(int length);
int * fill_rand_array();
int * seed_rand_array_from_number(int seedNumber);
int * seed_rand_array_from_system_time();
void get_array_stats(double array[], int length, double& max, double& min, double& average);

// Main fucntion
int main()
{	

	// Initialize variables and arrays
	double * array;
	int * rand_array, * seeded_rand_array_from_number, * seeded_rand_array_from_system_time;
	double  max, min, average;
	int length, seedNumber;

	// Prompts user for array length
	cout << "How many numbers would you like to input? ";
	cin >> length;

	// Gets values for array from user
	array = query_for_array(length);

	// Gets an array filled with random numbers
	rand_array = fill_rand_array();

	// Prompts user for a seed number
	cout << "Enter your seed number: ";
	cin >> seedNumber;

	// Gets an array seeded from the user's seed number
	seeded_rand_array_from_number = seed_rand_array_from_number(seedNumber);

	// Gets an array seeded from the current system time
	seeded_rand_array_from_system_time = seed_rand_array_from_system_time();

	// Gets the max, min, and average of the first array
	get_array_stats(array, length, max, min, average);

	// Prints the results
	cout << "Min value: " << min << endl;
	cout << "Max value: " << max << endl;
	cout << "Average: " << average << endl;


}

// Gets the user's values for an array
double * query_for_array(int length) {
	
	// Initialize variables
	double * array;

	// Declares the array
	array = new double[length];

	//Prompts the user for values
	for (int i = 0; i < length; i++) {

		cout << "Enter value: ";
		cin >> array[i];

	}

	// Returns the array
	return array;
}

// Gets array filled with random numbers
int * fill_rand_array() {

	// Initialize variables
	int * rand_array;
	int length = 25;

	// Declares the array
	rand_array = new int[length];

	// Sets each array location to a random variable
	for (int i = 0; i < length; i++) {
		rand_array[i] = rand();
	}

	// Returns the array
	return rand_array;

}

// Gets array filled with seeded random numbers
int * seed_rand_array_from_number(int seedNumber) {

	// Initialize variables
	int * seeded_rand_array;
	int length = 25;

	// Declares the array
	seeded_rand_array = new int[length];

	// Sets seed to the user's seednumber
	srand(seedNumber);

	// Sets each array location to a random seeded variable
	for (int i = 0; i < length; i++) {
		seeded_rand_array[i] = rand();
	}

	// Returns the array
	return seeded_rand_array;

}

// Gets array filled with seeded random numbers based on system time
int * seed_rand_array_from_system_time() {
	
	// Initialize variables
	int * seeded_rand_array;
	int length = 25;

	// Declares the array
	seeded_rand_array = new int[length];

	// Sets the seed based on the current system time
	srand(time(0));

	// Sets each array location to a random seeded variables
	for (int i = 0; i < length; i++) {
		seeded_rand_array[i] = rand();
	}

	// Returns the seed
	return seeded_rand_array;
}

// Gets array's max value
double getMaxVal(const double array[], int length) {
	
	// Initialize variables
	double maxVal;

	// Sets variable to the first value in the array
	maxVal = array[0];

	// Gets max val
	for (int i = 0; i < length; i++) {

		if (maxVal < array[i]) {

			maxVal = array[i];

		}

	}

	// Returns max value
	return maxVal;
}

// Gets array's min value
double getMinVal(const double array[], int length) {
	
	// Initialize variables
	double minVal;

	// Sets variable to the first value in the array
	minVal = array[0];

	// Gets min value
	for (int i = 0; i < length; i++) {

		if (minVal > array[i]) {

			minVal = array[i];

		}

	}

	// Returns min value
	return minVal;
}

// Gets the array's average
double get_array_average(double array[], int length) {
	
	// Initialize variables
	double average;

	// Sets initial average to zero
	average = 0;

	// Gets running sum of array values
	for (int i = 0; i < length; i++) {

		average = average + array[i];

	}

	// Calculates the average
	average = average / length;

	// Returns average
	return average;
}

// Returns the array's stats
void get_array_stats(double array[], int length, double& max, double& min, double& average) {

	// Returns the values
	max = getMaxVal(array, length);
	min = getMinVal(array, length);
	average = get_array_average(array, length);


}