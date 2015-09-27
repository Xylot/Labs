#include <iostream>
using namespace std;
	// sample nested loop, sample use of tab.
	// This program outputs a table of numbers with 10 rows and 4 columns
int main(int)
{		
	for (int i=0;i<10;i++)		// output 10 rows
	{
		for (int j=0;j<4;j++)	// output 4 numbers in each row.
		{
			int num = i*10 + j ;		// outputting 10 times the row plus the column
			cout << "\t" << num;
		}
		cout << endl;	// put a newline at the end of each row
	}
	return 0;
}