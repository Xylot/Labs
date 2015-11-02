#include <iostream>
#include <iomanip>

// sample program to demonstrate that arrays are passed by reference (even without the &)

using namespace std;

void reverse_it(int array[], int siz);    // function to reverse the elements of an array.

int main(void)
{
    int myarray[3] = {5, 10, 15};
	int herarray[5] = {101, 102, 103, 104, 105};
	int hisarray[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
			// Let's reverse myarray:
    cout << "myarray is: ";
    for (int i=0;i<3;i++) cout << myarray[i]<<" ";
    cout << endl;
    reverse_it(myarray, 3);
    cout << "back in main, after calling reverse_it, array is ";
    for (int i=0;i<3;i++) cout << myarray[i]<<" ";
    cout << endl;

			// Now, to it to a different, larger array
    
    cout << "herarray is: ";
    for (int i=0;i<5;i++) cout << herarray[i]<<" ";
    cout << endl;
    reverse_it(herarray, 5);
    cout << "back in main, after calling reverse_it, array is ";
    for (int i=0;i<5;i++) cout << herarray[i]<<" ";
    cout << endl;

    
			// Now, lets reverse just part of an array:
    
    cout << "hisarray is: ";
    for (int i=0;i<10;i++) cout << hisarray[i]<<" ";
    cout << endl;
	cout << "calling reverse_it with (his_array,7), even though the array is 10 long."<<endl;
    reverse_it(hisarray, 7);
    cout << "back in main, after calling reverse_it, array is ";
    for (int i=0;i<10;i++) cout << hisarray[i]<<" ";
    cout << endl;

    return 0;
}

/* reverses the elements.  arrays passed by value, so original argument array will be reversed, too
    inputs:  int array[]    integer array
             int siz        length of array
    outputs: int array[]    reversed array put back in same place.
*/

void reverse_it(int array[], int siz)
{
    cout << "in reverse_it, array is ";
    for (int i=0;i<siz;i++) cout << array[i]<<" ";
    cout << endl;
            // now reverse the elements
    for (int i=0;i<siz/2;i++)
    {
        int t = array[i];
        array[i] = array[siz-1-i];
        array[siz-1-i] = t;
    }
    cout << "in reverse_it, after swapping, array is ";
    for (int i=0;i<siz;i++) cout << array[i]<<" ";
    cout << endl;
}

