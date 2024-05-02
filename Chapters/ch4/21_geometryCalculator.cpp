// Vannara Thong CSC5 Chapter 4, P. 225, #21
//
/**************************************************************
 *
 * COMPUTE AREA FOR SHAPES
 * ____________________________________________________________
 * This program computes the area of a circle, square, and
 * triangle base on user input.
 *
 *
 * Computation is based on the formula:
 * area = PI * pow(radius, 2);
 * area = length * width;
 * area = (base * height) * .5;
 * ____________________________________________________________
 * INPUT
 * user_choice		: Number 1-4 for menu
 *
 *
 * OUTPUT
 * area             : Area for circle, rectangle, and triangle
 *
 **************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // VARIABLE DECLARATION
    const float PI = 3.14159; // PI HELPS TO CALCULATE AREA OF CIRCLE
    int user_choice;          // INPUT - USER WILL ENTER NUMBER
    float area;               // AREA OF CIRCLE, RECTANGLE, AND TRIANGLE

    // DISPLAY MENU OPTION
    cout << "\nGeometry Calculator\n"
         << "\t1. Calculate the Area of a Circle\n"
         << "\t2. Calculate the Area of a Rectangle\n"
         << "\t3. Calculate the Area of a Triangle\n"
         << "\t4. Quit\n"
         << "\nEnter your choice (1-4): ";
    cin >> user_choice;
    cout << endl;

    // SWITCH CASE BASED ON USER CHOICE
    switch (user_choice)
    {
    // AREA OF CIRCLE
    case 1:
        int radius;

        cout << "What is the radius: ";
        cin >> radius;

        if (radius < 0)
        {
            cout << "Enter a positive number for the radius.\nRe-run the program and try again.";
        }
        else
        {
            area = PI * pow(radius, 2); // CALCULATE AREA OF CIRCLE
            cout << fixed << setprecision(2) << "The area of circle is " << area;
        }
        break;
    // AREA OF SQUARE
    case 2:
        float width, length;

        cout << "What is the length? " << endl;
        cin >> length;

        if (length > 0)
        {
            cout << "What is the width?" << endl;
            cin >> width;

            if (width > 0)
            {
                area = length * width; // CALCULATE AREA OF RECTANGLE

                cout << "The area of rectangle is " << area << endl;
            }
            else
            {
                cout << "Enter a width number greater than 0.\nRe-run the program and try again." << endl;
            }
        }
        else
        {
            cout << "Enter a length number greater than 0.\nRe-run the program and try again." << endl;
        }
        break;
    // AREA OF TRIANGLE
    case 3:
        float height,
            base;

        cout << "What is base length? ";
        cin >> base;

        if (base > 0)
        {
            cout << "What is the height? ";
            cin >> height;

            if (height > 0)
            {
                area = (base * height) * .5; // CALCULATE AREA OF TRIANGLE
                cout << "The area of triangle is " << area << endl;
            }
        }
        else
        {
            cout << "Enter a base  number greater than 0.\nRe-run the program and try again." << endl;
        }

        break;
    // QUIT
    case 4:
        cout << "Good-bye." << endl;
        break;
    // INVALID INPUT
    default:
        cout << "Invalid input, please enter a number 1-4. Re-run the program.";
        break;
    }
    return 0;
}