// Vannara Thong CSC5 Chapter 6, p.371, #8
//
/**************************************************************
 *
 * FLIP HEAD OR TAILS
 * ____________________________________________________________
 * This program will generate a random number of 1 or 2. Which-
 * ever it is, the program will display heads or tail.
 * ____________________________________________________________
 * INPUT
 * count                     : Full name of person
 *
 *
 * OUTPUT
 * cointoss                  : Output head or tails
 *
 **************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// FUNCTION PROTOTYPE
void coinToss();
int inputValidation(int count);

int main()
{
    // VARIABLE DECLARATION
    int inputCount; // INPUT -  user will enter data
    int tossCount;  // For loop counter

    // RANDOM NUMBER SET-UP
    unsigned seed = time(0);
    srand(seed);

    // INVOKE FUNCTION TO VARIABLE
    tossCount = inputValidation(inputCount);

    // FOR LOOP: LOOP tossCount amount
    for (int i = 0; i < tossCount; ++i)
    {
        coinToss(); // Call coinToss Function
    }

    // END OF PROGRAM
    return 0;
}

/**************************************************************
 * Definition of function coinToss.                           *
 * This function will generate random number of 1 and 2 and   *
 * display whether it is 1(head) or 2(tails).                 *
 **************************************************************/
void coinToss()
{
    int cointoss = (rand() % 2) + 1;
    cout << (cointoss == 1 ? "You landed on head." : "You landed on tail.") << endl;
}

/**************************************************************
 * Definition of function inputValidation.                    *
 * This function will prompt user to enter a number for the   *
 * counter of a for-loop.                                     *
 **************************************************************/
int inputValidation(int count)
{
    do
    {
        cout << "Enter a positive number to flip coin amount: ";
        cin >> count;
        cout << endl;
    } while (count < 0);

    return count;
}