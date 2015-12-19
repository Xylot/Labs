/* file:  binary_timing.cpp
    lab 10 exercise
    program to demonstrate to the student how much faster it is to write (and read)
    a data file in binary than in ascii.
    
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int SIZE=64*1048576;    // 64 * 1024*1024, 64 MegBytes
void initialize_dat(char dat[], int size);
void write_ascii_data(const char dat[], int size);
void read_ascii_data(char dat[], int size);
/*
void write_binary_data(const char dat[], int size);
void read_binary_data(char dat[], int size);
*/

int main( )
{
    char *dat = new char[SIZE];
	if (! dat) {cerr << "cannot alloc dat array"<<endl; return 1;}
	
    initialize_dat(dat, SIZE);    // fill it with random numbers
            // open a file for writing and write 10 MB of data into it

    cout << "writing 64 MB of 8-bit integer data in ascii"<<endl;
    write_ascii_data(dat, SIZE);
    cout << "reading 64 MB of 8-bit integer data in ascii"<<endl;
    read_ascii_data(dat, SIZE);

/*      Now write and read data in binary format.
            // you need to write the functions
            // write_binary_data( ) and read_binary_data(...)    
            
    cout << "writing 64 MB of 8-bit integer data in binary"<<endl;
    write_binary_data(dat, SIZE);
    cout << "reading 64 MB of 8-bit integer data in binary"<<endl;
    read_binary_data(dat, SIZE);
*/
    
    
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}

void initialize_dat(char dat[], int size)
{
    for (int i=0;i<size; i++)
        dat[i] = rand()%256 - 128;      // get random # between -128 and 127.
}
void write_ascii_data(const char *dat, int size)
{
    ofstream ofs("ascii.txt");
    for (int i=0;i<size;i++)    // output dat as integer values (like pixels?)
    {
        ofs << setw(4) << static_cast<int>(dat[i]);
        if (i%16==15)   ofs << endl;
        else            ofs << ' ';
        if(i%(1024*1024)==0) {cout << "\r" << i/1024/1024<<" MB text written"; cout.flush();}     // write something every MB so we know something is happening
   }
    cout << "done writing text"<<endl;}

void read_ascii_data(char *dat, int size)
{
    ifstream ifs("ascii.txt");
    for (int i=0;i<size;i++)
    {
        int val;
        ifs >> val;     // read number into an integer
        dat[i] = static_cast<char>(val);   // convert it to a char.
        if(i%(1024*1024)==0) {cout << "\r" << i/1024/1024<<" MB text read in"; cout.flush();}     // write something every MB so we know something is happening
    }
    cout << "done reading text"<<endl;
}

/*      finish these two functions

void write_binary_data(const char *dat, int size)
{
    cout << "you need to write this routine!"<<endl;
    cout << "done writing 64 MB binary";
}

void read_binary_data(char *dat, int size)
{
    cout << "you need to write this routine!"<<endl;
    cout << "done reading 64 MB binary";
}

*/
