// Vannara Thong CSC5 Chapter 3, p.143, #2
//
/**************************************************************
 *
 * STADIUM SEATING
 * ____________________________________________________________
 * Calculates and displays the total income generated from
 * ticket sales for three different classes.
 *
 *
 * Computation is based on the formula:
 * totalIncomeAll = Income from class A, B, C
 * ____________________________________________________________
 * INPUT
 * classA                    : Seats for class A
 * classB                    : Seats for class B
 * classC                    : Seats for class C
 * ticketA                   : Price for ticket A
 * ticketB                   : Price for ticket B
 * ticketC                   : Price for ticket C
 * totalIncomeA              : Income from class A
 * totalIncomeB              : Income from class B
 * totalIncomeC              : Income from class C
 *
 *
 * OUTPUT
 * totalIncomeAll            : Income from all class
 *
 **************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /* There are three seating categories at a stadium. For a softball game, Class A seats cost $15, Class B seats cost $12, and Class C seats cost $9. Write a program that asks how many tickets for each class of seats were sold, then displays the amount of income generated from ticket sales. Format your dollar amount in fixed-point notation, with two decimal places of precision, and be sure the decimal point is always displayed. */

    // VARIABLE DECLARATION
    float classA;         // Seats for class A
    float classB;         // Seats for class B
    float classC;         // Seats for class C
    float ticketA;        // Price for ticket A
    float ticketB;        // Price for ticket B
    float ticketC;        // Price for ticket C
    float totalIncomeA;   // Income from class A
    float totalIncomeB;   // Income from class B
    float totalIncomeC;   // Income from class C
    float totalIncomeAll; // Total Income from class A, B, and C

    // ASSIGN VALUES
    classA = 15;
    classB = 12;
    classC = 9;

    // INPUT VALUE
    cout << "Enter the number of Class A tickets sold: ";
    cin >> ticketA; // The variable to store the user input.
    cout << "Enter the number of Class B tickets sold: ";
    cin >> ticketB; // The variable to store the user input.
    cout << "Enter the number of Class C tickets sold: ";
    cin >> ticketC; // The variable to store the user input.

    // CALCULATIONS
    totalIncomeA = classA * ticketA;                             // Calculate income for class A
    totalIncomeB = classB * ticketB;                             // Calculate income for class A
    totalIncomeC = classC * ticketC;                             // Calculate income for class A
    totalIncomeAll = totalIncomeA + totalIncomeB + totalIncomeC; // Calculate income from class A, B, C

    // ADD SINGLE SPACE
    cout << "\n";

    // OUTPUT DISPLAY
    cout << setw(35) << "Class A" << setw(12) << "Class B" << setw(12) << "Class C" << endl;
    cout << "Amount of tickets sold:" << right << setw(12) << ticketA << setw(12) << ticketB << setw(12) << ticketC << endl;
    cout << "Income Generated:" << right << setprecision(2) << fixed << setw(12) << "$" << totalIncomeA << setw(6) << "$" << totalIncomeB << setw(6) << "$" << totalIncomeC << endl;
    cout << setw(59) << "_______________________________" << endl;
    cout << "Total Income: " << setw(39) << "$" << totalIncomeAll;

    return 0;
}