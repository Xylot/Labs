//============================================================================
// Name        : count_down_for_loop.cpp
// Author      : Ian Scott-Fleming
// Version     :
// Description : Sample program to demo using a for loop.
//
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int counter;

	for (counter = 10; counter >= 0; counter--)
		cout << "count-down:  "<< counter << endl;
	cout << "blast-off!"<<endl;
    cout << "counter is now: "<<counter<<endl<<endl;

        // you can also declare the loop counter in the for loop
        // The difference is that the loop counter will be destroyed 
        // (will not exist) after the loop finishes

    for (int ctr2=10;  ctr2 >= 0;  ctr2--)
        cout << "count-down2: " << ctr2 << endl;

	cout << "blast-off!"<<endl;
    cout << "variable ctr2 no longer exists"<<endl;
        // this won't compile if you uncomment the next line.
//  cout << "ctr2 is now: " << ctr2 << endl;       

    return 0;
}
