#include <iostream>
#include <fstream>
#include <iomanip>      // so we can format our output nicely
#include <cmath>        // trig functions are in cmath header file

                        // sin( ), cos( ), tan( ) give us sine, cosine and tangent of an angle
                        // asin( ), acos( ) give us the arc-sine and arc-cosine.
                        // C++'s trig functions work in radians, not degrees.

using namespace std;

const double PI=3.14159263;             // create a constant for PI
// or: 
//const double PI=acos(-1.0);           // acos( ) gives us the arc-cosine.  Q: Why does this give us PI?

int main(void)
{
    double angle=30.0;
    double angle_radians = angle * 2.0 * PI / 360.0;    // 2 PI radians in a full circle
    double my_cosine = cos(angle_radians);              // trig functions work in radians, not degrees
    double my_sine   = sin(angle_radians);

    cout << angle << "degrees equals "<< angle_radians << " radians"<<endl;
    cout << "cosine of " << angle_radians << " is " << my_cosine << endl;
    cout << "sine   of " << angle_radians << " is " << my_sine << endl;

            // now print out 24 sines and cosines (actually, 25 of 'em)

    cout << "i" << "\t" << "theta" << "\t" << "cosine" << "\t" << "sine" << endl;
    cout << setprecision(4);        // output with four decimal places.
    for (int i=0;i<=24; i++)
    {
        double theta;
        theta = 2.0*PI/24.0 * i;     // got partway around the circle each time through the loop

        cout << i << "\t" << theta << "\t" << cos(theta) << "\t" << sin(theta) << endl;
    }
    
            // Now, write the same data to a file:
    
    ofstream ofs("sincos.txt");
    ofs << setprecision(4);
    for (int i=0;i<=24; i++)
    {
        double theta;
        theta = 2.0*PI/24.0 * i;     // got partway around the circle each time through the loop
        ofs << i << "\t" << theta << "\t" << cos(theta) << "\t" << sin(theta) << endl;
    }
    ofs.close();
    cout << endl << "sines, cosines written to sincos.txt"<<endl;

    return 0;
}
