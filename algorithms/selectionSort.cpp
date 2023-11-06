// This program uses the selection sort algorithm to sort an
// array in ascending order.
#include <iostream>
using namespace std;
// Function prototypes
void selectionSort(int[], int);
void showArray(const int[], int);
int main()
{
    // Define an array with unsorted values
    const int SIZE = 6;
    int values[SIZE] = {5, 7, 2, 8, 9, 1};
    // Display the values.
    cout << "The unsorted values are\n";
    showArray(values, SIZE);
    // Sort the values.
    selectionSort(values, SIZE);
    // Display the values again.
    cout << "The sorted values are\n";
    showArray(values, SIZE);
    return 0;
}

//**************************************************************
// Definition of function selectionSort. *
// This function performs an ascending order selection sort on *
// array. size is the number of elements in the array. *
//**************************************************************
void selectionSort(int array[], int size)
{
    int startScan, minIndex, minValue;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];

        // Display list
        cout << "list now: ";
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;

        // Start checking for swaps
        for (int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                cout << "Swapping..." << array[index] << " and " << minValue << endl;
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

//**************************************************************
// Definition of function showArray. *
// This function displays the contents of array. size is the *
// number of elements. *
//**************************************************************
void showArray(const int array[], int size)
{
    for (int count = 0; count < size; count++)
        cout << array[count] << " ";
    cout << endl;
}