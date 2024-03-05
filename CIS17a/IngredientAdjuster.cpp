#include <iostream>
#include <iomanip>
using namespace std;

/*
Ingredient Adjuster

A cookie recipe calls for the following ingredients:
• 1.5 cups of sugar
• 1 cup of butter
• 2.75 cups of flour
The recipe produces 48 cookies with this amount of the ingredients.

Write a program that asks the user how many cookies he or she wants to make, and then displays the number of cups of each ingredient needed for the specified number of cookies.
*/
int main()
{
    // Declare variables
    int inputNumber = 0;       // User input number of cookies
    const double SUGAR = 1.5;  // fixed value for 48 cookies
    const double BUTTER = 1.0; // fixed value for 48 cookies
    const double FLOUR = 2.75; // fixed value for 48 cookies
    double sugarPerCookie = 0;
    double butterPerCookie = 0;
    double flourPerCookie = 0;

    // Prompt to ask user how many cookies
    cout << "How much cookies to make? ";
    cin >> inputNumber;

    // Calculations
    sugarPerCookie = (SUGAR / 48);   // for one cookie
    butterPerCookie = (BUTTER / 48); // for one cookie
    flourPerCookie = (FLOUR / 48);   // for one cookie

    // Display output
    cout << setprecision(2) << fixed << showpoint;
    cout << "Sugar needed: " << sugarPerCookie * inputNumber << endl;
    cout << "Butter needed: " << butterPerCookie * inputNumber << endl;
    cout << "Flour needed: " << flourPerCookie * inputNumber << endl;

    return 0;
}