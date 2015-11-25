#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    long i = 5, j=10, k=15;
    long data[5] = {10, 20, 30, 40, 50};
    char my_cstring[8] = "the fox";
    
    long *p = NULL;
    char *pc = NULL;
    
    // do something useful with the arrays and the pointers
    
    p = &i;
    cout << "i: "<<setw(3)<<i<<" "<<" *p: "<<setw(3)<< *p<<" p: "<<p<<endl;
    p = &j;
    cout << "j: "<<setw(3)<<j<<" "<<" *p: "<<setw(3)<< *p<<" p: "<<p<<endl;
    p = &k;
    cout << "k: "<<setw(3)<<k<<" "<<" *p: "<<setw(3)<< *p<<" p: "<<p<<endl;

    cout << endl << "data: "<<endl;
    for (int i=0;i<5;i++)
        cout << data[i]<<" ";
    cout << endl << "via *(p++);"<<endl;
    for (p=data; p<data+5; p++)
    {
        cout << "p: "<< p << " *p: "<<*p<<endl;
    }

    // and put some clean-up code to delete any 
    // dynamically allocated variables

    cout << "done"<<endl;
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}
        
