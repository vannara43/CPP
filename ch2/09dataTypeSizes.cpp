// Vannara Thong CSC5 Chapter 2, p.82, #9
//
/**************************************************************
 *
 * CYBORG DATA TYPE SIZES
 * ____________________________________________________________
 * This program will compute the size of
 * char, int, float, and double
 * ____________________________________________________________
 * INPUT
 * sizeChar               : Byte Size of Char
 * sizeInt                : Byte Size of Integer
 * sizeFloat              : Byte Size of Float
 * sizeDouble             : Byte Size of Double
 *
 *
 * OUTPUT
 * sizeChar               : Will give byte size of Char
 * sizeInt                : Will give byte size of Int
 * sizeFloat              : Will give byte size of Float
 * sizeDouble             : Will give byte size of Double
 *
 **************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    size_t sizeChar = sizeof(char);     // will get byte size of char
    size_t sizeInt = sizeof(int);       // will get byte size of int
    size_t sizeFloat = sizeof(float);   // will get byte size of float
    size_t sizeDouble = sizeof(double); // will get byte size of double

    cout << "The size of Char: " << sizeChar << " bytes" << endl;     // will output size of char
    cout << "The size of Int: " << sizeInt << " bytes" << endl;       // will output size of int
    cout << "The size of Float: " << sizeFloat << " bytes" << endl;   // will output size of float
    cout << "The size of Double: " << sizeDouble << " bytes" << endl; // will output size of double
    cin.get();                                                        // wait for any keys to be pressed to end code

    return 0;
}