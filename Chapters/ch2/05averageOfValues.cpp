// Vannara Thong CSC5 Chapter 2, p.81, #5
//
/**************************************************************
 *
 * AVERAGE OF VALUES
 * ____________________________________________________________
 * This program will compute the sum of all integers and
 * will get the average of those values
 * ____________________________________________________________
 * INPUT
 * a               : integer of 32
 * b               : integer of 28
 * c               : integer of 37
 * d               : integer of 24
 * e               : integer of 33
 * sum             : add all variables
 *
 *
 * OUTPUT
 * totalAverage    : is the average of sum
 *
 **************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c, d, e, sum;    // store integers
    float totalAverage;        // totalAverage will divide by 5
    a = 28;                    // a store the number 32
    b = 32;                    // b store the number 28
    c = 37;                    // c store the number 37
    d = 24;                    // d store the number 24
    e = 33;                    // e store the number 33
    sum = (a + b + c + d + e); // sum will add all variable together
    totalAverage = (sum / 5);  // totalAverage will get the average of sum

    cout << "The average is " << totalAverage << endl; // will output totalAverage
    cin.get();                                         // wait for any keys to be pressed to end code

    return 0;
}