// Vannara Thong CSC5 Chapter 2, p.82, #8
//
/**************************************************************
 *
 * TOTAL PURCHASE
 * ____________________________________________________________
 * This program will compute the sum of all integers and
 * sales tax for the cost of purchases
 * ____________________________________________________________
 * INPUT
 * item1               : integer of $12.95
 * item2               : integer of $24.95
 * item3               : integer of $6.95
 * item4               : integer of $14.95
 * item5               : integer of $3.95
 * subtotal            : add all items together
 * salesTax            : sales tax for items
 *
 *
 * OUTPUT
 * total    : is the total of all purchases and tax
 *
 **************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double item1, item2, item3, item4, item5, subtotal, salesTax, total; // total will divide by 5
    item1 = 12.95;                                                       // item1 store the number 12.95
    item2 = 24.95;                                                       // item2 store the number 24.95
    item3 = 6.95;                                                        // item3 store the number 6.95
    item4 = 14.95;                                                       // item4 store the number 14.95
    item5 = 3.95;                                                        // item5 store the number 3.95
    subtotal = item1 + item2 + item3 + item4 + item5;                    // subtotal will add all items together
    salesTax = .06;                                                      // this is tax added onto subtotal
    total = subtotal * salesTax + subtotal;                              // total will get total cost of purchase items

    cout << "The total is $" << total << endl; // will output total of all items and tax
    cin.get();                                 // wait for any keys to be pressed to end code

    return 0;
}