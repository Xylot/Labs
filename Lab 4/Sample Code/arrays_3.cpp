#include <iostream>
using namespace std;

// sample program to demonstrate how to declare,  initialize arrays and access the elements

int main()
{
	int i;
			// declare an array but don't initialize it.
	int data_garbage[5];
    
            // using an assignment statement, put something in the first element only.
    data_garbage[0] = 99.9;

			// output them to see if they contain anything interesting...last 4 should be garbage.

	for (i=0;i<5;i++) 
		cout << data_garbage[i] << " ";
	cout << endl;
			// declare an array of 5 integers and initialize them

	int data1[5] = {20, 21, 22, 23, 24};

			// output them to see if they were initialized properly

	for (i=0;i<5;i++) 
		cout << data1[i] << " ";
	cout << endl;

			// declare an array and initialize some elements.  rest are initialized to 0

	int data2[5] = {30, 31, 32};
			// output them to see if they were initialized as expected

	for (i=0;i<5;i++) 
		cout << data2[i] << " ";
	cout << endl;

			// Now, declare an array and initialize it, but don't explicitly give it a size.  
			// It will be sized based on the number of elements initialized.

	int data3[] = {40,41,42,43,44,45};

	for (i=0;i<6;i++)
		cout << data3[i]<<" ";
	cout << endl;

			// finally, to show that no bounds checking is done on arrays in c++,
			// let's try indexing out of range on data3 just to see what happens.
	cout << "now indexing out of range.  results are indeterminate and may crash"<<endl;
	cout.flush();
	cout << data3[-3]<<endl;	// this may cause it to crash!
	cout.flush();
	cout << data3[8]<<endl;		// so might this.
			// or you might just get garbage out.

	return 0;
}