// Vannara Thong CSC5 Chapter 5, p.294, #2
//
/**************************************************************
 *
 * DISPLAY NUMBER TO ASCII CHARACTER
 * ____________________________________________________________
 * This program converts 127 character into ASCII characters.
 *
 *
 * Computation is based on the formula:
 * ascii_code_num = i
 * ____________________________________________________________
 * INPUT
 * N/A                       : N/A
 *
 *
 * OUTPUT
 * ascii_code_num            : Number to ASCII Character
 *
 **************************************************************/
#include <iostream>

using namespace std;

int main()
{
    // VARIABLE DECLARATION
    char ascii_code_num;

    // FOR LOOP: DISPLAY ALL ASCII CODE 0-127
    for (int i = 0; i < 127; i++)
    {
        ascii_code_num = i;
        cout << ascii_code_num << " "; // DISPLAY OUTPUT

        if (i % 16 == 0) // 16 Character per line
        {
            cout << endl;
        }
    }

    // END OF PROGRAM
    return 0;
}