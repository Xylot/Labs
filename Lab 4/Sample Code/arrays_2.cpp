#include <iostream>
#include <string>
using namespace std;

/* Like arrays1.cpp, except it uses loops and an index variable 
	to step through the array.
*/

int main()
{
		// declare an array of 3 strings.
	string names[3];

		// prompt user for 3 names and read them in
	for (int i=0;i<3;i++)
	{
		cout << "name "<<i<<"? ";
		cin >> names[i];
	}

		// output the three names to the screen
	cout << "you typed: ";
	for (int j=0;j<3;j++)
	{
		cout << names[j]<<" ";
	}
	cout << endl;

		// and some magic to pause it on a PC so the console doesn't close right away:
		// this has nothing to do with arrays.
#ifdef WIN32
	system("pause");
#endif

	return 0;
}