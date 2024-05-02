// Vannara Thong CSC5 Chapter 7, p.444, #1
//
/**************************************************************
 *
 * DISPLAY THE HIGHEST AND LOWEST NUMBER
 * ____________________________________________________________
 * This program accepts user input to store data into an array.
 * The array will be checked and display the highest & lowest
 * number.
 *
 * Computation is based on the formula:
 * arr[i] > highest and arr[i] < lowest
 * ____________________________________________________________
 * INPUT
 * arr                        : User input data stored
 *
 *
 * OUTPUT
 * highest                    : Highest number
 * lowest                     : Lowest number
 * total                      : Total of number
 *
 **************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

// FUNCTION PROTOTYPE DECLARATION
void findHighest(int[], int); // Finds the highest number
void findLowest(int[], int);  // Finds the lowest number

int main()
{
    // VARIABLE DECLARATION
    const int SIZE = 10; // Size Amount for array
    int arr[SIZE];       // INPUT - Array will store values

    // FOR LOOP: ENTER DATA INTO ARRAY
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter a value for element " << i << " : ";
        cin >> arr[i];
    }

    cout << endl;
    findHighest(arr, SIZE); // Calls findHighest Function
    cout << endl;
    findLowest(arr, SIZE); // Calls findLowest Function

    // END OF PROGRAM
    return 0;
}

/**************************************************************
 * Definition of function findHighest.                        *
 * This function receives data from array and calculates the  *
 * highest value. The function will display highest.          *
 **************************************************************/
void findHighest(int arr[], int SIZE)
{
    // VARIABLE DECLARATION
    int highest = arr[0];

    // FOR LOOP: COMPARES HIGHEST NUMBER
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > highest) // Checks if value is greater
        {
            highest = arr[i]; // Highest will equal to higher number
        }
    }

    // DISPLAY HIGHEST
    cout << "The highest is " << highest;
}

/**************************************************************
 * Definition of function findLowest.                         *
 * This function receives data from array and calculates the  *
 * lowest value. The function will display lowest.            *
 **************************************************************/
void findLowest(int arr[], int SIZE)
{
    // VARIABLE DECLARATION
    int lowest = arr[0];

    // FOR LOOP: COMPARES LOWEST NUMBER
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] < lowest) // Checks if value is lower
        {
            lowest = arr[i]; // Lowest is equal to lowest number
        }
    }
    // DISPLAY LOWEST
    cout << "The lowest is " << lowest;
}