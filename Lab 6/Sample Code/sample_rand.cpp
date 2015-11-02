#include<iostream>
#include<iomanip>

#include <ctime>    // needed for time( ), used to seed the random number generator from the system clock.

using namespace std;

//..............................................................


int main(void)
{
    int n = 0;

    cout << "6 random numbers: "<<endl;
    
    for (int i=0;i<6;i++)
        cout << setw(10) << rand() << " ";
    cout << endl;
    
    cout << endl << "setting the seed to 0: "<<endl;
    srand(0);
    cout << "6 more random numbers: "<<endl;
    
    for (int i=0;i<6;i++)
        cout << setw(10) << rand() << " ";
    cout << endl;
    
    cout << endl << "setting the seed to 1: "<<endl;
    srand(1);
    cout << "6 more random numbers: "<<endl;
    
    for (int i=0;i<6;i++)
        cout << setw(10) << rand() << " ";
    cout << endl;
    
    cout << endl << "setting the seed to 0 again: "<<endl;
    srand(0);
    cout << "6 more random numbers, which should be the same as the earlier 0-seed numbers: "<<endl;
    
    for (int i=0;i<6;i++)
        cout << setw(10) << rand() << " ";
    cout << endl;
    
    cout << endl << "setting the seed 'randomly', by using the system clock: "<<endl;
    unsigned int my_seed = time(0);     // get a seed from the system clock
    srand(my_seed);
    
    for (int i=0;i<6;i++)
        cout << setw(10) << rand() << " ";
    cout << endl;
    


    return 0;
}

