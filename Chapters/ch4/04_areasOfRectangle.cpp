#include <iostream>

using namespace std;

int main()
{
    /*The area of a rectangle is the rectangle's length times its width. Write a program that asks for the length and width of two rectangles. The program should tell the user which rectangle has the greater area, or if the areas are the same.*/

    int length1;
    int length2;
    int width1;
    int width2;
    int rectangle1;
    int rectangle2;

    cout << "Enter a length for area 1: ";
    cin >> length1;
    cout << "Enter a width for area 1: ";
    cin >> width1;
    cout << "Enter a length for area 2: ";
    cin >> length2;
    cout << "Enter a width for area 2: ";
    cin >> width2;

    rectangle1 = length1 * width1;
    rectangle2 = length2 * width2;

    if (rectangle1 == rectangle2)
    {
        cout << "rectangle 1 and rectangle 2 are the same area." << endl;
    }
    else if (rectangle1 > rectangle2)
    {
        cout << "rectangle 1 has a greater area." << endl;
    }
    else
    {
        cout << "rectangle 2 has a greater area." << endl;
    }
    return 0;
}