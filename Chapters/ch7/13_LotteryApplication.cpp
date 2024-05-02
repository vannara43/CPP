// Vannara Thong CSC5 Chapter 7, p.447, #13
//
/**************************************************************
 *
 * PLAY THE LOTTERY TICKED FOR FREE
 * ____________________________________________________________
 * This program allows users to enter a lottery number. This
 * program will match lottery numbers and result a prize.
 *
 *
 * Computation is based on the formula:
 * arr[i] != randArr[i]
 * ____________________________________________________________
 * INPUT
 * userInput                 : Input for mode selection
 * arr                       : Input user lottery
 *
 *
 * OUTPUT
 * randArr                   : Random Lottery Number
 *
 **************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // VARIABLE DECLARATION
    unsigned seed = time(0);             // Seed for Srand
    srand(seed);                         // srand for rand()
    const int SIZE = 5;                  // Array size for elements
    int arr[SIZE];                       // User lottery number
    int randArr[SIZE] = {1, 2, 3, 4, 5}; // Lottery Number
    bool arrEqual = true;                // Checks if arrays are equal
    int userInput = 0;                   // INPUT - User enter value

    cout << "Select Mode(enter 1 or 2):";
    cin >> userInput;
    cout << endl;

    // SWITCH CASE: USER SELECT MODE FOR FIXED OR RANDOM LOTTERY
    switch (userInput)
    {
    case 1: // FIXED LOTTERY NUMBER
        cout << "Selected 1: Lottery# is { 1,2,3,4,5 }" << endl;
        break;
    case 2: // RANDOM LOTTERY NUMBER
        cout << "Selected 2: Lottery# is random" << endl;

        // FOR LOOP: RANDOMIZE LOTTERY NUMBER
        for (int i = 0; i < SIZE; i++)
        {
            randArr[i] = rand() % 10; // GENERATE RANDOM NUMBERS 0-9
        }
        break;
    default: // END THE PROGRAM AND PROMPTS USER TO RE-RUN
        cout << "Please enter 1 or 2. Re-run program";
        return 0;
    }

    // FOR LOOP: USER INPUT LOTTERY NUMBERS
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter your lottery numbers" << endl;
        cin >> arr[i];
    }

    // DISPLAY USER LOTTERY NUMBER
    cout << "Your numbers are: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " "; // Display User Lottery pick
    }

    // DISPLAY LOTTERY NUMBER
    cout << endl;
    cout << "Lottery Numbers: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << randArr[i] << " "; // Display Random Lottery Number
    }

    // COMPARES LOTTERY NUMBERS
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] != randArr[i]) // Compares the two lottery numbers
        {
            arrEqual = false;
        }
    }

    // Checks if the arrays are equal
    if (arrEqual) // If true, prompts user if win or lose.
    {
        cout << "Congratulation! You won a grand prize!" << endl;
    }
    else
    {
        cout << "You did not win. Please try again." << endl;
    }

    // END OF PROGRAM
    return 0;
}