/*
 * Author: Vannara Thong
 * Purpose:  Template aggregates
 */

// User Libraries
#include <iostream>
#include <iomanip>
using namespace std;

// User Libraries
template <class T>
class RowAray
{
protected:
    int size;   // Size of the row
    T *rowData; // Prointer to an array

public:
    RowAray(int);       // Constructor
    virtual ~RowAray(); // Destructor
    int mrkRand(int);   // Random Number Generator
    int getSize() const // Return size
    {
        return size;
    }
    T getData(int i) const // return rowData index value
    {
        if (i >= 0 && i < size)
            return rowData[i];
        else
            return 0;
    }
    void setData(int, T); // Set the value at index value
};
// Random Number Generator
template <class T>
int RowAray<T>::mrkRand(int seed)
{
    // Xn+1 = (aXn + c) mod m
    // where X is the sequence of pseudo-random values
    // m, 0 < m  - modulus
    // a, 0 < a < m  - multiplier
    // c, 0 ≤ c < m  - increment
    // x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a = 31051;          // Short Prime
    unsigned int c = 997;            // Another Prime
    unsigned int shrt = 1 << 15 - 1; // Range of positive signed short
    unsigned int m = 1 << 31 - 1;    // Range of positive signed int
    static int Xn = 30937;           // Short Prime
    static int cnt = 0;              // Initialize the seed
    if (cnt == 0 && seed <= shrt)
        Xn = seed;
    cnt++;
    Xn = (a * Xn + c) % m;
    return Xn;
}

// RowAray Constructor
template <class T>
RowAray<T>::RowAray(int n)
{
    size = n;
    rowData = new T[size];
    int seed = 30937;
    for (int i = 0; i < size; i++)
    {
        rowData[i] = mrkRand(size) % 90 + 10;
    }
}

// RowAray Destructor
template <class T>
RowAray<T>::~RowAray()
{
    delete[] rowData;
}

// RowAray setData() function
template <class T>
void RowAray<T>::setData(int row, T val)
{
    if (row >= 0 && row < size)
        rowData[row] = val;
    else
        rowData[row] = 0;
}

// Table Class
template <class T>
class Table
{
protected:
    int szRow; // Number of rows
    int szCol; // Number of columns
    RowAray<T> **columns;

public:
    Table(unsigned int, unsigned int);     // Constructor
    Table(const Table<T> &);               // Copy Constructor
    virtual ~Table();                      // Destructor
    int getSzRow() const { return szRow; } // Return number of row
    int getSzCol() const { return szCol; } // Return number of columns
    T getData(int, int) const;             // Return data at row n column
    void setData(int, int, T);             // Set value at row n column
    Table<T> operator+(const Table<T> &);  // Olverload operator
};

// Table Constructor
template <class T>
Table<T>::Table(unsigned int rows, unsigned int cols)
{
    // Student to correct/complete
    szRow = rows;                      // number of rows
    szCol = cols;                      // number of cols
    columns = new RowAray<T> *[szCol]; // Allocate memory
    for (int i = 0; i < szCol; i++)
    {
        columns[i] = new RowAray<T>(szRow); // Allocate memory
    }
}

// Table Copy Constructor
template <class T>
Table<T>::Table(const Table &a)
{
    // Student to correct/complete
    szRow = a.szRow;
    szCol = a.szCol;
    columns = new RowAray<T> *[szCol];
    for (int i = 0; i < szCol; i++)
    {
        columns[i] = new RowAray<T>(szRow);
        for (int j = 0; j < szRow; j++)
        {
            columns[i]->setData(j, a.columns[i]->getData(j));
        }
    }
}

// Table Destructor
template <class T>
Table<T>::~Table()
{
    // Student to correct/complete
    for (int i = 0; i < szCol; i++)
    {
        delete columns[i]; // Delete each row
    }
    delete[] columns; // Delete the array of row pointers
}

// Table getter(read data)
template <class T>
T Table<T>::getData(int row, int col) const
{
    // Student to correct/complete
    if (row >= 0 && row < szRow && col >= 0 && col < szCol)
    {
        return columns[col]->getData(row);
    }
    else
    {
        return 0;
    }
}

// Table Setter(set value)
template <class T>
void Table<T>::setData(int row, int col, T val)
{
    if (row >= 0 && row < szRow && col >= 0 && col < szCol)
    {
        columns[col]->setData(row, val); // Set the data at the specified row and column
    }
}

// Overloaded Operator+
template <class T>
Table<T> Table<T>::operator+(const Table<T> &a)
{
    Table<T> result(szRow, szCol);
    for (int i = 0; i < szCol; i++)
    {
        for (int j = 0; j < szRow; j++)
        {
            result.setData(j, i, this->getData(j, i) + a.getData(j, i));
        }
    }
    return result;
}

// Global Constants

// Function Prototype
template <class T>
void prntRow(T *, int);
template <class T>
void prntTab(const Table<T> &);

// Execution Begins Here!
int main(int argc, char **argv)
{
    // Initialize the random seed
    srand(static_cast<unsigned int>(time(0)));

    // Declare Variables
    int rows, cols;

    // Input the rows and the cols
    cout << "Input the Rows and Columns for the Row and Table Arrays" << endl;
    cin >> rows >> cols;

    // Test out the Row with integers and floats
    RowAray<int> a(rows);
    RowAray<float> b(cols);
    cout << "Test the Integer Row with Rows" << endl;
    prntRow(&a, rows);
    cout << "Test the Float Row with Columns" << endl;
    prntRow(&b, cols);

    // Test out the Table with a float
    Table<float> tab1(rows, cols);
    Table<float> tab2(tab1);
    Table<float> tab3 = tab1 + tab2;

    cout << "Float Table 3 size is [row,col] = Table 1 + Table 2 ["
         << rows << "," << cols << "]";
    cout << endl
         << "Table 1" << endl;
    prntTab(tab1);
    cout << "Table 2 copy of Table 1" << endl;
    prntTab(tab2);
    cout << "Table 3 addition of Table 1 and Table 2" << endl;
    prntTab(tab3);

    // Exit Stage Right
    return 0;
}

template <class T>
void prntRow(T *a, int perLine)
{
    cout << fixed << setprecision(1) << showpoint << endl;
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
    cout << fixed << setprecision(1) << showpoint << endl;
    for (int row = 0; row < a.getSzRow(); row++)
    {
        for (int col = 0; col < a.getSzCol(); col++)
        {
            cout << setw(8) << a.getData(row, col);
        }
        cout << endl;
    }
    cout << endl;
}
