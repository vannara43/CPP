#include <iostream>

using namespace std;

int main()
{
    /*
    Running on a particular treadmill you burn 3.9 calories per minute. Write a program that uses a loop to display the number of calories burned after 10, 15, 20, 25, and 30  minutes.
    */

    float caloriesPerMin = 3.9;
    float totalBurnedCalories = 0;

    for (int i = 10; i <= 30; i += 5)
    {
        totalBurnedCalories = (caloriesPerMin * i);
        cout << "In " << i << " minutes, you burned " << totalBurnedCalories << " calories." << endl;
    }

    return 0;
}