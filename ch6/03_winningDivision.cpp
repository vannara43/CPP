// Vannara Thong CSC5 Chapter 6, p.369, #3
//
/**************************************************************
 *
 * GET TOP QUARTER SALES RESULT
 * ____________________________________________________________
 * This program collect all sales data and output the highest
 * sale and location of the highest sale.
 * ____________________________________________________________
 * INPUT
 * northeastSales           : Sales for location NE
 * southeastSales           : Sales for location SE
 * northwestSales           : Sales for location NW
 * southwestSales           : Sales for location SW
 *
 * OUTPUT
 * highest                  : Output the highest sale
 *
 **************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

// DECLARE FUNCTION PROTOTYPE
double getSales(double);
void findHighest(double, double, double, double);

int main()
{
    // VARIABLE DECLARATION
    double sales = 0;      // Sales
    double northeastSales; // INPUT - Sales for location NE
    double southeastSales; // INPUT - Sales for location SE
    double northwestSales; // INPUT - Sales for location NW
    double southwestSales; // INPUT - Sales for location SW

    // INVOLKE FUNCTION
    northeastSales = getSales(sales); // Get sales
    southeastSales = getSales(sales); // Get sales
    northwestSales = getSales(sales); // Get sales
    southwestSales = getSales(sales); // Get sales

    // CALL "findHighest" FUNCTION
    findHighest(northeastSales, southeastSales, northwestSales, southwestSales);

    // END OF PROGRAM
    return 0;
}
/***********************************************************
 * Definition for function getSales.                       *
 * This function will prompt user to enter data for each   *
 * location and return its call back.                      *
 ***********************************************************/
double getSales(double sales)
{
    // INPUT VALUE
    cout << "Enter Sales: " << endl;
    cin >> sales;

    // WHILE LOOP: PROMP USER TO ENTER POSTIVE DATA
    while (sales < 0)
    {
        cout << "Enter Sales that is positive: " << endl;
        cin >> sales;
    }

    // END OF FUNCTION
    return sales;
}

/***********************************************************
 * Definition for function findHighest.                    *
 * This function will compare all four sales from each     *
 * location and display which one is the highest sale.     *
 ***********************************************************/

void findHighest(double northeastSales, double southeastSales, double northwestSales, double southwestSales)
{
    // VARIABLE DECLARATION
    float highest = northeastSales;
    string name = "Northeast";
    bool found = false;

    // WHILE LOOP: FIND THE HIGHEST SALE
    while (!(found))
    {
        if (highest < southeastSales)
        {
            highest = southeastSales;
            name = "Southeast";
        }
        else if (highest < northwestSales)
        {
            highest = northwestSales;
            name = "Northwest";
        }
        else if (highest < southwestSales)
        {
            highest = southwestSales;
            name = "Southwest";
        }
        else
        {
            // DISPLAY HIGHEST SALE AND LOCATION
            cout << name << " has the biggest sale! "
                 << "With the highest number of " << highest << endl;
            found = true;
        }
    }
}