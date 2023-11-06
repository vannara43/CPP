/****************************************************
 * PROGRAMMED By : Vannara Thong
 * CLASS         : CSC5
 * SECTION       : MW 2:20PM - 5:30PM
 * ASSIGNMENT #1 : Basic Input / Output
 ****************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**************************************************************
 *
 *  COMPUTE RETROACTIVE PAY
 *  ___________________________________________________________
 *  This program accepts as user input an employee
 *  name, current annual salary and percent increase
 *  and computes a new annual salary, new monthly
 *  salary and retroactive pay due.  The program will
 *  execute three times prompting the user for the
 *  appropriate input and then displaying the computed
 *  values for the given input.
 *
 *  Computations are based on the assumption that input
 *  values are effective on January 1 and calculations
 *  are effective for July.
 *  _______________________________________________________
 *  INPUT
 *    fullName		 : Emplyee's full name
 *    salaryCurrent  : Current annual salary
 *    percentIncrease: Percent increase due
 *
 *  OUTPUT
 *    salaryNew: New salary after applying rate increase
 *    salaryMonthly  : New monthly salary
 *    retroactivePay : Retroactive pay due employee
 *
 **************************************************************/

int main()
{

     /**********************************************************
      * CONSTANTS
      * ---------------------------------------------------
      * MONTHS		: Total number months
      * RETRO_MONTHS : Number of months retroactive
      *****************************************************/

     // VARIABLE DECLARATION
     const int MONTHS = 12;      // INPUT - Employee's full name
     const int RETRO_MONTHS = 6; // INPUT - Employee's full name

     char fullName[30];     // INPUT - Employee's full name
     float salaryCurrent;   // INPUT - Current annual salary
     float percentIncrease; // INPUT - Percent increase due
     float salaryNew;       // OUTPUT - New salary after increase
     float salaryMonthly;   // OUTPUT - New monthly salary
     float retroactivePay;  // OUTPUT - Retroactive pay due employee

     // PERSONAL INFORMATION
     cout << "**************************************************** \n"
          << "* PROGRAMMED By : Vannara Thong \n"
          << "* CLASS         : CSC5 \n"
          << "* SECTION       : MW 2:20PM - 5:30PM \n"
          << "* ASSIGNMENT #1 : Basic Input / Output \n"
          << "**************************************************** \n"
          << endl;

     // FOR LOOP
     for (int i = 0; i <= 2; i++) // for loop begins and run 3 times
     {
          // INPUT VALUES
          cout << left << setw(29) << "What is your name?";           // Prompt to ask for name
          cin.getline(fullName, sizeof(fullName));                    // User will input full name
          cout << left << setw(29) << "What is your current salary?"; // Prompt to ask for salary
          cin >> salaryCurrent;                                       // User will input salary
          cout << left << setw(29) << "What is your pay increase?";   // Prompt to ask for name
          cin >> percentIncrease;                                     // User will input pay increase

          // CALCULATIONS
          salaryNew = salaryCurrent * percentIncrease + salaryCurrent;            // Calculation for New Salary
          salaryMonthly = salaryNew / MONTHS;                                     // Calculation for Monthly Salary
          retroactivePay = (salaryNew - salaryCurrent) / (MONTHS / RETRO_MONTHS); // Calculation for Retroactive Pay

          // DISPLAY OUTPUT
          cout << "\n"
               << fullName << "'s "
               << "SALARY INFORMATION" << endl;                                                                              // Display Name and Salary Information
          cout << left << setw(15) << "New Salary" << setw(19) << "Monthly Salary" << setw(15) << "Retroactive Pay" << endl; // Display Title
          cout << right << setprecision(2) << fixed
               << showpoint << setw(10) << salaryNew
               << setw(19) << salaryMonthly << setw(20)
               << retroactivePay << endl; // Display Outputs

          cout << "\n <Press Enter to continue> \n"
               << endl; // Will prompt user to press enter to continue
          cin.ignore(); // Ignore next line
          cin.get();    // Will wait for user to press enter key
     }

     return 0;
}
