#include <iostream>
#include <string>
using namespace std;

/* Sample program to declare an array of 3 strings, prompt the user for
	three values, read them in and write them back out.
*/

int main()
{
		// declare an array of 3 strings.
	string names[3];

		// prompt user for 3 names and read them in
	cout << "first name? ";
	cin >> names[0];		// zero-based arrays!
	cout << "second name? ";
	cin >> names[1];
	cout << "third name? ";
	cin >> names[2];

		// output the three names to the screen
	cout << "you typed: " << names[0]<<" "<<names[1]<<" "<<names[2]<<endl;

	// and some magic to pause it on a PC so the console doesn't close right away:
		// this has nothing to do with arrays!
#ifdef WIN32
	system("pause");
#endif

	return 0;
}