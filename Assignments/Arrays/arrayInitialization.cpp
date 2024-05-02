#include <iostream>
#include <iomanip>
#include <fstream> // for ifStream and ofstream

using namespace std;

int main()
{
    const int ARRAY_SIZE = 10;                                // Array Size
    int numbers[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Array with initialization list
    char characters[ARRAY_SIZE] = {'A', 65, 'B', 66};
    string strings[ARRAY_SIZE] = {"string 1", "string 2", "string 3"};
    double doubles[ARRAY_SIZE] = {1.0, 1.5, 2.0, 2.5, 3.0};

    /************************************************************************
     * does not provide a way to skip elements                              *
     * int numbers2[ARRAY_SIZE] = {0, 1, 2, , 4, , 6, 7, 8, 9};             *
     ************************************************************************/
    int count = 0; // Loop counter variable

    // Read the numbers from the file into the array
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << doubles[count] << endl;
    }

    return 0;
}