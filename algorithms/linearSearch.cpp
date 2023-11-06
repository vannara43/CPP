#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int SIZE = 10;
    int arr[SIZE] = {13579, 26791, 26792, 33445, 55555,
                     62483, 77777, 79422, 85647, 93121};
    int userNumber;
    bool outcome = false;

    cout << "Enter lucky number: ";
    cin >> userNumber;

    for (int i = 0; i < SIZE; i++)
    {
        if (userNumber = arr[SIZE])
        {
            outcome = true;
        }
    }

    if (outcome)
    {
        cout << "You won!";
    }
    else
    {
        cout << "No matches.";
    }

    return 0;
}