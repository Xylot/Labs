#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(void)
{
    char buf[ ] = "The quick brown fox jumps over the lazy dog.\n";
//                 ....+....1....+....2....+....3....+....4....+        buf is 45 chars, plus the null-char '\0'

    int *a = reinterpret_cast<int *>(buf);      // point an int* (ptr-to-int) to same place in memory.
                                                // a[...] will treat the bytes as integer values --
                                                // i.e., a[0] is the first 4 bytes of buf, a[1] the next 4 bytes, etc..

    int b[11]={0};

    cout << endl<< "Program to demo binary i/o."<<endl;
    cout << "On this computer, an int is "<<sizeof(int)<<" bytes long"<<endl<<endl;

        // write out some text to a file twice.  First as plain text, then in binary format.
        // these files should be the same  on a unix machine, but on a PC the text version
        // should be 1 byte longer, because the newline will be translated to a carriage return/newline.

    cout << "writing buf in binary mode to file \"binary.dat\""<<endl;
    ofstream ofs("binary.dat", ios::binary);
    ofs.write(buf, 45);     // write out the 45 chars in buf, in binary format.
    ofs.close();

        // reopen not in binary mode, and write the text out using << .
    ofs.open("text_fox.txt");
    cout << endl << "writing buf as text to file \"text_fox.txt\":"<<endl;
    ofs << buf;
    ofs.close();

        // now output buf to see what it looks like.
    cout << endl <<  " i\tbuf[i]\tint\thex"<<endl;
    for (int i=0;i<46;i++)
        if (isprint(buf[i]))
            cout << setw(2)<<i<<"\t  "<<buf[i]      << "\t " << static_cast<int>(buf[i])<<"\t "<<hex <<static_cast<int>(buf[i]) << dec << endl;
        else
            cout << setw(2)<<i<<"\t"<< "notprint"   << " "   << static_cast<int>(buf[i])<<"\t "<<hex <<static_cast<int>(buf[i]) << dec << endl;

        // read in binary.dat into array b[ ]
    ifstream ifs("binary.dat", ios::binary);
    ifs.read(reinterpret_cast<char *>(b), 11*sizeof(int));
    ifs.close();

        // print the 2 arrays:

    cout << endl << " i     a[i]       b[i]"<<endl;
    for (int i=0;i< 11; i++)
        cout << setw(2)<<i << "  "<<setw(10) << a[i] << " " << setw(10) << b[i] << endl;

    return 0;
}
