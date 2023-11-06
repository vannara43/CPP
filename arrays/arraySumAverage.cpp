#include <iostream>

using namespace std;

int main()
{
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0; // Loop counter variable
    int total = 0; // Initialize Accumulator
    double average;

    for (count = 0; count < ARRAY_SIZE; count++)
    {
        total += numbers[count];
    }

    average = total / ARRAY_SIZE;
    cout << "Total: " << total << endl;
    cout << "Size: " << ARRAY_SIZE << endl;
    cout << "Average: " << average << endl;

    return 0;
}