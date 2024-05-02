#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int const SIZE = 10;
    int arr[SIZE] = {13579, 26791, 26792, 33445, 55555,
                     62483, 77777, 79422, 85647, 93121};
    int userNumber;
    int first = 0;
    int last = SIZE - 1;
    int middle;
    int position = -1;
    bool found = false; // flag

    cout << "Enter lucky number: ";
    cin >> userNumber;

    // WHILE LOOP: BINARY SEARCH
    while (!found && first <= last)
    {
        middle = (first + last) / 2;   // Calculate midpoint
        if (arr[middle] == userNumber) // mid value is found
        {
            found = true;
            position = middle;
        }
        else if (arr[middle] > userNumber)
        {
            last = middle - 1;
            cout << "Index: " << middle << endl;
            cin.get();
        }
        else
        {
            first = middle + 1;
            cout << "Index: " << middle << endl;
            cin.get();
        }
    }

    if (found)
    {
        cout << "You won! This value is found at element " << position;
    }
    else
    {
        cout << "No matches.";
    }

    return 0;
}