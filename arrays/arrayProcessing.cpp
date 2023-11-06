#include <iostream>
#include <iomanip>
#include <fstream> // for ifStream and ofstream

using namespace std;

int main()
{
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numbers2[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0; // Loop counter variable

    // ++ Operators
    cout << endl;
    cout << endl;
    cout << "++ Operators" << endl;
    cout << "numbers[count]: ";
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << numbers[count] << " ";
    }

    cout << endl;
    cout << "++numbers[count]: ";
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << ++numbers[count] << " ";
    }

    cout << endl;
    cout << "numbers[count]++: ";
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << numbers[count]++ << " ";
    }

    cout << endl;
    cout << "numbers[++count]: ";
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << numbers[++count] << " ";
    }

    cout << endl;
    cout << "numbers[count]++: ";
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << numbers[count++] << " ";
    }

    // -- Operators
    cout << endl;
    cout << endl;
    cout << "-- Operators" << endl;
    cout << "numbers2[count]: ";
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << numbers2[count] << " ";
    }

    cout << endl;
    cout << "--numbers2[count]: ";
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << --numbers2[count] << " ";
    }

    cout << endl;
    cout << "numbers2[count]--: ";
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << numbers2[count]-- << " ";
    }
    cout << endl;
    cout << "numbers2[count]-- After: ";
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << numbers2[count] << " ";
    }

    // INFINITY LOOP
    // cout << endl;
    // cout << "numbers2[--count]: ";
    // for (count = 0; count < ARRAY_SIZE; count++)
    // {
    //     cout << numbers2[--count] << " ";
    // }

    // INFINITY LOOP
    // cout << endl;
    // cout << "numbers2[count--]: ";
    // for (count = 0; count < ARRAY_SIZE; count++)
    // {
    //     cout << numbers2[count--] << " ";
    // }

    return 0;
}