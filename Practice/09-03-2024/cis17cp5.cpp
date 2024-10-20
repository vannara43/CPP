// System Libraries Here
#include <iostream> //cin,cout
#include <iomanip>  //setw(10)
using namespace std;

// Global Constants Only, No Global Variables
// Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 80; // Max Columns much larger than needed

// Function Prototypes Here
void read(int array[][COLMAX], int &row, int &col);                          // Prompt for size then table
void sum(const int array[][COLMAX], int row, int col, int augAry[][COLMAX]); // Sum rows, col, grand total
void print(const int array[][COLMAX], int row, int col, int width);          // Either table can be printed

// Program Execution Begins Here
int main(int argc, char **argv)
{
    // Declare all Variables Here
    const int ROW = 80;           // Max Rows much larger than needed
    int array[ROW][COLMAX] = {};  // Declare original array
    int augAry[ROW][COLMAX] = {}; // Actual augmented table row+1, col+1
    int row, col;

    // Input the original table
    read(array, row, col);

    // Augment the original table by the sums
    sum(array, row, col, augAry);

    // Output the original array
    cout << endl
         << "The Original Array" << endl;
    print(array, row, col, 10); // setw(10)

    // Output the augmented array
    cout << endl
         << "The Augmented Array" << endl;
    print(augAry, row + 1, col + 1, 10); // setw(10)

    // Exit
    return 0;
}

// Function to read the size and the elements of the table
void read(int array[][COLMAX], int &row, int &col)
{
    cout << "Input a table and output the Augment row, col, and total sums." << endl;
    cout << "First input the number of rows and cols. <20 for each" << endl;
    cin >> row >> col;

    cout << "Now input the table." << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> array[i][j];
        }
    }
}

// Function to augment the original table with row sums, column sums, and total sum
void sum(const int array[][COLMAX], int row, int col, int augAry[][COLMAX])
{
    // Copy the original array into augAry
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            augAry[i][j] = array[i][j];
        }
    }

    // Calculate row sums
    for (int i = 0; i < row; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < col; j++)
        {
            rowSum += array[i][j];
        }
        augAry[i][col] = rowSum; // Place row sum in the last column
    }

    // Calculate column sums
    for (int j = 0; j < col; j++)
    {
        int colSum = 0;
        for (int i = 0; i < row; i++)
        {
            colSum += array[i][j];
        }
        augAry[row][j] = colSum; // Place column sum in the last row
    }

    // Calculate the grand total sum
    int grandTotal = 0;
    for (int i = 0; i < row; i++)
    {
        grandTotal += augAry[i][col]; // Sum of the row sums
    }
    augAry[row][col] = grandTotal; // Place the grand total in the bottom-right corner
}

// Function to print the table in a formatted manner
void print(const int array[][COLMAX], int row, int col, int width)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(width) << array[i][j];
        }
        cout << endl;
    }
}
