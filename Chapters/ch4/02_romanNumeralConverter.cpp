// Vannara Thong CSC5 Chapter 4, P. 220, #2
//
/**************************************************************
 *
 * CONVERT NUMERICAL NUMBER TO ROMAN
 * ____________________________________________________________
 * This program computes numberical numbers to roman
 * characters. This program converts a number between 1 and 10
 * to its Roman numeral representation.
 *
 *
 * Computation is based on the formula:
 * Switch Case
 * ____________________________________________________________
 * INPUT
 * inputNumber		    : Input number for 1 to 10
 *
 *
 * OUTPUT
 * N/A                  : N/A
 *
 **************************************************************/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLE DECLARTION
    int inputNumber;

    // USER INPUT
    cout << "Enter a number between 1 and 10: ";
    cin >> inputNumber;

    // SWITCH CASE STATEMENT FOR INPUT NUMBER
    switch (inputNumber)
    {
    case 1:
        cout << "I" << endl;
        break;
    case 2:
        cout << "II" << endl;
        break;
    case 3:
        cout << "III" << endl;
        break;
    case 4:
        cout << "IV" << endl;
        break;
    case 5:
        cout << "V" << endl;
        break;
    case 6:
        cout << "VI" << endl;
        break;
    case 7:
        cout << "VI" << endl;
        break;
    case 8:
        cout << "VI" << endl;
        break;
    case 9:
        cout << "IX" << endl;
        break;
    case 10:
        cout << "X" << endl;
        break;

    default:
        cout << "Do not accept a number less than 1 or greater than 10." << endl;
        break;
    }
    return 0;
}