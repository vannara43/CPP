#include <iostream>
#include <array>
#include <string>

using namespace std;

int main()
{
    const int SIZE = 4;

    array<string, SIZE> names{"Jamie", "Ashley", "Doug", "Claire"};
    array<string, SIZE>::iterator it;

    // Display names
    cout << "Here are the names:\n";

    for (it = names.begin(); it != names.end(); ++it)
        cout << *it << endl;
    return 0;
}