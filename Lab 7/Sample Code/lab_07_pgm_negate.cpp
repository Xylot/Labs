#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

string get_filename( );
void readPGM(string fname, int &nc, int &nr, int &mv, int * &pix);
void negatePGM(int nc, int nr, int mv, int *pix);
void writePGM(string fname, int nc, int nr, int mv, int *pix);

//.......................................

int main( )
{
    int ncols=0, nrows=0, maxval=255;
    int *pix = NULL;        // instead of static int pix[1024*1024];
    string filename = get_filename( );
    
    readPGM(filename, ncols, nrows, maxval, pix);
    negatePGM(ncols, nrows, maxval, pix);
    writePGM("neg_"+filename, ncols, nrows, maxval, pix);
    
    // add code to delete the pixel array here!
}

//.......................................

    // get the filename of an existing file.
string get_filename( )
{
    bool ok = false;
    string fn = "";
    do
    {
        if (fn.size()==0) cout << "filename? ";
        else cout << "can't open "<<fn<<". re-enter filename: ";
        cin >> fn;
        ifstream ifs(fn);       // make sure we can open the file.
        if (ifs) ok = true;
    } while (!ok);
    return fn;
}
    
//............................write these two functions:

//readPGM:  opens file, reads header, allocates pixel array, reads in pixels.
//note that nc, nr, mv and pix are all passed by reference.
void readPGM(string fname, int &nc, int &nr, int &mv, int * &pix)
{
    // you need to write this!
}

//.......................................

//writePGM:  opens output file, outputs header line, outputs pixel array.
void writePGM(string fname, int nc, int nr, int mv, int *pix)
{
    // you need to write this !
}
//.......................................

//negatePGM:  note that pix is passed by value.  but since it is a pointer,
//we can still modify the pixel array by indexing it.  why?
void negatePGM(int nc, int nr, int maxval, int *pix)
{
    for (int r=0;r<nr;r++)
        for (int c=0;c<nc;c++)
            pix[r*nc + c] = maxval - pix[r*nc + c];
}
