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
void findHighest(double arrRainfall[], string arrMonths[], int SIZE); // Finds highest number
void findLowest(double arrRainfall[], string arrMonths[], int SIZE);  // Finds lowest number
double findTotal(double[], int);                                      // Totals of all numbers.

int main()
{
    // VARIABLE DECLARATION
    const int SIZE = 12; // Size of array
    string arrMonths[SIZE] = {"January", "February", "March", "April",
                              "May", "June", "July", "August",
                              "September", "October", "November", "December"};
    double arrRainfall[SIZE];
    double average; // OUTPUT - Average for rainfall

    // FOR LOOP: User enter rainfall data for each months
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter a rainfall value for " << arrMonths[i] << " : ";
        cin >> arrRainfall[i];

        // INPUT VALIDATION
        while (arrRainfall[i] < 0)
        {
            cout << "Please enter a positive number! Try again.\n";
            cin >> arrRainfall[i];
        }
    }

    // GET RESULTS
    cout << endl;
    findHighest(arrRainfall, arrMonths, SIZE); // Calls findHighest Function
    cout << endl;
    findLowest(arrRainfall, arrMonths, SIZE); // Calls findLowest Function
    cout << endl;
    average = findTotal(arrRainfall, SIZE) / SIZE; // Average of all numbers
    cout << endl;
    cout << "The average rainfall for the year is: " << average << endl;

    // END OF PROGRAM
    return 0;
}

/**************************************************************
 * Definition of function findHighest.                        *
 * This function receives data from array and calculates the  *
 * highest value. The function will display highest.          *
 **************************************************************/
void findHighest(double arr[], string arrMonths[], int SIZE)
{
    // VARIABLE DECLARATION
    int highest = arr[0];
    int position = 0;

    // FOR LOOP: Compares the highest number
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > highest) // Compares the highest number
        {
            highest = arr[i];
            position = i;
        }
    }
    cout << "The highest rainfall is " << highest << " from " << arrMonths[position];
}

/**************************************************************
 * Definition of function findLowest.                         *
 * This function receives data from array and calculates the  *
 * lowest value. The function will display lowest.            *
 **************************************************************/
void findLowest(double arr[], string arrMonths[], int SIZE)
{
    // VARIABLE DECLARATION
    int lowest = arr[0];
    int position = 0;

    // FOR LOOP: Compares the lowest number
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] < lowest) // Compares the lowest number
        {
            lowest = arr[i];
            position = i;
        }
    }
    cout << "The lowest rainfall is " << lowest << " from " << arrMonths[position];
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