/*
 * File:   main.cpp
 * Author: Vannara Thong
 * Created on: 09/03/2024 05:23:00AM
 * Purpose:  To tell the Truth
 */

// System Libraries Here
#include <iostream>
using namespace std;

// User Libraries Here

// Global Constants Only, No Global Variables
// Like PI, e, Gravity, or conversions

// Function Prototypes Here

// Program Execution Begins Here
int main(int argc, char **argv)
{
    // Declare all Variables Here
    bool x, y;

    // Display the Heading
    cout << "X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y " << " !(X||Y) !X&&!Y" << endl;

    while (cin >> x >> y)
    {
        // Display Rows
        cout << (x ? 'T' : 'F') << " "
             << (y ? 'T' : 'F') << "  "
             << (!x ? 'T' : 'F') << "  "
             << (!y ? 'T' : 'F') << "   "
             << (x && y ? 'T' : 'F') << "    "
             << (x || y ? 'T' : 'F') << "   "
             << (x ^ y ? 'T' : 'F') << "    "
             << (x ^ y ^ x ? 'T' : 'F') << "     "
             << (x ^ y ^ y ? 'T' : 'F') << "       "
             << (!(x && y) ? 'T' : 'F') << "      "
             << (!x || !y ? 'T' : 'F') << "        "
             << (!(x || y) ? 'T' : 'F') << "      "
             << (!x && !y ? 'T' : 'F')
             << endl;
    };

    cout << endl;

    // Exit
    return 0;
}