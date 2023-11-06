#include <iostream>
#include <iomanip>
#include <fstream> // for ifStream and ofstream

using namespace std;

int main()
{
    const int ARRAY_SIZE = 10; // Array Size
    int numbers[ARRAY_SIZE];   // Array with 10 elements
    int count = 0;             // Loop counter variable

    ifstream inputFile; // Input File Stream Object

    // Open the file
    inputFile.open("D:\\Repositories\\CPP\\arrays\\inFile.txt");

    // Read the numbers from the file into the array
    while (count < ARRAY_SIZE && inputFile >> numbers[count])
    {
        count++;
    }

    inputFile.close();

    // Display the numbers read:
    cout << "The numbers are: ";
    for (count = 0; count <= ARRAY_SIZE; count++)
    {
        cout << numbers[count] << " " << endl;
    }

    return 0;
}