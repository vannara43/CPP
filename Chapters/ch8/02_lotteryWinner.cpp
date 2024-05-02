// Vannara Thong CSC5 Chapter 8, p.487, #2
/**************************************************************
 *
 * WIN THE LOTTERY
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
    int SIZE = 10; // Size of array
    int arr[SIZE] = {13579, 26791, 26792, 33445, 55555,
                     62483, 77777, 79422, 85647, 93121};
    int userNumber;       // INPUT - user number
    bool outcome = false; // outcome if user win or lose

    cout << "Enter lucky number: "; // Prompts user to enter data
    cin >> userNumber;              // User enter data

    // FOR LOOP: Checks if user number
    for (int i = 0; i < SIZE; i++)
    {
        if (userNumber = arr[SIZE]) // chekcs if number match lottery numbers
        {
            outcome = true; // it is matching
        }
    }

    if (outcome) // checks outcome
    {
        cout << "You won!";
    }
    else
    {
        cout << "No matches.";
    }

    // END OF PROGRAM
    return 0;
}