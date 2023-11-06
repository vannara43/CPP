#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> integers = {10, 20, 30};
    vector<int> integers2 = {1, 2, 3, 4, 5};
    vector<float> floats = {1, 2, 3, 4, 5};
    vector<string> strings;
    vector<char> chars;
    int x = 0;

    integers.push_back(2 * 2); // Add value into element
    for (int i = 0; i < integers.size(); i++)
    {
        cout << "push_back: " << integers[i] << endl;
    }

    integers.clear();     // Clear all elements from integers variable
    if (integers.empty()) // Detect empty vectors
    {
        cout << "No values in integers variable.\n";
    }

    integers.push_back(2 * 2); // Add value into element
    integers.push_back(2 * 3); // Add value into element
    integers.push_back(2 * 4); // Add value into element
    integers.push_back(2 * 5); // Add value into element
    integers.push_back(2 * 6); // Add value into element
    integers.push_back(2 * 7); // Add value into element
    integers.push_back(2 * 8); // Add value into element
    integers.push_back(2 * 9); // Add value into element
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << " ";
    }

    cout << endl;

    integers.pop_back(); // Remove last element
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << " ";
    }
    cout << endl;

    reverse(integers.begin(), integers.end()); // Reverse the order of elements in vector
    cout << "reverse(): ";
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << " ";
    }

    integers.insert(integers.begin() + 3, 50); // Inserts value to element location
    cout << "\nAdd 50 to element 3: ";
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << " ";
    }

    cout << endl;
    cout << "swap(): ";
    integers.swap(integers2);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << " ";
    }

    cout << endl;
    cout << "at(): " << integers.at(1); // Return value of element located in vector

    cout << endl;
    x = integers.capacity(); // Returns maximum number of elements
    cout << "capacity(): " << x;
    return 0;
}