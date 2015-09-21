//============================================================================
// Name        : print_table.cpp

// Author      : 
// Version     :
// Description : Sample program to demo using a for loop
//	prompts for starting & ending #'s & # of columns
//	prints numbers from start_num to end_num, in ncols columns.
//
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int i, start_num, end_num, ncols;

			// get starting, ending
	cout << "program to print a table of numbers."<<endl;
	cout << "starting #? ";
	cin >> start_num;
	cout << "ending #? ";
	cin >> end_num;
	cout << "# cols? ";
	cin >> ncols;

	for (i=start_num;  i<= end_num; i++)
	{
		cout << i << "\t";			// output the number
		if ((i-start_num)%ncols == ncols-1)
			cout << endl;			// and a newline from time to time
	}

	cout << endl;
	return 0;
}
