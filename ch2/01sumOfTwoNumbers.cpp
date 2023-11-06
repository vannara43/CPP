// Vannara Thong CSC5 Chapter 2, p.81, #1
//
/**************************************************************
 *
 * SUM OF TWO NUMBERS
 * ____________________________________________________________
 * This program will computes the sum of two integers and
 * total will show outcome of the two integers
 * ____________________________________________________________
 * INPUT
 * a               : integer of 62
 * b               : integer of 99
 *
 * OUTPUT
 * total 	       : is the sum of a + b
 *
 **************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, total; // Integers
    a = 62;          // a store the number 62
    b = 99;          // b store the number 99
    total = a + b;   // total will add a and b variable together

    cout << "The total is " << total << endl; // will output total
    cin.get();                                // wait for any keys to be pressed to end code

    return 0;
}