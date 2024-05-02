// Vannara Thong CSC5 Chapter 8, p.487, #1
/**************************************************************
 *
 * VALIDATE ACCOUNT NUMBER
 * ____________________________________________________________
 * This program accepts an account number and display if the
 * account number is valid in the system.
 *
 * Computation is based on the formula:
 * inputNumber == acctNum[i]
 * ____________________________________________________________
 * INPUT
 * inputNumber                : User account number
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
    // VARIABLE DECLARATION
    const int SIZE = 18; // Size for array
    int acctNum[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                         8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                         1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    int inputNumber = 0;      // INPUT - User input number
    bool found = false;       // Check if acct number is found
    bool activeSearch = true; // Check if user search is active

    // DO-WHILE: USER INPUT
    do
    {
        cout << "Enter an account number(Enter '-1' to exit): ";
        cin >> inputNumber;

        // FOR LOOP: Checks if account number exist in system
        for (int i = 0; i < SIZE; i++)
        {
            if (inputNumber == acctNum[i])
            {
                found = true; // if number exist, found is true
            }
        }

        // CHECK IF ACCT# IS FOUND
        if (inputNumber == -1)
        {
            activeSearch = false; // this will exit program
            cout << "Thank you for using the program. Goodbye!" << endl;
        }
        else if (found) // prompts user that number is in system
        {
            cout << "Number is valid." << endl;
        }
        else // prompts user that number is not valid
        {
            cout << "Number is not valid. Please try again." << endl;
        }

    } while (!found && activeSearch == true); // continue search or until -1 is entered

    // END OF PROGRAM
    return 0;
}