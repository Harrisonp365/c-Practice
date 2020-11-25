#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

double getNumber();

int main()
{
    double x;

    while (true)
    {
        cout << "Enter a number or Press ENTER to exit. ";
        x = getNumber();

        if (x == 0.0)
            break;
        
        cout << "Square root of x is: " << sqrt(x) << endl;
    }
    return 0;
}

double getNumber()
{
    char s[100];

    cin.getline(s, 100);
    if (strlen(s) == 0)
        return 0.0;
    return atof(s);
} // If a user presses enter with no number this will give a default value of 0.0

