#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {12, 321, 13, 45, 124, 567}; // Initiatalize Vector
    int k = 124;                                   // Declare k
    for (int i = 0; i < arr.size(); i++)           // Run for loop
    {
        if (arr[i] == k) // Check array for value k(124)
        {
            cout << "Index:" << i << endl;
            cout << "Value:" << arr[i] << endl;
        }
        else
        {
            cout << "Value not found in array" << endl;
            return -1;
        }
    }
}