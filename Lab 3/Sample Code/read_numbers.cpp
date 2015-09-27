/* Sample program to show how to read
    data from a file.
    It opens a file called "numbers.txt" and reads numbers
    until it reaches the end of the file.
    It prints the number of entries in the file and the
    average of the numbers read in.
*/

#include <iostream>
#include <fstream>      // hdr file for input and output filestreams

using namespace std;

int main(void)
{
    int n = 0;
    double x, sum=0, avg;
    ifstream ifs;

    cout << "This program opens a file called 'numbers.txt', reads numbers"<<endl;
    cout << "from the file, and outputs the count and average.  "<<endl;
    cout << "A challenge for beginners is to know where the input file"<<endl;
    cout << "needs to be located.  The following statement will print out"<<endl;
    cout << "the folder where I will look for the file.  If it's not there"<<endl;
    cout << "I won't be able to do the job"<<endl<<endl;

    system("cd");       // run the DOS command 'cd' . which prints the current working directory.
                        // if on a Mac or Linux machine, use 'system("pwd");' instead.
    cout << endl;

    ifs.open("numbers.txt");        // open the data file
    if (!ifs)                       // make sure it opened properly.
    {
        cerr << "error:  can't find the file 'numbers.txt'.  Please put it in the"<<endl;
        cerr << "directory listed above and rerun this program"<<endl;
        exit(1);
    }

    while (ifs)         // loop while the input stream is valid
                        // (it will become invalid when we reach the end of the file)
    {
        ifs >> x;           // try to read a number into x
        if (! ifs) break;   // bail out if we reached the end of the file.
							// "break" exits you from the innermost loop.  
							// See textbook, pp 64-65, under "branching mechanisms

        n++;                // count it
        sum += x;           // add it
        cout << "number read in:  "<<x<<"  total so far: "<<sum << endl;     // debug print statement
                                                                             // remove when program is tested and working!
    }

    cout << n << " numbers read in"<<endl;
    if (n > 0)              // can't calculate an average if we didn't read anything...
    {
        avg = sum / n;
        cout << "total:  " << sum << endl;     // output sum in a field 6 chars wide
        cout << "avg:    " << avg << endl;
    }
    else
        cout << "couldn't read anything from the file"<<endl;
            // note:  we don't need braces around the else clause here because
            // the clause is a single statement.  We could have used braces, though,
            // and it would have compiled just fine.

    return 0;
}

