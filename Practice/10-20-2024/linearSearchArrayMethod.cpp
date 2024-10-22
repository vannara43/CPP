#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 6> arr = {12, 321, 13, 45, 124, 567};
    int k = 124;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == k)
        {
            cout << "Index:" << i << endl;
            cout << "Value:" << arr[i] << endl;
        }
    }
    return -1;
}