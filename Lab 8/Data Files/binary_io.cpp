#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(void)
{
    int a[11] = {543516756,  1667855729, 1919033451,   544110447,  544763750, 1886221674, 1986994291, 1948283493, 1814062440,  544832097,  778530660 };
    int b[11] = { 0};
    char buf[100] = {0};

    cout << endl<< "Program to demo binary i/o."<<endl;
    cout << "On this computer, an int is "<<sizeof(int)<<" bytes long"<<endl<<endl;

    ofstream ofs("binary.dat", ios::binary);

        // write out a[ ] in binary format
    ofs.write(reinterpret_cast<char *>(a), 11*sizeof(int));
    ofs.close();

        // read in binary.dat into array b[ ]
    ifstream ifs("binary.dat", ios::binary);
    ifs.read(reinterpret_cast<char *>(b), 11*sizeof(int));
    ifs.close();

        // print the 2 arrays:

    cout << "i     a[i]       b[i]"<<endl;
    for (int i=0;i< 11; i++)
        cout << setw(2)<< i << "  "<<setw(10) << a[i] << " " << setw(10) << b[i] << endl;


        // now reread the file into a char array and print it out:

    ifs.open("binary.dat", ios::binary);
    ifs.read(buf, 11*sizeof(int));

    cout << endl << "reading data as char array:"<<endl;

    cout << " i\tbuf[i]\tint"<<"\thex"<<endl;
    for (int i=0;i<11*sizeof(int)+1;i++)
        if (isprint(buf[i]))
            cout << setw(2)<<i<<"\t"<<buf[i] << "\t" << static_cast<int>(buf[i])<< "\t" << hex << static_cast<int>(buf[i])<< dec << endl;
        else
            cout << setw(2)<<i<<"\t"<< " "   << "\t" << static_cast<int>(buf[i])<< "\t" << hex << static_cast<int>(buf[i])<< dec << endl;


    return 0;
}
