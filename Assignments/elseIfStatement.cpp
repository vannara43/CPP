#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    char employed,  // Currently employed, Y or N
        recentGrad; // Recent graduate, Y or N
    // Is the user employed and a recent graduate?
    cout << "Answer the following questions\n";
    cout << "with either Y for Yes or ";
    cout << "N for No.\n";
    cout << "Are you employed? ";
    cin >> employed;
    cout << "Have you graduated from college ";
    cout << "in the past two years? ";
    cin >> recentGrad;
    // Determine the user's loan qualifications.
    if (employed == 'Y')
    {
        if (recentGrad == 'Y') // Nested if
        {
            cout << "You qualify for the special ";
            cout << "interest rate.\n";
        }
        else // Not a recent grad, but employed
        {
            cout << "You must have graduated from ";
            cout << "college in the past two\n";
            cout << "years to qualify.\n";
        }
    }
    else // Not employed
    {
        cout << "You must be employed to qualify.\n";
    }

    return 0;
}