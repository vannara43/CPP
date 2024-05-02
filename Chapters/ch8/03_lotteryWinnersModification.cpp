// Vannara Thong CSC5 Chapter 8, p.487, #3
/**************************************************************
 *
 * WIN THE LOTTERY(UPDATED)
 * ____________________________________________________________
 * This program accepts a 5 digit number and display if the
 * number is a winning lottery number.
 *
 * Computation is based on the formula:
 * userNumber = arr[SIZE]
 * ____________________________________________________________
 * INPUT
 * userNumber                 : User input data
 *
 *
 * OUTPUT
 * N/A                        : N/A
 *
 **************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int SIZE = 10;                                      // Size of array
    int arr[SIZE] = {13579, 26791, 26792, 33445, 55555, // List of winning lottery number
                     62483, 77777, 79422, 85647, 93121};
    int userNumber;      // INPUT - user number
    int first = 0;       // first index
    int last = SIZE - 1; // last index
    int middle;          // middle index
    int position = -1;   // position of found number
    bool found = false;  // flag variable

    // USER INPUT NUMBER
    cout << "Enter lucky number: "; // prompts to enter number
    cin >> userNumber;              // user inputs

    // WHILE LOOP: BINARY SEARCH
    while (!found && first <= last) // check if found is false and first is <= last
    {
        middle = (first + last) / 2;   // Calculate midpoint
        if (arr[middle] == userNumber) // mid value is found
        {
            found = true;      // value is found and true
            position = middle; // position of element
        }
        else if (arr[middle] > userNumber) // compares if user number is greater or less than middle number
        {
            last = middle - 1; // cut the last half
        }
        else
        {
            first = middle + 1; // cut the first half
        }

        if (found) // Check if found
        {
            cout << "You won! This value is found at element " << position;
        }
        else
        {
            cout << "No matches.";
        }
    }
    // END OF PROGRAM
    return 0;
}