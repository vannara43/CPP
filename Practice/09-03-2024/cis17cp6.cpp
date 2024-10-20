/*
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 *
 */

// System Libraries Here
#include <iostream> //cin,cout,getline()
#include <cstring>  //strlen()
using namespace std;

// Function Prototypes Begin Here
int srch1(const char sntnce[], const char pattern[], int startPos);   // Search for 1 occurrence
void srchAll(const char sntnce[], const char pattern[], int match[]); // Search for all occurrences
void print(const char arr[]);                                         // Print the character arrays
void print(const int match[]);                                        // Print the array of indexes where the pattern was found

// Program Execution Begins Here
int main(int argc, char **argv)
{
    // Declare all Variables Here
    const int LINE = 81;              // Size of sentence or pattern to find
    char sntnce[LINE], pattern[LINE]; // 80 + null terminator
    int match[LINE];                  // Index array where pattern was found

    // Initialize match array to -1 (indicating no match)
    for (int i = 0; i < LINE; i++)
    {
        match[i] = -1;
    }

    // Input a sentence and a pattern to match
    cout << "Match a pattern in a sentence." << endl;
    cout << "Input a sentence" << endl;
    cin.getline(sntnce, LINE);
    cout << "Input a pattern." << endl;
    cin.getline(pattern, LINE);

    // Search for the pattern
    srchAll(sntnce, pattern, match);

    // Display the inputs and the outputs
    cout << endl
         << "The sentence and the pattern" << endl;
    print(sntnce);
    print(pattern);
    cout << "The positions where the pattern matched" << endl;
    print(match);

    // Exit
    return 0;
}

// Function to search for one occurrence of the pattern in the sentence
int srch1(const char sntnce[], const char pattern[], int startPos)
{
    int sLen = strlen(sntnce);  // Length of the sentence
    int pLen = strlen(pattern); // Length of the pattern

    for (int i = startPos; i <= sLen - pLen; i++)
    {
        bool found = true;
        for (int j = 0; j < pLen; j++)
        {
            if (sntnce[i + j] != pattern[j])
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return i; // Return the position where the pattern starts
        }
    }
    return -1; // Return -1 if pattern is not found
}

// Function to search for all occurrences of the pattern in the sentence
void srchAll(const char sntnce[], const char pattern[], int match[])
{
    int pos = 0;
    int index = 0;

    while (true)
    {
        pos = srch1(sntnce, pattern, pos);
        if (pos == -1)
        {
            break; // No more matches found
        }
        match[index++] = pos;
        pos += 1; // Move to the next position to continue searching
    }
}

// Function to print the character arrays
void print(const char arr[])
{
    cout << arr << endl;
}

// Function to print the array of indexes where the pattern was found
void print(const int match[])
{
    bool found = false;
    for (int i = 0; i < 81; i++)
    {
        if (match[i] != -1)
        {
            cout << match[i] << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "None" << endl;
    }
    // cout << endl;
}
