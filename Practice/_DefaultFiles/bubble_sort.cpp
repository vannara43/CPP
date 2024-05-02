/* This program uses the bubble sort algorithm to sort an array in ascending order. */

#include <iostream>

using namespace std;

/* FUNCTION PROTOTYPES: MUST DECLARE TO CALL FUNCTIONS*/
void sortArray(int[], int);
void showArray(const int[], int);

/* MAIN FUNCTION */
int main()
{
    int values[6] = {7, 2, 3, 8, 9, 1}; // Array of unsorted values

    /* DISPLAY VALUES OF ARRAY */
    cout << "Unsorted values:\n"; // Display the values.
    showArray(values, 6);         // Show array values.
    sortArray(values, 6);         // Sort the values.
    cout << "Sorted values:\n";   // Display the values.
    showArray(values, 6);         // Show sorted array values.

    /* END OF PROGRAM */
    return 0;
}

/* SORT ARRAY: BUBBLE SORT ALGORITHM */
void sortArray(int array[], int size) //  Function takes an array and its size as arguments.
{
    bool swap; //  Set variable for swapping needed flag. For Do-While Loop condition!
    int temp;  //  Temporary storage location for array[i].
    do         // Begin loop that will continue until no more swaps
    {
        swap = false; // Reset the swapping flag.

        /* FOR LOOP: COMPARE ELEMENTS AND SORT */
        for (int i = 0; i < (size - 1); i++) // (size-1) is used because we are comparing i and i+1
        {
            if (array[i] > array[i + 1]) // Swap if array[i] is  greater than array[i+1]
            {
                temp = array[i];         // 1. Store array[i] in temp
                array[i] = array[i + 1]; // 2. Put array[i+1] into array[i]
                array[i + 1] = temp;     // 3. Put temp into array[i+1]
                swap = true;             // 4. Indicate a swap was made.
            }
        }
    } while (swap); //  Continue looping if a swap was made.
}

// Function to display an array's contents
void showArray(const int array[], int size)
{ // Output each element of array.
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}