/*
 * File:   main.cpp
 * Author: Vannara Thong
 * Created on September 16,2024
 * Purpose:  Triangular array
 *           Complete the functions with the defined structure
 */

// System Libraries Here
#include <iostream> //I/O Library
using namespace std;

// User Libraries Here
struct TriMatx
{
    int size;   // Represents the number of rows
    int *col;   // Represents the column array, i.e. number of columns for each row
    int *indx;  // Represents the index matrix which you can sort to use for display
    int **data; // Represents the data contents of the Triangular matrix
};

// Global Constants Only, No Global Variables
// Like PI, e, Gravity, or conversions

// Function Prototypes Here
int mrkRand(int = 1 << 15 - 1); // PSRNG repeating the same sequence
void prntAry(int *, int);       // Print a 1-D array
void destroy(TriMatx *);        // Deallocate memory
// Complete the following Function
TriMatx *fillMat(int);   // Randomly fill a triangular structure
void mrkSort(TriMatx *); // Use a database sort
void prntAry(TriMatx *); // Print a triangular array

// Program Execution Begins Here
int main(int argc, char **argv)
{
    // Declare all Variables Here
    int rowSize;    // Number of Rows in the Array
    TriMatx *triMt; // Triangular Matrix Structure

    // Input or initialize values Here
    cout << "Input the Number of Rows in the Array" << endl;
    cin >> rowSize;
    triMt = fillMat(rowSize); // Dynamic triangular array

    // Output Located Here
    cout << "The Column Array Size" << endl;
    prntAry(triMt->col, triMt->size);
    cout << "The Triangular Array Sorted" << endl;
    mrkSort(triMt); // Sort the columns with an index
    prntAry(triMt); // Display the Matrix with Columns sorted
    cout << endl;
    // Deallocate the structure
    destroy(triMt);

    // Exit
    return 0;
}

// Function to fill the Triangular Matrix
TriMatx *fillMat(int rows)
{
    TriMatx *triMt = new TriMatx;
    triMt->size = rows;
    triMt->col = new int[rows];
    triMt->indx = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        triMt->col[i] = mrkRand() % 9 + 1; // Columns between 1 and 9
        triMt->indx[i] = i;                // Initialize index array
    }

    triMt->data = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        triMt->data[i] = new int[triMt->col[i]]; // Each row has different column sizes
        for (int j = 0; j < triMt->col[i]; j++)
        {
            triMt->data[i][j] = mrkRand() % 9 + 1; // Fill with random digits [1-9]
        }
    }
    return triMt;
}

void prntAry(int *a, int n)
{
    if (a == 0)
        return;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl
         << endl;
}

void prntAry(TriMatx *triMt)
{
    for (int i = 0; i < triMt->size; i++)
    {
        int row = triMt->indx[i]; // Use sorted index to print rows
        for (int j = 0; j < triMt->col[row]; j++)
        {
            cout << triMt->data[row][j] << " "; // Print elements in the row
        }
        cout << endl; // Newline after each row
    }
    cout << endl; // Extra newline after the array is printed
}

void mrkSort(TriMatx *triMt)
{
    for (int pos = 0; pos < triMt->size - 1; pos++)
    {
        for (int lst = pos + 1; lst < triMt->size; lst++)
        {
            if (triMt->col[triMt->indx[pos]] > triMt->col[triMt->indx[lst]])
            {
                // Swap the indices to reorder based on column size
                int temp = triMt->indx[pos];
                triMt->indx[pos] = triMt->indx[lst];
                triMt->indx[lst] = temp;
            }
        }
    }
}

void destroy(TriMatx *triMt)
{
    for (int i = 0; i < triMt->size; i++)
    {
        delete[] triMt->data[i]; // Delete each row of the data array
    }
    delete[] triMt->data; // Delete the data array pointer
    delete[] triMt->col;  // Delete the column array
    delete[] triMt->indx; // Delete the index array
    delete triMt;         // Delete the structure itself
}

int mrkRand(int seed)
{
    // Xn+1 = (aXn + c) mod m
    unsigned int a = 31051;       // Short Prime
    unsigned int c = 997;         // Another Prime
    unsigned int m = 1 << 31 - 1; // Range of positive signed int
    static int Xn = 30937;        // Short Prime
    static int cnt = 0;           // Initialize the seed
    if (cnt == 0 && seed > 0)
        Xn = seed;
    cnt++;
    Xn = (a * Xn + c) % m;
    return Xn;
}