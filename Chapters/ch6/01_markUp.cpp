// Vannara Thong CSC5 Chapter 6, p.369, #1
//
/**************************************************************
 *
 * GET TOTAL MARKUP PRICE
 * ____________________________________________________________
 * This program will prompt the user to enter a wholesale
 * price and mark up percentage. Program will compute the
 * final sale price.
 *
 * Computation is based on the formula:
 * itemCost * (markup / 100) + itemCost
 * ____________________________________________________________
 * INPUT
 * itemCost                  : Item cost
 * markup                    : Mark up percentage
 *
 *
 * OUTPUT
 * retailPrice               : Total price
 *
 **************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

float calculateRetail(float, float);
int main()
{

    // VARIABLE DECLARATION
    float itemCost;    // INPUT - item cost
    float markup;      // INPUT - mark up percentage
    float retailPrice; // OUTPUT - total price

    // INPUT DATA
    cout << "Enter an item wholesale cost: " << endl;
    cin >> itemCost;
    cout << "Enter markup percentage: " << endl;
    cin >> markup;

    // INPUT VALIDATION
    while (!(itemCost > 0 && markup > 0))
    {
        cout << "ERROR: You must enter a positive number, please try again. " << endl;
        if (!(itemCost > 0))
        {
            cout << "Enter an item wholesale cost: " << endl;
            cin >> itemCost;
        }
        else if (!(markup > 0))
        {
            cout << "Enter markup percentage: " << endl;
            cin >> markup;
        }
    }

    // CALCULATION
    retailPrice = calculateRetail(itemCost, markup);

    // DISPLAY OUTPUT
    cout << setprecision(2) << fixed;
    cout << "Total: $" << retailPrice;

    // END OF PROGRAM
    return 0;
}

/***********************************************************
 * Definition for function float calculateRetail.          *
 * This function will calculate the retail price. The      *
 * parameters is the cost of item and mark up percentage.  *
 ***********************************************************/
float calculateRetail(float itemCost, float markup)
{
    float total; // declare variable

    total = (itemCost * (markup / 100) + itemCost); // get total calculation

    return total; // return value to function caller
}