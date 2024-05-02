// Vannara Thong CSC5 Chapter 7, p.444, #2
/**************************************************************
 *
 * GET RAINFALL STATISTICS
 * ____________________________________________________________
 * This program accepts rainfall data and totals all rainfall
 * and returns an average. Also this programs reports the
 * highest and lowest number.
 *
 * Computation is based on the formula:
 * arr[i] > highest and arr[i] < lowest
 * average = findTotal(arr, SIZE) / SIZE;
 * ____________________________________________________________
 * INPUT
 * arr                        : User input data stored
 *
 *
 * OUTPUT
 * highest                    : Highest number
 * lowest                     : Lowest number
 * average                    : Average number
 *
 **************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

// DECLARE FUNCTION PROTOTYPES
void findHighest(double[], int); // Finds highest number
void findLowest(double[], int);  // Finds lowest number
double findTotal(double[], int); // Totals of all numbers

int main()
{
    // VARIABLE DECLARATION
    const int SIZE = 12; // Size of array
    double arr[SIZE];    // INPUT - Array stores rainfall amount
    double average;      // OUTPUT - Average for rainfall

    // FOR LOOP: User enter rainfall data for each months
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter a rainfall value for month " << i + 1 << " : ";
        cin >> arr[i];

        // INPUT VALIDATION
        while (arr[i] < 0)
        {
            cout << "Please enter a positive number! Try again.\n";
            cin >> arr[i];
        }
    }

    // GET RESULTS
    cout << endl;
    findHighest(arr, SIZE); // Calls findHighest Function
    cout << endl;
    findLowest(arr, SIZE); // Calls findLowest Function
    cout << endl;
    average = findTotal(arr, SIZE) / SIZE; // Average of all numbers
    cout << endl;
    cout << "The average rainfall for the year is: " << average << ".";

    // END OF PROGRAM
    return 0;
}

/**************************************************************
 * Definition of function findHighest.                         *
 * This function receives data from array and calculates the  *
 * highest value. The function will display highest.            *
 **************************************************************/
void findHighest(double arr[], int SIZE)
{
    // VARIABLE DECLARATION
    int highest = arr[0];

    // FOR LOOP: Compares the highest number
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > highest) // Compares the highest number
        {
            highest = arr[i];
        }
    }
    cout << "The highest rainfall is " << highest;
}

/**************************************************************
 * Definition of function findLowest.                         *
 * This function receives data from array and calculates the  *
 * lowest value. The function will display lowest.            *
 **************************************************************/
void findLowest(double arr[], int SIZE)
{
    // VARIABLE DECLARATION
    int lowest = arr[0];

    // FOR LOOP: Compares the lowest number
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] < lowest) // Compares the lowest number
        {
            lowest = arr[i];
        }
    }
    cout << "The lowest is " << lowest;
}

/**************************************************************
 * Definition of function findTotal.                          *
 * This function receives data from array and total the       *
 * value. The function will return the variable total.        *
 **************************************************************/
double findTotal(double arr[], int SIZE)
{
    // VARIABLE DECLARATION
    double total = 0;

    // FOR LOOP: Total of all number
    for (int i = 0; i < SIZE; i++)
    {
        total += arr[i]; // Totals all numbers
    }
    cout << "The total rainfall is " << total;

    // Returns Total
    return total;
}