#include <iostream>
#include <iomanip>
#include <fstream> // for ifStream and ofstream

using namespace std;

int main()
{
    const int ARRAY_SIZE = 10;                                // Array Size
    int numbers[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Array with initialization list
    int count = 0;                                            // Loop counter variable

    ofstream outputFile; // Input File Stream Object

    // Open the file
    outputFile.open("D:\\Repositories\\CPP\\arrays\\outputFile.txt");

    // Read the numbers from the file into the array
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        outputFile << numbers[count] << endl;
    }

    // Close the file
    outputFile.close();

    // Display the numbers read:
    cout << "The numbers were saved to the file.";

    return 0;
}