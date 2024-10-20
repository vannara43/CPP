/*
 * Author: Dr. Mark E. Lehr
 * Purpose: Template aggregates
 */

// User Libraries
#include <iostream>  // Allows input-output operations
#include <iomanip>   // Allows formatted output
using namespace std; // Simplifies the use of standard library functions

// RowAray Class Declaration
template <class T>
class RowAray
{
protected:
    int size;   // Size of the row (number of elements)
    T *rowData; // Pointer to an array that holds the data

public:
    RowAray(int);                        // Constructor
    virtual ~RowAray();                  // Destructor (virtual to allow inheritance)
    int mrkRand(int);                    // Random number generator function
    int getSize() const { return size; } // Returns the size of the array
    T getData(int i) const
    { // Returns the value at a specific index
        if (i >= 0 && i < size)
            return rowData[i];
        else
            return 0; // Return 0 if the index is out of bounds
    }
    void setData(int, T); // Function to set the value at a specific index
};

// Random Number Generator (mrkRand)
template <class T>
int RowAray<T>::mrkRand(int seed)
{
    // Xn+1 = (aXn + c) mod m
    // where X is the sequence of pseudo-random values
    // m, 0 < m  - modulus
    // a, 0 < a < m  - multiplier
    // c, 0 ≤ c < m  - increment
    // x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a = 31051;          // Multiplier (a prime number)
    unsigned int c = 997;            // Increment (a prime number)
    unsigned int shrt = 1 << 15 - 1; // Maximum value for signed short
    unsigned int m = 1 << 31 - 1;    // Maximum value for signed int
    static int Xn = 30937;           // Starting seed value
    static int cnt = 0;              // Counter to check if seed has been set
    if (cnt == 0 && seed <= shrt)    // Set seed only once
        Xn = seed;
    cnt++;
    Xn = (a * Xn + c) % m; // Generate pseudo-random number using the linear congruential method
    return Xn;
}

// RowAray Constructor and Destructor
template <class T>
RowAray<T>::RowAray(int n)
{
    size = n;              // Initialize the size
    rowData = new T[size]; // Dynamically allocate memory for the row data
    for (int i = 0; i < size; i++)
    {
        rowData[i] = mrkRand(size) % 90 + 10; // Populate with random numbers between 10 and 99
    }
}

template <class T>
RowAray<T>::~RowAray()
{
    delete[] rowData; // Free dynamically allocated memory when object is destroyed
}

// RowAray setData() Function
template <class T>
void RowAray<T>::setData(int row, T val)
{
    if (row >= 0 && row < size)
        rowData[row] = val; // Assign value if the index is within bounds
    else
        rowData[row] = 0; // Default to 0 if the index is invalid
}

// Table Class Declaration
template <class T>
class Table
{
protected:
    int szRow;            // Number of rows
    int szCol;            // Number of columns
    RowAray<T> **columns; // Pointer to an array of pointers to RowAray objects

public:
    Table(unsigned int, unsigned int);     // Constructor
    Table(const Table<T> &);               // Copy Constructor
    virtual ~Table();                      // Destructor
    int getSzRow() const { return szRow; } // Returns the number of rows
    int getSzCol() const { return szCol; } // Returns the number of columns
    T getData(int, int) const;             // Gets data at a specific row and column
    void setData(int, int, T);             // Sets data at a specific row and column
    Table<T> operator+(const Table<T> &);  // Overloaded addition operator to add two tables
};

// Table Constructor
template <class T>
Table<T>::Table(unsigned int rows, unsigned int cols)
{
    szRow = rows;                      // Initialize number of rows
    szCol = cols;                      // Initialize number of columns
    columns = new RowAray<T> *[szRow]; // Allocate memory for rows (array of pointers to RowAray objects)
    for (int i = 0; i < szRow; i++)
    {
        columns[i] = new RowAray<T>(szCol); // Create a new RowAray object for each row
    }
}

// Table Copy Constructor
template <class T>
Table<T>::Table(const Table &a)
{
    szRow = a.szRow;                   // Copy number of rows
    szCol = a.szCol;                   // Copy number of columns
    columns = new RowAray<T> *[szRow]; // Allocate memory for rows
    for (int i = 0; i < szRow; i++)
    {
        columns[i] = new RowAray<T>(szCol); // Create new row for each row in the original table
        for (int j = 0; j < szCol; j++)
        {
            setData(i, j, a.getData(i, j)); // Copy data from the original table
        }
    }
}

// Table Destructor
template <class T>
Table<T>::~Table()
{
    for (int i = 0; i < szRow; i++)
    {
        delete columns[i]; // Free each RowAray
    }
    delete[] columns; // Free the array of row pointers
}

// Table getData() and setData()
template <class T>
T Table<T>::getData(int row, int col) const
{
    if (row >= 0 && row < szRow && col >= 0 && col < szCol)
    {
        return columns[row]->getData(col); // Get the data from the specified row and column
    }
    else
    {
        return 0; // Return 0 if the indices are invalid
    }
}

template <class T>
void Table<T>::setData(int row, int col, T val)
{
    if (row >= 0 && row < szRow && col >= 0 && col < szCol)
    {
        columns[row]->setData(col, val); // Set the data at the specified row and column
    }
}

// Overloaded Operator+
template <class T>
Table<T> Table<T>::operator+(const Table<T> &a)
{
    Table result(szRow, szCol); // Create a new table to store the result
    for (int i = 0; i < szRow; i++)
    {
        for (int j = 0; j < szCol; j++)
        {
            result.setData(i, j, this->getData(i, j) + a.getData(i, j)); // Add corresponding elements
        }
    }
    return result;
}

// Function Prototypes
template <class T>
void prntRow(T *, int); // Prints a single row (RowAray)
template <class T>
void prntTab(const Table<T> &); // Prints the entire table

// Main Function
int main(int argc, char **argv)
{
    // Initialize the random seed
    srand(static_cast<unsigned int>(time(0)));

    // Declare Variables
    int rows, cols;

    // Input the rows and the columns
    cout << "Input the Rows and Columns for the Row and Table Arrays" << endl;
    cin >> rows >> cols;

    // Test out the Row with integers and floats
    RowAray<int> a(rows);   // Integer row
    RowAray<float> b(cols); // Float row

    cout << "Test the Integer Row with Rows" << endl;
    prntRow(&a, rows); // Print integer row
    cout << "Test the Float Row with Columns" << endl;
    prntRow(&b, cols); // Print float row

    // Test out the Table with a float
    Table<float> tab1(rows, cols);   // Create a table of floats
    Table<float> tab2(tab1);         // Copy the first table
    Table<float> tab3 = tab1 + tab2; // Add the two tables

    cout << "Float Table 3 size is [row,col] = Table 1 + Table 2 [" << rows << "," << cols << "]" << endl;
    cout << "Table 1" << endl;
    prntTab(tab1); // Print table 1
    cout << "Table 2 copy of Table 1" << endl;
    prntTab(tab2); // Print table 2
    cout << "Table 3 addition of Table 1 and Table 2" << endl;
    prntTab(tab3); // Print table 3

    // Exit Program
    return 0;
}

// Function Definitions
template <class T>
void prntRow(T *a, int perLine)
{
    cout << fixed << setprecision(1); // Set floating point precision for consistent formatting
    for (int i = 0; i < a->getSize(); i++)
    {
        cout << a->getData(i) << " ";
        if (i % perLine == (perLine - 1))
            cout << endl;
    }
    cout << endl;
}

template <class T>
void prntTab(const Table<T> &a)
{
    for (int i = 0; i < a.getSzRow(); i++)
    {
        for (int j = 0; j < a.getSzCol(); j++)
        {
            cout << fixed << setprecision(1) << setw(6) << a.getData(i, j) << " "; // Print with proper spacing and precision
        }
        cout << endl;
    }
    cout << endl;
}
