#include <iostream>
using namespace std;

int square(int); // prototype for function square

int main()
{
    int a{10}; // value to square (local variable in main)

    int result{square(a)}; // calculate s squared and store in result

    cout << result << endl;
}

// returns the square of an integer
int square(int x)
{                 // x is a local variable
    return x * x; // calculate square and return result
}