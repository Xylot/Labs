#include <iostream>
#include <string>


// sample program to demonstrate passing arrays as consts, or as regular references.
// this is like sample_array.cpp, but uses a separate function to display  the contents of the array,
// along with a string.  Very useful idea for debugging your code!

using namespace std;

void display_it(const int array[], int siz, string s);    // displays contents of an array.
void reverse_it(int array[], int siz);    // function to reverse the elements of an array.

//.....................................................

int main(void)
{
    int myarray[3] = {5, 10, 15};
    
    display_it(myarray, 3, "myarray is: ");
    reverse_it(myarray, 3);
    display_it(myarray, 3, "back in main, after calling reverse_it, array is ");
    
    return 0;
}

//.....................................................

/* displays the elements of an array.
    inputs:  int array[]    integer array
             int siz        length of array
    string   s              text to display with array
*/

void display_it(const int array[], int siz, string s)    // displays contents of an array.
{
    cout << s << " ";
    for (int i=0;i<siz;i++) cout << array[i]<<" ";
    cout << endl;
    
            // note:  if you try to change array[], the compiler won't like it.
            // try un-commenting the following line and recompile:
//    array[0] = -99999;      // this won't compile!
}


//.....................................................

/* reverses the elements.  arrays passed by value, so original argument array will be reversed, too
    inputs:  int array[]    integer array
             int siz        length of array
    outputs: int array[]    reversed array put back in same place.
*/

void reverse_it(int array[], int siz)
{
    display_it(array, siz, "in reverse_it, array is ");
            // now reverse the elements
    for (int i=0;i<siz/2;i++)
    {
        int t = array[i];
        array[i] = array[siz-1-i];
        array[siz-1-i] = t;
    }
    display_it(array, siz, "in reverse_it, after swapping, array is ");
}
