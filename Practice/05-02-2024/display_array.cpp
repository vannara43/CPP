#include <iostream>

using namespace std;

int main()
{
    int const SIZE = 5;
    int array[SIZE] = {5, 3, 9, 8, 1};

    for (int i = 0; i < SIZE; i++) // loops until SIZE value is reached
    {
        cout << array[i] << " "; // prints each elements
    }
    return 0;
}