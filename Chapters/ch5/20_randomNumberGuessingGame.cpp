// Vannara Thong CSC5 Chapter 5, P. 298, #20
//
/**************************************************************
 *
 *  GUESS THE RIGHT NUMBER
 *  ___________________________________________________________
 *  This program generates a random number for user to guess
 *  correctly. If the answer is too low or too high, it will
 *  prompt user to enter lower or higher.
 *
 *  Computations are based on:
 *  input data == randomNumber
 *  ___________________________________________________________
 *  INPUT
 *    inputNumber		      : User Input Numbers
 *
 *  OUTPUT
 *    randomNumber		      : Randon Number
 *
 **************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // VARIABLE DECLARATION
    int randomNumber;       // Random Number
    int inputNumber;        // User Input Number
    bool unanswered = true; // To begin while loop

    // GET THE SYSTEM TIME
    unsigned seed = time(0);

    // SEED THE RANDOM NUMBER GENERATOR
    srand(seed);

    // STORE RANDOM NUMBER IN VARIABLE "randomNumber"
    randomNumber = 1 + (rand() % 10);

    // WHILE LOOP: VERIFYING INPUT NUMBER
    while (unanswered) // Begin while loop
    {
        cout << "Guess what the number is?(1-10) " << endl; // Prompt user to guess number
        cin >> inputNumber;                                 // User input data

        if (inputNumber < 1 || inputNumber > 10) // Validates number is betweek 1 - 10
        {
            cout << "Invalid Input! Please choose a number between 1 and 10." << endl;
        }
        else if (inputNumber == randomNumber) // Validate if number is equal to random number
        {
            cout << "Congratulations! You're right."
                 << " The Random number is " << randomNumber << endl; // Display Random Number
            unanswered = false;                                       // Unanswer is now answered, value is true.
        }
        else if (inputNumber > randomNumber) // Validate if number is too high
        {
            cout << "Too high, try again." << endl; // Prompts user to enter a lower number
        }
        else // Number is too low
        {
            cout << "Too low, try again." << endl; // Prompts user to enter a higher number
        }
    }

    // END OF PROGRAM
    return 0;
}