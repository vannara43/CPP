// Practice 4: A Program for User Input

#include <iostream>
using namespace std;
int main()
{
    // Declare Variables
    int x, y;

    // Display cout
    cout << "User Input \n"
         << endl;
    cout << "Insert a number: " << endl;
    cin >> x; // Input
    cout << "Insert second number: " << endl;
    cin >> y; // Input
    cout << "You entered: " << x << " and " << y << endl;
    return 0;
}
