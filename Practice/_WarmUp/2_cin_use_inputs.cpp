#include <iostream>
#include <istream>
#include <string>

using namespace std;

int main()
{
    /* INPUT INTEGERS */
    int inputInteger;
    cout << "Enter an integer: ";
    // Use cin >> 'inputInteger'.
    cout << "You entered: " << inputInteger << endl;

    /* INPUT STRINGS */
    string inputString;
    cout << "Enter a string: "; // Prompt for user to enter a string.
    // Use cin.ignore();
    // Use getline(cin, inputString);
    cout << "You entered: \"" << inputString << "\"\n";
    return 0;
}