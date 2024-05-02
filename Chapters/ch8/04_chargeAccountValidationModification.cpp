// Vannara Thong CSC5 Chapter 8, p.487, #4
/**************************************************************
 *
 * CHECK ACCOUNT NUMBER
 * ____________________________________________________________
 * This program accepts an account number and display if the
 * account number is valid in the system.
 *
 * Computation is based on the formula:
 * inputNumber == acctNum[middle]
 * ____________________________________________________________
 * INPUT
 * inputNumber                   : User input number
 *
 *
 * OUTPUT
 * N/A                           : N/A
 *
 **************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

// DECLARE FUNCTION PROTOTYPE
void selectionSort(int acctNum[], int SIZE);
bool binarySearch(int acctNum[], int SIZE, int inputNumber);

int main()
{
    // VARIABLE DECLARATION
    const int SIZE = 18; // Size for array
    int acctNum[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                         8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                         1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    int inputNumber = 0; // INPUT - User input number
    bool found = false;  // Check if acct number is found

    // USER INPUT
    cout << "Enter an account number: ";
    cin >> inputNumber;

    selectionSort(acctNum, SIZE); // call selectiosSort function

    found = binarySearch(acctNum, SIZE, inputNumber); // call binarySearch and store in found variable

    if (found) // check if found is true
    {
        cout << "Number is valid." << endl; // prompts user that number is valid
    }
    else
    {
        cout << "Number is not valid. Please try again." << endl; // prompts user that number is NOT valid
    }

    // END OF PROGRAM
    return 0;
}

/**************************************************************
 * Definition of function selectionSort.                      *
 * This function receives an array data and sorts from lowest *
 * highest inside of the array.                               *
 **************************************************************/
void selectionSort(int acctNum[], int SIZE)
{
    // DECLARE VARIABLE
    int minValue; // Stores min values
    int minIndex; // stores min index

    // FIRST LOOP: Current Elements
    for (int i = 0; i < (SIZE - 1); i++)
    {
        minValue = acctNum[i]; // Min Value assign to start
        minIndex = i;          // Min Index assign to start

        // SECOND LOOP: Other Elements
        for (int i2 = i + 1; i2 < SIZE; i2++)
        {
            if (acctNum[i2] < minValue) // COMPARISION
            {
                minValue = acctNum[i2]; // Swaps min value
                minIndex = i2;          // Swaps min index
            }
        }
        acctNum[minIndex] = acctNum[i]; // Assigns value to current element
        acctNum[i] = minValue;          // Assigns current element
    }
}

/**************************************************************
 * Definition of function binarySearch.                       *
 * This function receives an array data that is already sorted*
 * The function will perform a search to find wanted value.   *
 **************************************************************/
bool binarySearch(int acctNum[], int SIZE, int inputNumber)
{
    // DECLARE VARIABLE
    int first = 0,      // First index
        last = SIZE,    // Last index
        middle,         // Middle index
        position = -1;  // Position of element
    bool found = false; // Flag variable

    // WHILE LOOP: BINARY SEARCH
    while (!found && first <= last)
    {
        middle = (first + last) / 2;        // Get middle number
        if (inputNumber == acctNum[middle]) // Check if inputNumber matches
        {
            found = true;      // found is true
            position = middle; // position of found element
        }
        else if (inputNumber < acctNum[middle]) // If our number is less than current value
        {
            last = middle - 1; // Cut the higher half out
        }
        else
        {
            first = middle + 1; // Cut the lower half out
        }
    }

    // END OF FUNCTION
    return found;
}