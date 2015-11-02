#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

bool get_filenames(string &infname, string &outfname);
    
//...............put your prototypes here...................


//..........................................................

int main (void)

{

    string infilename, outfilename;
            // for image:
    string type;
    int ncols=0, nrows=0, maxval=0;
    int pixels[512 * 512] = {0};
    
            // get input & output filenames, or bail out if problem
    if (!get_filenames(infilename, outfilename))
    {
        cout << "Error opening input or output file "<<endl;
        return 1;
    }
    
    cout << "reading "<<infilename<<", displaying, and copying to "<<outfilename<<endl;
    
    // Read the PGM file.  as the code below suggests, set ncols & nrows to zero in the function
    //  and let that be a flag that there is a problem reading the file.
    // Or, you could have your program return a boolean, as
    // get_filenames(...) does, to flag that there was a problem.  If you do, then modify
    // the call to read something like
    // if (!readPGM(...) {output error message and exit}
 
    readPGM(infilename, type, ncols, nrows, maxval, pixels);
    if (ncols*nrows == 0)       // if image array is size 0, problem!
    {
        cout << "error reading file "<<infilename<<endl;
        return 1;
    }   
 
     // Display the PGM header info and the pixel array
     
//...........add your function call to printPGM here!

    
    // Save PGM file

//...........add your function call to savePGM here! 


     return 0;
}


        // get input & output filenames, verify input file can be read
        // outputs:  infname and outfname, both strings.
        // return value:
        //      true        if we can open the input & output files properly
        //      false       if there is a problem.  This allows the calling code
        //                      to decide the appropriate response if there is a problem.
bool get_filenames(string &infname, string &outfname)
{
    cout << "Enter the name of the PGM file: ";
    cin >> infname;
    ifstream ifs(infname.c_str());   // verify file is readable
    if (!ifs)
    {
        cout << "Error:  can't open "<<infname<< " for reading "<<endl;
        return(false);    // bail out if problem.
    }
    ifs.close();
    
    cout << "enter the outputname to copy the PGM to: ";
    cin >> outfname;
    ofstream ofs(outfname.c_str());   // verify we can write to the output file
    if (!ofs)
    {
        return false;    // bail out if problem.
    }
    ofs.close();    // close it.  you'll open it later in savePGM
}

//...............put your prototypes here...................


