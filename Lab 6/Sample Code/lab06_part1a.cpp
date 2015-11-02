#include<iostream>
#include<cmath>

using namespace std;

//      for part a, put your function prototype for mag here!


//............................................................

int main(void)
{
    double x = 0;
    double y = 0;
    double v=3.0, w=4.0;
    double m;

    cout << "Please enter the X coordinate: ";
    cin >> x;
    cout << "Please enter the Y coordinate: ";
    cin >> y;

    m = mag(x,y);       // you need to write this function!
    cout << "The magnitude of ( "<< x << " , "<< y <<" ) is: " << m << endl;
    
    m = mag(v,w);       // now get the magnitude of vector (v,w)
    cout << "The magnitude of ( "<< v << " , "<< w <<" ) is: " << m << endl;
    

    return 0;
}


//.................put your mag function here...................
// be sure to add comments describing the inputs and outputs so a reader would
// know how to use it.

