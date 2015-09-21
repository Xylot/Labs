//============================================================================
// Name        : count_down_while_loop.cpp
// Author      : Ian Scott-Fleming
// Version     :
// Description : Sample program to demo using a while loop.
//
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int counter = 10;

	while (counter >= 0)
	{
		cout << "count-down:  "<< counter << endl;
		counter = counter - 1;
	}
	cout << "blast-off!"<<endl;
}
