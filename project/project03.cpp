/****************************************************
 * PROGRAMMED By : Vannara Thong
 * CLASS         : CSC5
 * SECTION       : MW 2:20PM - 5:30PM
 * ASSIGNMENT #1 : Basic Input / Output
 ****************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

/**************************************************************
 *
 *  COMPUTER LETTER GRADE AND GPA
 *  ___________________________________________________________
 *  This program accepts user inputs to enter letter grades
 *  and get verification to ensure no errors can be made
 *  during the calculations process to get GPA. This program
 *  executes three times prompting user to enter the appropriate
 *  information, it will then calculate all class scores and
 *  total classes to get GPA result.
 *
 *  Computations are based on letter grade scores divided by the
 *  amount of classes that are taken during the input process.
 *  _______________________________________________________
 *  INPUT
 *    enterGrade		      : Input data for grade score
 *
 *  OUTPUT
 *    gradePoints		      : Total Grade Points
 *    GPA		              : Grade Point Average
 *
 **************************************************************/

// DEFINE FUNCTIONS
void OutputInvoice(int accountNumber, string countyCode, int month, int day, int year, float totalSaleAmount, float CalcDiscount, float CalcSalesTax, float CalcShipping, float totalDue);
void GetSalesInfo(int &accountNumber, int &month, int &day, int &year, string &countyCode, float &totalSaleAmount, int &shippingWeight);
float CalcDiscount(int month);
float CalcSalesTax(string &countyCode);
float CalcShipping(int shippingWeight);

int main()
{
    int accountNumber;     // INPUT - User Account Number
    int month;             // INPUT - Month of sale
    int day;               // INPUT - Day of sale
    int year;              // INPUT - Year of sale
    string countyCode;     // INPUT - County Code of buyer
    int shippingWeight;    // INPUT - Weight of Product
    float totalSaleAmount; // Total Sales Amount
    float totalDue;        // Total Due from Sale
    float discount;        // Discount
    float salesTax;        // Sales Tax
    float shippingCost;    // Shipping Cost
    float discountTotal;   // Total Discount
    float salesTaxTotal;   // Total Sales Tax

    // PERSONAL INFORMATION
    cout << "**************************************************** \n"
         << "* PROGRAMMED BY : Vannara Thong \n"
         << "* CLASS         : CSC5 \n"
         << "* SECTION       : MW 2:20PM - 5:30PM \n"
         << "* ASSIGNMENT #2 : Functions\n"
         << "**************************************************** \n"
         << endl;

    // FOR LOOP
    for (int i = 0; i < 3; i++)
    {

        // INVOLKING FUNCTIONS AND STORING TO VARIABLES
        GetSalesInfo(accountNumber, month, day, year, countyCode, totalSaleAmount, shippingWeight); // call GetSalesInfo() to get user input data
        discount = CalcDiscount(month);
        salesTax = CalcSalesTax(countyCode);
        shippingCost = CalcShipping(shippingWeight);

        // CALCULATION
        discountTotal = totalSaleAmount * discount;                                  // Calculations for Discount
        salesTaxTotal = (totalSaleAmount - discountTotal) * salesTax;                // Calculations for Sales Tax
        totalDue = (totalSaleAmount - discountTotal + salesTaxTotal + shippingCost); // Calculations for Total Due

        // CALL FUNCTION
        OutputInvoice(accountNumber, countyCode, month, day, year, totalSaleAmount, discountTotal, salesTaxTotal, shippingCost, totalDue);
    }

    return 0;
}

void OutputInvoice(int accountNumber, string countyCode, int month, int day, int year, float totalSaleAmount, float CalcDiscount, float CalcSalesTax, float CalcShipping, float totalDue)
{
    // DISPLAY OUTPUT
    cout << setw(40) << left << "ACCOUNT NUMBER"
         << "COUNTY" << endl;
    cout << setw(9) << right << accountNumber
         << setw(41) << countyCode << endl;
    cout << "\n";
    cout << "DATE OF SALE: " << month << "/" << day << "/" << year << endl;
    cout << "\n\n";
    cout << setprecision(2) << fixed;
    cout << "SALE AMOUNT:" << setw(8) << "$" << right << setw(8) << totalSaleAmount << endl;
    cout << "DISCOUNT:" << setw(11) << "$" << right << setw(8) << CalcDiscount << endl;
    cout << "SALES TAX:" << setw(10) << "$" << right << setw(8) << CalcSalesTax << endl;
    cout << "SHIPPING:" << setw(11) << "$" << right << setw(8) << CalcShipping << endl;
    cout << "TOTAL DUE:" << setw(10) << "$" << right << setw(8) << totalDue << endl;
    cout << "\n\n";
}

void GetSalesInfo(int &accountNumber, int &month, int &day, int &year, string &countyCode, float &totalSaleAmount, int &shippingWeight)
{
    // INPUT DATA
    cout << "Please Enter your Account Number: "; // Prompt to enter Account Number
    cin >> accountNumber;
    cout << "Please Enter the Sales Date." << endl;
    cout << "Enter Month: "; // Prompt to enter a Month
    cin >> month;
    cout << "Enter Day: "; // Prompt to enter a Day
    cin >> day;
    cout << "Enter Year: "; // Prompt to enter a Year
    cin >> year;
    cout << "Please Enter the County Code: "; // Prompt to enter a County Code
    cin >> countyCode;
    cout << "Please Enter the Sales Amount: "; // Prompt to enter a Sales Amount
    cin >> totalSaleAmount;
    cout << "Please Enter the Weight: "; // Prompt to enter a weight
    cin >> shippingWeight;
    cout << "\n";
}

float CalcDiscount(int month)
{

    float discount;
    // DISCOUNT ON MONTH ORDERED
    if (month >= 1 && month <= 5) // 5 percent discount
    {
        discount = 0.05;
    }
    else if (month >= 6 && month <= 8) // 10 percent discount
    {
        discount = .10;
    }
    else if (month >= 9 && month <= 12) // 15 percent discount
    {
        discount = .15;
    }

    return discount; // returns the appropriate discount for the sale
}

float CalcSalesTax(string &countyCode)
{

    float salesTax;
    // COUNTY CODE SALES TAX
    if (countyCode == "o" || countyCode == "O")
    {
        countyCode = "Orange County";
        salesTax = .0775;
    }
    else if (countyCode == "s" || countyCode == "S")
    {
        countyCode = "San Diego County";
        salesTax = .0825;
    }
    else if (countyCode == "l" || countyCode == "L")
    {
        countyCode = "Los Angeles County";
        salesTax = .0800;
    }

    return salesTax; // returns the appropriate sales tax based on the county.
}

float CalcShipping(int shippingWeight)
{

    float shippingCost;
    // SHIPPING COST
    if (shippingWeight <= 25)
    {
        shippingCost = 5.00;
    }
    else if (shippingWeight >= 26 && shippingWeight <= 50)
    {
        shippingCost = ((shippingWeight - 25) * .10) + 5.00;
    }
    else if (shippingWeight > 50)
    {
        shippingCost = ((shippingWeight - 50) * .07) + 5.00;
    }

    return shippingCost; // returns the shipping based on weight.
}
