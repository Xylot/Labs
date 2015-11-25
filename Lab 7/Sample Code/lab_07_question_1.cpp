#include <iostream>
using namespace std;

int main()
{
    int i = 5;
    int data[5] = {10, 20, 30, 40, 50};
    
    int *p = &i;        // point p to the address of i.
    
    cout << "pointers & single values: "<<endl;
    cout << "i:              "<< i  <<endl;
    cout << "address of i:   "<< &i << endl;
    cout << "dereferenced p: "<< *p << endl;        // dereference p to get value where it points
    cout << "just plain p:   "<< p  << endl;
    
    cout << endl<<"pointers and arrays: "<<endl;

    p = data;           // point p to the beginning of array data
                        // NOTE: NO & here! Remember:  name of array <--> address of beginning of array
                        // NOTE 2:  I could also have done:  p = &data[0];
                        //  where I take the address of a single integer, in this case the address 
                        // of the first element of data.
    cout << "now p is equal to data"<<endl;
    cout << "data: "<<data<<endl;
    cout << "p:    "<<p<<endl;
    cout << "data[0]: "<<data[0]<<endl;
    cout << "*p:      "<<*p<<endl;          // dereference p to get value where it points
    cout << "data[2]: "<<data[2]<<endl;
    cout << "p[2]:    "<<p[2]<<endl;        // index p just like indexing regular array.
    
    cout << "indexing arrays: "<<endl;
    cout << "indexing data: ";
    for (int j=0;j<5;j++) cout << data[j]<<' ';
    cout << endl << "indexing p:    ";
    for (int j=0;j<5;j++) cout << p[j]<<' ';

    cout << endl<<endl<<"what's the difference here? "<<endl;
    p = data;
    cout << "(*p)++: ";
    for (int i=0;i<5;i++)
        cout << (*p)++ << ' ';      // incrementing where p points
    cout << endl;
    cout << "*(p++): ";             // incrementing p
    for (int i=0;i<5;i++)
        cout << *(p++) << ' ';
        
    
    cout << endl<<endl<<"why is p+1 not one more than p?"<<endl;
    cout << "p:   "<<p<<endl;
    cout << "p+1: "<<p+1<<endl;
    cout << "hint:  sizeof(int) = " << sizeof(int)<<endl;
    
    int *q = data;
    cout << endl<<endl<<"how does this step through the array? "<<endl;
    for (int k=0;  k < 5;  k++) 
        cout << "k: "<<k<<"  q+k: "<<q+k<<" *(q+k): "<<*(q+k)<<endl;
    cout << endl<<endl;
    
    cout << "c-strings are a legacy of c, which didn't have string objects."<<endl;
    cout << "therefore outputting char addresses outputs the text, not the address-in-hex"<<endl;
    cout << "it actually outputs chars until it finds a null char, and then stops"<<endl<<endl;
    
    char text[4] = "abc";
    cout << "p:    "<<p<<" (regular pointers are output as hex values)"<<endl;
    cout << "text: "<<text<<" (but char pointers are assumed to point to c-strings)"<<endl;
    cout << "text individual char values: "<<endl;
    cout << "text[0]: " <<static_cast<int>(text[0]) << " '"<<text[0]<<"'"<<endl;
    cout << "text[1]: " <<static_cast<int>(text[1]) << " '"<<text[1]<<"'"<<endl;
    cout << "text[2]: " <<static_cast<int>(text[2]) << " '"<<text[2]<<"'"<<endl;
    cout << "text[3]:  "<<static_cast<int>(text[3]) << " '"<<text[3]<<"'"<<endl;
        
    cout << "done"<<endl;
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}
        
