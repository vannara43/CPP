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
    bool switchWhile = true; // INPUT - x
    char enterGrade = 'A';   // INPUT - Input for letter grade
    int gradePoints = 0;     // INPUT - Grade points
    float classTotal = 0;    // INPUT - Total Classes
    float GPA;               // INPUT - Total Classes

    // FOR LOOP
    for (int i = 1; i <= 3; i++)
    {
        cout << "TEST #" << i << ":\n"
             << endl;
        switchWhile = true; // Restart condition for while loop

        // WHILE LOOP
        while (switchWhile == true)
        {
            // INPUT VARIABLE
            cout << "\tEnter Letter Grade(enter 'X' to exit): ";
            cin >> enterGrade;

            // IF STATEMENTS
            if (enterGrade == 'A')
            {
                gradePoints += 4;
                classTotal++;
            }
            else if (enterGrade == 'a')
            {
                gradePoints += 4;
                classTotal++;
            }
            else if (enterGrade == 'B')
            {
                gradePoints += 3;
                classTotal++;
            }
            else if (enterGrade == 'b')
            {
                gradePoints += 3;
                classTotal++;
            }
            else if (enterGrade == 'C')
            {
                gradePoints += 2;
                classTotal++;
            }
            else if (enterGrade == 'c')
            {
                gradePoints += 2;
                classTotal++;
            }
            else if (enterGrade == 'D')
            {
                gradePoints += 1;
                classTotal++;
            }
            else if (enterGrade == 'd')
            {
                gradePoints += 1;
                classTotal++;
            }
            else if (enterGrade == 'F')
            {
                gradePoints += 0;
                classTotal++;
            }
            else if (enterGrade == 'f')
            {
                gradePoints += 0;
                classTotal++;
            }
            else if (enterGrade == 'X')
            {
                switchWhile = false;
            }
            else if (enterGrade == 'x')
            {
                switchWhile = false;
            }
            else
            {
                cout << "\n\tInvalid letter grade, please try again\n"
                     << endl;
            }
        };

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
    return 0;
}
