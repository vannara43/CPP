#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x;
    cout << "Enter value for x :" << endl;
    cin >> x;

    switch (x)
    {
    case 1:
        cout << "Case 1 is running" << endl;
        break;
    case 2:
        cout << "Case 2 is running" << endl;
        break;
    default: // If enter any value beside 1 and 2
        cout << "I don't know where you went wrong" << endl;
    }

    return 0;
}