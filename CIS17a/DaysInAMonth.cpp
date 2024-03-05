#include <iostream>

using namespace std;

int main()
{
    // Variable Declaration
    int month;     // INPUT - Month of the year
    int year;      // INPUT - years
    int days = 31; // number of days

    // Prompt to enter month
    cout << "Enter a month (1-12): ";
    cin >> month; // Enter month value

    // Checks if user enter 1-12
    if (!(month < 1 || month > 12))
    {

        // Prompt user to enter year
        cout << "Enter a year: ";
        cin >> year;

        // SWITCH CASE: Determine what month
        switch (month) // Enter year value
        {
        case 1:
            // January has 31 days.
            break;
        case 2:
            // Calculation for leap year
            if ((year % 100 == 0) && (year % 400 == 0) || (year % 4 == 0))
                days = 29; // 29 days
            else
                days = 28; // 28 days
            break;
        case 3:
            // March has 31 days
            break;
        case 4:
            // April has 30 days
            days = 30;
            break;
        case 5:
            // May has 31 days
            break;
        case 6:
            // June has 30 days
            days = 30;
            break;
        case 7:
            // July has 31 days
            break;
        case 8:
            // August has 31 days
            break;
        case 9:
            // September has 30 days
            days = 30;
            break;
        case 10:
            // October has 31 days
            break;
        case 11:
            // November has 30 days
            days = 30;
            break;
        case 12:
            // Decemeber has 31 days
            break;
        }
        // Display Output for days
        cout << days << " days" << endl
             << endl;
    }
    else
    {
        cout << "Please re-run the program and try again.";
    }

    // End of program
    return 0;
}