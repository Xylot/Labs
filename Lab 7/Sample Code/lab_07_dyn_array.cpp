#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void print_array(double *  p, int npts);     // function with pass-by-value pointer parameter
void change_ptr (double * &p, int n);        // function with pass-by-reference pointer parameter

int main( )
{
    double *q = NULL, *r = NULL;    // you should always initialize pointers to NULL 
    
    cout << fixed << setprecision(4);

        // allocate a double.
    q = new double;
    *q = acos(-1.0);
    cout << "pi is "<< *q << endl;
    
    delete q;   // We're done with it.  give it back.
    q = NULL;   // point it back to NULL to flag that it's not pointing at valid memory.
    
        // allocate a block of 10 doubles and put some values in them.
        
    q = new double[10];
    for (int i=0;i<10;i++)
        q[i] = 1.0/(i+1);
    
    cout << "q contains: "<<endl;

    for (int i=0;i<10;i++)
        cout << q[i] << " ";
    cout << endl;

        // pass q to a subroutine and use it:

    cout << "passing q to function to print it: "<<endl;

        // LOOK AT PRINT_ARRAY and notice that it changes the pointer.  
        // Why doesn't it affect q?  (hint:  how does c++ pass parameters by default?)
     print_array(q, 10);
    
        // pass r to a subroutine (by reference) and change it:

    r = q;    
    change_ptr(r, 2);   // moves r to r+2.

    cout << endl<<"r was moved over 2.  print out 8 elements now"<<endl;    
    print_array(r, 8);
    
    delete [] q;    // give back the memory.  note the [ ] comes before q!
    q = NULL;       // again, point it back to NULL to flag that it's not pointing at valid memory.

                    // NOTE:  better not delete [] r, because r doesn't point to
                    // its own block of dynamically allocated memory!
    r = NULL;
    
    cout << "done"<<endl;
    
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}

    // parameter p is pass-by-value, so changing it doesn't affect actual argument
void print_array(double *p, int npts)
{
    for (int i=0; i<npts; i++)
        cout << *p++ << ' ';    // this changes p, but p is passed by value, so it is a copy
                                // of the pointer in the calling code, so doesn't affect the
                                // main's pointer.
    cout << endl;
}

    // a simple pass-by-reference example.  changes p, so p is passed by reference.
    // note the syntax to do this.
void change_ptr(double * &p, int offset)
{
    p += offset;     // move the pointer over by offset.  This changes the pointer in the calling code...
}


        
