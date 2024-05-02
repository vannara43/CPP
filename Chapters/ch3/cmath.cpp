#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Trigonometric Functions
    double value = 0.5;
    cout << "sin: " << sin(value) << endl;
    cout << "cos: " << cos(value) << endl;
    cout << "tan: " << tan(value) << endl;

    // Inverse Arc Functions
    cout << "asin: " << asin(value) << endl;
    cout << "acos: " << acos(value) << endl;
    cout << "atan: " << atan(value) << endl;

    // Hyperbolic Trig Functions
    cout << "sinh: " << sinh(value) << endl;
    cout << "cosh: " << cosh(value) << endl;
    cout << "tanh: " << tanh(value) << endl;

    // Some Root Functions
    cout << "sqrt(4): " << sqrt(4) << endl;
    cout << "sqrt(8)" << sqrt(8) << endl;

    // Logariths
    std::cout << "log(1.5)" << log(1.5) << std::endl;

    // Round Function
    cout << "round: " << round(50.5) << endl;
    cout << "round: " << round(50.49999) << endl;

    // Power Functions
    cout << "power: " << pow(3, 4) << endl;

    // Other Functions
    cout << "ceil: " << ceil(11.1) << endl;   // next highest whole number
    cout << "floor: " << floor(11.9) << endl; // next lowest whole number
    cout << "fabs: " << fabs(-11) << endl;    // absolute value of the variable
    cout << "hypot: " << hypot(3, 2) << endl; // we give (a,b) -> c from Pythagorean's theorem
    cout << "fmod: " << fmod(3, 2) << endl;   // Get the remainder

    // Comparison Functions
    double number = -2.4;
    if (isgreater(number, 0))
        cout << number << " is greater than 0" << endl;
    else
        cout << number << " is not greater than 0" << endl;

    return 0;
}