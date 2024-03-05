#include <iostream>

using namespace std;

/*Cyborg Data Type Sizes

You have been given a job as a programmer on a Cyborg supercomputer. In order to accomplish some calculations,
you need to know how many bytes the following datatypes

use: char, unsigned short int, int, long, float, and double.

You do are notto use any manuals, so you will need to utilize the sizeof operator. Write a C++ program
that will determine the amount of memory used by these types and display the information on the screen.*/

int main()
{
    cout << "The byte size for char: " << sizeof(char) << endl;
    cout << "The byte size for unsigned short in: " << sizeof(unsigned short int) << endl;
    cout << "The byte size for int: " << sizeof(int) << endl;
    cout << "The byte size for long: " << sizeof(long) << endl;
    cout << "The byte size for float: " << sizeof(float) << endl;
    cout << "The byte size for double: " << sizeof(double) << endl;
    return 0;
}