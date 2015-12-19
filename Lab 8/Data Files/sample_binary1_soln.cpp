#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

/* this program reads a sequence of 8 binary bytes of data into an int array
    and prints them out.  The data is output in both decimal and hex.
    
    It then rewinds the file to the beginning, and reads the same binary data
    into a char array and prints them out, first in decimal and then in hex.
    
    Note that PCs are big-endian, whereas Macs are little-endian.  Therefore 
    there are two versions of the program (controlled by #ifdef's).  The first is for
    Macs, the second is for PCs.  The only difference is that the PC version swaps the
    bytes around after reading, so it can give the same results as the Mac does.
    
    Note 2:  It only opens the data file once.  Then after reading the 24 bytes, using
    ifstream.seekg(0) to rewind to the beginning of the file.
    
    Note 3:  the read function expects the address of a char array.  Therefore,
    to use it to read integer data, we have to cast the address of the int array so
    it looks like the address of a char array.  For this, we use reinterpret_cast<char *>
*/

using namespace std;

#ifndef WIN32           // Mac version first:
    
int main( )
{
    char buf[8]={0};
    int ibuf[2]={0};
    
                // Open file for reading in binary mode
    ifstream ifs("sample_binary1.dat", ios::binary);
    if (!ifs) {cerr << "error opening file"<<endl; return 1;}

                // read the file into an int array and output as ints and then in hex
    ifs.read(reinterpret_cast<char *>(ibuf), 2*sizeof(int));
    cout << "int:"<<endl;
    for (int i=0;i<2;i++)
        cout << dec << setw(10)<< ibuf[i]<<" ";
        cout << endl;
//    cout <<setfill('0');
    for (int i=0;i<6;i++)
        cout << "0x"<<hex << setw(8)<< ibuf[i]<<" ";
//    cout << setfill(' ');
    cout << endl << endl;
    
                // now read the file into a char array    
    ifs.seekg(0);       // rewind the file first.
    ifs.read(buf, 8*sizeof(char));
    cout << "char: "<<endl;
                // output the 8 chars.
    for (int i=0;i<8;i++)
        cout << "  "<<buf[i]<<"  ";
    cout << endl;
                // output the integer version of each char
    for (int i=0;i<8;i++)
        cout << setw(4)<<static_cast<int>(buf[i])<<" ";
    cout << endl;
                // and now output it in hexadecimal
    for (int i=0;i<8;i++)
        cout << "0x"<<hex << setw(2)<<static_cast<int>(buf[i])<<" ";
    cout << endl << endl;

    return 0;
}


#else       //............................PC version, which does byte swapping after reading the ints.

void swap(char &a, char &b);        // swaps 2 chars
void reverse(short &sval);          // reverse the bytes of a short
void reverse(int &ival);            // int

int main( )
{
    int ibuf[2]={0};
    char buf[8]={0};
    
                // Open file for reading in binary mode
    ifstream ifs("sample_binary1.dat", ios::binary);
    if (!ifs) {cerr << "error opening file"<<endl; return 1;}

                // read the file into an int array and output as ints and then in hex
    ifs.read(reinterpret_cast<char *>(ibuf), 2*sizeof(int));
    reverse(ibuf[0]);
    reverse(ibuf[1]);
    cout << "int:"<<endl;
    for (int i=0;i<2;i++)
        cout << dec << setw(10)<< ibuf[i]<<" ";
    cout << endl;
    for (int i=0;i<2;i++)
        cout << "0x"<<hex << setw(8)<< ibuf[i]<<" ";
    cout << endl << endl;
    
                // now read the file into a char array    
    ifs.seekg(0);       // rewind the file first.
    ifs.read(buf, 8*sizeof(char));
    cout << "char: "<<endl;
                // output the 8 chars.
    for (int i=0;i<8;i++)
        cout << "  "<<buf[i]<<"  ";
    cout << endl;
                // output the integer version of each char
    for (int i=0;i<8;i++)
        cout << dec << setw(4)<<static_cast<int>(buf[i])<<" ";
    cout << endl;
                // and now output it in hexadecimal
    for (int i=0;i<8;i++)
        cout << "0x"<<hex << setw(2)<<static_cast<int>(buf[i])<<" ";
    cout << endl << endl;
    
    system("pause");

    return 0;
}


void swap(char &a, char &b)
{char t = a; a = b; b = t;}

void reverse(short &sval)
{
    char *p = reinterpret_cast<char *>(&sval);
    swap(p[0],p[1]);
    
}
void reverse(int &ival)
{
    char *p = reinterpret_cast<char *>(&ival);
    swap(p[0],p[3]);
    swap(p[1],p[2]);
}
#endif

