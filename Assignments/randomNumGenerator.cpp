#include <iostream>
#include <iomanip>
// #include <cstdlib>
// #include <string>
#include <ctime>
using namespace std;

int main()
{
    // Get the system time.
    unsigned seed = time(0);

    // Seed the random number generator.
    srand(seed);
    // Display three random numbers.
    cout << rand() % 10 << endl;
    cout << rand() % 10 << endl;
    cout << rand() % 10 << endl;

    return 0;
}