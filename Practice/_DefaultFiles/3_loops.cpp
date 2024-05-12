#include <iostream>

using namespace std;

int main()
{
    cout << endl;

    /* FOR LOOP*/
    for (int i = 0; i < 10; i++) // reset i to 0
    {
        cout << "For Loop: #" << i << endl; // display value of i per loop
    }

    /* Enhanced for loop */
    int collections[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // this is an array
    cout << "Enhanced For loop | collections : ";         // prompt for collection
    for (int i : collections)                             // collections gets stored to i
    {
        cout << i << " "; // display value of i per loop
    }
    cout << endl; // new line

    /* WHILE LOOP */
    int j = 0; // j is set to 0

    while (j < 10) // j is less than 10, continue looping
    {
        cout << "While Loop: #" << j << endl; // display value of j
        j++;                                  // j increase by 1 per loop
    }

    /* DO-WHILE LOOP */
    int k = 0;

    do // runs block of code below and then checks condition
    {
        cout << "Do-While Loop: #" << k << endl; // display value of k
        k++;                                     // k increase by 1
    } while (k < 10);                            // checks the condition if true

    return 0;
}