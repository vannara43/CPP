// This program demonstrates that an array element is passed
// to a function like any other variable.
#include <iostream>
using namespace std;
void showValue(int);         // Function prototype
void showValue2(int[], int); // Function prototype
int main()
{
    const int ARRAY_SIZE = 8;
    int numbers[ARRAY_SIZE] = {5, 10, 15, 20, 25, 30, 35, 40};

    // Method 1
    for (int index = 0; index < ARRAY_SIZE; index++)
        showValue(numbers[index]); // Send to function showValue

    cout << endl;

    // Method 2
    showValue2(numbers, ARRAY_SIZE);
    return 0;
}
//**********************************************
// Definition of function showValue. *
// This function accepts an integer argument. *
// The value of the argument is displayed. *
//**********************************************
void showValue(int num)
{
    cout << num << " ";
}

//**************************************************
// Definition of function showValue. *
// This function accepts an array of integers and *
// the array's size as its arguments. The contents *
// of the array are displayed. *
//**************************************************
void showValue2(int nums[], int size)
{
    for (int index = 0; index < size; index++)
        cout << nums[index] * 2 << " ";
    cout << endl;
}