/* 
    Sample program to demonstrate writing to a file and reading from a fil
*/


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(void)
{

	ofstream ofs("hello_file.txt");     // we'll write to the file hello_file.txt
            // write something to hello_file.txt
	ofs << "Hello world"<<endl;

    ifstream ifs("numbers.txt");        // we'll read from the file "numbers.txt"
    int a,b,c,d;
    
	if (!ifs)       // did we open the input file properly?
	{
		cout << "problem.  couldn't open the file"<<endl;
		return 1;
	}

        // read a,b,c & d from the file "numbers.txt"
	ifs >> a >> b >> c >> d;

	if (!ifs)       // did we read 4 values from the file as expected?
	{
		cout << "problem reading from the file"<<endl;
		return 2;
	}

	cout << "a,b,c and d are: "<< a<< " "<<b <<" "<<c <<" "<<d <<endl;

        // output a,b,c & d to hello_file.txt.
        // am using setw( ) here to set the output field width
        // (using a different width each time just for fun...)
	ofs << setw(4) << a << setw(5) << b << setw(6) << c << setw(7) << d
		<< setw(8)<< a+b+c+d << endl;
	ofs << "goodbye world"<<endl;

	ofs.close();

	return 0;
}