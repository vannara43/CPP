/*
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

// System Libraries Here
#include <iostream> //cin,cout
#include <vector>   //vectors<>
#include <iomanip>  //Format setw(),right
using namespace std;

// User Libraries Here

// Global Constants Only, No Global Variables
// Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 2; // Only 2 columns needed, even and odd

// Function Prototypes Here
void read(vector<int> &even, vector<int> &odd);
void copy(vector<int> even, vector<int> odd, int array[][COLMAX]);
void prntVec(vector<int> even, vector<int> odd, int width);
void prntAry(const int array[][COLMAX], int evenSize, int oddSize, int width);

// Program Execution Begins Here
int main(int argc, char **argv)
{
    // Declare all Variables Here
    const int ROW = 80;     // No more than 80 rows
    int array[ROW][COLMAX]; // Really, just an 80x2 array, even vs. odd
    vector<int> even, odd;  // Declare even, odd vectors

    // Input data and place even in one vector, odd in the other
    read(even, odd);

    // Now output the content of the vectors
    prntVec(even, odd, 10); // Input even, odd vectors with setw(10);

    // Copy the vectors into the 2 dimensional array
    copy(even, odd, array);

    // Now output the content of the array
    prntAry(array, even.size(), odd.size(), 10); // Same format as even/odd vectors

    // Exit
    return 0;
}

// Function to read input and separate even and odd numbers
void read(vector<int> &even, vector<int> &odd)
{
    int n;
    cout << "Input the number of integers to input." << endl;
    cin >> n;

    cout << "Input each number." << endl;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num % 2 == 0)
        {
            even.push_back(num);
        }
        else
        {
            odd.push_back(num);
        }
    }
}

// Function to copy the vectors into a 2D array
void copy(vector<int> even, vector<int> odd, int array[][COLMAX])
{
    int i;
    for (i = 0; i < even.size(); i++)
    {
        array[i][0] = even[i];
    }
    for (int j = 0; j < odd.size(); j++)
    {
        array[j][1] = odd[j];
    }
}

// Function to print the vectors in a formatted way
void prntVec(vector<int> even, vector<int> odd, int width)
{
    cout << setw(width) << "Vector" << setw(width) << "Even" << setw(width) << "Odd" << endl;

    int size = max(even.size(), odd.size());
    for (int i = 0; i < size; i++)
    {
        cout << setw(width) << setw(20);
        if (i < even.size())
        {
            cout << even[i];
        }
        else
        {
            cout << "";
        }
        cout << setw(width);
        if (i < odd.size())
        {
            cout << odd[i];
        }
        else
        {
            cout << "";
        }
        cout << endl;
    }
}

// Function to print the 2D array in a formatted way
void prntAry(const int array[][COLMAX], int evenSize, int oddSize, int width)
{
    cout << setw(width) << "Array" << setw(width) << "Even" << setw(width) << "Odd" << endl;

    int size = max(evenSize, oddSize);
    for (int i = 0; i < size; i++)
    {
        cout << setw(width) << setw(20);
        if (i < evenSize)
        {
            cout << array[i][0];
        }
        else
        {
            cout << "";
        }
        cout << setw(width);
        if (i < oddSize)
        {
            cout << array[i][1];
        }
        else
        {
            cout << "";
        }
        cout << endl;
    }
}
