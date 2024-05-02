// Vannara Thong CSC5 Chapter 4, p.220, #3
//
/**************************************************************
 *
 * GET MAGIC DATE
 * ____________________________________________________________
 * This program will calculate the day and month together to
 * check if the date is a magical date.
 *
 *
 * Computation is based on the formula:
 * month * day == year
 * ____________________________________________________________
 * INPUT
 * day                        : Day of the year
 * month                      : Month of the year
 * year                       : Year
 *
 *
 * OUTPUT
 * N/A                        : N/A
 *
 **************************************************************/

#include <iostream>

using namespace std;

int main()
{
    /*The date June 10, 1960 is special because when we write it in the following format, the month times the day equals the year.

    6/10/60

    Write a program that asks the user to enter a month (in numeric form), a day, and a two-digit year. The program should then determine whether the month times the day is equal to the year. If so, it should display a message saying the date is magic. Otherwise it should display a message saying the date is not magic.*/

    // VARIABLE DECLARTION
    int day;
    int month;
    int year;

    // USER INPUT FOR MONTH, DAY, AND YEAR
    cout << "Enter a month(in numeric form): ";
    cin >> month;
    cout << "Enter a day(in numeric form): ";
    cin >> day;
    cout << "Enter a two digit year(in numeric form): ";
    cin >> year;

    // DECISION STATEMENT: CHECK IF ITS A MAGIC DATE
    if (month * day == year) // IS A MAGIC DATE
    {
        cout << month << "/" << day << "/" << year << endl;
        cout << "This date date is magic" << endl;
    }
    else // NOT A MAGIC DATE
    {
        cout << month << "/" << day << "/" << year << endl;
        cout << "This date date is not magic" << endl;
    }
    return 0;
}