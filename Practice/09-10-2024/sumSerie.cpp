#include <iostream>

using namespace std;

int main()
{

    int C, m, n;    // INPUTS:
    int result = 0; // Total value

    // Get input values from the user
    cout << "Enter the value of C: ";
    cin >> C;
    cout << "Enter the starting index m: ";
    cin >> m;
    cout << "Enter the ending index n: ";
    cin >> n;

    // Solution 1: Using the for loop to solve
    cout << "\nSolution 1: for-loop" << endl;

    // Calculate the result using a for loop
    for (int i = m; i <= n; i++)
    {
        result += C;
        cout << "n" << i << "(" << result - C << ") + " << C << " = " << result << endl;
    }

    // Print the result
    cout << "The result of the series is: " << result << endl;

    // Solution 2: Using the formula to solve
    cout << "\nSolution 2: (n - m + 1) * C" << endl;
    cout << "(" << n << " - " << m << " + 1) * " << C << endl;
    result = (n - m + 1) * C; // Calculation
    cout << "The result of the series is: " << result << endl;

    return 0;
}