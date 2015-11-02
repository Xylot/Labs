#include<iostream>
#include<cmath>

using namespace std;

//      for part a, put your function prototype for mag here!

//      for part b, put your function prototype for rec2polar here!

//............................................................

int main(void)
{
    double x = 0;
    double y = 0;
    double v=-6.0, w=8.0;
    double m;

    cout << "Please enter the X coordinate: ";
    cin >> x;
    cout << "Please enter the Y coordinate: ";
    cin >> y;

    m = mag(x,y);       // you need to write this function!
    cout << "The magnitude of ( "<< x << " , "<< y <<" ) is: " << m << endl;
    
    m = mag(v,w);       // now get the magnitude of vector (v,w)
    cout << "The magnitude of ( "<< v << " , "<< w <<" ) is: " << m << endl;
    
    
/*
            // for part 1b, uncomment these lines and add a function to calculate
            // the polar form of (x,y);
            
    double r, theta;
    
    rect2polar(x,y,r,theta);
 
    cout << "the polar form of ( "<< x << " , "<< y <<" ) is: ( " << r << " , " << theta << " )"<<endl;

    rect2polar(v,w,r,theta);
 
    cout << "the polar form of ( "<< v << " , "<< w <<" ) is: ( " << r << " , " << theta << " )"<<endl;
*/ 

    return 0;
}


//.................put your mag function here...................
// be sure to add comments describing the inputs and outputs so a reader would
// know how to use it.


//.................put your rect2polar function here...................
// be sure to add comments describing the inputs and outputs so a reader would
// know how to use it.

