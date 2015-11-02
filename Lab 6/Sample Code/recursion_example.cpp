#include <iostream>
#include <cmath>

using namespace std;

double my_pow(double x, int n); // returns x to the n power

int main(void)
{
    double a=2, a_fourth, a_minus_third;
    int n1 = 4, n2 = -3;

    a_fourth      = my_pow(a, n1);
    a_minus_third = my_pow(a, n2);

    cout << a << " to the "<< n1 << " power is "<< a_fourth << endl;
    cout << a << " to the "<< n2 << " power is "<< a_minus_third << endl;

    return 0;
}

double my_pow(double x, int n)
{
    if (n == 0 ) return 1;
    if (n == 1 ) return x;

    if (n  > 0) return x * my_pow(x, n-1);
    else        return 1.0 / (x * my_pow(x, abs(n)-1));
}

