#include <iostream>
#include <istream>
#include <string>

using namespace std;

int main()
{
    /* Input Integer*/
    int inputInteger;                                // To store the user's input.
    cout << "Enter an integer: ";                    // Prompt for user to enter an integer.
    cin >> inputInteger;                             // Get the user's input and store it in 'inputInteger'.
    cout << "You entered: " << inputInteger << endl; // Display input back to the user.

    /* Input Strings*/
    string inputString;                                 // To store the user's input.
    cout << "Enter a string: ";                         // Prompt for user to enter a string.
    cin.ignore();                                       // Ignore the extra newline character from previous input
    getline(cin, inputString);                          // Get the user's entire line of input and store it in 'inputString'.
    cout << "You entered: \"" << inputString << "\"\n"; // Display input back to the user.
    return 0;
}