// Vannara Thong CSC5 Chapter 5, p.294, #1
//
/**************************************************************
 *
 * DISPLAY THE TOTAL SUM OF INPUT NUMBER
 * ____________________________________________________________
 * This program accepts user input and get the sum of all
 * integer from 1 up to the user input.
 *
 *
 * Computation is based on the formula:
 * total += i
 * ____________________________________________________________
 * INPUT
 * inputNumber               : Number inputted by user
 *
 *
 * OUTPUT
 * Total                     : Total sum of input number
 *
 **************************************************************/

#include <iostream>

using namespace std;

int main()
{
    // VARIABLE DECLARATION
    int inputNumber; //  INPUT - Input number by user
    int total = 0;   // OUTPUT - Total sums of integers

    // INPUT VALUE
    cout << "Enter a positive number: "; // Prompts User to enter positive number
    cin >> inputNumber;                  // Input Positive Number

    // WHILE LOOP: VALIDATE POSITIVE NUMBER
    while (inputNumber <= 0)
    {
        cout << "\nERROR: Must input a positive number\n"
             << endl;
        cout << "Enter a positive number: ";
        cin >> inputNumber; // Input Positive Number
    }

    // FOR LOOP: ADD SUM OF ALL INTEGERS STARTING FROM 1
    for (int i = 1; i <= inputNumber; i++)
    {
        total += i; // CALCULATE - Total sum of all integers
    }

    // DISPLAY OUTPUT
    cout << total;

    // END OF PROGRAM
    return 0;
}