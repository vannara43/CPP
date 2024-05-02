// Vannara Thong CSC5 Chapter 3, p.143, #4
//
/**************************************************************
 *
 * AVERAGE RAINFALL
 * ____________________________________________________________
 * This program will calculates the average rainfall
 * for three months.
 *
 *
 * Computation is based on the formula:
 * Average = Three Months / 3
 * ____________________________________________________________
 * INPUT
 * month1                    : Name of the first month
 * month2                    : Name of the second month
 * month3                    : Name of the third month
 * rainMonth1                : Rainfall in the first month
 * rainMonth2                : Rainfall in the second month
 * rainMonth3                : Rainfall in the third month
 *
 *
 * OUTPUT
 * average                   : average rainfall for three months.
 *
 **************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    /* Write a program that calculates the average rainfall for three months. The program should ask the user to enter the name of each month, such as June or July, and the amount of rain (in inches) that fell each month. The program should display a message similar to the following:

    The average rainfall for June, July, and August is 6.72 inches. */

    // VARIATION DECLARATION
    string month1;     // Name of the first month
    string month2;     // Name of the second month
    string month3;     // Name of the third month
    float rainMonth1;  // Rainfall in the first month
    float rainMonth2;  // Rainfall in the second month
    float rainMonth3;  // Rainfall in the third month
    float averageRain; // Average rainfall for three months.

    // INPUT VALUES
    cout << "Enter First Month: ";
    cin >> month1;
    cout << "Inches of rain fall first month: ";
    cin >> rainMonth1;
    cout << "Enter Second Month: ";
    cin >> month2;
    cout << "Inches of rain fall 2nd month: ";
    cin >> rainMonth2;
    cout << "Enter Third Month: ";
    cin >> month3;
    cout << "Inches of rain fall 3rd month: ";
    cin >> rainMonth3;

    // CALCULATION
    averageRain = (rainMonth1 + rainMonth2 + rainMonth3) / 3;

    // OUTPUT DISPLAY
    cout << setprecision(2) << fixed;
    cout << "The average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is " << averageRain << " inches.";

    return 0;
}