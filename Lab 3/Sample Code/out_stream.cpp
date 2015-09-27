/*
 * io.cpp
 *
 *  Created on: Feb 12, 2013
 *      Author: icsf
 *
 *      Sample File Output program
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
    string words, more_words;       // declare two variables named "words" and "more_words"
                                    //      of type string
	ofstream outfs;                 // declare a variable named "outfs" of type ofstream

    words="The quick brown fox jumps over the lazy dog.";
    more_words="The lazy dog snaps at the fox, but just gets a mouthful of the fox's tail.";

        // open a file for writing
        // open the file (connected to file "dogfox.txt"), and make sure it opened properly
	outfs.open("dogfox.txt");

	if (!outfs)
	{
		cout << "error opening file dogfox.txt"<<endl;
		return -1;
	}

		// output some stuff
        // note that writing to a file is the same as writing to the console,
        // except we've changed from cout to an output file stream, outfs, that we created above.
	outfs << "The word on the street is: "<<endl;
	outfs << words << endl << more_words << endl;

        // and write something to the console so the user knows the program ran.
	cout << "output was written to file 'dogfox.txt'"<<endl;
		// close the file
	outfs.close();
    
    return 0;
}
