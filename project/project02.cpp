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
 *    switchWhile		      : Switch for while loop
 *    classTotal		      : Keep record of total classes
 *
 *  OUTPUT
 *    gradePoints		      : Total Grade Points
 *    GPA		              : Grade Point Average
 *
 **************************************************************/

int main()
{

    /**********************************************************
     * Accumulators
     * ---------------------------------------------------
     * classTotal		: Totals all classes
     * gradePoints      : Totals all grade points
     *****************************************************/

    // VARIABLE DECLARATIONS
    char enterGrade = 'A';   //  INPUT - Input for letter grade
    float classTotal = 0;    //  INPUT - Total Classes
    bool switchWhile = true; //  INPUT - Switch for while loop
    int gradePoints = 0;     // OUTPUT - Total Grade points
    float GPA;               // OUTPUT - Grade Point Average

    // FOR LOOP
    for (int i = 1; i <= 3; i++)
    {
        cout << "TEST #" << i << ":\n"
             << endl;       // Display Test Number
        switchWhile = true; // Restart condition for while loop

        // WHILE LOOP
        while (switchWhile == true)
        {
            // INPUT VARIABLE
            cout << "\tEnter Letter Grade(enter 'X' to exit): ";
            cin >> enterGrade;

            // IF STATEMENT VERIFICATION
            if (enterGrade == 'A' ||
                enterGrade == 'a' ||
                enterGrade == 'B' ||
                enterGrade == 'b' ||
                enterGrade == 'C' ||
                enterGrade == 'c' ||
                enterGrade == 'D' ||
                enterGrade == 'd' ||
                enterGrade == 'F' ||
                enterGrade == 'f' ||
                enterGrade == 'X' ||
                enterGrade == 'x')
            {
                // SWITCH CASE STATEMENT
                switch (enterGrade)
                {
                case 'a':
                case 'A':
                    gradePoints += 4;
                    classTotal++;
                    break;
                case 'b':
                case 'B':
                    gradePoints += 3;
                    classTotal++;
                    break;
                case 'c':
                case 'C':
                    gradePoints += 2;
                    classTotal++;
                    break;
                case 'd':
                case 'D':
                    gradePoints += 1;
                    classTotal++;
                    break;
                case 'f':
                case 'F':
                    gradePoints += 0;
                    classTotal++;
                    break;
                case 'x':
                case 'X':
                    switchWhile = false;
                    break;
                }
            }
            else // Prompt User to enter valid letter grade
            {
                cout << "\n\tInvalid letter grade, please try again\n"
                     << endl;
            }
        };

        // Check for any grade points
        if (gradePoints)
        {
            // SINGLE SPACE
            cout << "\n";

            // CALCULATIONS
            GPA = gradePoints / classTotal;

            // OUTPUT DISPLAY
            cout << "Total Grade Points: " << gradePoints << endl;
            cout << left << setprecision(2) << fixed << "GPA: " << GPA << endl;
        }

        // RESET
        gradePoints = 0;
        classTotal = 0;

        // DOUBLE SPACE
        cout << "\n\n";
    }
    // outside of for loop, were in main now.
    return 0;
}
