#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void get_filenames(string &infname, string &outfname);
    
//...............put your prototypes here...................


//..........................................................

int main (void)

{

    string infilename, outfilename;
            // for image:
    string type;
    int ncols=0, nrows=0, maxval=0;
    static int pixels[1024 * 1024] = {0};       // large array needs to be static!
    
    get_filenames(infilename, outfilename);
    
    cout << "reading "<<infilename<<", displaying, and copying to "<<outfilename<<endl;
    
    // Read the PGM file
 
    readPGM(infilename, type, ncols, nrows, maxval, pixels);
    if (ncols*nrows == 0)       // if image array is size 0, problem!
    {
        cout << "error reading file "<<infilename<<endl;
        return 0;
    }   
 
     // Display the PGM header info and the pixel array
     
//...........add your function call to printPGM here!

    
    // Save PGM file

//...........add your function call to savePGM here! 


     return 0;
}


        // get input & output filenames, verify input file can be read
        // outputs:  infname and outfname, both strings.
void get_filenames(string &infname, string &outfname)
{
    cout << "Enter the name of the PGM file: ";
    cin >> infname;
    ifstream ifs(infname.c_str());   // verify file is readable
    if (!ifs)
    {
        cout << "Error:  can't open "<<infname<< " for reading "<<endl;
        exit(1);    // bail out of program altogether.
    }
    ifs.close();
    
    cout << "enter the outputname to copy the PGM to: ";
    cin >> outfname;
    ofstream ofs(outfname.c_str());   // verify we can write to the output file
    if (!ofs)
    {
        cout << "Error:  can't open "<<outfname<< " for writing "<<endl;
        exit(1);    // bail out of program altogether.
    }
    ofs.close();    // close it.  you'll open it later in savePGM
}

//...............put your prototypes here...................


