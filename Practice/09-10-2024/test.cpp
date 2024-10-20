
/*
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

// System Libraries Here
#include <iostream> // cin, cout
#include <cstring>  // strlen(), strcmp(), strcpy()
using namespace std;

const int COLMAX = 80; // Only 20 required, and 1 for null terminator

// Function Prototypes
int read(char array[][COLMAX], int &rowDet);                                                    // Outputs rows and columns detected from input
void sort(char array[][COLMAX], int rowIn, int colIn, const char replace[], const char with[]); // Sort by row using strcmp
void print(const char array[][COLMAX], int rowIn, int colIn);                                   // Print the sorted 2-D array
int custom_strcmp(char a[], char b[], const char replace[], const char with[]);                 // Replace sort order

int main(int argc, char **argv)
{
    // Declare all Variables
    const int ROW = 30;                 // Only 20 required
    char array[ROW][COLMAX];            // Bigger than necessary
    int colIn, colDet, rowIn, rowDet;   // Row, Col input and detected
    char replace[COLMAX], with[COLMAX]; // New sort order

    // Input the new sort order then sort
    cout << "Modify the sort order by swapping these characters." << endl;
    cin >> replace;
    cout << "With the following characters" << endl;
    cin >> with;
    cout << "Read in a 2 dimensional array of characters and sort by Row" << endl;
    cout << "Input the number of rows <= 20" << endl;
    cin >> rowIn;
    cout << "Input the maximum number of columns <=20" << endl;
    cin >> colIn;

    // Now read in the array of characters and determine its size
    rowDet = rowIn;
    cout << "Now input the array." << endl;
    colDet = read(array, rowDet);

    // Sort the array and print the result
    sort(array, rowIn, colIn, replace, with);
    cout << "The Sorted Array" << endl;
    print(array, rowIn, colIn);

    // Exit
    return 0;
}

// Function to read the 2D array
int read(char array[][COLMAX], int &rowDet)
{
    int colDet = 0;
    for (int i = 0; i < rowDet; i++)
    {
        cin >> array[i];
        int len = strlen(array[i]);
        if (len > colDet)
            colDet = len;
    }
    return colDet;
}

// Function to sort the 2D array rows
void sort(char array[][COLMAX], int rowIn, int colIn, const char replace[], const char with[])
{
    for (int i = 0; i < rowIn - 1; i++)
    {
        for (int j = i + 1; j < rowIn; j++)
        {
            if (custom_strcmp(array[i], array[j], replace, with) > 0)
            {
                char temp[COLMAX];
                strcpy(temp, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], temp);
            }
        }
    }
}

// Custom strcmp function with replacement sorting
int custom_strcmp(char a[], char b[], const char replace[], const char with[])
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        char charA = a[i];
        char charB = b[i];

        // Find and replace characters based on the custom order
        for (int j = 0; replace[j] != '\0'; j++)
        {
            if (charA == replace[j])
            {
                charA = with[j];
                break;
            }
        }
        for (int j = 0; replace[j] != '\0'; j++)
        {
            if (charB == replace[j])
            {
                charB = with[j];
                break;
            }
        }

        if (charA != charB)
        {
            return charA - charB;
        }
        i++;
    }

    return a[i] - b[i];
}

// Function to print the 2D array
void print(const char array[][COLMAX], int rowIn, int colIn)
{
    for (int i = 0; i < rowIn; i++)
    {
        cout << array[i] << endl;
    }
}
