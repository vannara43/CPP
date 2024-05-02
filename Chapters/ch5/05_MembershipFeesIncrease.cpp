#include <iostream>

using namespace std;

int main()
{
    /*
    A country club, which currently charges $2,500 per year for membership, has
    announced it will increase its membership fee by 4% each year for the next six years. Write a program that uses a loop to display the projected rates for the next six years.
    */

    const float CURRENT_CHARGE_PER_YEAR = 2500;
    const float INCREASE_PER_YEAR = .04;

    float fee = CURRENT_CHARGE_PER_YEAR;

    for (int i = 1; i <= 6; i++)
    {
        cout << "Fee for year " << i << " = $" << fee << endl;
        fee += fee * INCREASE_PER_YEAR; // increase the current charge by a percentage of itself.
    }

    return 0;
}