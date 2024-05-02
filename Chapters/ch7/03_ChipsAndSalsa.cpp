// Vannara Thong CSC5 Chapter 7, p.444, #3
//
/**************************************************************
 *
 * GET SALSA SALES REPORT
 * ____________________________________________________________
 * This program accepts user input to store data into an array.
 * The array will be checked and display the highest & lowest
 * number.
 *
 * Computation is based on the formula:
 * arr[i] > highest and arr[i] < lowest
 * ____________________________________________________________
 * INPUT
 * arr                        : User input data stored
 *
 *
 * OUTPUT
 * highest                    : Highest number sales
 * lowest                     : Lowest number sales
 * total                      : Total of number sales
 *
 **************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

// DECLARE FUNCITON PROTOTYPES
void findHighest(string arrString[], int arrInt[], int SIZE); // Find the highest value
void findLowest(string arrString[], int arrInt[], int SIZE);  // Find the lowest value
double findTotal(int[], int);                                 // Total of all values

int main()
{

    // VARIABLE DECLARATION
    const int SIZE = 5;                                                   // Size for array elements
    string arrString[SIZE] = {"mild", "medium", "sweet", "hot", "zesty"}; // Chips and salsa type
    int arrInt[SIZE] = {1, 2, 3, 4, 5};                                   // Number of jars hold

    // FOR LOOP:
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter a number of jars sold for " << arrString[i] << " : ";
        cin >> arrInt[i];

        // INPUT VALIDATION
        while (arrInt[i] < 0) // Checks if less than 0
        {
            cout << "Please enter a positive number! Try again.\n"; // Re-read
            cin >> arrInt[i];
        }
    }

    // SALES REPORT
    cout << endl;
    cout << "SALES REPORT" << endl; // Display Title

    findHighest(arrString, arrInt, SIZE); // CALLS findHighest FUNCTION

    cout << endl;
    findLowest(arrString, arrInt, SIZE); // CALLS findLowest FUNCTION

    cout << endl;
    findTotal(arrInt, SIZE); // CALLS findTotal FUNCTION

    return 0;
}

/**************************************************************
 * Definition of function findHighest.                        *
 * This function receives data from array and calculates the  *
 * highest value. The function will display highest.          *
 **************************************************************/
void findHighest(string arrString[], int arrInt[], int SIZE)
{
    // VARIABLE DECLARATION
    string highestName = arrString[0];
    int highest = arrInt[0];

    // FOR LOOP: Compares the highest number
    for (int i = 0; i < SIZE; i++)
    {
        if (arrInt[i] > highest) // Compares the highest number
        {
            highest = arrInt[i];        // Assigns highest number
            highestName = arrString[i]; // Assigns highest name
        }
    }
    cout << "The highest jar sale is " << highest << " from " << highestName << ".";
}

/**************************************************************
 * Definition of function findLowest.                         *
 * This function receives data from array and calculates the  *
 * lowest value. The function will display lowest.            *
 **************************************************************/
void findLowest(string arrString[], int arrInt[], int SIZE)
{
    // VARIABLE DECLARATION
    string lowestName = arrString[0];
    int lowest = arrInt[0];

    // FOR LOOP: Compares the lowest number
    for (int i = 0; i < SIZE; i++)
    {
        if (arrInt[i] < lowest) // Compares the lowest number
        {
            lowest = arrInt[i];        // Assigns lowest number
            lowestName = arrString[i]; // Assigns lowest name
        }
    }
    cout << "The lowest jar sale is " << lowest << " from " << lowestName << ".";
}

/**************************************************************
 * Definition of function findTotal.                          *
 * This function receives data from array and total the       *
 * value. The function will return the variable total.        *
 **************************************************************/
double findTotal(int arr[], int SIZE)
{
    // VARIABLE DECLARATION
    double total = 0;

    // FOR LOOP: Total of all number
    for (int i = 0; i < SIZE; i++)
    {
        total += arr[i]; // Total sum of all number sales
    }
    cout << "The total jar sale is " << total;

    return total;
}