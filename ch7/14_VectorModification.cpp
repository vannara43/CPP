// Vannara Thong CSC5 Chapter 7, p.448, #14
//
/**************************************************************
 *
 * SHOW MATCHING PINS
 * ____________________________________________________________
 * This program compares multiple pin numbers and produces
 * the result of the pin numbers.
 *
 *
 * Computation is based on the formula:
 * customerPIN[index] != databasePIN[index]
 * ____________________________________________________________
 * INPUT
 * N/A                          : N/A
 *
 *
 * OUTPUT
 * N/A                          : N/A
 *
 **************************************************************/
#include <iostream>
#include <vector>

using namespace std;

// DECLARE FUNCTION PROTOTYPE
bool testPIN(const vector<int>, const vector<int>);

int main()
{
    // VARIABLE DECLARATION
    vector<int> pin1{2, 4, 1, 8, 7, 9, 0}; // Numbers for pin 1
    vector<int> pin2{2, 4, 6, 8, 7, 9, 0}; // Numbers for pin 2
    vector<int> pin3{1, 2, 3, 4, 5, 6, 7}; // Numbers for pin 3

    if (testPIN(pin1, pin2)) // Calls Function testPIN
        cout << "Error: pin 1 and pin 2 report to be the same.\n";
    else
        cout << "Success: pin 1 and pin 2 are different.\n";

    if (testPIN(pin1, pin3)) // Calls Function testPIN
        cout << "ERROR: pin 1 and pin 3 report to be the same.\n";
    else
        cout << "SUCCESS: pin 1 and pin 3 are different.\n";

    if (testPIN(pin1, pin2)) // Calls Function testPIN
        cout << "SUCCESS: pin 1 and pin 1 report to be the same.\n";
    else
        cout << "ERROR: pin1 and pin1 report to be different.\n";

    // END OF PROGRAM
    return 0;
}

/**************************************************************
 * Definition of function testPIN.                            *
 * This function receives data from two arrays and compares   *
 * if the PINS are matching.                                  *
 **************************************************************/
bool testPIN(const vector<int> customerPIN, const vector<int> databasePIN)
{
    // FOR LOOP: Compares the two arrays and return true or false
    for (int index = 0; index < customerPIN.size(); index++) // Loops by array size
    {
        // IF STATEMENT: Compares both arrays and checks if they dont match
        if (customerPIN[index] != databasePIN[index]) // Checks if the arrays dont match
            return false;                             // Return false
    }

    // Return true
    return true;
}