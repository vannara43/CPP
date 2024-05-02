#include <iostream>

using namespace std;

int main()
{
    int const SIZE = 5;
    int array[SIZE] = {5, 4, 3, 2, 1};

    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}