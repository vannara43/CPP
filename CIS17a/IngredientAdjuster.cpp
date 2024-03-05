#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Declare variables
    int inputNumber = 0;        // User input number of cookies
    const double SUGAR = 1.5;   // fixed value for 48 cookies
    const double BUTTER = 1.0;  // fixed value for 48 cookies
    const double FLOUR = 2.75;  // fixed value for 48 cookies
    double sugarPerCookie = 0;  // Sugar amounts per cookies
    double butterPerCookie = 0; // Butter amounts per cookies
    double flourPerCookie = 0;  // Flour amounts per cookies

    // Prompt to ask user how many cookies
    cout << "How much cookies to make? ";
    cin >> inputNumber; // Enter value for

    // Calculations
    sugarPerCookie = (SUGAR / 48);   // for one cookie
    butterPerCookie = (BUTTER / 48); // for one cookie
    flourPerCookie = (FLOUR / 48);   // for one cookie

    // Display output for recipes
    cout << setprecision(2) << fixed << showpoint;
    cout << "Sugar needed: " << sugarPerCookie * inputNumber << endl;
    cout << "Butter needed: " << butterPerCookie * inputNumber << endl;
    cout << "Flour needed: " << flourPerCookie * inputNumber << endl;

    return 0;
}