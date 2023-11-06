#include <iostream>
#include <string>
using namespace std;

// DECLARE FUNCTION PROTOTYPES
void showArray(string names[], int arrSize);
void selectionSort(string names[], int arrSize);

int main()
{
    // DECLARE VARIABLES
    const int NUM_NAMES = 20;                                  // Array size
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", // String Array
                               "Allen, Jim", "Griffin, Jim",
                               "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill",
                               "Allison, Jeff", "Looney, Joe",
                               "Wolfe, Bill", "James, Jean",
                               "Weaver, Jim", "Pore, Bob",
                               "Rutherford, Greg", "Javens, Renee",
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth"};

    // CALL FUNCTION showArray()
    cout << "\nThe unsorted values are: " << endl;
    showArray(names, NUM_NAMES);

    // CALL FUNCTION selectionSort()
    selectionSort(names, NUM_NAMES);

    cout << "\nThe sorted values are: " << endl;
    showArray(names, NUM_NAMES);

    // END OF PROGRAM
    return 0;
}

/**************************************************************
 * Definition of function showArray.                          *
 * This function displays the contents of array. size is the  *
 * number of elements.                                        *
 **************************************************************/
void showArray(string names[], int arrSize)
{
    // FOR LOOP: Display names array
    for (int i = 0; i < arrSize; i++)
    {
        cout << names[i] << endl;
    }
}

/**************************************************************
 * Definition of function selectionSort.                      *
 * This function performs an ascending order selection sort on*
 * names. arrSize is the number of elements in the array.     *
 **************************************************************/
void selectionSort(string names[], int arrSize)
{
    int startScan = 0; // This variable will start the scan at 0
    int minIndex;      // Store the index with lowest value
    string minValue;   // Store the lowest value

    // FOR LOOP:
    for (startScan = 0; startScan < (arrSize - 1); startScan++)
    {
        minIndex = startScan;        // stores as lowest index and continues
        minValue = names[startScan]; // stores as lowest value and continues

        // FOR LOOP: Marks the 2nd value and compares with the first
        for (int index = startScan + 1; index < arrSize; index++) // Index starts on element 1
        {
            // IF STATEMENT: Checks the values
            if (names[index] < minValue) // Checks for lower value
            {
                minValue = names[index]; // Swaps Value
                minIndex = index;        // Swap Index
            }
        }
        names[minIndex] = names[startScan]; // Assigns the newly swap values
        names[startScan] = minValue;        // Assigns the newly swap index

        // Loop ends and increments
    }
}