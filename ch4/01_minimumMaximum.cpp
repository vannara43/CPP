// Vannara Thong CSC5 Chapter 4, p.220, #1
//
/**************************************************************
 *
 * Output which is the bigger number.
 * ____________________________________________________________
 * Compare two numbers and displays the bigger number.
 *
 *
 * Computation is based on the formula:
 * inputNumber1 > inputNumber2
 * ____________________________________________________________
 * INPUT
 * inputNumber1              : Number 1
 * inputNumber2              : Number 2
 *
 *
 * OUTPUT
 * N/A                       : N/A
 *
 **************************************************************/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLE DECLARATION
    int inputNumber1;
    int inputNumber2;

    // USER INPUT
    cout << "Enter two numbers: ";
    cin >> inputNumber1 >> inputNumber2;

    // DECISION STATEMENT TO CHECK WHICH NUMBER IS BIGGER
    if (inputNumber1 > inputNumber2)
    {
        cout << inputNumber1 << " is bigger." << endl;
    }
    else
    {
        cout << inputNumber2 << " is bigger." << endl;
    }
    return 0;
}