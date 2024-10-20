/*
 * Author: Dr. Mark E. Lehr
 * Purpose:  Abstraction, Operator Overloading,
 *           Copy Construction and Polymorphism
 */

// User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

// User Libraries
class AbsRow
{
protected:
    int size;
    int *rowData;

public:
    virtual int getSize() const = 0;
    virtual int getData(int) const = 0;
};

class RowAray : public AbsRow
{
public:
    RowAray(unsigned int);
    virtual ~RowAray();
    int mrkRand(int);
    int getSize() const { return size; }
    int getData(int i) const
    {
        if (i >= 0 && i < size)
            return rowData[i];
        else
            return 0;
    }
    void setData(int, int);
};

int RowAray::mrkRand(int seed)
{
    unsigned int a = 31051;
    unsigned int c = 997;
    unsigned int shrt = 1 << 15 - 1;
    unsigned int m = 1 << 31 - 1;
    static int Xn = 30937;
    static int cnt = 0;
    if (cnt == 0 && seed <= shrt)
        Xn = seed;
    cnt++;
    Xn = (a * Xn + c) % m;
    return Xn;
}

RowAray::RowAray(unsigned int n)
{
    size = n;
    rowData = new int[size];
    for (int i = 0; i < size; i++)
    {
        rowData[i] = mrkRand(size) % 90 + 10;
    }
}

RowAray::~RowAray()
{
    delete[] rowData;
}

void RowAray::setData(int row, int val)
{
    if (row >= 0 && row < size)
        rowData[row] = val;
    else
        rowData[row] = 0;
}

class AbsTabl
{
protected:
    int szRow;
    int szCol;
    RowAray **columns;

public:
    virtual int getSzRow() const = 0;
    virtual int getSzCol() const = 0;
    virtual int getData(int, int) const = 0;
};

class Table : public AbsTabl
{
public:
    Table(unsigned int, unsigned int);
    Table(const Table &); // Copy constructor
    virtual ~Table();     // Destructor
    int getSzRow() const { return szRow; }
    int getSzCol() const { return szCol; }
    int getData(int, int) const;
    void setData(int, int, int);
};

Table::Table(unsigned int rows, unsigned int cols)
{
    szRow = rows;
    szCol = cols;
    columns = new RowAray *[szCol];
    for (int col = 0; col < szCol; col++)
    {
        columns[col] = new RowAray(szRow);
    }
}

// Copy constructor
Table::Table(const Table &a)
{
    szRow = a.szRow;
    szCol = a.szCol;
    columns = new RowAray *[szCol];
    for (int col = 0; col < szCol; col++)
    {
        columns[col] = new RowAray(szRow);
        for (int row = 0; row < szRow; row++)
        {
            columns[col]->setData(row, a.getData(row, col));
        }
    }
}

// Destructor
Table::~Table()
{
    for (int col = 0; col < szCol; col++)
    {
        delete columns[col];
    }
    delete[] columns;
}

// Get data from the table
int Table::getData(int row, int col) const
{
    if (row >= 0 && row < szRow && col >= 0 && col < szCol)
    {
        return columns[col]->getData(row);
    }
    return 0;
}

// Set data in the table
void Table::setData(int row, int col, int val)
{
    if (row >= 0 && row < szRow && col >= 0 && col < szCol)
    {
        columns[col]->setData(row, val);
    }
}

class PlusTab : public Table
{
public:
    PlusTab(unsigned int r, unsigned int c) : Table(r, c) {};
    PlusTab operator+(const PlusTab &);
};

// Operator overloading
PlusTab PlusTab::operator+(const PlusTab &a)
{
    PlusTab temp(szRow, szCol);
    for (int row = 0; row < szRow; row++)
    {
        for (int col = 0; col < szCol; col++)
        {
            temp.setData(row, col, this->getData(row, col) + a.getData(row, col));
        }
    }
    return temp;
}

// Global Constants

// Function Prototypes
void prntTab(const Table &);

// Execution Begins Here!
int main(int argc, char **argv)
{
    srand(static_cast<unsigned int>(time(0)));

    // Declare Variables
    int rows, cols;

    // Initialize Variables
    cout << "Input the Rows and Cols" << endl;
    cout << "For a 2-D Array composed of 1-D Rows" << endl;
    cout << "Created from Abstract Classes" << endl;
    cout << "Inherited to include Overloaded Operators" << endl;
    cin >> rows >> cols;

    // Test out the Tables
    PlusTab tab1(rows, cols);
    PlusTab tab2(tab1);
    PlusTab tab3 = tab1 + tab2;

    // Print the tables
    cout << "Abstracted and Polymorphic Print Table 1 size is [row,col] = ["
         << rows << "," << cols << "]";
    prntTab(tab1);
    cout << "Copy Constructed Table 2 size is [row,col] = ["
         << rows << "," << cols << "]";
    prntTab(tab2);
    cout << "Operator Overloaded Table 3 size is [row,col] = ["
         << rows << "," << cols << "]";
    prntTab(tab3);

    return 0;
}

void prntTab(const Table &a)
{
    cout << endl;
    for (int row = 0; row < a.getSzRow(); row++)
    {
        for (int col = 0; col < a.getSzCol(); col++)
        {
            cout << setw(4) << a.getData(row, col);
        }
        cout << endl;
    }
    cout << endl;
}
