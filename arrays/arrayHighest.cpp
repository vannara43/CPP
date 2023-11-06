#include <iostream>

using namespace std;

int main()
{
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0;            // Loop counter variable
    int highest = numbers[0]; // Initialize Accumulator

    for (count = 0; count < ARRAY_SIZE; count++)
    {
        if (numbers[count] > highest)
        {
            highest = numbers[count];
        }
    }
    cout << "Highest: " << highest;

    return 0;
}