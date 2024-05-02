#include <iostream>
#include <istream>
#include <string>

using namespace std;

int main()
{
    /* INPUT INTEGERS */
    int inputInteger; // stores input from user
    cout << "Enter an integer: ";
    cin >> inputInteger; // reads the input from user
    cout << "You entered: " << inputInteger << endl;

    /* INPUT STRINGS */
    string inputString;         // stores input from user
    cout << "Enter a string: "; // Prompt for user to enter a string.
    cin.ignore();               // Ignore the first character before reading the string
    getline(cin, inputString);  // stores entire line, including space to inputString
    cout << "You entered: \"" << inputString << "\"\n";
    return 0;
}