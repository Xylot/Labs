#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
/* program to demonstrate function pass-by-reference and void functions.

    this program asks the user for a word, then repeatedly strips off the first letter of the word until it is empty.
    
    There are two versions of this function:  one which takes 3 parameters (one input, 2 output)
    and one which takes 2 parameters (one input/output, one output)
*/

// function prototypes.  Look like functions, but without bodies.

void trim_word(string w_in, string &w_out, char &c);  // removes 1st char from w_in, returns results in w_out and c
void trim_word2(string &w, char &c);                 // same as above, but w is both input and output.

//..............................................................

int main(void)
{
    string word, w2;
	string w3 = "Rumplestilstkin";
     
    cout << "enter a word ";
    cin >> word;
    w2 = word;     // copy word into w2 & w3 for later use.
    
    cout << "splitting "<<word<<endl;
    while (word.size() > 0)
    {
        string w;
        char c;
        trim_word(word, w, c);      // w & c are changed by function.
        cout << "word, char: "<<w<<" "<<c<<endl;
        word = w;
    }
    cout << endl;
    
    cout << "splitting "<<w2<<endl;       // do it again, using trim_word2
    while (w2.size() > 0)
    {
        char c;
        trim_word2(w2, c);          // w2 and c are changed by function
        cout << "word, char: "<<w2<<" "<<c<<endl;
    }
    cout << endl;
    
			// And, just to show that we can call a function multiple times, with
			// different values each time, let's split Rumplestiltskin using trim_word2(...)

    cout << "splitting "<<w3<<endl;       // do it again, using trim_word2
    while (w3.size() > 0)
    {
        char c;
        trim_word2(w3, c);          // w2 and c are changed by function
        cout << "word, char: "<<w3<<" "<<c<<endl;
    }
    cout << endl;
    
    return 0;
}

//..............................................................

/* function to split a word;  removes first char, returns char and remaining string
    inputs:  string    w_in    word to split (value parameter)
    outputs: string    w_out   remainder of word   (reference param)
             char      c       first char      (reference param)
    returns:                nothing (is void)
*/
void trim_word(string w_in, string &w_out, char &c)  // removes 1st char from w_in, returns results in w_out and c
{
    c = w_in[0];        // get first char.
    w_out = w_in.substr(1);   // get rest of word.
    return;
}


//..............................................................

/* function to split a word;  removes first char, returns char and remaining string
    inputs:  string    w       word to split
    outputs: string    w       remainder of word   (w is both input and output here, so is reference param)
             char      c       first char      (reference param)
    returns:                nothing (is void)
*/
void trim_word2(string &w, char &c)                 // same as above, but w is both input and output.
{
    c = w[0];        // get first char.
    w = w.substr(1);   // get rest of word.
    return;
}

