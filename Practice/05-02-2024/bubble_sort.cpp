#include <iostream>

using namespace std;

// Function prototypes
void sortArray(int[], int);
void showArray(const int[], int);

/* SORT FUNCTION */
void sortArray(int array[], int size)
{
    bool swap; // Declare bool swap;
    int temp;  // Declare int temp;
    do
    {
        swap = false; // set swap = false;

        /* FOR LOOP: COMPARE ELEMENTS AND SORT */
        for (int i = 0; i < (size - 1); i++) // use for loop: for (int i = 0; i < (size - 1); i++)
        {
            if (array[i] > array[i + 1]) // array[i] is greater than array[i+1]
            {
                temp = array[i];         // temp copys value of array[i] because its greater than 2nd operand
                array[i] = array[i + 1]; // swaps 2nd operand to current position for index
                array[i + 1] = temp;     // array[i+1] takes in the temp value which is greater
                swap = true;             // lets the do-while know that a swap has been made
            }
        }
    } while (swap);
}

void showArray(const int array[], int size)
{
    // Use for loop to display array elements
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Main Function
int main()
{
    int values[6] = {7, 2, 3, 8, 9, 1};   // Array of unsorted values
    cout << "The unsorted values are:\n"; // Display the values.
    showArray(values, 6);                 // Call showArray(values, 6);
    sortArray(values, 6);                 // Call sortArray(values, 6);
    cout << "The sorted values are:\n";
    showArray(values, 6); // Call showArray(values, 6); again
    return 0;
}
