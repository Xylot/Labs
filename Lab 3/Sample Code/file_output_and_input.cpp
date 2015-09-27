/* sample program to write to a file, close it and read from it */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
    string fname="nums.txt";

        // some variables for reading in numbers and calc. average.
    int num;
    double sum=0.0, avg;
    int npts = 0;

        // declare, and open, an output filestream
    ofstream ofs(fname);
            // note:  if the above doesn't compile, your compiler doesn't support ANSI C++ 2011
            // if that's the case, use the following instead:
    //ofstream ofs(fname.c_str());

        // declare, but don't open yet, an input filestream;
    ifstream ifs;

        // make sure ofs opened OK
    if (!ofs)
    {
        cerr << "error opening " << fname << " for writing"<<endl;
        return 1;
    }

        // write some numbers to the file
    ofs << "10 20 30"<<endl;
    ofs << "40 51"<<endl;

        // close the file
    ofs.close();
    cout << "results written to file "<<fname<<endl;

        // now open the input filestream
    ifs.open(fname);

        // make sure it opened properly
    if (ifs)
        cout << "opening file "<<fname<<" in ifstream ifs succeeded"<<endl;
    else
    {
        cerr << "error:  cannot open file "<<fname<<" for reading!"<<endl;
        return 1;
    }

        // read the first number in
    ifs >> num;

        // while file stream is valid (i.e., we haven't reached the end of the file)
    while (ifs)
    {
        // add in, and count, last number
        sum += num;
        npts++;

        // a debugging print statement to make sure things are working properly
        // remove this when program is tested and working properly!!!
        cout << "in loop: num, sum, npts = "<< num << " " << sum <<" "<< npts <<endl;

        // and read in next data point
        ifs >> num;
    }

    if (npts == 0)
        cerr << "error:  no data read in!"<<endl;
    else
    {
        avg = sum / npts;
        cout << "average of "<<npts<<" numbers is:  "<<avg << endl;
    }
    
    ifs.close();    // close the file.
    
    return 0;
}

