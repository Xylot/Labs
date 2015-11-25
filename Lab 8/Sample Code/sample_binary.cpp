#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

/* this program reads a sequence of 24 binary bytes of data into different data types
    and prints them out.  The data is output in both decimal and hex.
   
 Note:  the file is opened only once, and the code rewinds the file to the beginning
 using ifs.seekg(0).  
 The commented code would do essentially the same thing, by closing the file stream and
 re-opening it.
 
*/

using namespace std;

int main( )
{
    char buf[24]={0};
    short int sibuf[12]={0};
    int ibuf[6]={0};
    float fbuf[6]={0};
    double dbuf[3]={0};
    
                // Open file for reading in binary mode
    ifstream ifs("sample_binary.dat", ios::binary);
    if (!ifs) {cerr << "error opening file"<<endl; return 1;}

                // read the file into a char array    
    ifs.read(buf, 24*sizeof(char));
    cout << "char: "<<endl;
                // output the 24 chars.
    for (int i=0;i<24;i++)
        {cout << "  "<<buf[i]<<"  "; if (i==11) cout << endl;}
    cout << endl;
                // output the integer version of each char
    for (int i=0;i<24;i++)
        {cout << setw(4)<<static_cast<int>(buf[i])<<" "; if (i==11) cout << endl;}
    cout << endl;
                // and now output it in hexadecimal
    for (int i=0;i<24;i++)
        {cout << "0x"<<hex << setw(2)<<static_cast<int>(buf[i])<<" "; if (i==11) cout << endl;}
    cout << endl << endl;

                // rewind the file and read into a short array and output as ints and then in hex
    ifs.seekg(0);       // sets file point back to byte 0 of the file.
/*      or:
    ifs.close();
    ifs.open("sample_binary.dat", ios::binary);
*/
    ifs.read(reinterpret_cast<char *>(sibuf), 12*sizeof(short int));
    cout << "short:"<<endl;
    for (int i=0;i<12;i++)
        cout << setw(6)<< dec << sibuf[i]<<" ";
    cout << endl;
    cout <<setfill('0');
    for (int i=0;i<12;i++)
        cout << "0x"<< setw(4)<< hex << sibuf[i]<<" ";
    cout << endl << endl;
    cout << setfill(' ');
    
                // rewind the file and read into an int array and output as ints and then in hex
    ifs.seekg(0);
    ifs.read(reinterpret_cast<char *>(ibuf), 6*sizeof(int));
    cout << "int:"<<endl;
    for (int i=0;i<6;i++)
        cout << dec << setw(10)<< ibuf[i]<<" ";
        cout << endl;
    cout <<setfill('0');
    for (int i=0;i<6;i++)
        cout << "0x"<<hex << setw(8)<< ibuf[i]<<" ";
    cout << setfill(' ');
    cout << endl << endl;
    
                // rewind the file and read into a float array and output
    ifs.seekg(0);
    ifs.read(reinterpret_cast<char *>(fbuf), 6*sizeof(float));
    cout << "float:"<<endl;
    for (int i=0;i<6;i++)
        cout << setw(10)<<fbuf[i]<<" ";
    cout << endl << endl;
    
                // rewind the file and read into a double array and output
    ifs.seekg(0);
    ifs.read(reinterpret_cast<char *>(dbuf), 3*sizeof(double));
    cout << "double:"<<endl;
    for (int i=0;i<3;i++)
        cout << setw(18)<<dbuf[i]<<" ";
    cout << endl << endl;
    
    return 0;
}
