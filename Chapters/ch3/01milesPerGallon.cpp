// Vannara Thong CSC5 Chapter 3, P. 143, #1
//
/**************************************************************
 *
 * MILES PER TANK OF GAS
 * ____________________________________________________________
 * This program computes the miles a car can travel on one
 * gallon on gas.
 *
 *
 * Computation is based on the formula:
 * MilesPerGallon = Number of Gallons / Max Mileage on Full Tank
 * ____________________________________________________________
 * INPUT
 * gallonsCanHold		: Total Gallon in car
 * milesDrivenFullTank  : Total Miles on Full tank of Gas
 *
 *
 * OUTPUT
 * gasMilagePerGallon   : Get miles per gallon
 *
 **************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    /* Write a program that calculates a car s gas mileage. The program should ask the user
    to enter the number of gallons of gas the car can hold, and the number of miles it can
    be driven on a full tank. It should then display the number of miles that may be driven
    per gallon of gas. */

    // VARIABLE DECLARATION
    float gallonsCanHold;      // INPUT - Total Gallon in car
    float milesDrivenFullTank; // INPUT - Total Miles on Full tank of Gas
    float gasMilagePerGallon;  // OUTPUT - Get miles per gallon

    // INPUTS
    cout << "Enter number of gallon your car can hold: ";
    cin >> gallonsCanHold; // Enter value for how much gallon car can holds
    cout << "Enter the number of miles it can be driven on a full tank: ";
    cin >> milesDrivenFullTank; // Enter value for maximum miles on full tank

    // CALCULATIONS
    gasMilagePerGallon = milesDrivenFullTank / gallonsCanHold; // Calculations to get miles per gallon

    // OUTPUT DISPLAY
    cout << "Your miles per gallon is: " << gasMilagePerGallon << endl; // Result for miles per gallon
}