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
        // use for loop: for (int i = 0; i < (size - 1); i++)
        {
            // use if statement: (array[i] > array[i + 1])
            {
                // 1. use temp = array[i];
                // 2. use array[i] = array[i + 1];
                // 3. use array[i + 1] = temp;
                // 4. use swap = true;
            }
        }
    } while (swap);
}

void showArray(const int array[], int size)
{
    // Use for loop to display array elements
    cout << endl;
}

// Main Function
int main()
{
    int values[6] = {7, 2, 3, 8, 9, 1};
    cout << "Unsorted values:\n";
    // Call showArray(values, 6);
    // Call sortArray(values, 6);
    cout << "Sorted values:\n";
    // Call showArray(values, 6);
    return 0;
}
