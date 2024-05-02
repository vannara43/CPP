#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    // SHOULD BE DOUBLE TYPE FOR pow()
    double area, radius = 10;
    double PI = 3.14159;

    // 4 is raised to the power of 2
    area = pow(4.0, 2.0);

    // OUTPUT
    cout << "\n4 to the power of 2 is: " << area << "\n";

    // RADIUS OF A CIRCLE
    area = PI * pow(radius, 2.0);
    // area = PI * radius * radius; METHOD 2

    cout << "\nThe radius of a circle is: " << area << "\n";

    return 0;
}