#include<iostream>
#include<iomanip>

using namespace std;

//......................add your prototypes here................


//..............................................................


int main(void)
{
    int n = 10;
    int myarray[10];
    // int rand_array[25]  // for part 2d
    int val = 0;
    int mymin, mymax;


    for(int i = 0;i < n;i++)
    {
        cout << "Enter the element No. " << i  << "of the array ";
        cin >> val;
        myarray[i] = val;
    }
    
// for part 2b, replace the above loop with a this function call, and write the function:
    
//    query_for_array(10, my_array);
    
// for part 2c, add a function to calculate the average of an array, and a function to return all 3 values (min, max and average).

    mymin = min_element(myarray, n);
    mymax = max_element(myarray, n);
    cout << "The minimum element of the array is " << mymin << endl;

    cout << "The maximum element of the array is " << mymax << endl;

// for part 2d, add code here to fill rand_array[] with 25 random numbers, and then use your stats function
// to find the min, max and average
    
    return 0;
}

//.......................add your functions here....................

