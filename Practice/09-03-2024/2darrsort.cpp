#include <iostream>
#include <cstring>
using namespace std;

const int COLMAX = 80;

// function prototype
int read(char array[][COLMAX], int &row);
void sort(char array[][COLMAX], int rows, int cols);
void print(const char array[][COLMAX], int rows, int cols);
int main()
{
    const int ROW = 30;               // Only 20 required
    char array[ROW][COLMAX];          // Bigger than necessary
    int colIn, colDet, rowIn, rowDet; // Row, Col input and detected

    // Input the size of the array you are sorting
    do
    {
        cout << "Read in a 2 dimensional array of characters and sort by Row" << endl;
        cout << "Input the number of rows <= 20" << endl;
        cin >> rowIn;
        cout << "Input the maximum number of columns <=20" << endl;
        cin >> colIn;

        if (rowIn > ROW || colIn > COLMAX - 1)
        {
            return 0;
            // cout << "\nERROR!:Number of rows or columns exceeds the maximum allowed." << endl;
            // cout << "Please try again."
            //      << endl
            //      << endl;
        }
    } while (rowIn > ROW || colIn > COLMAX - 1);
    // cin.ignore();

    // Now read in the array of characters and determine it's size
    rowDet = rowIn;
    cout << "Now input the array." << endl;
    colDet = read(array, rowDet);

    // Compare the size input vs. size detected and sort if same
    // Else output different size
    if (rowDet == rowIn && colDet == colIn)
    {
        sort(array, rowIn, colIn);
        cout << "The Sorted Array" << endl;
        print(array, rowIn, colIn);
    }
    else
    {
        if (rowDet != rowIn)
            cout << (rowDet < rowIn ? "Row Input size less than specified." : "Row Input size greater than specified.") << endl;
        if (colDet != colIn)
            cout << (colDet < colIn ? "Column Input size less than specified." : "Column Input size greater than specified.") << endl;
    }

    return 0;
}

int read(char array[][COLMAX], int &rows)
{
    int maxCols = 0;
    cin.ignore(); // Clear newline left in buffer
    for (int i = 0; i < rows; ++i)
    {
        cin.getline(array[i], COLMAX); // Read input line with spaces if any
        int len = strlen(array[i]);
        if (len > maxCols)
            maxCols = len;
        if (len > COLMAX - 1)
            array[i][COLMAX - 1] = '\0'; // Ensure null termination if input is too long
        if (!(array[i]))
            return 0;
        // array[i][COLMAX - 1] = '\0'; // Ensure null termination if input is too long
    }
    return maxCols;
}

void sort(char array[][COLMAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < rows; j++)
        {
            if (strcmp(array[i], array[j]) > 0)
            {
                char temp[COLMAX];
                strcpy(temp, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], temp);
            }
        }
    }
}

void print(const char array[][COLMAX], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (!(array[i][j]))
                break;           // Stop printing at null terminator
            cout << array[i][j]; // Print each character in the row
        }
        cout << endl; // Move to the next line after each row
    }
}