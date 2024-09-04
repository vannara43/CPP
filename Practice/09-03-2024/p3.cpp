// Practice 3: A Program for Local and Global Variables

#include <iostream>
using namespace std;

// Global Variables
int x = 9, w = 6;
float z;

int main()
{
    int x = 3;
    float z;
    cout << "Local and Global Variables in C++ \n"
         << endl;
    cout << "The value of z = " << x + w << endl;
    return 0;
}
