#include <iostream>

using namespace std;

// Function prototype
int factorial(int n);

int main()
{
    cout << "The factorial of 5 is "
         << factorial(5) << endl;
    return 0;
}

int factorial(int n)
{
    if (n == 0) // Base case
        return 1;
    else // Recursive Case
        return n * factorial(n - 1);
}