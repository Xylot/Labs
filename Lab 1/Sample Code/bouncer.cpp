/*  name:       John Smith
                worked with Fred Young
    course:     ECE 1305-004, spring 2015
    assignment: Lab 01, part 1

    Description:  a bouncer's decision
        if age >= 21, person can enter and drink
        if 18 <= age < 21, person can enter, but no alcohol
        if age < 18, person cannot enter.
*/

#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "How old are you? ";
    cin >> age;
    if (age >= 21)
    {
      cout << "Come on in, have a beer!" << endl;
    }
    else if (age >= 18)
    {
      cout << "Come on in, have a coke!" << endl;
    }
    else
    {
      cout << "Sorry, can't let you in!" << endl;
    }
  
    return 0;
}
