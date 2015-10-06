/*

Joseph Meriam
ECE 1305 Lab 4
10/1/15
Prompts the user for their numbers, calculates the sum and average, 
and outputs the array in different styles

*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	// Initialize Variables
	int amount, sum;
	double average;
	
	// Prompts user for the amount of numbers
	cout << "How many numbers? ";
	cin >> amount;
	
	// Creates numbers array
	int numbers[amount];
	
	// Sets sum and average to zero
	sum = 0;
	average = 0;

	// Prompts the user for their numbers and sums the numbers up
	for(int i = 0; i < amount; i++) {
		
		// Prompts user for their number
		cout << "Enter you number: ";
		cin >> numbers[i];
		
		// Adds the current number to the running sum
		sum += numbers[i];
	}
	
	// Calculates average
	average = double(sum) / double(amount);
	
	// Clears the screen
	system("cls");
	
	for(int i = 0; i < amount; i++) {
		
		// Prints fowards if this is the first iteration
		if(i == 0) {
			cout << "Your numbers: ";
		}
		
		// Prints the numbers
		cout << numbers[i]  << " ";
		
		// Ends the line on the last iteration
		if(i == amount - 1) {
			cout << endl;
		}
		
	}		
	
	// Prints sum
	cout << "Sum: " << sum << endl;
	
	// Prints average
	cout << "Average: " << average << endl;
	
	// Prints the numbers from first to last
	for(int i = 0; i < amount; i++) {
		
		// Prints fowards if this is the first iteration
		if(i == 0) {
			cout << "Fowards: ";
		}
		
		// Prints the numbers
		cout << numbers[i]  << " ";
		
		// Ends the line on the last iteration
		if(i == amount - 1) {
			cout << endl;
		}
	}
	
	// Prints the numbers from last to first
	for(int i = amount; i > 0; i--) {
		
		// Prints backwards if this is the first iteration
		if(i == amount) {
			cout << "Backwards: ";
		}
		
		// Prints the numbers
		cout << numbers[i - 1]  << " ";
		
		// Ends the line on the last iteration
		if(i == 1) {
			cout << endl;
		}
	}
}