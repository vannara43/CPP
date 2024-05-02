#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 10;
    int arr1[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool arrEqual = true; // Flag variable
    int count = 0;

    // Determine whether the elements contain the same data.
    while (arrEqual && count < SIZE)
    {
        if (arr1[count] != arr2[count])
        {
            arrEqual = false;
        }
        count++;
    }

    if (arrEqual)
    {
        cout << "The arrays are equal.\n";
    }
    else
    {
        cout << "The arrays are NOT equal.\n";
    }

    return 0;
}