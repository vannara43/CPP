// Vannara Thong CSC5 Chapter 5, p.294, #3
//
/**************************************************************
 *
 * COMPUTES OCEAN LEVEL EVERY YEAR
 * ____________________________________________________________
 * This program calculate the ocean level per year and tracks
 * every year it rises.
 *
 *
 * Computation is based on the formula:
 * risePerYear += RISE
 * ____________________________________________________________
 * INPUT
 * N/A                       : N/A
 *
 *
 * OUTPUT
 * risePerYear               : Rise of ocean level per year
 *
 **************************************************************/
#include <iostream>

using namespace std;

int main()
{
    /*
    Assuming the oceans level is currently rising at about 1.5 millimeters per year, write a program that displays a table showing the number of millimeters that the ocean will have risen each year for the next 25 years.
    */

    // VARIABLE DECLARATION
    const float RISE = 1.5; // Constant rise of 1.5 per year
    float risePerYear = 0;  // OUTPUT - Rise of ocean per year

    // FOR LOOP: Increase risePerYear by 1.5
    for (int i = 1; i <= 25; i++)
    {
        risePerYear += RISE; // Add ocean level rise by 1.5
        cout << "Year " << i << ": " << risePerYear << " milimeters" << endl;
    }

    // END OF PROGRAM
    return 0;
}