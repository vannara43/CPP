#include <iostream>

using namespace std;

int main()
{
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE] = {4, 10, 2, 30, 4, 5, 60, 7, 8, 9};
    int count = 0;           // Loop counter variable
    int lowest = numbers[0]; // Initialize Accumulator

    for (count = 0; count < ARRAY_SIZE; count++)
    {
        if (numbers[count] < lowest)
        {
            lowest = numbers[count];
        }
    }
    cout << "Lowest: " << lowest;

    return 0;
}