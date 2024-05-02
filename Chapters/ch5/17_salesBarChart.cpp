// Vannara Thong CSC5 Chapter 5, P. 297, #17
//
/**************************************************************
 *
 *  STORE INPUT DATA AND CONVERT TO "*" FOR EVERY $100
 *  ___________________________________________________________
 *  This program prompts user five times to enter the data and
 *  displays it to represent a certain number of stars.
 *
 *  Computations are based on:
 *  input data / 100 = total stars
 *  _______________________________________________________
 *  INPUT
 *    inputData1		      : Sales for store 1
 *    inputData2		      : Sales for store 2
 *    inputData3		      : Sales for store 3
 *    inputData4		      : Sales for store 4
 *    inputData5		      : Sales for store 5
 *
 *  OUTPUT
 *    N/A		       		  : N/A
 *
 **************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    // VARIABLE DECLARATION
    int inputData1; // Data for store 1
    int inputData2; // Data for store 2
    int inputData3; // Data for store 3
    int inputData4; // Data for store 4
    int inputData5; // Data for store 5

    // INPUT DATA
    cout << "Enter today's sales for store 1: "; // Prompt user to input sales for store 1
    cin >> inputData1;                           // User input sales for store 1
    cout << "Enter today's sales for store 2: "; // Prompt user to input sales for store 2
    cin >> inputData2;                           // User input sales for store 2
    cout << "Enter today's sales for store 3: "; // Prompt user to input sales for store 3
    cin >> inputData3;                           // User input sales for store 3
    cout << "Enter today's sales for store 4: "; // Prompt user to input sales for store 4
    cin >> inputData4;                           // User input sales for store 4
    cout << "Enter today's sales for store 5: "; // Prompt user to input sales for store 5
    cin >> inputData5;                           // User input sales for store 5

    // CALCULATION
    inputData1 /= 100; // Converts every $100 to "*"
    inputData2 /= 100; // Converts every $100 to "*"
    inputData3 /= 100; // Converts every $100 to "*"
    inputData4 /= 100; // Converts every $100 to "*"
    inputData5 /= 100; // Converts every $100 to "*"

    // DISPLAY OUTPUT
    cout << "\n\nSALES BAR CHART\n(Each * = $100)" << endl;
    cout << "Store 1: " << setfill('*') << setw(inputData1) << "*" << endl; // Display Sales Bar for store 1
    cout << "Store 2: " << setfill('*') << setw(inputData2) << "*" << endl; // Display Sales Bar for store 2
    cout << "Store 3: " << setfill('*') << setw(inputData3) << "*" << endl; // Display Sales Bar for store 3
    cout << "Store 4: " << setfill('*') << setw(inputData4) << "*" << endl; // Display Sales Bar for store 4
    cout << "Store 5: " << setfill('*') << setw(inputData5) << "*" << endl; // Display Sales Bar for store 5

    return 0;
}
