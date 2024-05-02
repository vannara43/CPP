#include <iostream>
#include <iomanip>
using namespace std;

// Pointer is a variable that holds the memory address of another variable

int main()
{

    int x, y;
    int *ptr = &x;
    int *ptr2 = &y;
    int sum;

    cout << "enter value for x : ";
    cin >> x;
    cout << "enter value for y : ";
    cin >> y;

    sum = *ptr + *ptr2;

    cout << "value of *ptr1: " << *ptr << endl;           // value
    cout << "value of *ptr2: " << *ptr2 << endl;          // value
    cout << "the sum of ptr1 and *ptr2: " << sum << endl; // value
    // cout << "memory address of ptr: " << ptr << endl; // memory address
}