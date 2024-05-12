#include <iostream>

using namespace std;

// 1. Declare Function Prototypes
string stringFunction(string string1, string string2); // String function
int addFunction(int num1, int num2);                   // Sum function with integers
void printArray(int arr[], int size);                  // Print Array function

// 2. Declare functions
string stringFunction(string string1, string string2)
{
    string string3 = string1 + string2; // We concatenate and store into string3
    cout << "The result of your stringFunction:\n";
    cout << string3 << endl; // display string3
    ;

    return string3; // return string to main for use
}

int addFunction(int num1, int num2)
{
    int total = num1 + num2;
    cout << "The result of your addFunction:\n"
         << num1 << " + " << num2 << " = " << total << "\n"; // prompt for sum
    return total;                                            // return total for main for use
}

// array function
void printArray(int arr[], int size)
{ // We use a loop to display array elements
    cout << "Printing elements from array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 3. Call functions
int main()
{
    // Declare Variables
    string string1 = "Hello this is string 1 and ";
    string string2 = "this is string 2!";
    int num1 = 10;
    int num2 = 15;
    int const SIZE = 5;
    int arr[SIZE] = {9, 4, 7, 6, 8};

    cout << endl;
    /* Invoke the functions */
    stringFunction(string1, string2); // Call stringFunction
    addFunction(num1, num2);          // Call addFunction
    printArray(arr, SIZE);            // Call printArray
    return 0;
}