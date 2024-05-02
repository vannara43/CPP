// Vannara Thong CSC5 Chapter 4, P. 224, #20
//
/**************************************************************
 *
 * CHECK FREEZING AND BOILING POINTS
 * ____________________________________________________________
 * This program computes the temperature and tells you what
 * substance will freeze and boil.
 *
 *
 * Computation is based on the formula:
 * user_temp <= 32 to -362
 * ____________________________________________________________
 * INPUT
 * user_temp		: Temperature
 *
 *
 * OUTPUT
 * N/A              : N/A
 *
 **************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

/*  Freezing and Boiling Points

    The following table lists the freezing and boiling points of several substances. Write a
    program that asks the user to enter a temperature, and then shows all the substances
    that will freeze at that temperature and all that will boil at that temperature. For
    example, if the user enters 20 the program should report that water will freeze and
    oxygen will boil at that temperature.
*/

int main()
{
    // VARIABLE DECLARATION
    float user_temp;

    // TEMPERATURE INPUT
    cout << "Enter Temperature: ";
    cin >> user_temp;

    cout << "\nAt " << user_temp << "(F) these substances will either freeze or boil.\n"
         << endl;

    cout << left;
    cout << setw(14) << "Substance" << setw(22) << "Freezing Point(F)"
         << "Boiling Point(F)" << endl;
    cout << setw(14) << "---------" << setw(22) << "-----------------"
         << "----------------" << endl;

    // DECISION STATEMENT
    if (user_temp <= 32)
    {
        cout << setw(14) << "Water" << setw(22) << "32"
             << "212" << endl; // DISPLAY WATER

        if (user_temp <= -38)
        {
            cout << setw(14) << "Mercury" << setw(22) << "-38"
                 << "676" << endl; // DISPLAY MERCURY

            if (user_temp <= -173)
            {
                cout << setw(14) << "Ethyl Alcohol" << setw(22) << "-173"
                     << "172" << endl; // DISPLAY ETHYL ALCOHOL

                if (user_temp <= -362)
                {
                    cout << setw(14) << "Oxygen" << setw(22) << "-362"
                         << "-306" << endl; // DISPLAY OXYGEN
                }
            }
        }
    }

    return 0;
}