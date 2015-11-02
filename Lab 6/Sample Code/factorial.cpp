/* assignment:  modify the code below by adding a recursive function

    factorial(n)

    Note:  the answer for the looping factorial is wrong for integers > 12.  Why?
    What happens if we change fact from an int to a long?  to a float?  to a double?
    If you use a float or a double, when is the answer not exactly correct?

*/

#include <iostream>
#include <iomanip>
using namespace std;


//......................put your factorial prototype here


//......................

int main(void)
{

    int n, n2, fact;

    cout << "enter an integer number: "<<endl;
    cin >> n;

    n2 = n;


            // calculate n factorial with a loop:

    fact = 1;
    while (n2 > 1)
    {
        fact *= n2;
        n2--;
    }

    cout << n << " factorial is: " << fact << endl;

            // now uncomment the line below, and do it using your recursive function:

//    fact = factorial(n);

    cout << n << " recursive factorial is: " << fact << endl;

    return 0;

}

//...................... add your recursive factorial function here

