/*

Joseph Meriam
ECE 1305 Lab 7
11 / 15 / 15

Other group members:
	Syed Ahmed
	Trevor Calvert
	aAdolfo Carrillo
	Bin Lee

*/
#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;

// Prototypes
void readFile(int &length, double* &arr);
double getAverage(int length, double arr[]);
void getMinAndMax(int length, double arr[], double &max, double &min);

int main()
{
	// Initialize variables
	int length = 0;
	double * arr = NULL;
	double avg, max = 0, min = 0;

	// Calls the read file function
	readFile(length, arr);

	// Sets the average to the result of the average function
	avg = getAverage(length, arr);

	// Sets the min and max to the results of the min and max functions
	getMinAndMax(length, arr, max, min);

	cout << "The count is: " << length << endl;
	cout << "The max is:" << max << endl;
	cout << "The min is:" << min << endl;
	cout << "The average is:" << avg << endl;


	delete[] arr;
}

void readFile(int &length, double* &arr)
{
	// Initialize variables
	string fName;

	// Prompts user for their filename of choice
	cout << "Filename:" << endl;
	cin >> fName;

	// Opens file
	ifstream datain(fName);

	// Gets first data
	datain >> length;

	// Allocates arr to the chosen length
	arr = new double[length];

	// Puts the data into arr
	for (int i = 0; i < length; i++)
	{
		datain >> arr[i];
	}

	// Closes file
	datain.close();

}

double getAverage(int length, double arr[])
{
	double sum = 0;
	double avg;

	// Calculates sum
	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
	}

	// Divides sum by length
	avg = sum / length;

	// Returns the value
	return avg;
}

void getMinAndMax(int length, double arr[], double &max, double &min)
{
	// Sets max to the first element
	max = arr[0];

	// Sets min to the max
	min = max;

	// Calculates max and min
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		else if (arr[i] < min)
			min = arr[i];
	}
}