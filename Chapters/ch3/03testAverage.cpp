// Vannara Thong CSC5 Chapter 3, p.143, #3
//
/**************************************************************
 *
 * TEST AVERAGE
 * ____________________________________________________________
 * This program will calculate the average of five
 * test scores.
 *
 *
 * Computation is based on the formula:
 * Average = Five Test scores / 5
 * ____________________________________________________________
 * INPUT
 * a                         : The first number.
 * b                         : The second number.
 * c                         : The third number.
 * d                         : The fourth number.
 * e                         : The fifth number.
 *
 *
 * OUTPUT
 * average                   : The average of the five numbers.
 *
 **************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    /* Write a program that asks for five test scores. The program should calculate the average test score and display it. The number displayed should be formatted in fixed-point notation, with one decimal point of precision. */

    // VARIATION DECLARATION
    float a, b, c, d, e; // variables for test score
    float average;       // The average of the five numbers.

    // INPUT VALUE
    cout << "Enter 5 test scores: a b c d e" << endl;
    cin >> a >> b >> c >> d >> e;

    // CALCULATION
    average = (a + b + c + d + e) / 5;

    // OUTPUT DISPLAY
    cout << setprecision(1) << fixed << "Average test score is: " << average;

    return 0;
}